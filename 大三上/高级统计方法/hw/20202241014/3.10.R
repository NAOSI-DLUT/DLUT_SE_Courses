
#e.
lm.fit2 = lm(Sales ~ Price + US)
summary(lm.fit2)

#f.
# 基于线性回归的 RSE 和 R^2，它们都类似地拟合数据，
# 来自 (e) 的线性回归对数据的拟合略好。

#g.
confint(lm.fit2)

#h.
par(mfrow=c(2,2))
plot(lm.fit2)
