set.seed(1)
x = rnorm(100)

eps = rnorm(100, 0, I(0.25^(0.5)))

y = -1 + 0.5*x + eps

lm.fit = lm(y~x)
plot(x, y)
abline(lm.fit, lwd=3, col=2)
abline(-1, 0.5, lwd=3, col=3)
legend(x = -1,, legend = c("model fit", "pop. regression"),col=2:3, lwd=3)