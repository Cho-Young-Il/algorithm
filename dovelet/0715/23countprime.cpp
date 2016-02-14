#include <stdio.h>

int arrPrime[1000000] = { 0, };
int Q[10000000];

int main()
{
	int n, k, front = 0, rear = 0, sum = 0;


	scanf("%d %d", &n, &k);

	for (int i = 2; i <= n; i++)
	{
		if (arrPrime[i] == 0)
		{
			for (int j = i + i; j <= n; j += i)
			{
				arrPrime[j] = -1;
			}
		}
	}


	for (int i = 2; i <= n; i++)
	{
		if (arrPrime[i] == 0)
		{
			sum += i;
			Q[rear++] = i;
			while (sum > n&&front<rear)
				sum -= Q[front++];
			if (rear - front > k)
				sum -= Q[front++];
			if ((sum == n) && (rear - front == k))
			{
				printf("yes\n");
				return 0;
			}
		}
	}
	printf("no\n");

	return 0;
}
