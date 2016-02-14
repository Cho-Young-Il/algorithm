#include <stdio.h>

int n;
int arr[110][110] = { 0, };
bool visit[110][110] = { 0, };
int Q[100000];
int front = 0, rear = 0;

void bfsFunc(int x, int y, int h)
{
	if (!visit[x][y] && arr[x][y] > h)
	{
		visit[x][y] = true;
		Q[rear++] = x;
		Q[rear++] = y;
	}
}

void bfs(int x, int y, int h)
{
	bfsFunc(x + 1, y, h);
	bfsFunc(x, y + 1, h);
	bfsFunc(x - 1, y, h);
	bfsFunc(x, y - 1, h);
}

int prediction(int h)
{
	int ret = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if ((arr[i][j] > h) && (!visit[i][j]))
			{
				ret++;
				Q[rear++] = i;
				Q[rear++] = j;
				visit[i][j] = true;
				while (front < rear)
				{
					int pop_x = Q[front++];
					int pop_y = Q[front++];

					bfs(pop_x, pop_y, h);
				}
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			visit[i][j] = false;
	}

	return ret;
}

int main()
{

	int itr;
	int h = 1, ret = 1;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &arr[i][j]);
			visit[i][j] = false;
		}
	}

	while (h <= 100)
	{
		int temp = prediction(h);
		rear = 0;
		front = 0;
		h++;
		if (temp >= ret)
			ret = temp;
		//else
		//	break;
	}

	printf("%d\n", ret);
	return 0;	/* 반드시 return 0으로 해주셔야합니다. */
}