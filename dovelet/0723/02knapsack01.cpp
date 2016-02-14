#include <stdio.h>

int n,k;
int memo[101][20200]={0};

int isBig(int a,int b)
{
	if(b>a)	return b;
	return a;
}

int main()
{
	scanf("%d %d",&n,&k);

	int input;
	int sum=0;
	for(int i=1;i<=k;i++)
	{
		int wei,value;
		scanf("%d %d",&wei,&value);

		sum+=wei;

		for(int j=0;j<=n;j++)
		{
			memo[i][j]=memo[i-1][j];


			if(j<wei)			continue;
			//if(j>sum)			break;
		
			memo[i][j] = isBig(memo[i-1][j],memo[i-1][j-wei]+value);
		}
	}

	int max=0;

	for(int i=1;i<=n;i++)
	{
		if(max<memo[k][i])
			max=memo[k][i];
	}


	printf("%d\n",max);

	return 0;
}