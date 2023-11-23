# 3.7.13
# (a)
rm(list = ls())
set.seed(1)
x=rnorm(100)

# (b)
# rnorm函数，参数分别为向量长度、均值、标准差
eps = rnorm(100, 0, sqrt(0.25))

# (c)
y = -1 + 0.5*x + eps
# y的长度为100,β0=-1,β1=0.5

# (d)
plot(x, y)
# 散点图总体呈上升趋势
# 即x和y大致上是正相关的

# (e)
lm.fit=lm(y~x)
summary(lm.fit)
# 拟合的结果：截距为-1.0189，x的系数为0.4995，和β0、β1很相近
# F统计量为85.99，比较大
# 同时p值远小于0.05，具有显著性，结果显示拟合的效果较好

# (f)
plot(x, y)
abline(lm.fit, lwd=3, col=2)
abline(-1, 0.5, lwd=3, col=3)
legend(-1, legend = c("模型拟合结果", "总体回归线"), col=2:3, lwd=3)

# (g)
lm.fit0 = lm(y~x+I(x^2))
summary(lm.fit0)
# 模型的RSE减少了，且R-squared增加了，表明模型拟合效果略微变好了
# 虽然二次项的t统计量的p值显示，其并没有显著性

# (h)
set.seed(1)
# 减小数据噪声，将其方差设为0.1
eps1 = rnorm(100, 0, sqrt(0.1))
x1 = rnorm(100)
y1 = -1 + 0.5*x1 + eps1
plot(x1, y1)
lm.fit1 = lm(y1~x1)
summary(lm.fit1)

abline(lm.fit1, lwd=3, col=2)
abline(-1, 0.5, lwd=3, col=3)
legend(-1, legend = c("model fit", "pop. regression"), col=2:3, lwd=3)
# 结果是显然模型的RSE减少了，且R-squared增加了
# 说明模型的拟合效果随着噪声减小而变好了

# (i)
# 增加数据的噪声，将方差设为0.5
eps2 = rnorm(100, 0, sqrt(0.5))
x2 = rnorm(100)
y2 = -1 + 0.5*x2 + eps2
plot(x2, y2)
lm.fit2 = lm(y2~x2)
summary(lm.fit2)

abline(lm.fit2, lwd=3, col=2)
abline(-1, 0.5, lwd=3, col=3)
legend(-1, legend = c("model fit", "pop. regression"), col=2:3, lwd=3)
# 结果是显然模型的RSE增加了，且R-squared降低了
# 说明模型的拟合效果随着噪声增加而变差了

# (j)
confint(lm.fit)
confint(lm.fit1)
confint(lm.fit2)
# 三个区间都以0.5为中心，宽度不同
# 其中噪声越小，范围越窄；噪声越大，范围越宽