# 8.4.8
library(ISLR)
library(caTools)
library(tree)
library(randomForest)
# (a)
set.seed(123)
# 划分测试集与训练集(随机7:3)
train = sample.split(Carseats$Sales, SplitRatio = 0.7)
train.set = subset(Carseats, train==T)
test.set = subset(Carseats, train==F)

# (b)
# Carseats为响应变量的回归决策树
tree.carseats = tree(Sales~.,data=train.set)
summary(tree.carseats)
plot(tree.carseats)
text(tree.carseats,pretty=0)
# 计算测试错误率(均方误差)
tree.pred = predict(tree.carseats,test.set)
test.mse = mean((tree.pred-test.set$Sales)^2)
test.mse
# 回归决策树没有测试错误率，估计得到的均方误差为4.84

# (c)
set.seed(1)
cv.carseats = cv.tree(tree.carseats)
plot(cv.carseats$size,cv.carseats$dev,xlab="终端结点个数",ylab="交叉验证误差",type="b")
# 从图中可以看到剪枝能够减小测试错误率，因为交叉验证误差并不是单调递减的
prune.carseats = prune.tree(tree.carseats,best=11)
tree.pred = predict(prune.carseats,test.set)
test.mse = mean((tree.pred-test.set$Sales)^2)
test.mse
# 最优树在结点数为11处，其测试误差为4.6139，比未剪枝略微更小

# (d)
set.seed(123)
# 装袋法
bag.carseats = randomForest(Sales~.,data=train.set,mtry=10,importance=T)
bag.yhat = predict(bag.carseats,newdata = test.set)
bag.mse=mean((bag.yhat-test.set$Sales)^2)
bag.mse
importance(bag.carseats)

# 使用装袋法得到的测试均方误差为2.489959
# 从结果能够看出Price和ShelveLoc是最重要的变量

# (e)
set.seed(123)
# 随机森林
# p=m/2
rf1.carseats = randomForest(Sales~.,data=train.set,mtry=10/2,importance=T)
# 计算mse
rf1.yhat = predict(rf1.carseats,newdata = test.set)
rf1.mse=mean((bag.yhat-test.set$Sales)^2)
rf1.mse
# 重要性计算和画图
importance(rf1.carseats)
varImpPlot(rf1.carseats)

# p=根号下m
rf2.carseats = randomForest(Sales~.,data=train.set,mtry=sqrt(10),importance=T)
# 计算mse
rf2.yhat = predict(rf1.carseats,newdata = test.set)
rf2.mse=mean((bag.yhat-test.set$Sales)^2)
rf2.mse
# 重要性计算和画图
importance(rf2.carseats)
varImpPlot(rf2.carseats)

# p=m/2时，均方误差估计为2.649312
# p=根号下m时，均方误差估计为2.46048
# 两种情况下Price和ShelveLoc都是最重要的变量