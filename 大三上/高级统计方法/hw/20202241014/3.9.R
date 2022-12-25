library(ISLR)
#1. 
pairs(Auto)
attach(Auto)
#2. 
cor(subset(Auto, select=-name))

#3. 
lm.fit1 = lm(mpg~.-name, data = Auto)
summary(lm.fit1)

#4.
par(mfrow=c(2,2))
plot(lm.fit1)
# 似乎不准确，因为残差图有可辨别的曲线模式。 
# 从杠杆图中，第 14 点似乎具有高杠杆，尽管残差并不高。


lm.fit2 = lm(mpg~log(weight)+I(horsepower^(1/2))+acceleration+I(acceleration^2), data = Auto)
summary(lm.fit2)
