#include <stdio.h>

int n;

bool checkPrime(int value)
{
	for(int i=2;i*i<=value;i++)
	{
		if(value%i==0)
			return false;
	}
	if(value==1)
		return false;

	return true;
}

void dfs(int arr[],int index)
{
	if(index==n)
	{
		int value=0;
		for(int i=0;i<index;i++)
			value=value*10+arr[i];

		for(int i=0,digit=1;i<index;i++,digit*=10)
		{
			if(!checkPrime(value/digit))
				return;
		}
		printf("%d\n",value);
		return;
	}
	
	arr[index]=1;
	dfs(arr,index+1);

	if(index==0)
	{
		arr[index]=2;
		dfs(arr,index+1);	
	}


	arr[index]=3;
	dfs(arr,index+1);
	
	if(index==0)
	{
		arr[index]=5;
		dfs(arr,index+1);
	}

	arr[index]=7;
	dfs(arr,index+1);

	arr[index]=9;
	dfs(arr,index+1);
}


int main()
{
	int arr[9]={0,};

	scanf("%d",&n);

	if(n>1)
		dfs(arr,0);
	else
		printf("%d\n%d\n%d\n%d\n",2,3,5,7);

	return 0;
}