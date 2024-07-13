UdReality=xlsread("EXP02_04_2307_20232241110.xlsx","C2:C47");
IdReality=xlsread("EXP02_04_2307_20232241110.xlsx","D2:D47");

UdEmulate=xlsread("EXP02_04_2307_20232241110.xlsx","J2:J47");
IdEmulate=xlsread("EXP02_04_2307_20232241110.xlsx","K2:K47");

plot(UdEmulate, IdEmulate,'.-', 'LineWidth', 1, 'Color', 'red' ); 
hold on;

plot(UdReality, IdReality,'.-', 'LineWidth', 1, 'Color', 'blue');  
hold off; 

legend('Emulate','Reality');
xlabel("Ud(V)");
ylabel("Id(mA)");
title("稳压二极管1N4735伏安特性曲线仿真与实际对比");

%%
x1=-7:0.001:1;
x1=x1';

[UdRealityUnique, idx] = unique(UdReality);
IdRealityUnique = IdReality(idx);

y1 = interp1(UdRealityUnique, IdRealityUnique, x1,"linear");
plot(x1, y1,'r');
hold on;
y1 = interp1(UdRealityUnique, IdRealityUnique, x1,"nearest");
plot(x1, y1,'b');
hold off;

legend('linear','nearest');
xlabel("Ud(V)");
ylabel("Id(mA)");
title("两种插值方式对比");








