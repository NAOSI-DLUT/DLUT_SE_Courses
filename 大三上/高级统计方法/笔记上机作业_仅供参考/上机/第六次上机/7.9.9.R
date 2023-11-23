# 7.9.9
library(MASS)
library(caTools)
library(splines)
library(boot)
library(ggplot2)

# (a)
# poly函数拟合nox~dis三次模型
glm.fit = glm(nox~poly(dis,3), data=Boston)
summary(glm.fit)
# dis区间序列
dis.grid = seq(from=min(Boston$dis),to=max(Boston$dis),0.2)
preds=predict(glm.fit,newdata=list(dis=dis.grid), se=T)
# 散点图
plot(Boston$dis,Boston$nox, main="nox~dis三次模型", xlab="到波士顿五个就业中心的加权平均距离", ylab="每十万分之一的氮氧化物颗粒浓度")
# 拟合曲线
lines(dis.grid,preds$fit,col="blue",lwd=2)
# 置信区间预测曲线
lines(dis.grid,preds$fit+2*preds$se,col="blue",lwd=2,lty=2)
lines(dis.grid,preds$fit-2*preds$se,col="blue",lwd=2,lty=2)

# (b)
set.seed(123)
# 分割 训练集、测试集 dataframe 数据(随机4:1)
boston_sample = sample.split(Boston$dis, SplitRatio = 0.80)
boston_train = subset(Boston, boston_sample==TRUE)
boston_test = subset(Boston, boston_sample==FALSE)

rss = rep(0,10)
colours = rainbow(10)
# 画散点图
plot(Boston$dis,Boston$nox, main="nox~dis的1~10阶多项式拟合", xlab="到波士顿五个就业中心的加权平均距离", ylab="每十万分之一的氮氧化物颗粒浓度")
# 循环：从1~10阶
for (i in 1:10){
  # 拟合i阶模型
  glm.fit2 = glm(nox~poly(dis,i), data=boston_train)
  
  # 计算i阶模型的残差平方和
  rss[i] = sum((boston_test$nox - predict(glm.fit2,newdata=list(dis=boston_test$dis)))^2)
  # 预测曲线并画图
  preds=predict(glm.fit2,newdata=list(dis=dis.grid))
  lines(dis.grid,preds,col=colours[i], lwd=2, lty=1)
}
legend(10,0.8,legend=1:10, col= colours[1:10],lty=1,lwd=2)
# 测试集上的RSS
print(rss)
# 画测试集RSS曲线
plot(1:10,rss,xlab="多项式最高阶数", ylab="RSS", main="1~10阶多项式的RSS", type='b')

# RSS从线性模型的0.469降低到三次、四次模型的0.340左右，之后又慢慢上升

# (c)
cv.err = rep(0, 10)
set.seed(123)
# 循环：从1~10阶
for (i in 1:10) {
  glm.fit = glm(nox ~ poly(dis, i), data = Boston)
  # 10折交叉验证
  # 结果包含原始交叉验证值和调整的交叉验证值，使用调整的交叉验证值更具说服力
  cv.err[i] = cv.glm(Boston, glm.fit, K = 10)$delta[2]
}
plot(1:10,cv.err,xlab="多项式最高阶数", ylab="调整的交叉验证测试集均方误差", main="10折交叉验证下Test-MSE~poly-degree", type='b')
# 红点标注最小值
points(which.min(cv.err), cv.err[which.min(cv.err)], col = "red", pch = 16)

# 通过标注MSE的最小点，我们发现当阶数为3时均方误差最小
# 故选择最高阶数为3最合适

# (d)
# df=4 自由度为4的回归样条
spline.fit = lm(nox~bs(dis,df=4), data=Boston)
summary(spline.fit)
# 查看
attr(bs(Boston$dis,df=4),"knots")
# 当df=4时，只有一个结点(knots)，它的位置在整个dis点集的50%的位置，即中位数(3.20745)
# 注意，这个50%并不是dis的序列区间的50%位置，而是点集横坐标值的50%位置

# 散点图和预测曲线以及置信区间的曲线(和a问类似)
plot(Boston$dis,Boston$nox,xlab="到波士顿五个就业中心的加权平均距离", ylab="每十万分之一的氮氧化物颗粒浓度")
preds = predict(spline.fit, newdata=list(dis=dis.grid), se=T)
lines(dis.grid, preds$fit,col="blue",lwd=3)
lines(dis.grid, preds$fit+2*preds$se,col="blue",lwd=3,lty=2)
lines(dis.grid, preds$fit-2*preds$se,col="blue",lwd=3,lty=2)

# (e)
# 本题尝试了自由度为1~15的一组回归样条进行拟合
# 主要关注自由度为5~15与自由度为4的回归样条进行比较
set.seed(123)
rss = rep(0,15)
colours = rainbow(15)
plot(Boston$dis,Boston$nox,xlab="到波士顿五个就业中心的加权平均距离", ylab="每十万分之一的氮氧化物颗粒浓度",main="自由度为5~15的样条回归曲线")
for (i in 1:15){ 
  spline.fit = lm(nox~bs(dis,df=i), data=boston_train)
  rss[i] = sum((boston_test$nox - predict(spline.fit,newdata=list(dis=boston_test$dis)))^2)
  preds=predict(spline.fit,newdata=list(dis=dis.grid))
  lines(dis.grid,preds,col=colours[i], lwd=2, lty=1)
}
legend(10,0.8,legend=1:15, col=colours[1:15],lty=1,lwd=2)
# RSS曲线图
plot(1:15,rss,xlab="回归样条的自由度", ylab="RSS", main="自由度为1~15的回归曲线的RSS", type='b')
points(which.min(rss), rss[which.min(rss)], col = "red", pch = 16)
# 观察5~15的自由度回归样条曲线能够发现，由于自由度都比4更大，这一组曲线灵活程度都比df=4的回归样条更高
# 结果发现前期RSS先随自由度增大而升高，当自由度到达12后上下起伏不稳定

# (f)
# 与(c)问一样，把poly函数换成bs即可
set.seed(123)
cv.err = rep(0, 15)
# 循环：从1~10阶
for (i in 1:15) {
  glm.fit = glm(nox ~ bs(dis, i), data = Boston)
  # 10折交叉验证
  # 结果包含原始交叉验证值和调整的交叉验证值，使用调整的交叉验证值更具说服力
  cv.err[i] = cv.glm(Boston, glm.fit, K = 10)$delta[2]
}
plot(1:15,cv.err,xlab="回归样条的自由度度", ylab="调整的交叉验证测试集均方误差", main="自由度为1~15的回归曲线的RSS", type='b')
# 红点标注最小值
points(which.min(cv.err), cv.err[which.min(cv.err)], col = "red", pch = 16)
# 发现自由度为10的时候，交叉验证均方误差最小
# 故自由度为10的时候模型最合适