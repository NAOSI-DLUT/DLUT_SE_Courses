# 6.8.9
rm(list=ls())
library(ISLR)
library(glmnet)
attach(College)
# (a)
set.seed(123)
# x为其他变量,y为申请人数
x = model.matrix(Apps~.,College)[,-1]
y = College$Apps
# 划分训练集与测试集(随机7:3)
train = sample(1:nrow(x), nrow(x)*0.7)
test = (-train)
y.test = y[test]
train.df = data.frame(College[train,])
test.df = data.frame(College[test,])

# (b)
# 最小二乘
lm.fit = lm(Apps~., data=train.df)
lm.pred = predict(lm.fit, test.df, type="response")
# 测试误差
err.lm = mean((lm.pred-test.df$Apps)^2)
err.lm
# MSE=1734841

# (c)
# 使用交叉验证选择的λ拟合岭回归模型
# 定义λ取值序列(10^-2~10^10)
grid = 10^seq(10,-2,length=100)
cv.out = cv.glmnet(x[train,],y[train],alpha=0)
ridge.mod = glmnet(x[train,],y[train],alpha=0,lambda=grid)
# 选择最佳λ时的岭回归预测
ridge.pred = predict(ridge.mod, s=cv.out$lambda.min, newx=x[test,])
# 测试误差
err.ridge = mean((ridge.pred-y.test)^2)
err.ridge
# 岭回归测试误差MSE=2970683

# (d)
# 操作与岭回归类似
cv.out = cv.glmnet(x[train,],y[train],alpha=1)
lasso.mod = glmnet(x[train,],y[train],alpha=1,lambda=grid)
lasso.pred = predict(lasso.mod, s=cv.out$lambda.min, newx=x[test,])
err.lasso = mean((lasso.pred-y.test)^2)
err.lasso
lasso.coef = predict(lasso.mod, type="coefficients", s=cv.out$lambda.min)[1:18,]
length(lasso.coef[lasso.coef!= 0])
# 17个不为0的系数(总共18个变量系数)
lasso.coef

# lasso回归测试误差MSE=1729378，略低于最小二乘的MSE
# 只有S.F.Ratio变量的系数为0，但是很多变量的系数几乎为0

# (e)
library(pls)
# 主成分回归模型
pcr.fit = pcr(Apps~., data=College, subset=train, scale=T, validation="CV")
# 验证统计量绘图，MSEP为主成分个数M的函数(MSEP为测试均方误差)
validationplot(pcr.fit, val.type="MSEP")
# 从该图中我们可以看出M=5的时候下降的幅度很大，但是M继续增大时，下降变化不大
# 最终M=16时降到最低

pcr.pred = predict(pcr.fit, x[test,], ncomp=5)
mean((pcr.pred-y.test)^2)
# M=5时MSE=4484678，非常大
pcr.pred = predict(pcr.fit, x[test,], ncomp=16)
err.pcr = mean((pcr.pred-y.test)^2)
err.pcr
# M=16时主成分回归MSE=1853635，比M=5低得多，同时也与最小二乘相近

# (f)
# 偏最小二乘回归
pls.fit = plsr(Apps~., data=College, subset=train, scale=T, validation="CV")
validationplot(pls.fit, val.type="MSEP")
# 同样，从图中发现大概在M=8时降到最低
pls.pred = predict(pls.fit, x[test,], ncomp=8)
err.pls = mean((pls.pred-y.test)^2)
err.pls
# M=8时偏最小二乘MSE=1774522，与PCR和最小二乘相近

# (g)
# 计算预测变量测试值平均值(y bar)
test.avg = mean(y.test)
# 计算各个模型的R方(1-RSS/TSS)
lm.r2 = 1 - mean((lm.pred - y.test)^2) / mean((test.avg - y.test)^2)
ridge.r2 = 1 - mean((ridge.pred - y.test)^2) / mean((test.avg - y.test)^2)
lasso.r2 = 1 - mean((lasso.pred - y.test)^2) / mean((test.avg - y.test)^2)
pcr.r2 = 1 - mean((pcr.pred - y.test)^2) / mean((test.avg - y.test)^2)
pls.r2 = 1 - mean((pls.pred - y.test)^2) / mean((test.avg - y.test)^2)
barplot(c(lm.r2, ridge.r2, lasso.r2, pcr.r2, pls.r2), xlab="模型", ylab="R方",names=c("最小二乘", "岭回归", "lasso", "主成分分析", "偏最小二乘"))
# 从柱状图能够看出所有模型的R方都在0.9附近，岭回归模型R方低一些

err.all = c(err.lm, err.ridge, err.lasso, err.pcr, err.pls)
barplot(err.all, xlab="模型", ylab="测试误差", names=c("最小二乘", "岭回归", "lasso", "主成分分析", "偏最小二乘"))
# 发现岭回归模型的误差明显别的更大，其他四个模型MSE几乎相同

