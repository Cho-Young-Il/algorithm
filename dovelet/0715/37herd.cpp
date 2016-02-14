#include <stdio.h>


int main()
{
	int n, sum = 0, Q;
	int cnt = 1;

	scanf("%d", &n);

	Q = 1;
	for (int i = 1; i < n; i++)
	{
		sum += i;

		while (sum > n)
			sum -= Q++;
		
		if (sum == n)
			cnt++;
	}

	printf("%d", cnt);
	return 0;
}