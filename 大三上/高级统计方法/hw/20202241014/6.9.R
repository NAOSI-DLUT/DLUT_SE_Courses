
library(ISLR)
set.seed(11)
sum(is.na(College))
## [1] 0
train.size = dim(College)[1] / 2
train = sample(1:dim(College)[1], train.size)
test = -train
College.train = College[train, ]
College.test = College[test, ]

# b

lm.fit = lm(Apps~., data=College.train)
lm.pred = predict(lm.fit, College.test)
mean((College.test[, "Apps"] - lm.pred)^2)
## [1] 1538442
# Test RSS is 1538442

# c
library(glmnet)

train.mat = model.matrix(Apps~., data=College.train)
test.mat = model.matrix(Apps~., data=College.test)
grid = 10 ^ seq(4, -2, length=100)
mod.ridge = cv.glmnet(train.mat, College.train[, "Apps"], alpha=0, lambda=grid, thresh=1e-12)
lambda.best = mod.ridge$lambda.min
# lambda.best
## [1] 18.74
ridge.pred = predict(mod.ridge, newx=test.mat, s=lambda.best)
mean((College.test[, "Apps"] - ridge.pred)^2)
## [1] 1608859
# Test RSS 1608859.

# d

mod.lasso = cv.glmnet(train.mat, College.train[, "Apps"], alpha=1, lambda=grid, thresh=1e-12)
lambda.best = mod.lasso$lambda.min
lambda.best
## [1] 21.54
lasso.pred = predict(mod.lasso, newx=test.mat, s=lambda.best)
mean((College.test[, "Apps"] - lasso.pred)^2)
## [1] 1635280
# Test RSS is 1635280.

mod.lasso = glmnet(model.matrix(Apps~., data=College), College[, "Apps"], alpha=1)
predict(mod.lasso, s=lambda.best, type="coefficients")
## 19 x 1 sparse Matrix of class "dgCMatrix"
##                      1
## (Intercept) -6.038e+02
## (Intercept)  .        
## PrivateYes  -4.235e+02
## Accept       1.455e+00
## Enroll      -2.004e-01
## Top10perc    3.368e+01
## Top25perc   -2.403e+00
## F.Undergrad  .        
## P.Undergrad  2.086e-02
## Outstate    -5.782e-02
## Room.Board   1.246e-01
## Books        .        
## Personal     1.833e-05
## PhD         -5.601e+00
## Terminal    -3.314e+00
## S.F.Ratio    4.479e+00
## perc.alumni -9.797e-01
## Expend       6.968e-02
## Grad.Rate    5.160e+00

# e

library(pls)
pcr.fit = pcr(Apps~., data=College.train, scale=T, validation="CV")
validationplot(pcr.fit, val.type="MSEP")


pcr.pred = predict(pcr.fit, College.test, ncomp=10)
mean((College.test[, "Apps"] - data.frame(pcr.pred))^2)
## [1] 3014496
# Test RSS for PCR is about 3014496.

# f

pls.fit = plsr(Apps~., data=College.train, scale=T, validation="CV")
validationplot(pls.fit, val.type="MSEP")

pls.pred = predict(pls.fit, College.test, ncomp=10)
mean((College.test[, "Apps"] - data.frame(pls.pred))^2)
## [1] 1508987
# Test RSS for PLS is about 1508987.

# g
# OLS、Lasso、Ridge 的结果具有可比性。
# Lasso 将 F.Undergrad 和 Books 变量减少到零，并缩小其他变量的系数。
# 这是所有型号的测试 R2。

test.avg = mean(College.test[, "Apps"])
lm.test.r2 = 1 - mean((College.test[, "Apps"] - lm.pred)^2) /mean((College.test[, "Apps"] - test.avg)^2)
ridge.test.r2 = 1 - mean((College.test[, "Apps"] - ridge.pred)^2) /mean((College.test[, "Apps"] - test.avg)^2)
lasso.test.r2 = 1 - mean((College.test[, "Apps"] - lasso.pred)^2) /mean((College.test[, "Apps"] - test.avg)^2)
pcr.test.r2 = 1 - mean((College.test[, "Apps"] - data.frame(pcr.pred))^2) / mean((College.test[, "Apps"] - test.avg)^2)
pls.test.r2 = 1 - mean((College.test[, "Apps"] - data.frame(pls.pred))^2) / mean((College.test[, "Apps"] - test.avg)^2)
barplot(c(lm.test.r2, ridge.test.r2, lasso.test.r2, pcr.test.r2, pls.test.r2), col="red", names.arg=c("OLS", "Ridge", "Lasso", "PCR", "PLS"), main="Test R-squared")

# 除 PCR 之外的所有模型的测试 R2 都在 0.9 左右，
# PLS 的测试 R2 比其他的略高。
# PCR 的检验 R2 小于 0.8。
# 除 PCR 外，所有模型都可以精确预测大学申请。