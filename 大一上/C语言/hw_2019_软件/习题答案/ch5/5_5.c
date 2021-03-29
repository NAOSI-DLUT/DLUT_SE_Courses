/*5.5
   将字符串译成密码，密码规律是用原来的字母后面的第4个字母代替原来的字母
*/
#include<stdio.h>
 
int main()
{
   char C1 = 'C',C2='h',C3='i',C4='n',C5 = 'a';

   C1 +=4 ;
   C2 +=4 ;
   C3 +=4 ;
   C4 +=4 ;
   C5 +=4 ;

   printf("%c%c%c%c%c\n",C1,C2,C3,C4,C5);

}
