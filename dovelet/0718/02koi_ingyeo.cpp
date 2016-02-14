#include <stdio.h>

long long pow(int n, int r)
{
	if (r == 0)
		return 1;
	if (r == 1)
		return n;

	long long value = pow(n, r / 2);
	if (r % 2 == 0)
		return (value * value)%100000000;
	
	return value * ((value*n) % 100000000) % 100000000;
}

int main()
{
	int n,sum = 0;
	int len = 0;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		sum += pow(i, i);
		sum %= 100000000;
	}

	int temp = sum;
	while (temp >= 10)
	{
		temp /= 10;
		len++;
	}
	for (int i = 0; i < 7 - len; i++)
		printf("0");	
	printf("%d\n",sum);
	return 0;
}