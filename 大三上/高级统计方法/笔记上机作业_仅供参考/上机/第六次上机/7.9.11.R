# 7.9.11
rm(list=ls())
# (a)
set.seed(123)
# 随机生成数据
X1 = rnorm(100, sd=3)
X2 = rnorm(100, sd=1)
e = rnorm(100, sd=1)
b0 =10; b1=3 ; b2=5
Y = b0 +b1*X1 + b2*X2 + e

# (b)
# 随机指定β1
beta1 = 0.5

# (c)
a=Y-beta1*X1
beta2=lm(a~X2)$coef[2]
beta2
# β2=4.679358

# (d)
a=Y-beta2*X2
beta1 = lm(a~X1)$coef[2]
beta1
# β1=2.949585

# (e)
beta.df = data.frame("beta0"=rep(0,1000),"beta1"=rep(0,1000),"beta2"=rep(0,1000))
beta1=0.5
# 迭代1000次
for (i in 1:1000){
  # β1 => β2
  a=Y-beta1*X1
  model = lm(a~X2)
  beta2 = model$coef[2]
  # 记录系数值
  beta.df$beta2[i]= beta2
  # β2 => β1
  a=Y-beta2*X2
  model = lm(a~X1)
  beta1 = model$coef[2]
  # 记录系数值
  beta.df$beta1[i]=beta1
  
  # 记录系数值
  beta.df$beta0[i]=model$coef[1]
}
# 画曲线图
plot(1:1000,beta.df$beta2,ylim=range(0:15),type='l', lwd="3", col="blue",xlab="迭代次数",ylab="系数值")
lines(1:1000,beta.df$beta1, col="red", lwd=3)
lines(1:1000,beta.df$beta0, col="green",lwd=3)

# (f)
# 获取迭代结果
print(beta.df$beta0[1000])
print(beta.df$beta1[1000])
print(beta.df$beta2[1000])
# abline画线
abline(h=10.13507, lty=2, lwd=2, col=1)
abline(h=2.955609, lty=2, lwd=2, col=1)
abline(h=5.023811, lty=2, lwd=2, col=1)
legend(800,12, legend=c("迭代beta0", "迭代beta1", "迭代beta2", "回归beta0", "回归beta1", "回归beta2"),col=c("green","red","blue", 1, 1, 1), lty = c(1,1,1,2,2,2))

# (g)
# 抽取前10次的结果来观察
plot(1:10,beta.df$beta2[1:10],ylim=range(0:15),type='l', lwd="3", col="blue",xlab="迭代次数",ylab="系数值")
lines(1:10,beta.df$beta1[1:10], col="red", lwd=3)
lines(1:10,beta.df$beta0[1:10], col="green",lwd=3)

# 发现当迭代到第2~3次时，就已经基本迭代完成

# 再将迭代到第2~3次的系数值与多元线性回归的拟合系数值对比
print(beta.df$beta0[3])
print(beta.df$beta1[3])
print(beta.df$beta2[3])
lm.fit = lm(Y~X1+X2)
coef(lm.fit)

# 系数的差距非常小，即逼近效果很好
# 故需要三次迭代就能很好地逼近多元线性回归的结果