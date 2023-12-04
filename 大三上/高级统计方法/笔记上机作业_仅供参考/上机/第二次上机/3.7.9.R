library(ISLR)
# 发现数据中有缺值的数据单元(表示为？)，先替换？为NA，再使用na.omit进行处理
Auto$horsepower[which(Auto$horsepower=="?")]=NA
Auto$mpg[which(Auto$mpg=="?")]=NA
Auto = na.omit(Auto)
# 发现数据都为字符型，直接操作是无法计算的，遂改为数字型
Auto = as.data.frame(lapply(Auto, as.numeric))
attach(Auto)

# (a)
pairs(Auto)

# (b)
# 使用subset取子集，使用select参数加负号去除name
cor(subset(Auto, select=-name))

# (c)
lm.fit = lm(mpg~.-name, data=Auto)
summary(lm.fit)

# i
# 有关系，基于零假设：预测变量和响应变量之间所有回归系数均为0
# 而其F统计量为252.4，远大于1，p值远小于0.05

# ii
# displacement,weight,year,origin存在显著关系
# cylinders,horsepower,acceleration不存在显著关系

# iii
# year的系数约为0.758，代表year每增长一年，mpg增长大约0.758个单位
# 即汽车每年的燃油效率提高约0.758mpg/年

# (d)
par(mfrow=c(2,2))
plot(lm.fit)
# 分析残差图，发现有比较明显的曲线（先下降后上升）
# 存在较大的离群点、高杠杆点14（约0.2处，而大部分点不超过0.05）
plot(predict(lm.fit), rstudent(lm.fit))
# 画出学生化残差图，发现其中有大于3的点(高杠杆点)，可能存在异常

# (e)
lm.fit1 = lm(mpg~cylinders*displacement+displacement*weight)
summary(lm.fit1)
# 存在统计显著的交互作用
# 观察发现cylinders:displacement交互项的p值为0.384>0.05，不够显著
# 而displacement:weight的p值远小于0.05，足够显著

# (f)
lm.fit2 = lm(mpg~log(weight)+log(horsepower)+log(acceleration))
summary(lm.fit2)
lm.fit2 = lm(mpg~sqrt(weight)+sqrt(horsepower)+sqrt(acceleration))
summary(lm.fit2)
lm.fit2 = lm(mpg~I(weight^2)+I(horsepower^2)+I(acceleration^2))
summary(lm.fit2)

# 通过尝试发现如下变量显著性水准比较高
lm.fit3 = lm(mpg~log(horsepower)+sqrt(horsepower)+log(weight)+I(acceleration^2))
summary(lm.fit3)

# 画图进行分析
par(mfrow=c(2,2)) 
plot(lm.fit3)
# 残差图曲线趋势不明显，拟合效果比较好
# 存在离群点
plot(predict(lm.fit3), rstudent(lm.fit3))
# 画出学生化残差图，发现其中有大于3的点，可能存在异常