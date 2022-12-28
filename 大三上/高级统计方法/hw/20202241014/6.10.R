# a
set.seed(1)
p = 20
n = 1000
x = matrix(rnorm(n * p), n, p)
B = rnorm(p)
B[3] = 0
B[4] = 0
B[9] = 0
B[10] = 0
B[19] = 0
eps = rnorm(p)
# matrix multiply 
y = x %*% B + eps

# b
train = sample(seq(1000), 100, replace = FALSE)
y.train = y[train, ]
y.test = y[-train, ]
x.train = x[train, ]
x.test = x[-train, ]

# c
library(leaps)
regfit.full = regsubsets(y ~ ., data = data.frame(x = x.train, y = y.train), 
    nvmax = p)
val.errors = rep(NA, p)
x_cols = colnames(x, do.NULL = FALSE, prefix = "x.")
for (i in 1:p) {
    coefi = coef(regfit.full, id = i)
    pred = as.matrix(x.train[, x_cols %in% names(coefi)]) %*% coefi[names(coefi) %in% 
        x_cols]
    val.errors[i] = mean((y.train - pred)^2)
}
plot(val.errors, ylab = "Training MSE", pch = 19, type = "b")

# d
val.errors = rep(NA, p)
for (i in 1:p) {
    coefi = coef(regfit.full, id = i)
    pred = as.matrix(x.test[, x_cols %in% names(coefi)]) %*% coefi[names(coefi) %in% 
        x_cols]
    val.errors[i] = mean((y.test - pred)^2)
}
plot(val.errors, ylab = "Test MSE", pch = 19, type = "b")

# e
which.min(val.errors)
## [1] 16
# 16 parameter model has the smallest test MSE.

# f
coef(regfit.full, id = 16)
## (Intercept)         x.1         x.2         x.5         x.6         x.7 
##     0.09613     0.28257     0.19386     0.99995    -0.28598    -1.50482 
##         x.8        x.11        x.12        x.13        x.14        x.15 
##     0.77817     0.90816     0.48478    -0.19747    -0.71979    -0.74282 
##        x.16        x.17        x.18        x.19        x.20 
##    -0.33901     0.12235     1.74270    -0.12435    -1.03003

# 在 x.19 处捕获除一个归零系数之外的所有系数。

# g
val.errors = rep(NA, p)
a = rep(NA, p)
b = rep(NA, p)
for (i in 1:p) {
    coefi = coef(regfit.full, id = i)
    a[i] = length(coefi) - 1
    b[i] = sqrt(sum((B[x_cols %in% names(coefi)] - coefi[names(coefi) %in% x_cols])^2) + 
        sum(B[!(x_cols %in% names(coefi))])^2)
}
plot(x = a, y = b, xlab = "number of coefficients", ylab = "error between estimated and true coefficients")
which.min(b)
## [1] 16

# 具有 9 个系数的模型（10 个带截距）最小化误差
# 在估计系数和真实系数之间。
# 使用 16 参数模型最小化测试误差。
# 更好地拟合此处测量的真实系数
# 但并不意味着模型将具有较低的测试 MSE。