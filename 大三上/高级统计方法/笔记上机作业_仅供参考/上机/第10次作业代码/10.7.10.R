# 10.7.10
rm(list=ls())
library(ISLR)

# (a)
set.seed(123)
# 使用不同均值来构造不同类的数据
# 60 * 50, n=60, p=50
simulated.data = matrix(c(rnorm(20 * 50, mean = -1),               
                          rnorm(20 * 50, mean = 1),
                          rnorm(20 * 50, mean = 3)), ncol = 50, byrow = TRUE)
class = unlist(lapply(1:3,function(x){rep(x,20)}))

# (b)
# 画图
pr.out2 = prcomp(simulated.data)
plot(pr.out2$x[,1:2],col=class)

# (c)
# K=3的均值聚类
kmeans.out = kmeans(simulated.data, 3, nstart = 60)
table(class, kmeans.out$cluster)

# 结果发现与真实类相比所有类(每个类20个)都完全分类正确

# (d)
# K=2的均值聚类
kmeans.out = kmeans(simulated.data, 2, nstart = 60)
table(kmeans.out$cluster)

# 结果发现确实分成了两类，第一类20个第二类40个

# (e)
kmeans.out = kmeans(simulated.data, 4, nstart = 60)
table(kmeans.out$cluster)

# 结果发现分成了四类，第一类20个，第二类12个，第三类8个，第四类20个

# (f)
kmeans.out = kmeans(pr.out2$x[,1:2], 3, nstart = 60)
table(kmeans.out$cluster)
table(class)
# 分类结果与真实相比完全正确

# (g)
set.seed(123)
# 使用scale进行标准化
kmeans.out = kmeans(scale(simulated.data), 3, nstart = 60)
table(kmeans.out$cluster)
table(class)

plot(pr.out2$x[,1:2],col=kmeans.out$cluster)

# 分类结果与真实相比仍然完全正确