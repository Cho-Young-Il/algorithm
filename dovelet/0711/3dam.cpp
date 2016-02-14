#pragma warning(disable:4996)

#include <stdio.h>

int n;
int arr[100][100] = { 0 };
int Queue[100000][2] = { 0 };
int front = 0;
int rear = 0;

void bfs(int x, int y)
{
	if (x + 1 < n)
	{
		if (arr[x + 1][y] == -2)
		{
			Queue[rear][0] = x + 1;
			Queue[rear][1] = y;
			arr[x + 1][y] = arr[x][y] + 1;
			rear++;
		}
	}
	if (y + 1 < n)
	{
		if (arr[x][y + 1] == -2)
		{
			Queue[rear][0] = x;
			Queue[rear][1] = y + 1;
			arr[x][y + 1] = arr[x][y] + 1;
			rear++;
		}
	}
	if (x -1 >= 0)
	{
		if (arr[x - 1][y] == -2)
		{
			Queue[rear][0] = x - 1;
			Queue[rear][1] = y;
			arr[x - 1][y] = arr[x][y] + 1;
			rear++;
		}
	}
	if (y- 1 >=0)
	{
		if (arr[x ][y-1] == -2)
		{
			Queue[rear][0] = x;
			Queue[rear][1] = y-1;
			arr[x][y - 1] = arr[x][y] + 1;
			rear++;
		}
	}
}

int main()
{
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int input;
			scanf("%d", &input);
			arr[i][j] = input - 2;
		}
	}
	
	int startx, starty;
	scanf("%d %d",&starty,&startx);
	startx--,starty--;
	int K;
	scanf("%d", &K);
	arr[startx][starty] = 0;
	Queue[rear][0] = startx,Queue[rear][1] = starty;
	rear++;

	while (front<rear)
	{
		int pop_value[2];
		pop_value[0] = Queue[front][0],pop_value[1] = Queue[front][1];
		front++;
		if (arr[pop_value[0]][pop_value[1]]!=-1)
			bfs(pop_value[0],pop_value[1]);
		if (arr[pop_value[0]][pop_value[1]] > K)
			break;
	}
	
	int sum = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == K)
				sum++;
		}
	}
	if (sum == 0)
		printf("OH, MY GOD");
	else
		printf("%d",sum);
	return 0;
}