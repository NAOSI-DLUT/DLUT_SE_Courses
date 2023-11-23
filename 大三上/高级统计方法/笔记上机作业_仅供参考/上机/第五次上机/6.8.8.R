# 6.8.8
rm(list=ls())
# (a)
set.seed(123)
X = rnorm(100)
e = rnorm(100, mean=0, sd=1)

# (b)
b0 = 20
b1 = 2
b2 = 3
b3 = 6
Y = b0 + b1*X + b2*X^2 + b3*X^3 + e
plot(X ,Y)

# (c)
# 引入leaps库，其中包含regsubsets函数
library(leaps)
# 构造dataframe(X~X^10以及Y)
df = data.frame(X,X^2,X^3,X^4,X^5,X^6,X^7,X^8,X^9,X^10,Y)
# 选择Y的所有预测变量，最大变量个数为10
reg.fit = regsubsets(Y~.,data=df,nvmax=10)
reg.summary = summary(reg.fit)
# 通过summary可以看到每一步选择了哪些变量
reg.summary
# 查看Cp,BIC,以及调整R方在不同预测变量个数时的值
reg.summary$cp
reg.summary$bic
reg.summary$adjr2
# 对Cp,BIC,调整R方分别画图,以及标记最低点/最高点
par(mfrow=c(2,2))
plot(reg.summary$cp,xlab="预测变量个数", ylab="Cp",type="l")
points(which.min(reg.summary$cp), reg.summary$cp[which.min(reg.summary$cp)], col = "red", pch = 16)
plot(reg.summary$bic,xlab="预测变量个数", ylab="BIC",type="l")
points(which.min(reg.summary$bic), reg.summary$bic[which.min(reg.summary$bic)], col = "red", pch = 16)
plot(reg.summary$adjr2,xlab="预测变量个数", ylab="调整R方",type="l")
points(which.max(reg.summary$adjr2), reg.summary$adjr2[which.max(reg.summary$adjr2)], col = "red", pch = 16)

# 从图中可以看出Cp下的最优模型为p=3，BIC下为p=3，调整R方下为p=7
# 但是调整R方下当变量个数达到三个后，其值上升变化不大
# 故总体来说，当p=3时的模型是最优模型

# (d)
# 前向逐步法
reg.fit.fw = regsubsets(Y~.,data=df,nvmax=10,method='forward')
regfw.summary = summary(reg.fit.fw)
regfw.summary
regfw.summary$cp
regfw.summary$bic
regfw.summary$adjr2
# 与最佳子集方法得到的结果非常相似(p=3)

# 后向逐步法
reg.fit.bw = regsubsets(Y~.,data=df,nvmax=10,method='backward')
regbw.summary = summary(reg.fit.bw)
regbw.summary
regbw.summary$cp
regbw.summary$bic
regbw.summary$adjr2
# 与最佳子集方法得到的结果非常相似(p=3)

# (e)
library(glmnet)
set.seed(123)
# 从dataframe中构造X矩阵和Y向量
x = model.matrix(Y~.,df)[,-1]
y = df$Y
# 划分训练集和测试集(随机1:1)
train = sample(1:nrow(x), nrow(x)/2)
test = (-train)
y.test = y[test]
# 训练集下的lasso模型
lasso.train = glmnet(x[train,], y[train], alpha=1)
plot(lasso.train)
# 交叉验证误差与λ的函数与图像
cv.out = cv.glmnet(x[train,],y[train], alpha=1)
plot(cv.out)
cv.out$lambda.min
# 最佳λ=0.05840763

# 在完整的数据集上的lasso模型
lasso = glmnet(x,y,alpha=1)
plot(lasso)
lasso.coef = predict(lasso, type="coefficients",s=0.05840763)[1:11,]
lasso.coef

# 从图像以及参数的估计能够看出此模型在lasso下p=4时为最优模型
# 结论是该模型是一个有四个预测变量(X,X^2,X^3,X^4)的稀疏模型
# 同时预估结果与我们给定的系数非常相近(虽然没有给定b4,但是b4预估结果接近0)
# b0 = 20 b1 = 2 b2 = 3 b3 = 6 b4 = 0
# 估计值
# b0 = 20.09049402 b1 = 1.87440688 b2 = 2.66932011 b3 = 6.00730583 b4 = 0.04365821

# (f)
set.seed(123)
# 定义函数和dataframe
b7 = 7
Y = b0 + b7*X^7 + e
df = data.frame(X,X^2,X^3,X^4,X^5,X^6,X^7,X^8,X^9,X^10,Y)

# 最佳子集选择
reg.fit = regsubsets(Y~.,data=df,nvmax=10)
reg.summary = summary(reg.fit)
reg.summary
reg.summary$cp
reg.summary$bic
reg.summary$adjr2
# 整体来说p=3时达到最优模型

# lasso模型
# 训练集与数据集
x = model.matrix(Y~.,df)[,-1]
y = df$Y
train = sample(1:nrow(x), nrow(x)/2)
test = (-train)
y.test = y[test]

# 交叉验证误差与λ的函数
cv.out = cv.glmnet(x[train,],y[train], alpha=1)
cv.out$lambda.min
# 最佳λ=12.69134

# 设置λ为最佳λ后的模型
lasso = glmnet(x, y, alpha=1)
lasso.coef = predict(lasso,type="coefficients",s=12.69134)[1:11,]
lasso.coef

# b7的估计值6.757748 和 真实值7非常接近