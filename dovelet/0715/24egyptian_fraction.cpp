#include <stdio.h>

int gcd_func(int a, int b)
{
	if (a == 0)
		return 0;
	if (b == 0)
		return a;
	return gcd_func(b, a%b);
}

int nextFunc(int n, int k)
{
	return k / n + 1;
}

int main()
{
	int n, k, nextNum;

	scanf("%d %d", &n, &k);
	int gcd = gcd_func(k, n);
	n /= gcd;
	k /= gcd;
	if (n == 1)
	{
		printf("1/%d\n", k);
		return 0;
	}
	nextNum = nextFunc(n, k);
	printf("1/%d ", nextNum);

	while (1)
	{
		int mul = k*nextNum;
		n = n*nextNum - k;
		k = mul;
		int gcd = gcd_func(k, n);
		n /= gcd;
		k /= gcd;
		if (n == 1)
			break;
		nextNum = nextFunc(n, k);
		printf("1/%d ", nextNum);
	}
	printf("1/%d\n", k);


	return 0;
}
