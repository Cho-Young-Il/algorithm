#include <stdio.h>

int n,sum,cnt=0;

bool usedNum[40] = { 0, };



void dfs(int num,int dSum,int index)
{
	//if (dSum==sum/2)
	{
		//cnt++;
		//printf("index : %d\n", index);
		//return;
	}
	if (dSum > sum / 2)
		return;
	//if (index > n / 2 + 1)
	//	return;

	for (int i = num + 1; i <=n; i++)
	{
		if (!usedNum[i])
		{
			if (dSum + i < sum / 2)
			{
				usedNum[i] = true;
				dfs(i, dSum + i,index+1);
				usedNum[i] = false;
			}
			else if(dSum + i == sum / 2)
			{
				cnt++;
			}
		}
	}
}

int main()
{
	//while (1)
	{
		cnt = 0;
		scanf("%d", &n);

		sum = (n*(n + 1)) / 2;

		if (sum % 2 == 1)
		{
			printf("0\n");
			return 0;
			//continue;
		}

		for (int i = 1; i <= n; i++)
		{
			usedNum[i] = true;
			dfs(i, i,1);
			usedNum[i] = false;
		}
		printf("%d\n",cnt / 2 + cnt % 2);
	}
	return 0;
}