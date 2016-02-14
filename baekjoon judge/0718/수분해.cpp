#include <stdio.h>

int pow3(int p)
{
	if (p == 1)
		return 3;
	if (p == 0)
		return 1;

	int value = pow3(p / 2)%10007;

	if (p % 2 == 0)
		return (value * value)%10007;

	return (value * ((value*3)%10007)) % 10007;
}


int main()
{
	int n;
	int p, q;

	scanf("%d", &n);

	if (n<4)
	{
		printf("%d",n);
		return 0;
	}

	p = n / 3;
	q = n % 3;
	if (q == 1)
	{
		q = 4;
		p--;
	}
	if (q == 0)
		q = 1;

	printf("%d",(pow3(p)*q)%10007);

	return 0;
}