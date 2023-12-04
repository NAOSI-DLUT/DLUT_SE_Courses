# 4.7.10
library(ISLR)
attach(Weekly)
# 发现数据都为字符型，直接操作是无法计算的，遂改为数字型


# (a)
# 查看具体数据
fix(Weekly)
# 查看数据整体总结
summary(Weekly)
# 查看各变量之间的相关性
cor(as.data.frame(lapply(Weekly, as.numeric)))
# 不同变量两两画散点图
pairs(Weekly)

# 相关性矩阵中发现Year和Volume的相关系数达到0.8419，说明有关系（其他都是0.0几）
# 通过pairs画的Year-Volume散点图也能看出具有一定的趋势，更加证明有关系

# (b)
glm.fit=glm(Direction~Lag1+Lag2+Lag3+Lag4+Lag5+Volume,data=Weekly,family=binomial)
summary(glm.fit)
# Lag2的p值为0.0296，比较有显著性

# (c)
glm.probs=predict(glm.fit,type="response")
# 根据预测结果生成响应变量的预测值
glm.pred=rep("Down",length(glm.probs))
glm.pred[glm.probs>0.5]="Up"
# 查看混淆矩阵
table(glm.pred,Direction)
# 整体预测准确率为(54 + 557) / 1089 = 0.5610652
# 假阳性率 = 430 / (54 + 430) = 0.8884298
# 假阴性率 = 48 / (48 + 557) = 0.07933884

# (d)
# 划分训练集
train=(Year<2009)
# 划分测试集
test=Weekly[!train,]
# 拟合只有Lag2作为预测变量的逻辑斯蒂回归模型，并使用训练集作为数据集
glm.fit=glm(Direction~Lag2,data=Weekly,family=binomial,subset=train)
# 在测试集上进行预测
glm.probs=predict(glm.fit,test,type="response")
# 根据预测结果生成响应变量的预测值
glm.pred=rep("Down",length(glm.probs))
glm.pred[glm.probs>0.5]="Up"
# 取出标签
label=Direction[!train]
# 查看混淆矩阵
table(glm.pred,label)
# 查看总体预测准确率
mean(glm.pred==label)
# 结果为0.625

# (e)
# lda, qda函数在MASS库中
library(MASS)
lda.fit=lda(Direction~Lag2,data=Weekly,subset=train)
lda.pred=predict(lda.fit,test)
table(lda.pred$class,label)
mean(lda.pred$class == label)
# 结果为0.625

# (f)
qda.fit=qda(Direction~Lag2,data=Weekly,subset=train)
qda.pred=predict(qda.fit,test)
table(qda.pred$class,label)
mean(qda.pred$class == label)
# 结果为0.5865385

# (g)
library(class)
# 划分训练集
train.X=as.matrix(Lag2[train])
# 划分测试集
test.X=as.matrix(Lag2[!train])
# 取出标签
train.Y=Direction[train]
# 进行预测
knn.pred=knn(train.X, test.X, train.Y, k=1)
table(knn.pred, label)
mean(knn.pred == label)
# 结果大约为0.5

# (h)
# glm（逻辑斯蒂回归）和lda（线性判别分析）效果最好，总体预测准确率都为0.625

# (i)
glm.fit=glm(Direction~Lag1+Lag2+Lag1:Lag2,data=Weekly,family=binomial,subset=train)
glm.probs=predict(glm.fit,test,type="response")
glm.pred=rep("Down",length(glm.probs))
glm.pred[glm.probs>0.5]="Up"
label=Direction[!train]
table(glm.pred,label)
mean(glm.pred==label)
# lgm下Lag1+Lag2+Lag1:Lag2
# 结果准确率为0.5769231

lda.fit=lda(Direction~Lag2+log(abs(Lag2))+sqrt(abs(Lag2)),data=Weekly,subset=train)
lda.pred=predict(lda.fit,test)
table(lda.pred$class,label)
mean(lda.pred$class == label)
# lda下Lag1+Lag2+Lag1:Lag2
# 结果准确率为0.5769231
# lda下Lag2+log(abs(Lag2))+sqrt(abs(Lag2)
# 结果准确率为0.5769231

qda.fit=qda(Direction~Lag2+log(abs(Lag2))+sqrt(abs(Lag2)),data=Weekly,subset=train)
qda.pred=predict(qda.fit,test)
table(qda.pred$class,label)
mean(qda.pred$class == label)
# qda下Lag1+Lag2+Lag1:Lag2
# 结果准确率为0.4615385
# qda下Lag2+log(abs(Lag2))+sqrt(abs(Lag2)
# 结果准确率为0.5480769

set.seed(123)
knn.pred=knn(train.X, test.X, train.Y, k=100)
table(knn.pred, label)
mean(knn.pred == label)
# knn下k=10
# 结果准确率为0.5673077
# knn下k=50
# 结果准确率为0.5769231
# knn下k=100
# 结果准确率为0.5576923