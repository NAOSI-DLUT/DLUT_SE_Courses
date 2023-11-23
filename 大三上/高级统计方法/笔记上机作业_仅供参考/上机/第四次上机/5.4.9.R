# 5.4.9
# (a)
library(MASS)
attach(Boston)
set.seed(123)
medv.mean = mean(medv)
medv.mean
# 22.53281

# (b)
# medv.stderr medv的标准误差
medv.stderr = sd(medv)/sqrt(length(medv))
medv.stderr
# 使用提示给出的计算公式，得到标准误差为0.4088611

# (c)
library(boot)
# 定义均值的抽样函数
boot.fn.mean = function(data, index){
  # 返回的是数据的总体均值
  return (mean(data[index]))
}
bootstrap.mean=boot(medv, boot.fn.mean, 1000)
bootstrap.mean
# 结果为0.4045557，和(b)相比相差不大，几乎相同

# (d)
t.test(medv)
# t.test估计的95%置信区间为[21.72953, 23.33608]
c(bootstrap.mean$t0 - 2 * medv.stderr, bootstrap.mean$t0 + 2 * medv.stderr)
# 自助法估计的95%置信区间为[21.71508, 23.35053]
# 可以看出置信区间基本一致

# (e)
medv.median = median(medv)
medv.median
# medv的中位数为21.2

# (f)
# 定义中位数的抽样函数
boot.fn.median = function(data, index) {
  return(median(data[index]))
}
bootstrap.median=boot(medv, boot.fn.median, 1000)
bootstrap.median
# medv的中位数标准误差为0.3783996

# (g)
# quantile函数定义0.1比例的分位数
medv.10_div = quantile(medv, c(0.1))
medv.10_div
# medv的十分位数为12.75 

# (h)
# 定义十分位的抽样函数
boot.fn.10_div = function(data, index) {
  return(quantile(data[index], c(0.1)))
}
bootstrap.10_div=boot(medv, boot.fn.10_div, 1000)
bootstrap.10_div
# 十分位数的标准误差为0.5082798