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
	for (i = 0; i < X; i++)     //�������a,3��2��  
		for (j = 0; j < M; j++)
			scanf("%d", &a[i][j]);
 
 	printf("Input 2x4 matrix:\n");
	for (i = 0; i < M; i++)     //�������b,2��4��  
		for (j = 0; j < Z; j++)
			scanf("%d", &b[i][j]);
 
	for (i = 0; i < X; i++)     //��ʼ������c��3��4��  
		for (j = 0; j < Z; j++)
			c[i][j] = 0;
 
	for (i = 0; i<X; i++)            //����a�����b���  
		for (j = 0; j < Z; j++)
		{
			c[i][j] = 0;
			for (k = 0; k < M; k++)
				c[i][j] += a[i][k] * b[k][j];
		}
 
	for (i = 0; i < X; i++){
	      //�������c  
		for (j = 0; j < Z; j++)
			printf("%3d", c[i][j]);
		printf("\n");
	}
 
	system("pause");
	return 0;
}


