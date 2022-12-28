# 3.8.
library(ISLR)
Auto = na.omit(Auto)
summary(Auto)

# (a)
attach(Auto)
lm.fit = lm(mpg ~ horsepower)
summary(lm.fit)

# i.
# 通过测试所有回归系数为零的零假设来确定马力和 mpg 之间的关系。 
# 由于 F 统计量远大于 1 并且 F 统计量的 p 值接近于零，
# 我们可以拒绝原假设并声明马力和 mpg 之间存在统计上显着的关系。

# ii.
# 为了计算相对于响应的残差，我们使用响应的平均值和 RSE。 
# mpg 的平均值为 23.4459。 lm.fit 的 RSE 为 4.906，表示误差百分比为 20.9248%。 
# lm.fit 的 R2 约为 0.6059，这意味着 mpg 中 60.5948% 的差异可以用马力来解释。

# iii.
# mpg和马力之间的关系是负的。 汽车的马力越大，
# 线性回归表明汽车的 mpg 燃油效率就越低。

# iv.
predict(lm.fit, data.frame(horsepower=c(98)), interval="confidence")
predict(lm.fit, data.frame(horsepower=c(98)), interval="prediction")

# (b)
plot(horsepower, mpg)
abline(lm.fit)

# (c)
par(mfrow=c(2,2))
plot(lm.fit)
# 根据残差图，有一些非线性的证据。
