#include <stdio.h>

int main()
{
	int n, k, sum, rest;
	scanf("%d %d", &n,&k);

	sum = n;
	rest = n;
	while (n > 0)
	{
		n = rest / k;
		rest = rest%k+n;
		sum += n;
	}
	
	printf("%d", sum);

	return 0;
}