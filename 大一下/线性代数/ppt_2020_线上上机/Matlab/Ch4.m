clc; clear all;
A = round(rand(10)*10)

U1 = triu(A)%������
L1 = tril(A)%������

[X, Lambda] = jordan(A)%Jordan�ֽ�
[Q, R] = qr(A)%QR�ֽ�
[U, Sigma, V] = svd(A)%����ֵ�ֽ�
[L2, U2, P] = lu(A)%LU�ֽ�

Rank = rank(A)%��
Det = det(A)%����ʽ
f = poly(A)%��������ʽ
[x, d] = eig(A)%����������������
N = norm(A,inf)%�����