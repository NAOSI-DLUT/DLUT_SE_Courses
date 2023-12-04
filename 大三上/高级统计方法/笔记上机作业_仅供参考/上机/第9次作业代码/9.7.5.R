# 9.7.5
rm(list=ls())
library(ISLR)
library(caTools)
library("e1071")
# (a)
set.seed(123)
x1 = runif(500)-0.5
x2 = runif(500)-0.5
y = 1*(x1^2-x2^2 > 0)
df=data.frame(x1=x1, x2=x2, y=as.factor(y))

# (b)
plot(x1,x2,col = (2 - y))

# (c)
glm.fit = glm(y~x1+x2, data=df, family = 'binomial')

# (d)
# 预测
glm.probs = predict(glm.fit, newdata=df, type = 'response')
glm.preds = rep(0,500)
glm.preds[glm.probs>0.50] = 1
table(preds=glm.preds, truth=df$y)
# 画图
plot(x1,x2,col=2-glm.preds)

# (e)
glm.fit = glm(y~I(x1^2)+I(x2^2), data = df, family = 'binomial')

# (f)
glm.probs = predict(glm.fit, newdata = df, type = 'response')
glm.preds = rep(0,500)
glm.preds[glm.probs>0.5] = 1
table(preds=glm.preds, truth=df$y)
plot(x1,x2,col=2-glm.preds)

# X1和X2的二次变换非常完美的分离了，结果是所有观察都分类正确
# 即分类错误率为0

# (g)
# 最佳模型
tune.out=tune(svm,y~.,data = df,kernel='linear',
              ranges=list(cost=c(0.001,0.01,0.1,1,5,10,100)))
bestmod=tune.out$best.model

# 进行预测
ypred=predict(bestmod, newdata=df, type='response')
table(predict=ypred, truth=df$y)
plot(x1,x2,col=ypred)

# (h)
# 拟合径向内核函数的svm
tune.out=tune(svm, y~., data=df, kernel='radial',
              ranges=list(cost=c(0.1,1,10,100,1000),gamma=c(0.5,1,2,3,4)))
bestmod=tune.out$best.model

# 进行预测
ypred=predict(bestmod, newdata=df, type='response')
table(predict=ypred, truth=df$y)
plot(x1,x2,col=ypred)

# (i)
# 使用线性项和非线性项的逻辑回归模型分别与线性和径向内核完美拟合
# 即结果为具有非线性项的逻辑回归和具有径向内核的SVM优于使用线性项的模型
# 并且结果显示这些模型在预测方面准确性非常高，证实逻辑斯蒂回归和SVM是相似的方法