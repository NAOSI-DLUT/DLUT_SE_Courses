# 3.7.14
# (a)
set.seed(1)
x1 = runif(100)
x2 = 0.5 * x1 + rnorm(100)/10
y = 2 + 2*x1 + 0.3*x2 + rnorm(100)
# 系数：β0=2,β1=2,β2=0.3

# (b)
cor(x1, x2)
# 0.8351
plot(x1, x2)

# (c)
lm.fit = lm(y~x1+x2)
summary(lm.fit)
# β0=2.1305,β1=1.4396,β2=1.0097
# 可以拒绝β1的原假设，其p值小于0.05，具有显著性
# 不能拒绝β2的原假设，其p值大于0.05，不具有显著性

# (d)
lm.fit1 = lm(y~x1)
summary(lm.fit1)
# 可以拒绝β1的原假设，其p值小于0.05，具有显著性

# (e)
lm.fit2 = lm(y~x2)
summary(lm.fit2)
# 可以拒绝β2的原假设，其p值小于0.05，具有显著性

# (f)
# 不矛盾，因为x2由x1线性生成，故x1与x2具有共线性
# 当单独分别和y进行回归拟合时，显著性强；当同时拟合时，很难区分他们的影响

# (g)
x1 = c(x1, 0.1)
x2 = c(x2, 0.8)
y = c(y, 6)
lm.fit3 = lm(y~x1+x2)
summary(lm.fit3)
# x1的t统计量的p值大于0.05，没有统计显著性
# x2的t统计量的p值远小于0.05，统计显著
lm.fit4 = lm(y~x1)
summary(lm.fit4)
# x1的t统计量的p值远小于0.05，统计显著
lm.fit5 = lm(y~x2)
summary(lm.fit5)
# x2的t统计量的p值远小于0.05，统计显著

par(mfrow=c(2,2))
plot(lm.fit3)
# 存在明显的离群点（101）
plot(predict(lm.fit3), rstudent(lm.fit3))

par(mfrow=c(2,2))
plot(lm.fit4)
plot(predict(lm.fit4), rstudent(lm.fit4))
# 存在一个高杠杆点（大于3）

par(mfrow=c(2,2))
plot(lm.fit5)
# 存在明显的离群点（101）
plot(predict(lm.fit5), rstudent(lm.fit5))


