#include <stdio.h>


int getSum(int n)
{
	int sum = 0;
	int i;
	for (i = 2; i*i < n; i++)
	{
		if (n%i == 0)
			sum += (i + n / i);
	}
	if (i*i == n)
		sum += i;
	return sum + 1;
}

int main()
{
	int n;

	scanf("%d", &n);

	for (int i = 220; i <= n; i++)
	{
		int sum = getSum(i);
		int sumSum = getSum(sum);

		if (i == sumSum&&i != sum)
		{
			printf("%d %d\n", i, sum);
			i = sum;
		}
	}

	return 0;
}