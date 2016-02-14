#include <stdio.h>

int R, C, maxCourse = 0;
int map[110][110] = { 0, };
bool visit[110][110] = { false, };

void dfs(int row, int col, int depth)
{
	if (depth > maxCourse)
		maxCourse = depth;

	visit[row][col] = true;

	if (!visit[row + 1][col] && map[row + 1][col]<map[row][col])
		dfs(row + 1, col, depth + 1);

	if (!visit[row][col + 1] && map[row][col + 1]<map[row][col])
		dfs(row, col + 1, depth + 1);

	if (!visit[row - 1][col] && map[row - 1][col]<map[row][col])
		dfs(row - 1, col, depth + 1);

	if (!visit[row][col - 1] && map[row][col - 1]<map[row][col])
		dfs(row, col - 1, depth + 1);

	visit[row][col] = false;
}
void init()
{
	for (int i = 0; i<110; i++)
	{
		for (int j = 0; j<110; j++)
			map[i][j] = 999999;
	}
}

int main()
{
	scanf("%d %d", &R, &C);

	init();

	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
			scanf("%d", &map[i][j]);
	}

	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
			dfs(i, j, 0);
	}
	printf("%d\n", maxCourse + 1);
	return 0;
}