#include<stdio.h>

int Test1(){
	int a, b, c, temp;
	printf("Please input three numbers:\n");
	scanf("%d%d%d", &a, &b, &c);

	if(a>b && b>c)
		printf("%d %d %d\n", c, b, a);
	if(a>c && c>b)
		printf("%d %d %d\n", b, c, a);
	if(b>a && a>c)
		printf("%d %d %d\n", c, a, b);
	if(b>c && c>a)
		printf("%d %d %d\n", a, c, b);
	if(c>a && a>b)
		printf("%d %d %d\n", b, a, c);
	if(c>b && b>a)
		printf("%d %d %d\n", a, b, c);

	return 0;
}

main(){
	Test1();
}
