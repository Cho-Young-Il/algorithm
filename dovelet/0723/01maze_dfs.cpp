#include <stdio.h>

int map[30][30];
int visit[30][30];
int n,m;

void dfs(int x,int y);

void dfsFunc(int x,int y,int value)
{
	if((visit[x][y]>value+1)&&(map[x][y]==1))
	{
		visit[x][y]=value+1;
		dfs(x,y);
	}
}

void dfs(int x,int y)
{
	dfsFunc(x+1,y,visit[x][y]);
	dfsFunc(x-1,y,visit[x][y]);
	dfsFunc(x,y+1,visit[x][y]);
	dfsFunc(x,y-1,visit[x][y]);
}

int main()
{
	char input[30];
	scanf("%d %d",&m,&n);

	for(int i=n;i>=1;i--)
	{
		scanf("%s",input);
		for(int j=1;j<=m;j++)
		{
			map[i][j]=1-input[j-1]+'0';
			visit[i][j]=999999;
		}
	}
	visit[1][1]=1;
	dfs(1,1);

	printf("%d\n",visit[n][m]);

	return 0;
}