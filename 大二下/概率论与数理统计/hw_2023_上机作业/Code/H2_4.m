kaf=zeros(1,100000);
for i=1:1:100000
    X=normrnd(0,1,1,2);
    kaf(i)=sum(X.^2);
end
histogram(kaf,1000,"Normalization","pdf");
hold on;
xlabel("X1^2+X2^2");
ylabel("Probability");

Ex=0:0.01:15;
Ey=1/2/gamma(1)*exp(-Ex/2);
plot(Ex,Ey,".");

Ekaf=mean(kaf);
Dkaf=var(kaf);

disp([["E=",Ekaf,"卡方分布E=n=2"];["D=",Dkaf,"卡方分布D=2n=4"]]);
