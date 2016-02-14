#pragma warning(disable:4996)

#include <stdio.h>

int n, m;
int arr[110][110] = { 0, };
int Q[1000000];
int front = 0, rear = 0;

void bfsFunc(int x,int y)
{
	if (arr[x][y] == 1)
	{
		Q[rear++] = x;
		Q[rear++] = y;
		arr[x][y] = 0;
	}

}

void bfs(int x,int y)
{
	bfsFunc(x+1,y);
	bfsFunc(x-1,y);
	bfsFunc(x+1,y+1);
	bfsFunc(x-1,y+1);
	bfsFunc(x+1,y-1);
	bfsFunc(x-1,y-1);
	bfsFunc(x,y+1);
	bfsFunc(x,y-1);
}

int main()
{
	int cnt = 0;
	scanf("%d %d\n", &n,&m);
	char input[110];
	for (int i = 1; i <= n; i++)
	{
		scanf("%s",input);
		for (int j = 0; j < m; j++)
		{
			if (input[j] == 'W')
				arr[i][j+1] = 1;
			else
				arr[i][j + 1] = 0;
		}
	}


	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (arr[i][j] == 1)
			{
				cnt++;
				arr[i][j] = 0;
				Q[rear++] = i;
				Q[rear++] = j;

				while (front < rear)
				{
					int pop_x = Q[front++];
					int pop_y = Q[front++];

					bfs(pop_x,pop_y);
				}
				rear = 0, front = 0;
			}
		}
	}

	printf("%d\n", cnt);
	return 0;
}