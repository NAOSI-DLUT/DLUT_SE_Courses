# 4.7.11
library(ISLR)
# 发现数据中有缺值的数据单元(表示为？)，先替换？为NA，再使用na.omit进行处理
Auto$horsepower[which(Auto$horsepower=="?")]=NA
Auto$mpg[which(Auto$mpg=="?")]=NA
Auto = na.omit(Auto)
# 发现数据都为字符型，直接操作是无法计算的，遂改为数字型
Auto = as.data.frame(lapply(Auto, as.numeric))
attach(Auto)

# (a)
mpg01=rep(0,length(mpg))
# 当该行的mpg值大于中位数时，设为1
mpg01[mpg>median(mpg)]=1
# 与主数据集Auto合并
Auto=data.frame(Auto,mpg01)

# (b)
cor(Auto)
# 发现mpg01和mpg,cylinders,displacement,horsepower,weight都有比较强的相关性
pairs(Auto)
# 而从pairs散点图系上来看，mpg01和mpg,horsepower,weight有比较明显的01分布特点

# (c)
# 根据年份来划分测试集与数据集(81,82年为测试集,其余为训练集)
# 训练集的条件
train=(year<=80)
# 测试集的条件
test=(year>80)
# 训练集与测试集
Auto.train=Auto[train,]
Auto.test=Auto[test,]
# 测试集label标记
label=mpg01[test]

# (d)
library(MASS)
lda.fit=lda(mpg01~cylinders+weight+displacement+horsepower,data=Auto,subset=train)
lda.pred=predict(lda.fit,Auto.test)
mean(lda.pred$class!=label)
# 测试集上的误差为0.1206897

# (e)
qda.fit=qda(mpg01~cylinders+weight+displacement+horsepower,data=Auto,subset=train)
qda.pred=predict(qda.fit,Auto.test)
mean(qda.pred$class!=label)
# 测试集上的误差为0.137931

# (f)
glm.fit=glm(mpg01~cylinders+weight+displacement+horsepower,data=Auto,subset=train,family=binomial)
glm.probs=predict(glm.fit,Auto.test,type="response")
glm.pred=rep(0,length(glm.probs))
glm.pred[glm.probs>0.5]=1
mean(glm.pred!=label)
# 测试集上的误差为0.137931

# (g)
library(class)
# 划分训练集(cbind合并这些列)
train.X=cbind(cylinders,displacement,horsepower,weight)[train,]
# 划分测试集
test.X=cbind(cylinders,displacement,horsepower,weight)[test,]
# 取出训练集标签
train.Y=mpg01[train]
set.seed(123)
# 进行k=1预测
knn.pred=knn(train.X, test.X, train.Y, k=1)
table(knn.pred, label)
mean(knn.pred != label)
# 测试集上的误差为0.1896552

# 进行k=10预测
knn.pred=knn(train.X, test.X, train.Y, k=10)
table(knn.pred, label)
mean(knn.pred != label)
# 测试集上的误差为0.2068966

# 进行k=50预测
knn.pred=knn(train.X, test.X, train.Y, k=50)
table(knn.pred, label)
mean(knn.pred != label)
# 测试集上的误差为0.1724138

# 发现在此测试集上k=50时，其误差最低，效果最好
# 故k=50时可能最好