#include <stdio.h>

int map[30][30];
int n,m;
int Q[10000],rear=0,front=0;

void bfsFunc(int x,int y,int value)
{
	if(map[x][y]==1)
	{
		Q[rear++]=x;
		Q[rear++]=y;
		map[x][y]=value+1;
	}
}

void bfs(int x,int y)
{
	bfsFunc(x+1,y,map[x][y]);
	bfsFunc(x-1,y,map[x][y]);
	bfsFunc(x,y+1,map[x][y]);
	bfsFunc(x,y-1,map[x][y]);
}

int main()
{
	char input[30];
	scanf("%d %d",&m,&n);

	for(int i=n;i>=1;i--)
	{
		scanf("%s",input);
		for(int j=1;j<=m;j++)
			map[i][j]=1-input[j-1]+'0';
	}

	Q[rear++]=1;
	Q[rear++]=1;
	map[1][1]=2;

	while(front<rear)
	{
		int pop_x=Q[front++];
		int pop_y=Q[front++];
		bfs(pop_x,pop_y);
		if(pop_x==n&&pop_y==m)
			break;
	}

	printf("%d\n",map[n][m]-1);

	return 0;
}