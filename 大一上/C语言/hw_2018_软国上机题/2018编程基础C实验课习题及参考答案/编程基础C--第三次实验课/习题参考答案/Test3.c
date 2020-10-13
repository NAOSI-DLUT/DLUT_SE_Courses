#include <stdio.h>

void printNumber(int a)
{
	switch (a)
	{
	case 0: printf("��"); break;
	case 1: printf("Ҽ"); break;
	case 2: printf("��"); break;
	case 3: printf("��"); break;
	case 4: printf("��"); break;
	case 5: printf("��"); break;
	case 6: printf("½"); break;
	case 7: printf("��"); break;
	case 8: printf("��"); break;
	default: printf("��");
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
				printf("ʰ");
			else
			{
				printNumber(c);
				printf("ʰ");
			}
		}
		else
		{
			if (c == 1)
			{
				printf("ʰ");
				printNumber(d);
			}
			else
			{
				printNumber(c);
				printf("ʰ");
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
			printf("��");
		}
		else if (c == 0 && d != 0)
		{
			printNumber(b);
			printf("����");
			printNumber(d);
		}
		else if (c != 0 && d == 0)
		{
			printNumber(b);
			printf("��");
			printNumber(c);
			printf("ʰ");
		}
		else
		{
			printNumber(b);
			printf("��");
			printNumber(c);
			printf("ʰ");
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
			printf("Ǫ");
		}
		else if (b == 0 && c == 0 && d != 0)
		{
			printNumber(a);
			printf("Ǫ��");
			printNumber(d);
		}
		else if (b == 0 && c != 0 && d == 0)
		{
			printNumber(a);
			printf("Ǫ��");
			printNumber(c);
			printf("ʰ");
		}
		else if (b != 0 && c == 0 && d == 0)
		{
			printNumber(a);
			printf("Ǫ");
			printNumber(b);
			printf("��");
		}
		else if (b == 0 && c != 0 && d != 0)
		{
			printNumber(a);
			printf("Ǫ��");
			printNumber(c);
			printf("ʰ");
			printNumber(d);
		}
		else if (b != 0 && c == 0 && d != 0)
		{
			printNumber(a);
			printf("Ǫ");
			printNumber(b);
			printf("����");
			printNumber(d);
		}
		else if (b != 0 && c != 0 && d == 0)
		{
			printNumber(a);
			printf("Ǫ");
			printNumber(b);
			printf("��");
			printNumber(c);
			printf("ʰ");
		}
		else
		{
			printNumber(a);
			printf("Ǫ");
			printNumber(b);
			printf("��");
			printNumber(c);
			printf("ʰ");
			printNumber(d);
		}
	}

	printf("\n");


	return 0;
}
