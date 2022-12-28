
# a

set.seed(1)
X = rnorm(100)
eps = rnorm(100)

# b
# 选择 β0=3, β1=2, β2=−3 and β3=0.3.

beta0 = 3
beta1 = 2
beta2 = -3
beta3 = 0.3
Y = beta0 + beta1 * X + beta2 * X^2 + beta3 * X^3 + eps

# c
# 使用 regsubsets 选择具有 10 次 X 多项式的最佳模型
library(leaps)
data.full = data.frame(y = Y, x = X)
mod.full = regsubsets(y ~ poly(x, 10, raw = T), data = data.full, nvmax = 10)
mod.summary = summary(mod.full)

# 找到最佳 cp、BIC 和 adj r2 的模型大小
which.min(mod.summary$cp)
## [1] 3
which.min(mod.summary$bic)
## [1] 3
which.max(mod.summary$adjr2)
## [1] 3
# Plot cp, BIC and adjr2
plot(mod.summary$cp, xlab = "Subset Size", ylab = "Cp", pch = 20, type = "l")
points(3, mod.summary$cp[3], pch = 4, col = "red", lwd = 7)

plot(mod.summary$bic, xlab = "Subset Size", ylab = "BIC", pch = 20, type = "l")
points(3, mod.summary$bic[3], pch = 4, col = "red", lwd = 7)

plot(mod.summary$adjr2, xlab = "Subset Size", ylab = "Adjusted R2", pch = 20, 
    type = "l")
points(3, mod.summary$adjr2[3], pch = 4, col = "red", lwd = 7)

# 在 Cp、BIC 和调整后的 R2 标准下，3、3、
# 和 3 个变量模型分别被挑选出来。

coefficients(mod.full, id = 3)
##           (Intercept) poly(x, 10, raw = T)1 poly(x, 10, raw = T)2 
##               3.07627               2.35624              -3.16515 
## poly(x, 10, raw = T)7 
##               0.01047

# 所有统计数据都选择 X7 而不是 X3。 其余系数非常接近 β s。

# d

mod.fwd = regsubsets(y ~ poly(x, 10, raw = T), data = data.full, nvmax = 10, 
    method = "forward")
mod.bwd = regsubsets(y ~ poly(x, 10, raw = T), data = data.full, nvmax = 10, 
    method = "backward")
fwd.summary = summary(mod.fwd)
bwd.summary = summary(mod.bwd)
which.min(fwd.summary$cp)
## [1] 3
which.min(bwd.summary$cp)
## [1] 3
which.min(fwd.summary$bic)
## [1] 3
which.min(bwd.summary$bic)
## [1] 3
which.max(fwd.summary$adjr2)
## [1] 3
which.max(bwd.summary$adjr2)
## [1] 4
# Plot the statistics
par(mfrow = c(3, 2))
plot(fwd.summary$cp, xlab = "Subset Size", ylab = "Forward Cp", pch = 20, type = "l")
points(3, fwd.summary$cp[3], pch = 4, col = "red", lwd = 7)
plot(bwd.summary$cp, xlab = "Subset Size", ylab = "Backward Cp", pch = 20, type = "l")
points(3, bwd.summary$cp[3], pch = 4, col = "red", lwd = 7)
plot(fwd.summary$bic, xlab = "Subset Size", ylab = "Forward BIC", pch = 20, 
    type = "l")
points(3, fwd.summary$bic[3], pch = 4, col = "red", lwd = 7)
plot(bwd.summary$bic, xlab = "Subset Size", ylab = "Backward BIC", pch = 20, 
    type = "l")
points(3, bwd.summary$bic[3], pch = 4, col = "red", lwd = 7)
plot(fwd.summary$adjr2, xlab = "Subset Size", ylab = "Forward Adjusted R2", 
    pch = 20, type = "l")
points(3, fwd.summary$adjr2[3], pch = 4, col = "red", lwd = 7)
plot(bwd.summary$adjr2, xlab = "Subset Size", ylab = "Backward Adjusted R2", 
    pch = 20, type = "l")
points(4, bwd.summary$adjr2[4], pch = 4, col = "red", lwd = 7)


# 我们看到所有统计数据都选择了 3 个变量模型，除了后向逐步调整 R2。

coefficients(mod.fwd, id = 3)
##           (Intercept) poly(x, 10, raw = T)1 poly(x, 10, raw = T)2 
##               3.07627               2.35624              -3.16515 
## poly(x, 10, raw = T)7 
##               0.01047
coefficients(mod.bwd, id = 3)
##           (Intercept) poly(x, 10, raw = T)1 poly(x, 10, raw = T)2 
##               3.07888               2.41982              -3.17724 
## poly(x, 10, raw = T)9 
##               0.00187
coefficients(mod.fwd, id = 4)
##           (Intercept) poly(x, 10, raw = T)1 poly(x, 10, raw = T)2 
##              3.112359              2.369859             -3.275727 
## poly(x, 10, raw = T)4 poly(x, 10, raw = T)7 
##              0.027674              0.009997

# # 这里向前逐步选择 X7 而不是 X3。
# 带有 3 个变量的向后逐步选择 X9，而向后逐步选择
# 有 4 个变量选择 X4 和 X7。 所有其他系数都接近 β s。

# e
# Training Lasso on the data

library(glmnet)
xmat = model.matrix(y ~ poly(x, 10, raw = T), data = data.full)[, -1]
mod.lasso = cv.glmnet(xmat, Y, alpha = 1)
best.lambda = mod.lasso$lambda.min
best.lambda
## [1] 0.03991
plot(mod.lasso)

# Next fit the model on entire data using best lambda
best.model = glmnet(xmat, Y, alpha = 1)
predict(best.model, s = best.lambda, type = "coefficients")
## 11 x 1 sparse Matrix of class "dgCMatrix"
##                                 1
## (Intercept)             3.0398151
## poly(x, 10, raw = T)1   2.2303371
## poly(x, 10, raw = T)2  -3.1033193
## poly(x, 10, raw = T)3   .        
## poly(x, 10, raw = T)4   .        
## poly(x, 10, raw = T)5   0.0498411
## poly(x, 10, raw = T)6   .        
## poly(x, 10, raw = T)7   0.0008068
## poly(x, 10, raw = T)8   .        
## poly(x, 10, raw = T)9   .        
## poly(x, 10, raw = T)10  .
# Lasso 也选择 X5 而不是 X3。 它还选择系数可忽略不计的 X7。

# f
# Create new Y with different β7=7.

beta7 = 7
Y = beta0 + beta7 * X^7 + eps
# Predict using regsubsets
data.full = data.frame(y = Y, x = X)
mod.full = regsubsets(y ~ poly(x, 10, raw = T), data = data.full, nvmax = 10)
mod.summary = summary(mod.full)

# Find the model size for best cp, BIC and adjr2
which.min(mod.summary$cp)
## [1] 2
which.min(mod.summary$bic)
## [1] 1
which.max(mod.summary$adjr2)
## [1] 4
coefficients(mod.full, id = 1)
##           (Intercept) poly(x, 10, raw = T)7 
##                 2.959                 7.001
coefficients(mod.full, id = 2)
##           (Intercept) poly(x, 10, raw = T)2 poly(x, 10, raw = T)7 
##                3.0705               -0.1417                7.0016
coefficients(mod.full, id = 4)
##           (Intercept) poly(x, 10, raw = T)1 poly(x, 10, raw = T)2 
##                3.0763                0.2914               -0.1618 
## poly(x, 10, raw = T)3 poly(x, 10, raw = T)7 
##               -0.2527                7.0091
# 我们看到 BIC 选择了具有匹配系数的最准确的 1 变量模型。
# 其他标准选择其他变量。

xmat = model.matrix(y ~ poly(x, 10, raw = T), data = data.full)[, -1]
mod.lasso = cv.glmnet(xmat, Y, alpha = 1)
best.lambda = mod.lasso$lambda.min
# best.lambda
## [1] 12.37
best.model = glmnet(xmat, Y, alpha = 1)
predict(best.model, s = best.lambda, type = "coefficients")
## 11 x 1 sparse Matrix of class "dgCMatrix"
##                            1
## (Intercept)            3.820
## poly(x, 10, raw = T)1  .    
## poly(x, 10, raw = T)2  .    
## poly(x, 10, raw = T)3  .    
## poly(x, 10, raw = T)4  .    
## poly(x, 10, raw = T)5  .    
## poly(x, 10, raw = T)6  .    
## poly(x, 10, raw = T)7  6.797
## poly(x, 10, raw = T)8  .    
## poly(x, 10, raw = T)9  .    
## poly(x, 10, raw = T)10 .

# Lasso 也选择最好的 1变量模型，但 intercet 很差（3.8 vs 3）。