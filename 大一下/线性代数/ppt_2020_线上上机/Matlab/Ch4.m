clc; clear all;
A = round(rand(10)*10)

U1 = triu(A)%上三角
L1 = tril(A)%下三角

[X, Lambda] = jordan(A)%Jordan分解
[Q, R] = qr(A)%QR分解
[U, Sigma, V] = svd(A)%奇异值分解
[L2, U2, P] = lu(A)%LU分解

Rank = rank(A)%秩
Det = det(A)%行列式
f = poly(A)%特征多项式
[x, d] = eig(A)%特征向量与特征根
N = norm(A,inf)%无穷范数