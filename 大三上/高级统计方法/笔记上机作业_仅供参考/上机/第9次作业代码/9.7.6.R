# 9.7.6
rm(list=ls())
library(ISLR)
library(caTools)
library("e1071")

# (a)
set.seed(123)
x1 = runif(1000,-5,5)
x2 = runif(1000,-5,5)
x = cbind(x1,x2)

y = rep(NA,1000)
# 将abline(1.5,1)以上的点分类为 1，将abline(-1.5,1)以下的点分类为-1，其余为0
# 删除归类为0的点将创建一个更广泛的数据集
# 实际决策边界是一条y=x的线，即abline(0,1)
for (i in 1:1000) 
  if (x[i,2]-x[i,1] > 1.5) y[i]=1 else if (x[i,2]-x[i,1] < -1.5) y[i]=-1 else y[i]=0

# 结合x和y并删除所有y=0的行
x = cbind(x,y)
x = x[x[,3]!=0,]

plot(x[,1],x[,2],col=2-x[,3], xlab="X1", ylab="X2",xlim = c(-5,5), ylim = c(-5,5))
abline(0,1, col="red")
abline(1.5,1)
abline(-1.5,1)
abline(h=0,v=0)

# 沿线 y=1.5x(+-0.1) 生成要用作噪声的随机点
x.noise = matrix(NA,100,3)
x.noise[,1] = runif(100,-5,5)
# 前50个点的Y坐标值
x.noise[1:50,2] = (1.5*x.noise[1:50,1])-0.1
x.noise[51:100,2] = (1.5*x.noise[51:100,1])+0.1
# 所有噪声观测值的类值
x.noise[,3] = c(rep(-1,50), rep(1,50))

plot(x[,1],x[,2],col=2-x[,3], xlab='X1', ylab='X2',
     ylim = c(-5,5),xlim = c(-5,5), 
     main="线性可分并且已添加噪声的数据集")
par(new = TRUE)
plot(x.noise[,1],x.noise[,2],col=2-x.noise[,3], axes=F,
     xlab="", ylab="", ylim = c(-5,5), xlim = c(-5,5))
# 噪声
abline(0,1.5,col="blue")
# 实际决策边界
abline(0,1,col="red")

# (b)
x = rbind(x,x.noise)
train.dat = data.frame(x1=x[,1],x2=x[,2], y=as.factor(x[,3]))

# 具有各种成本值的线性 SVM 模型。
tune.out=tune(svm,y~.,data=train.dat,kernel='linear',
              ranges=list(cost=c(0.001,0.01,0.1,1,5,10,100,1000)))
summary(tune.out)

# 训练集错误分类数
tune.out$performances$cost
tune.out$performances$error*822

# 随着成本的增加，更少的训练观察被错误分类
# 交叉验证错误与训练集上的错误的数量直接相关
# 即较低的交叉验证错误意味着更少的训练错误

# (c)
# 生成一个新的合适的测试集
set.seed(1221)
test.x1 = runif(1000,-5,5)
test.x2 = runif(1000,-5,5)
test.y = rep(NA,1000)
# 训练集的实际决策边界是y=x
for (i in 1:1000) 
  if (test.x1[i]-test.x2[i] < 0) test.y[i]=1 else if (test.x1[i]-test.x2[i] > 0) test.y[i]=-1
# 测试dataframe构造
test.dat = data.frame(x1=test.x1,x2=test.x2,y=as.factor(test.y))

plot(test.dat$x1,test.dat$x2,col=2-test.y, xlab="X1", ylab="X2")

# 在测试集上预测，估计cost值为0.1的模型的性能。
svmfit = svm(y~., data = train.dat, kernel = 'linear', cost = 0.1)
ypred = predict(svmfit, newdata = test.dat, type = 'response')
table(predict=ypred, truth=test.dat$y)

svmfit2 = svm(y~., data = train.dat, kernel = 'linear', cost = 10)
ypred = predict(svmfit2, newdata = test.dat, type = 'response')
table(predict=ypred, truth=test.dat$y)

svmfit3 = svm(y~., data = train.dat, kernel = 'linear', cost = 100)
ypred = predict(svmfit3, newdata = test.dat, type = 'response')
table(predict=ypred, truth=test.dat$y)

# 由混淆矩阵可以看出来，cost值为0.1的模型在测试集上的表现要好于cost值更高的模型
# 在训练集上，cost值高于100的模型没有出现错误分类错误

# (d)
# cost值高的模型的间隔非常小，因此间隔里或越过决策边界的支持向量会更少
# 因此模型能正确分类大多数训练观察
# 虽然在训练集上表现非常好，但是偏差小方差大，故在测试集上表现不佳

# cost值较低的模型将有更大的间隔，因此间隔里或越过决策边界的支持向量会更多
# 这意味着模型错误地分类了更多的训练观察
# 虽然在训练集上表现不佳，但是偏差大方差小，故在测试集上表现不错

# 从这些结果中，我们可以发现cost值较高的模型过拟合了训练数据，而cost值较低的模型则相反