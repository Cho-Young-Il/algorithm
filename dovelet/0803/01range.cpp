#include <stdio.h>

int n;
int dp[300][300];
int sizeCnt[251];

void sumFunc(int value)
{
	for (int i = 2; i <= value; i++)
		sizeCnt[i]++;
}

int minT(int a, int b, int c)
{
	if (a <= b&&a <= c)	return a;
	if (b <= c&&b <= a)	return b;
	return c;
}

int main()
{
	char input[300];
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		scanf("%s", input);
		for (int j = 1; j <= n; j++)
			dp[i][j] = input[j - 1]-'0';
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (dp[i][j] == 0)	continue;
			dp[i][j] = minT(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;
			sumFunc(dp[i][j]);
		}
	}

	bool printCheck = true;
	for (int i = 2; i <= n; i++)
	{
		if (sizeCnt[i] == 0)	continue;
		printf("%d %d\n", i, sizeCnt[i]);
		printCheck = false;
	}
	if (printCheck)		printf("0\n");
	return 0;
}