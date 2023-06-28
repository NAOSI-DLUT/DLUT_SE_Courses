clc; clear all;
A = normrnd(15,1,10);%生成矩阵
A
B = round(A);%取整
B
C = B*diag(1:10);%乘以列表号
C
D = C(C>=30 & C<=70);%给出所选元素
D = D'
[row, col] = find(C>=30 & C<=70);%给出行数和列数
Row = row'
Col=col'