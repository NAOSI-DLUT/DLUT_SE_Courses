# 6.8.10
library(leaps)
rm(list=ls())
# (a)
set.seed(123)
n = 1000
p = 20
# n*p形正态分布随机数据矩阵X
X = matrix(rnorm(n*p), n, p)
# 设定系数矩阵B(-10到10范围随机选20个)
B = sample(-10:10, 20)
# 随机让一些系数为0
B[1] = 0
B[6] = 0
B[11] = 0
B[16] = 0
e = rnorm(1000, mean=0, sd=0.1)
# %*%为矩阵乘法(X[n,p] %*% B[p,1])
Y = X%*%B + e
df = data.frame(X, Y)

# (b)
# 训练集与测试集(随机9:1)
sample = sample.split(df$Y, 0.10)
train = subset(df, sample==T)
test = subset(df, sample==F)

# (c)
# 最佳子集选择
reg.fit = regsubsets(Y~., data=train, nvmax=20)
reg.summary = summary(reg.fit)
# 不同变量个数的训练集MSE
train.MSE = (reg.summary$rss)/length(train)
plot(1:20,train.MSE,xlab = "变量个数",ylab = "训练均方误差", pch = 20, type = "b")

# 训练均方误差确实随选择的变量个数的增加而单调下降

# (d)
library(HH)
test.MSE = rep(NA,20)
# 遍历i个变量模型
for(i in 1:20){
  model=lm.regsubsets(reg.fit, i)
  model.pred = predict(model, newdata=test, type="response")
  # 计算该模型的MSE
  test.MSE[i] =  mean((test$Y-model.pred)^2)
}
# Plot
plot(1:20,test.MSE,xlab = "变量个数",ylab = "测试均方误差", pch = 20, type = "b")

# 测试均方误差也随选择的变量个数的增加而下降，但是曲线没那么平滑

# (e)
# 寻找曲线的最低点并标红
points(which.min(test.MSE), test.MSE[which.min(test.MSE)], col = "red", pch = 20)
# 发现当变量个数为16时，测试均方误差达到最小值
# 模型变量个数增加，灵活性也增加，它能够更好地拟合数据集，导致测试 MSE 迅速下降，直到达到最小值
# 然后模型灵活性的进一步增加会导致过拟合，从而导致测试 MSE 的增加

# (f)
# 测试集模型
coef(reg.fit, 20)
# 真实模型
B

# 逐个对比发现测试集模型与真实模型的系数差距很小，几乎相同

# (g)
# Original coefficient values transposed and columns renamed.
B = as.data.frame(t(B))
# 将B的结构改为与coef返回值一致(增加名字Xi),方便dataframe直接相减
names(B) = paste0('X', 1:(ncol(B)))

# 循环计算
coef.err = rep(NA,20)
for (i in 1:20){
  a = coef(reg.fit, i)
  # B[names(a)[-1]]为真实系数向量
  # a[-1]为估计系数向量，即coef(reg.fit, i)[-1]
  # [-1]即去除截距项
  coef.err[i] = sqrt(sum(((B[names(a)[-1]]-a[-1])^2)))
}
# 与(d)中test.MSE对比
par(mfrow=c(1,2))
plot(1:20,test.MSE,xlab = "变量个数",ylab = "测试均方误差", main="(d)", pch = 20, type = "b")
plot(1:20,coef.err,xlab = "变量个数",ylab = "系数误差", main="(g)", pch = 20, type = "b")
# 标记最小误差
points(which.min(coef.err), coef.err[which.min(coef.err)], col = "red", pch = 16)

# 根据对比图像，我们发现共同的地方是都在变量个数等于16处达到最小误差
# 但是变量个数比较少时，(g)中系数误差的波动比较大，并不是单调下降
# 某种程度上通过给出有较小系数误差的模型不一定能有较低的测试均方误差(比如第一个点)