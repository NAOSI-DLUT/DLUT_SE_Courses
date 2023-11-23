# 9.7.7
rm(list=ls())
library(ISLR)
library(caTools)
library("e1071")

# (a)
set.seed(123)
# 创建二分变量
auto.length = length(Auto$mpg)
mpg.median = median(Auto$mpg)
mpg01 = rep(NA,auto.length) 
# 如果汽车的 mpg 高于中位数，则为1级，否则为0级
# 结果存储在 mpg01 变量中
for (i in 1:auto.length) if (Auto$mpg[i] > mpg.median) mpg01[i]=1 else mpg01[i]=0
# 数据Dataframe
auto.df = Auto
auto.df$mpg01 = as.factor(mpg01)

# (b)
# 使用线性SVM对mpg01进行预测
linear.tune=tune(svm,mpg01~.,data=auto.df,kernel='linear',
                 ranges=list(cost=c(0.001,0.01,0.1,1,5,10,100,1000)))
summary(linear.tune)

# 发现训练交叉验证误差随着cost值的增加而减少，在cost值为1时最小，此后逐渐增加增加

# (c)
set.seed(123)
# 具有各种 gamma 和成本值的径向内核。
radial.tune=tune(svm, mpg01~., data=auto.df, kernel='radial',
                 ranges=list(cost=c(0.1,1,10,100,1000),gamma=c(0.5,1,2,3,4)))
radial.tune$best.parameters
radial.tune$best.performance

# cost值为1和gamma=0.5的径向模型的训练交叉验证误差最低，但是比线性模型高约4倍

# 不同次数的多项式核函数
set.seed(123)
poly.tune = tune(svm, mpg01~., data=auto.df, kernel='polynomial',
                 ranges=list(cost=c(0.1,1,10,100,1000), degree=c(1,2,3,4,5)))
poly.tune$best.parameters
poly.tune$best.performance