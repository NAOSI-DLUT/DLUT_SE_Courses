# 2.4.10
# (a)
library(MASS)
print(Boston)
Boston
# 数据说明信息
print(?Boston)
# 506行，14列
dim(Boston)

# (b)
# 低地位人口的占比与自住房价值的中值之间的关系
# 随着低地位人口占比增加，自住房价值中值呈下降趋势
plot(Boston$lstat, Boston$medv)

# (c)
# 住宅越老，犯罪率越高
plot(Boston$age, Boston$crim)
# 税率越高，犯罪率越高
plot(Boston$tax, Boston$crim)
# 距离就业中心越近，犯罪率越高
plot(Boston$dis, Boston$crim)

# (d)
par(mfrow=c(3,3))
# 大部分城市犯罪率较低（小于20占大多数）
hist(Boston$crim[Boston$crim>1], breaks=30)
hist(Boston$crim[Boston$crim>2], breaks=30)
hist(Boston$crim[Boston$crim>5], breaks=30)
# 大部分城市税率在250-400之间，还有很多一部分城市的税率在660附近(666)
hist(Boston$tax, breaks=30)
hist(Boston$tax[Boston$tax>400], breaks=30)
hist(Boston$tax[Boston$tax>600], breaks=30)
# 除了在20左右分布大量数据外，其他师生比率下分布比较均匀
hist(Boston$ptratio, breaks=30)
hist(Boston$ptratio[Boston$ptratio>16], breaks=30)
hist(Boston$ptratio[Boston$ptratio>18], breaks=30)

# (e)
# 可以使用plyr包的count函数直接计数
library(plyr)
count(Boston$chas)
# 也可以使用子集函数选出与chas河临界的数据，再查看维度信息
dim(subset(Boston, chas == 1))
# 这个是使用nrow直接获得子集行数
nrow(subset(Boston, chas == 1))

# (f)
median(Boston$ptratio)

# (g)
# 通过使用子集函数选出中值最小的那一条/几条数据
t(subset(Boston, medv == min(Boston$medv)))
# 最小的两条数据是399河406
summary(Boston)
# 对比其他的总体数据的分布来说，399的黑人比例是全局最高
# 而其他的数据对比来说不是最好也不是最差

# (h)
# 平均居住房间数超过7个
dim(subset(Boston, rm > 7))
# 平均居住房间数超过8个
dim(subset(Boston, rm > 8))

summary(Boston)
summary(subset(Boston, rm > 8))
# 比较发现犯罪率和低地位人口占比都比较低
# 某种程度上说明住宅房间数越多，地区居民越富足优渥
