#include <stdio.h>

int main()
{
	int n, sum;
	scanf("%d", &n);
	
	sum = n * 12 / 19;

	while ((sum + (int)(sum / 3) + (int)(sum / 4)) < n)
		sum ++;

	printf("%d\n",sum);
		
	return 0;
}