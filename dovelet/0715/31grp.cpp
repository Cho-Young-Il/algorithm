#include <stdio.h>


int main()
{
	int n, k, cnt = 0, sum;

	scanf("%d %d", &n, &k);

	for (int i = 1; i <= n - k + 1; i++)
	{
		sum = 0;
		for (int j = 0; j < k; j++)
		{
			sum += i + j;
		}
		if (sum % 15 == 0)
			cnt++;
	}

	printf("%d", cnt);

	return 0;
}