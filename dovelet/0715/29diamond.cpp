#include <stdio.h>

int main()
{
	int n;

	scanf("%d", &n);

	for (int i = 1; i < n; i++)
	{
		for (int k = 0; k <(n * 2 - i * 2) / 2; k++)
			printf(" ");
		for (int k = 0; k < (i - 1) * 2 + 1; k++)
			printf("*");
		for (int k = 0; k <(n * 2 - i * 2) / 2; k++)
			printf(" ");
		printf("\n");
	}

	for (int i = n; i > 0; i--)
	{
		for (int k = 0; k <(n * 2 - i * 2) / 2; k++)
			printf(" ");
		for (int k = 0; k < (i - 1) * 2 + 1; k++)
			printf("*");
		for (int k = 0; k <(n * 2 - i * 2) / 2; k++)
			printf(" ");
		printf("\n");
	}

	return 0;
}
