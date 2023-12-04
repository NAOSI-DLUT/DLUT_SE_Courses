# 5.4.8
# (a)
set.seed(123)
y=rnorm(100)
x=rnorm(100)
y=x-2*x^2+rnorm(100)
# n=100, p=2
# y=x-2*x^2+ε

# (b)
plot(x, y)
# 可以看出散点图为下凹曲线，x与y是二次型关系

# (c)
library(boot)
# 创建同时包含x和y的数据集
Data = data.frame(x, y)
set.seed(123)
# 线性 10.06509 10.05872
glm.fit = glm(y ~ x)
cv.glm(Data, glm.fit)$delta
# 二次型 0.9857113 0.9851502
glm.fit = glm(y ~ poly(x, 2))
cv.glm(Data, glm.fit)$delta
# 三次型 1.007943 1.006951
glm.fit = glm(y ~ poly(x, 3))
cv.glm(Data, glm.fit)$delta
# 四次型 0.9970533 0.9960052
glm.fit = glm(y ~ poly(x, 4))
cv.glm(Data, glm.fit)$delta

# 结果线性的误差最大，二次型误差降低很多
# 随着次数再增加，误差不减反增

# (d)
set.seed(123456)
# 线性 10.06509 10.05872
glm.fit = glm(y ~ x)
cv.glm(Data, glm.fit)$delta
# 二次型 0.9857113 0.9851502
glm.fit = glm(y ~ poly(x, 2))
cv.glm(Data, glm.fit)$delta
# 三次型 1.007943 1.006951
glm.fit = glm(y ~ poly(x, 3))
cv.glm(Data, glm.fit)$delta
# 四次型 0.9970533 0.9960052
glm.fit = glm(y ~ poly(x, 4))
cv.glm(Data, glm.fit)$delta

# 结果一样，因为留一验证法会分割n次数据
# 每一次都将不重复的一条数据当作验证集，剩下的当作训练集
# 方法不存在随机性，改变随机数种子对留一验证不产生任何影响

# (e)
# 二次型具有最小的LOOCV误差
# 原因是最接近y与x的真实关系，拟合效果最好，所以误差最小

# (f)
summary(glm.fit)
# 发现二次项的回归系数最显著，而其他项的系数不够显著，与交叉验证的结论相符