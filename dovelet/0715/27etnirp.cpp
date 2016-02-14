#include <stdio.h>

int main()
{
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		if (n / 2 == i || i == 0 || i == n - 1)
		{
			for (int j = 1; j < n; j++)
				printf("*");
		}
		else
		{
			for (int j = 1; j < n; j++)
				printf(" ");
		}
		printf("*\n");
	}

	return 0;
}
