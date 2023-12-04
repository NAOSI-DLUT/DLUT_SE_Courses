# 3.7.11
set.seed(1)
x=rnorm(100)
y=2*x+rnorm(100)

# (a)
lm.fit = lm(y~x+0)
summary(lm.fit)
# x的估计系数为1.9939,标准差为0.1065,t统计量为18.73
# p值远小于0.05,表示有显著性

# (b)
lm.fit2 = lm(x~y+0)
summary(lm.fit2)
# y的估计系数为0.3911,标准差为0.0209,t统计量为18.73
# p值远小于0.05,表示有显著性

# (c)
# 发现两者t统计量是相同的
# 实际上两者是对同一条直线的拟合，互为反函数

# (d)
t = (sqrt(length(x)-1) * sum(x*y)) / (sqrt(sum(x*x) * sum(y*y) - (sum(x*y))^2))

# (e)
# 从(d)中计算得出t=18.7259,而从x对y与y对x的回归中都能够得出t统计量为18.73

# (f)
lm.fit3 = lm(y~x)
summary(lm.fit3)

lm.fit4 = lm(x~y)
summary(lm.fit4)
# t统计量都是18.56