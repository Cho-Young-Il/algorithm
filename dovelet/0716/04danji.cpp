#include <stdio.h>

char stack[100000];
int arr[26][26];
int top=0,n,res[26];
void dfs(int x,int y)
{
	if(arr[x+1][y]==-1)
	{
		arr[x+1][y]=arr[x][y];
		stack[top++]=x+1;
		stack[top++]=y;
	}
	if(arr[x][y+1]==-1)
	{
		arr[x][y+1]=arr[x][y];
		stack[top++]=x;
		stack[top++]=y+1;
	}
	if(arr[x-1][y]==-1)
	{
		arr[x-1][y]=arr[x][y];
		stack[top++]=x-1;
		stack[top++]=y;
	}
	if(arr[x][y-1]==-1)
	{
		arr[x][y-1]=arr[x][y];
		stack[top++]=x;
		stack[top++]=y-1;
	}
	
}

int main()
{
	scanf("%d",&n);

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&arr[i][j]);
			arr[i][j]-=2;
		}
	}

	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(arr[i][j]==-1)
			{
				int sum=0;
				
				stack[top++]=i;
				stack[top++]=j;
				arr[i][j]=cnt++;

				while(top>0)
				{
					int pop_y=stack[--top];
					int pop_x=stack[--top];
					dfs(pop_x,pop_y);
					sum++;
				}
				res[cnt-1]=sum;
				top=0;
			}
		}
	}

	printf("%d\n",cnt);

	for(int i=0;i<cnt;i++)
	{
		for(int j=i;j<cnt;j++)
		{
			if(res[i]>res[j])
			{
				int temp=res[i];
				res[i]=res[j];
				res[j]=temp;
			}
		}
	}

	for(int i=0;i<cnt;i++)
		printf("%d\n",res[i]);
	return 0;
}