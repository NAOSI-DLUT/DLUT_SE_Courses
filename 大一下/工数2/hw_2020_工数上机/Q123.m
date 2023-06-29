syms x n;
ans1 = limit(sin(sin(x))/x-1)
ans2 = limit(tan(pi/4+1/n)^n,n,inf)
ans3 = limit(x*(pi/2-asin(x/sqrt(x^2+1))),x,inf)
ans4 = limit(1/(1+exp(1/(x-1))),x,1,'left')
ans5 = limit(1/(1+exp(1/(x-1))),x,1,'right')

syms x n;
ans1 = symsum(1/n^2,n,1,inf)
ans2 = symsum((-1)^(n+1)/2^n,n,0,inf)
ans3 = symsum((-x)^(n+1)/(n*(n+1)),n,1,inf)

syms x y n m;
y = taylor(sin(x),'Order',4);
x = 3*pi/180;
ans1 = eval(y)

y = taylor((1+n)^(1/3),n,29,'Order',4);
n = 29;
ans2 = eval(y)

y = taylor(sqrt(m),m,4,'Order',3);
m = 4.4;
ans3 = eval(y)