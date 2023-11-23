# 3.7.10
# (a)
library(ISLR)
attach(Carseats)
lm.fit=lm(Sales~Price+Urban+US)
summary(lm.fit)

# (b)
# Price：有显著性，Sales和Price呈负相关，其系数为-0.054
# UrbanYes：p值远大于0.05，没有显著性
# USYes：有显著性，Sales和是否在美国存在正相关，如果商店在美国，则销售额将增加约 1201 件

# (c)
# 将系数代入式子即可
# Sales = 13.04 + -0.05 Price + -0.02 UrbanYes + 1.20 USYes

# (d)
lm.fit2 = lm(Sales~., data=Carseats)
summary(lm.fit2)
# 可以看到ComPrice,Income,Advertising,Price,ShelveLocGood,ShelveLocMedium,Age的p值显著，可以拒绝零假设

# (e)
lm.fit3 = lm(Sales ~ Price + Income)
summary(lm.fit3)
# Sales与Price和Income的拟合

# (f)
# 观察summary函数显示的RSE与R-squared
# (a) RSE=2.472 R-squared=0.2393
# (e) RSE=2.51  R-squared=0.2141
# 拟合情况比较类似，都只能解释约20%的方差，但是a中模型R-squared大些，拟合的效果稍微更好

# (g)
confint(lm.fit3)
# Price的95%置信区间为[-0.0627, -0.0417]
# Income的95%置信区间为[0.0040, 0.0217]

# (h)
par(mfrow=c(2,2))
plot(lm.fit3)
# 显然存在离群点（0.04处）

plot(predict(lm.fit3), rstudent(lm.fit3))
# 大部分点比较集中，高杠杆点不明显