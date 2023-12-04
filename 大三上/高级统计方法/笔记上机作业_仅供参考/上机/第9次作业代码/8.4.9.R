# 8.4.9
library(ISLR)
library(caTools)
library(tree)
# 回归树
library(gbm)
# (a)
set.seed(123)
# 从1070个数据中随机抽取800个作为训练集
train = sample.split(OJ$Purchase, SplitRatio = 800/1070)
train.set = subset(OJ,train==T)
test.set = subset(OJ,train==F)

# (b)
tree.OJ = tree(Purchase~.,data=train.set)
summary(tree.OJ)

# 残差平均偏差为0.7381，训练错误率为0.1538，有8个终端结点

# (c)
tree.OJ
# 观察22终端结点，归入此终端节点的分类标准是LoyalCH<0.277977，共有47个观测值被分类到该结点，该分支分类结果是MM

# (d)
# 树画图
plot(tree.OJ)
# 加上结点文字信息
text(tree.OJ,pretty=0)

# 从决策树图能够看出，root处使用的是LoyalCH进行分支，其是最关键的变量
# 然后还能看出此决策树只使用了4个变量

# (e)
# 用建立的决策树对测试集进行预测
pred.OJ = predict(tree.OJ, newdata = test.set, type = "class")
# 混淆矩阵
table(pred.OJ,test.set$Purchase)
# 测试错误率为(30+26)/270=0.2074

# (f)
set.seed(123)
# 训练集
cv.OJ = cv.tree(tree.OJ, FUN=prune.misclass)
cv.OJ
# (g)
plot(cv.OJ$size, cv.OJ$dev, xlab = "树的规模", ylab = "交叉验证分类错误率", type = "b")

# (h)
# 从cv.OJ以及图中能够看出来8个结点的树交叉验证分类错误率最低

# (i)
# 从图中能够看出来由于交叉验证错误率随属的规模增大而单调递减
# 故无法对剪枝后的树进行选择，建立一棵终端结点数为5的树
prune.OJ = prune.misclass(tree.OJ,best=5)
pred.prune = predict(prune.OJ, newdata = train.set, type = "class")

# (j)
table(pred.prune,train.set$Purchase)
# 剪枝后的树训练错误率为(30+101)/800=0.1638
# 未剪枝的树训练错误率0.1538
# 剪枝后相比剪枝前稍高一些

# (k)
pred.prune = predict(prune.OJ, newdata = test.set, type = "class")
table(pred.prune,test.set$Purchase)
# 剪枝后的树测试错误率为(18+38)/270=0.2074
# 未剪枝的树测试错误率为0.2074
# 剪枝后与剪枝前几乎一样