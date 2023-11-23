# 2.4.9
library(ISLR)
# (a)
# name和origin是定性的，其他是定量的（查看数据集每一列的实际意义）
sapply(Auto, is.factor)
# 发现数据中有缺值的数据单元(表示为？)，先替换？为NA，再使用na.omit进行处理
Auto$horsepower[which(Auto$horsepower=="?")]=NA
Auto$mpg[which(Auto$mpg=="?")]=NA
Auto = na.omit(Auto)
# 发现数据都为字符型，直接操作是无法计算的，遂改为数字型
Auto = as.data.frame(lapply(Auto, as.numeric))

# (b)
# 使用 sapply 批处理函数对矩阵的所有单元使用 range 函数处理
sapply(Auto[,1:7], range)

# (c)
# 同上使用 sapply -> mean, sd
sapply(Auto[,1:7], mean)
sapply(Auto[,1:7], var)

# (d)
# 剔除数据使用负号索引
Auto2 = Auto[-10,]
Auto2 = Auto2[-85,]

sapply(Auto2[,1:7], range)
sapply(Auto2[,1:7], mean)
sapply(Auto2[,1:7], sd)

# (e)
pairs(Auto[,1:7])
# 其中mpg和displacement、horsepower、weight，两两之间互有关系
Auto3 = Auto[,1:5]
Auto3 = Auto3[,-2]
pairs(Auto3)

# (f)
# 从(e)问中能够得到结论：displacement、horsepower、weight都可以预测mpg
# 再从相关性的角度来说明
cor(Auto)
# 发现weight和mpg的相关系数为-0.8322，显然有明显的负相关，可以用来预测mpg
plot(Auto$mpg, Auto$weight)
# 散点图大概能够看出是非线性的负相关关系
