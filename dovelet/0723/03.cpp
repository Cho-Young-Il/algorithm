#include <stdio.h>

int n, b;
int map[130][130] = { 0 };
int max = 0;
int dir[4][2] = { { 0, 1 }, { 0, -1 }, { -1, 0 }, { 1, 0 } };

void dfs(int x, int y, int direction, int value)
{
	int nextX = x + dir[direction][0];
	int nextY = y + dir[direction][1];


	//if (map[nextX][nextY] == 2)
	{
		if (max<value)
			max = value;
	}
	if (map[nextX][nextY] == 1)
	{
		map[nextX][nextY] = 2;
		dfs(nextX, nextY, direction, value + 1);
		map[nextX][nextY] = 1;
	}
	if (map[nextX][nextY] == 0)
	{
		if (direction == 0 || direction == 1)
		{
			for (int i = 2; i <= 3; i++)
			{
				nextX = x + dir[i][0];
				nextY = y + dir[i][1];
				if (map[nextX][nextY] == 1)
				{
					map[nextX][nextY] = 2;
					dfs(nextX, nextY, i, value + 1);
					map[nextX][nextY] = 1;
				}
			}

		}
		else
		{
			for (int i = 0; i <= 1; i++)
			{
				nextX = x + dir[i][0];
				nextY = y + dir[i][1];
				if (map[nextX][nextY] == 1)
				{
					map[nextX][nextY] = 2;
					dfs(nextX, nextY, i, value + 1);
					map[nextX][nextY] = 1;
				}
			}
		}
	}
}

int main()
{
	
	scanf("%d %d", &n, &b);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			map[i][j] = 1;
		}
	}


	for (int i = 0; i<b; i++)
	{
		char y; int x;
		scanf("\n%c%d", &y, &x);

		map[x][y - 'A' + 1] = 0;
	}

	map[1][1] = 2;
	dfs(1, 1, 0, 1);
	dfs(1, 1, 3, 1);



	printf("%d\n", max);

	return 0;
}