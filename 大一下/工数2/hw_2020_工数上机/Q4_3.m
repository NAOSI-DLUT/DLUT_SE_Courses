x1 = linspace(-2,2,25);
y1 = linspace(-2,2,25);
[x,y] = meshgrid(x1,y1);
f = x.^4-x.*y.*8+2*y.^2-3;
contour(x,y,f,'ShowText','on');
syms X Y
F = X^4-X*Y*8+2*Y^2-3;
fx = diff(F,X);
fy = diff(F,Y);
eqn = [fx==0,fy==0];
vars = [X Y];
S = solve(eqn,vars);
double(subs(X^4-X*Y*8+2*Y^2-3,vars,[S.X(1) S.Y(1)]))
double(subs(X^4-X*Y*8+2*Y^2-3,vars,[S.X(2) S.Y(2)]))
double(subs(X^4-X*Y*8+2*Y^2-3,vars,[S.X(3) S.Y(3)]))