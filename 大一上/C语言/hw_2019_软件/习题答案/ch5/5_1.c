/* 例 5.1
  编写程序求三个整型数的和、积和平均值，输入三个数的值，输出结果
*/
#include<stdio.h>
 
int main()
{
   int iA, iB, iC;
   int iSum, iPro;
  
   scanf("%d%d%d",&iA,&iB,&iC);
   iSum = iA + iB+ iC;
   iPro = iA * iB *iC; /*可能会溢出*/
 
   printf("sum = %d\nproduct=%d\n", iSum, iPro);
   printf("ave = %f\n",  iSum/3.0);

   return 0;

}
 