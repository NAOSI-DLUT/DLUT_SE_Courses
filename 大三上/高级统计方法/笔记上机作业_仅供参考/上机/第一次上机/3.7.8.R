# 3.7.8
# (a)
auto = read.csv("data/Auto.csv")
fix(auto)
# 发现数据中有缺值的数据单元(表示为？)，先替换？为NA，再使用na.omit进行处理
auto$horsepower[which(auto$horsepower=="?")]=NA
auto$mpg[which(auto$mpg=="?")]=NA
auto = na.omit(auto)
# 发现数据都为字符型，直接操作是无法计算的，遂改为数字型
auto = as.data.frame(lapply(auto, as.numeric))
summary(auto)
attach(auto)

lm.fit = lm(mpg~horsepower, data=auto)
summary(lm.fit)

# i
# ii
# iii
cov(auto)
cor(auto)
# horsepower和mpg有关系，协方差为-233.8580，相关性为-0.7784，是负相关

# iv
# 由于值为字符型，需要转型为数字
predict(lm.fit, data.frame(horsepower = 98))
# 是24.46708

# (b)
plot(horsepower, mpg)
abline(lm.fit, col="red")

# (c)
par(mfrow=c(2,2))
plot(lm.fit)
# 通过b中的散点图能够发现，红色拟合直线与散点图并不紧密贴合
# 通过c中左上角残差图与拟合图，发现残差值与拟合图存在曲线贴合关系
# 如果线性相关则残差值应该和拟合没有任何系统关联，故线性模型不能很好拟合
# QQ图是判断正态分布的，数据基本吻合正态分布
# 左下角是方差分布，先下降后上升，基本符合
# 右下角是极端点分布，发现没有特别极端的点（都在零点几）