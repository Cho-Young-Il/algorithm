#include <stdio.h>

int dp[160000][4];		//0Àº ÇöÀç²¨ Â¦¼ö¹øÀ¸·Î		(´ÙÀ½²¨ È¦¼ö·Î ¸Ô´Â´Ù)
						//1Àº ÇöÀç²¨ È¦¼ö¹øÀ¸·Î		(´ÙÀ½²¨ Â¦¼ö·Î ¸Ô´Â´Ù)
						//2´Â ÇöÀç²¨ È¦¼ö¹øÀ¸·Î ¸ÔÀ» Â÷·ÊÀÎµ¥ ¾È¸ÔÀ½ (´ÙÀ½²¨ È¦¼ö·Î ¸Ô´Â´Ù)
						//3Àº ÇöÀç²¨ Â¦¼ö¹øÀ¸·Î ¸ÔÀ» Â÷·ÊÀÎµ¥ ¾È¸ÔÀ½ (´ÙÀ½²¨ Â¦¼ö·Î ¸Ô´Â´Ù)
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