#include <stdio.h>

void printNumber(int a)
{
	switch (a)
	{
	case 0: printf("Áã"); break;
	case 1: printf("Ò¼"); break;
	case 2: printf("·¡"); break;
	case 3: printf("Èş"); break;
	case 4: printf("ËÁ"); break;
	case 5: printf("Îé"); break;
	case 6: printf("Â½"); break;
	case 7: printf("Æâ"); break;
	case 8: printf("°Æ"); break;
	default: printf("¾Á");
	}
}

int main()
{
	int num, a, b, c, d;


	printf("Please input a number less than 10000: ");
	scanf("%d", &num);

	if (num >= 10000)
	{
		printf("please input a number less than 10000\n");
		return 1;
	}

	printf("%d :  ", num);

	if (num < 10)
	{
		d = num;
		printNumber(d);
	}
	else if (num < 100)
	{
		c = num / 10;
		d = num % 10;

		if (d == 0)
		{
			if (c == 1)
				printf("Ê°");
			else
			{
				printNumber(c);
				printf("Ê°");
			}
		}
		else
		{
			if (c == 1)
			{
				printf("Ê°");
				printNumber(d);
			}
			else
			{
				printNumber(c);
				printf("Ê°");
				printNumber(d);
			}
		}
	}
	else if (num < 1000)
	{
		b = num / 100;
		c = num % 100 / 10;
		d = num % 100 % 10;

		if (c == 0 && d == 0)
		{
			printNumber(b);
			printf("°Û");
		}
		else if (c == 0 && d != 0)
		{
			printNumber(b);
			printf("°ÛÁã");
			printNumber(d);
		}
		else if (c != 0 && d == 0)
		{
			printNumber(b);
			printf("°Û");
			printNumber(c);
			printf("Ê°");
		}
		else
		{
			printNumber(b);
			printf("°Û");
			printNumber(c);
			printf("Ê°");
			printNumber(d);
		}
	}
	else
	{
		a = num / 1000;
		b = num % 1000 / 100;
		c = num % 1000 % 100 / 10;
		d = num % 1000 % 100 % 10;

		printf("%d %d %d %d \n", a, b, c, d);

		if (b == 0 && c == 0 && d == 0)
		{
			printNumber(a);
			printf("Çª");
		}
		else if (b == 0 && c == 0 && d != 0)
		{
			printNumber(a);
			printf("ÇªÁã");
			printNumber(d);
		}
		else if (b == 0 && c != 0 && d == 0)
		{
			printNumber(a);
			printf("ÇªÁã");
			printNumber(c);
			printf("Ê°");
		}
		else if (b != 0 && c == 0 && d == 0)
		{
			printNumber(a);
			printf("Çª");
			printNumber(b);
			printf("°Û");
		}
		else if (b == 0 && c != 0 && d != 0)
		{
			printNumber(a);
			printf("ÇªÁã");
			printNumber(c);
			printf("Ê°");
			printNumber(d);
		}
		else if (b != 0 && c == 0 && d != 0)
		{
			printNumber(a);
			printf("Çª");
			printNumber(b);
			printf("°ÛÁã");
			printNumber(d);
		}
		else if (b != 0 && c != 0 && d == 0)
		{
			printNumber(a);
			printf("Çª");
			printNumber(b);
			printf("°Û");
			printNumber(c);
			printf("Ê°");
		}
		else
		{
			printNumber(a);
			printf("Çª");
			printNumber(b);
			printf("°Û");
			printNumber(c);
			printf("Ê°");
			printNumber(d);
		}
	}

	printf("\n");


	return 0;
}
