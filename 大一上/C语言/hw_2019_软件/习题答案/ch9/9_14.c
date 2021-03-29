#include <stdio.h>
#define N 3
int x,y,exist=0;
int isrmax(int a[N][N])
{
int i;
for(i=0;i<N;i++)
if(a[x][y]<a[x][i])
return 0;
return 1;
}

int iscmin(int a[N][N])
{
int i;
for(i=0;i<N;i++)
if(a[x][y]>a[i][y])
return 0;
return 1;
}

void scanarray(int a[N][N])
{
int i,j;
for(i=0;i<N;i++)
{
printf("第%d行：",i+1);
for(j=0;j<N;j++)
scanf("%d",&a[i][j]);
}
printf("\n");
}

void printarray(int a[N][N])
{
int i,j;
for(i=0;i<N;i++)
{
for(j=0;j<N;j++)
printf("%5d",a[i][j]);
printf("\n");
}
}

main()
{
int a[N][N];
printf("请输入数组各元素的值：\n");
scanarray(a);
printf("您输入的数组为：\n");
printarray(a);
for(x=0;x<N;x++)
for(y=0;y<N;y++)
if(isrmax(a)&&iscmin(a))
{
printf("鞍点：%d，第%d行，第%d列。\n",a[x][y],x+1,y+1);
exist=1;
}
if(!exist)
printf("矩阵中不存在鞍点！\n");
}