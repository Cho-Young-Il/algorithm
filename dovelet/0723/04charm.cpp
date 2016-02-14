#include <stdio.h>

int n,max_wei;
int memo[3403][12900]={0};

int isBig(int a,int b)
{
	if(b>a)	return b;
	return a;
}

int main()
{
	scanf("%d %d",&n,&max_wei);

	for(int i=1;i<=n;i++)
	{
		int wei,value;
		scanf("%d %d",&wei,&value);

		for(int j=0;j<=max_wei;j++)
		{
			memo[i][j]=memo[i-1][j];

			if(j<wei)			continue;
		
			memo[i][j] = isBig(memo[i-1][j],memo[i-1][j-wei]+value);
		}
	}

	int max=0;

	for(int i=1;i<=max_wei;i++)
	{
		if(max<memo[n][i])
			max=memo[n][i];
	}


	printf("%d\n",max);

	return 0;
}