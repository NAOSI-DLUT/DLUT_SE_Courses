#include<stdio.h>  
#include<iostream>
#define X 3  
#define M 2  
#define Z 4  
int main()
{
	int i, j, k;
	int a[X][M], b[M][Z], c[X][Z];
 
 	printf("Input 3x2 matrix:\n");
	for (i = 0; i < X; i++)     //输入矩阵a,3行2列  
		for (j = 0; j < M; j++)
			scanf("%d", &a[i][j]);
 
 	printf("Input 2x4 matrix:\n");
	for (i = 0; i < M; i++)     //输入矩阵b,2行4列  
		for (j = 0; j < Z; j++)
			scanf("%d", &b[i][j]);
 
	for (i = 0; i < X; i++)     //初始化矩阵c，3行4列  
		for (j = 0; j < Z; j++)
			c[i][j] = 0;
 
	for (i = 0; i<X; i++)            //矩阵a与矩阵b相乘  
		for (j = 0; j < Z; j++)
		{
			c[i][j] = 0;
			for (k = 0; k < M; k++)
				c[i][j] += a[i][k] * b[k][j];
		}
 
	for (i = 0; i < X; i++){
	      //输出矩阵c  
		for (j = 0; j < Z; j++)
			printf("%3d", c[i][j]);
		printf("\n");
	}
 
	system("pause");
	return 0;
}


