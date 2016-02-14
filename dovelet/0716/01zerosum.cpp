#include <stdio.h>

char stack[100000];
int top=0,n;

int pow10(int i)
{
	int ret=1;
	while(i>0)
	{
		ret*=10;
		i--;
	}
	return ret;

}

int digit(int value)
{
	int ret=1;
	while(value>=10)
	{
		value/=10;
		ret++;
	}
	return ret;
}

void dfs(char oper[],int len)
{
	if(len==n-1)
	{
		int arr[10],sum=0;

		for(int i=1;i<=n;i++)
			arr[i]=i;

		for(int i=len-1;i>=0;i--)
		{
			if(oper[i]==' ')
			{
				arr[i+1]=arr[i+1]*pow10(digit(arr[i+2]))+arr[i+2];
				arr[i+2]=arr[i+1];
			}
		}
		
		sum=arr[1];

		for(int i=0;i<len;i++)
		{
			if(oper[i]=='+')
				sum+=arr[i+2];
			if(oper[i]=='-')
				sum-=arr[i+2];
		}
		
		if(sum==0)
		{
			int i=0;
			for(;i<len;i++)
				printf("%d%c",i+1,oper[i]);
			printf("%d\n",i+1);
		}
		return ;
	}
	oper[len]=' ';
	dfs(oper,len+1);

	oper[len]='+';
	dfs(oper,len+1);

	oper[len]='-';
	dfs(oper,len+1);
}

int main()
{
	scanf("%d",&n);
	char oper[10];

	dfs(oper,0);

	return 0;
}