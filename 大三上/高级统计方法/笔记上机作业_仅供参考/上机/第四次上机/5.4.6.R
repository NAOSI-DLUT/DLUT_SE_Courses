# 5.4.6
library(ISLR)
# (a)
set.seed(123)
summary(Default)
glm.fit = glm(default ~ income + balance, data = Default, family = binomial)
summary(glm.fit)
# 标准误差估计如下
# income 4.985e-06
# balance 2.274e-04

# (b)
boot.fn = function(data, index) {
  # 拟合模型, 子集条件为输入的index
  glm.fit = glm(default ~ income + balance, data = data, family = binomial, subset = index)
  # coef函数返回拟合模型的系数估计
  return (coef(glm.fit))
}

# (c)
library(boot)
# 数据集为Default，抽样函数为boot.fn，抽样次数为100
boot(Default, boot.fn, 100)

# (d)
#                 income       balance
# glm估计结果     4.985e-06    2.274e-04
# boot.fn估计结果 5.124683e-06 2.150082e-04
# 发现估计结果相差不大