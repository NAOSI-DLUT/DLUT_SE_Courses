1

int main ()
{
	int a[10];
	int i; 
	int *p;
	void zhuan (int*p,int n);
	p = a;
	for (i = 0; i < 10; i ++)
		a[i] = i;
	zhuan(a,10);
	for (i = 0; i < 10; i ++)
		printf("%-4d",a[i]);
}
void zhuan (int *p,int n)
{
	int tem, i;
	for (i = 0; i < n/2; i ++)
	{
		tem = p[i];
		p[i] = p[n-1-i];
		p[n-1-i] = tem;
	}
}
