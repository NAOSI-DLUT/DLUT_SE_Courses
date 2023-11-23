# 9.7.4
rm(list=ls())
library(ISLR)
library(caTools)
library("e1071")
# (a)
set.seed(123)
# 构造数据
x=matrix(rnorm(100*2), ncol=2)
y=c(rep(-1,70), rep(1,30))
x[1:30,]=x[1:30,]+3.3
x[31:70,]=x[31:70,]-3
dat=data.frame(x=x, y=as.factor(y))
# 训练集和测试集
sample.data = sample.split(dat$x.1, SplitRatio = 0.7)
train.set = subset(dat, sample.data==T)
test.set = subset(dat, sample.data==F)

plot(x,col=(2-y), xlab='X1', ylab='X2', main='Dataset with non-linear separation')

# 寻找最好的模型
set.seed(123)
tune.out=tune(svm,y~.,data = train.set,kernel='linear',
              ranges=list(cost=c(0.001,0.01,0.1,1,5,10,100)))
bestmod=tune.out$best.model
plot(bestmod, dat)

# 训练集上的预测
ypred=predict(bestmod, train.set)
table(predict=ypred, truth=train.set$y)
# 测试集上的预测
ypred=predict(bestmod, test.set)
table(predict=ypred, truth=test.set$y)

# 在一组cost值和gamma值上使用交叉验证的最佳模型。
set.seed(123)
tune.out=tune(svm, y~., data=train.set, kernel='radial',
              ranges=list(cost=c(0.1,1,10,100,1000),gamma=c(0.5,1,2,3,4)))
bestmod = tune.out$best.model
plot(bestmod, train.set)
# 训练集上进行预测
ypred=predict(bestmod, train.set)
table(predict=ypred, truth=train.set$y)
# 测试集上进行预测
ypred=predict(bestmod, test.set)
table(predict=ypred, truth=test.set$y)

# 具有线性核的 svm 错误地分类了 19/70 的训练观察和 11/30 的测试观察
# 具有径向内核的 svm 正确分类所有训练观察和仅错误分类了1/30的测试观察