# 2.4.8
# (a)
college = read.csv("data/College.csv")

# (b)
rownames(college) = college[,1]
fix(college)

college = college[,-1]
fix(college)

# (c)
# i
summary(college)

# ii
# 由于前两列不是数值参数，无法进行paris操作
# 故paris从第三列开始
pairs(college[,3:10])

# iii
# 画箱线图需要使用到ggplot2库，首先需要下载ggplot2库
# install.packages("ggplot2")
# 下载完成后使用library(ggplot2)加载ggplot2库
library(ggplot2)

ggplot(college, aes(x=Private, y=Outstate)) + geom_boxplot()

# iv
Elite = rep("No", nrow(college))
Elite[college$Top10perc>50] = "Yes"
Elite = as.factor(Elite)
college = data.frame(college, Elite)
summary(college$Elite)
plot(college$Elite, college$Outstate)

# v
par(mfrow=c(2,2))
hist(college$Accept,col=2)
hist(college$Enroll,col=3)
hist(college$Top10perc,col=4)
hist(college$Top25perc,col=5)

# vi
# 下面对大学的接受率与注册率，以及前25%和前10%的新生之间的关系画散点图进行研究
# 从图中能够看到随着大学的接收率增长，大学的注册率基本上单调增加
# 同时大学中随着是高中班前25%的新生的增长
# 其是高中班前10%的新生的概率也是单调增加
# 并且增加的幅度越来越大。
fix(college)
par(mfrow=c(1,2))
plot(college$Accept, college$Enroll)
plot(college$Top25perc, college$Top10perc)