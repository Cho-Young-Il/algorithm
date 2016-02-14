#include <stdio.h>

int stack[100000];
int top=0,n,m;
char arr[25][25]={0};
int visit[25][25]={0};

int dfs(int x,int y)
{
	int step = visit[x][y];
	if(x>n||y>m)
		return 0;
	if(x==n-1&&y==m-1)
	{
		if((arr[x][y]!=1))
			return step;
	}

	if(x+1<n)
	{
		if((arr[x+1][y]!=1)&&(step+1<visit[x+1][y]))
		{
			visit[x+1][y]=step+1;
			stack[top++]=x+1;
			stack[top++]=y;
		}		
	}
	if(y+1<m)
	{
		if((arr[x][y+1]!=1)&&(step+1<visit[x][y+1]))
		{
			visit[x][y+1]=step+1;
			stack[top++]=x;
			stack[top++]=y+1;
		}	
	}
	if(x-1>=0)
	{
		if((arr[x-1][y]!=1)&&(step+1<visit[x-1][y]))
		{
			visit[x-1][y]=step+1;
			stack[top++]=x-1;
			stack[top++]=y;
		}	
	}
	if(y-1>=0)
	{
		if((arr[x][y-1]!=1)&&(step+1<visit[x][y-1]))
		{
			visit[x][y-1]=step+1;
			stack[top++]=x;
			stack[top++]=y-1;
		}	
	}
	return -1;
}

int main()
{
	scanf("%d %d",&n,&m);

	for(int i=n-1;i>=0;i--)
	{
		scanf("%s",arr[i]);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			visit[i][j]=1000;
			arr[i][j]-='0';
		}
	}
	stack[top++]=0;
	stack[top++]=0;
	visit[0][0]=1;

	int min=999;

	while(top>0)
	{
		int pop_x=stack[top-2];
		int pop_y=stack[top-1];
		top-=2;
		int res=dfs(pop_x,pop_y);
		if(res<min&&res!=-1)
			min=res;
	}

	printf("%d",min);
	return 0;
}