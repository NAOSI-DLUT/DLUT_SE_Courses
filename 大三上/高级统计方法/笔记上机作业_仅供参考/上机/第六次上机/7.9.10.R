# 7.9.10
library(ISLR)
library(leaps)
library(gam)
# (a)
set.seed(123)

# 前向逐步选择，最大变量个数为17
fit.fwd = regsubsets(Outstate~., data=college_train, nvmax=17, method="forward")
fit.summary = summary(fit.fwd)
# 画图: Cp,BIC,调整R方, 以及最大/最小点
par(mfrow=c(2,2))
plot(1:17, fit.summary$cp,xlab="变量个数",ylab="Cp",main="Cp", type='b')
points(which.min(fit.summary$cp), fit.summary$cp[which.min(fit.summary$cp)], col = "red", pch = 16)
plot(1:17, fit.summary$bic,xlab="变量个数",ylab="BIC",main="BIC", type='b')
points(which.min(fit.summary$bic), fit.summary$bic[which.min(fit.summary$bic)], col = "red", pch = 16)
plot(1:17, fit.summary$adjr2,xlab="变量个数",ylab="调整R方",main="调整R方", type='b')
points(which.max(fit.summary$adjr2), fit.summary$adjr2[which.max(fit.summary$adjr2)], col = "red", pch = 16)

coef(fit.fwd,6)
# 通过趋势图能够发现三种方式都在变量数为6时到达比较稳定理想的状态
# 故选择变量数为6拟合效果良好，同时变量个数不会过于繁杂

# (b)
# 划分训练集与测试集(随机4:1)
college_df = College
college_sample = sample.split(college_df$Outstate, SplitRatio = 0.80)
college_train = subset(college_df, college_sample==TRUE) 
college_test = subset(college_df, college_sample==FALSE)
# 将(a)问得出来的6个预测变量加入，使用光滑样条并设定自由度为4
gam.m1 = gam(Outstate~Private+s(Room.Board,4)+s(PhD,4)+s(perc.alumni,4)+s(Expend,4)+s(Grad.Rate,4), data=college_train)
# 画出每个预测变量的函数对outstate的影响图示
par(mfrow=c(2,3))
plot(gam.m1, col="blue", se=T)

# 在其他变量不变的情况下，州外学费(outstate)随着Room.Board和perc.alumni单增
# 同时在其他变量的影响下也大体呈上涨趋势

# (c)
# 测试集上预测并计算测试集均方误差
preds = predict(gam.m1,newdata = college_test)
mse = mean((college_test$Outstate - preds)^2)
mse

# (d)
set.seed(123)
gam.m2 = gam(Outstate~Private+s(Room.Board,4)+s(PhD,4)+s(perc.alumni,2)+s(Expend,4), data=college_train)
gam.m3 = gam(Outstate~Private+s(Room.Board,4)+s(PhD,4)+s(perc.alumni,2)+s(Expend,4)+Grad.Rate, data=college_train)
gam.m4 = gam(Outstate~Private+s(Room.Board,4)+s(PhD,4)+s(perc.alumni,2)+s(Expend,4)+s(Grad.Rate,4), data=college_train)
anova(gam.m2,gam.m3,gam.m4, test="F")

gam.m2 = gam(Outstate~Private+s(Room.Board,4)+s(PhD,4)+s(perc.alumni,2)+s(Grad.Rate,4), data=college_train)
gam.m3 = gam(Outstate~Private+s(Room.Board,4)+s(PhD,4)+s(perc.alumni,2)+Expend+s(Grad.Rate,4), data=college_train)
gam.m4 = gam(Outstate~Private+s(Room.Board,4)+s(PhD,4)+s(perc.alumni,2)+s(Expend,4)+s(Grad.Rate,4), data=college_train)
anova(gam.m2,gam.m3,gam.m4, test="F")

# 从图中观察发现Expend和Grad.Rate和非线性接近
# 使用ANOVA方法进行验证：在广义可加模型中不添加、添加一次项以及四次项的目标变量
# 观察模型中该预测变量的显著程度
# 结果提供了令人信服的证据：
# s(Grad.Rate,4)的p值为0.03<0.05，s(Expend,4)的p值<2.2e-16
# 即证明Expend和Grad.Rate和响应变量有明显的非线性关系