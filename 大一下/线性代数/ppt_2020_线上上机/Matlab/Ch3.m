clc; clear all;
A = normrnd(15,1,10);%���ɾ���
A
B = round(A);%ȡ��
B
C = B*diag(1:10);%�����б��
C
D = C(C>=30 & C<=70);%������ѡԪ��
D = D'
[row, col] = find(C>=30 & C<=70);%��������������
Row = row'
Col=col'