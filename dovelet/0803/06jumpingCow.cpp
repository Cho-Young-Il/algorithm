#include <stdio.h>

int dp[160000][4];		//0�� ���粨 ¦��������		(������ Ȧ���� �Դ´�)
						//1�� ���粨 Ȧ��������		(������ ¦���� �Դ´�)
						//2�� ���粨 Ȧ�������� ���� �����ε� �ȸ��� (������ Ȧ���� �Դ´�)
						//3�� ���粨 ¦�������� ���� �����ε� �ȸ��� (������ ¦���� �Դ´�)
int maxTwo(int a, int b)
{
	if (a > b)	return a;
	return b;
}

int main()
{
	int n,value;
	scanf("%d", &n);

	scanf("%d", &value);
	dp[1][0] = dp[1][2] = value;
	dp[1][1] = dp[0][0] = dp[0][1] = 0;
	for (int i = 2; i <= n; i++)
	{
		scanf("%d", &value);
		
		dp[i][0] = maxTwo(dp[i - 1][1], dp[i - 1][3])+value;
		dp[i][1] = maxTwo(dp[i - 1][0], dp[i - 1][2])-value;
		dp[i][2] = maxTwo(dp[i - 1][0],dp[i-1][2]);
		dp[i][3] = maxTwo(dp[i - 1][1],dp[i-1][3]);
	}

	int res = maxTwo(maxTwo(dp[n][0], dp[n][1]), maxTwo(dp[n][2], dp[n][3]));
	printf("%d\n", res);

	return 0;
}