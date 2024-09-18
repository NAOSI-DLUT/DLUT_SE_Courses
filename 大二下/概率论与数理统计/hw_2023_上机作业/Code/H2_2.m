X=unifrnd(0,3,1,1000);
Y=-6.*X+3;

DX=var(X);
DY=var(Y);

CXY=cov(X,Y);
CXY=CXY(1,2);

p=CXY/sqrt(DX)/sqrt(DY);

disp(CXY);

disp([["D(X)",DX];["D(Y)",DY];["Cov(X,Y)",CXY];["相关系数",p]]);
