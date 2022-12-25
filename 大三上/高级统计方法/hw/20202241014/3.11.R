#a.
set.seed(1)
x = rnorm(100)
y = 2*x + rnorm(100)

#b.
lm.fit = lm(y~x+0)
summary(lm.fit)

#c.
lm.fit = lm(x~y+0)
summary(lm.fit)

#d.
A = (sqrt(length(x)-1) * sum(x*y)) / (sqrt(sum(x*x) * sum(y*y) - (sum(x*y))^2))

#e.
# t(x,y) = t(y,x)

#f
lm.fit = lm(y~x)
lm.fit2 = lm(x~y)
summary(lm.fit)
summary(lm.fit2)