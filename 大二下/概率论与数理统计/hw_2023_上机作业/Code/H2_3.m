X=unifrnd(0,3,1,1000);

for n=[0,1,10,50]
    Y=-6*(X.^n)+3;
    CXY=cov(X,Y);
    DX=CXY(1,1);
    DY=CXY(2,2);
    CXY=CXY(1,2);
    p=CXY/sqrt(DX)/sqrt(DY);
    disp([["n="+num2str(n),""];["D(X)",DX];["D(Y)",DY];["Cov(X,Y)",CXY];["相关系数",p]]);
end
