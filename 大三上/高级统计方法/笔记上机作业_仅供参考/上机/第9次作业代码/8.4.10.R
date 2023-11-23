# 8.4.10
library(magrittr)
library(tidyr)
library(glmnet)
# (a)
# 批量使用drop_na函数处理数据集
Hitters = Hitters %>% drop_na(Salary)
# 对数变换
Hitters$Salary = log(Hitters$Salary)

# (b)
set.seed(123)
# 划分训练集(200)和测试集(63)
sample.data = sample.split(Hitters$Salary, SplitRatio = 200/263) 
train.set = subset(Hitters, sample.data==T)
test.set = subset(Hitters, sample.data==F)

# (c)
# 使用提升法迭代1000次，产生1000棵树
# λ序列
lambdas = seq(0.0001,0.5,0.01)
train.mse = rep(NA,length(lambdas))
test.mse = rep(NA,length(lambdas))
set.seed(4)
for (i in lambdas){
  boost.Hitters = gbm(Salary~., data=train.set,distribution = "gaussian", n.trees = 1000, 
                      interaction.depth = 4, shrinkage = i)
  yhat.train = predict(boost.Hitters,newdata = train.set, n.trees = 1000)
  train.mse[which(i==lambdas)] = mean((yhat.train-train.set$Salary)^2)
  
  yhat.test = predict(boost.Hitters,newdata = test.set, n.trees = 1000)
  test.mse[which(i==lambdas)] = mean((yhat.test-test.set$Salary)^2)
}

# (d)
par(mfrow=c(1,2))
plot(lambdas,train.mse,type="b",xlab="λ值", ylab="训练均方误差")
plot(lambdas,test.mse,type="b",xlab="λ值", ylab="测试均方误差")

# (e)
# mse最小时的λ值
lambdas[which.min(test.mse)];min(test.mse)
lambdas[which.min(train.mse)];min(train.mse)

# 第三章中的线性回归模型
lm.fit = lm(Salary~., data=train.set)
lm.preds = predict(lm.fit, newdata = test.set)
lm.mse = mean((test.set$Salary-lm.preds)^2)
lm.mse

# 第六章中的Lasso回归模型
train = model.matrix(Salary~.,train.set)
test = model.matrix(Salary~.,test.set)
y.train = train.set$Salary
lasso.mod = glmnet(train, y.train, alpha = 1)

# 为Lasso回归模型选择最合适的λ
set.seed(123)
cv.out=cv.glmnet(train, y.train, alpha=1)
bestlam=cv.out$lambda.min
lasso.pred=predict(lasso.mod, s=bestlam, newx = test)
mean((test.set$Salary-lasso.pred)^2)

# (f)
# 使用gbm函数进行提升法
boost.best = gbm(Salary~., data=train.set, distribution = "gaussian", n.trees = 1000, 
                 interaction.depth = 4, shrinkage = 0.01)
summary(boost.best)

# 从图中以及可以看出CAtBat、CRuns以及CWalks是最重要的三个变量

# (g)
bag.Hitters = randomForest(Salary~.,train.set,mtry=19,importance=T)
bag.pred = predict(bag.Hitters,newdata = test.set)
mean((test.set$Salary-bag.pred)^2)

# 装袋法测试均方误差为0.3284043