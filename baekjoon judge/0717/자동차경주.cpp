#include <stdio.h>

int n, m;

int Q[10000000];
int front = 0, rear = 0;

int map[1010][1010] = { 0, };
int arr[1010][2] = { 0, };
int res[1000] = { 0, };

void bfs(int x)
{
	for (int i = 1; i <= n; i++)
	{
		if (map[x][i] != 0)
		{
			if (arr[i][0] < arr[x][0] + map[x][i])
			{
				arr[i][0] = arr[x][0] + map[x][i];
				arr[i][1] = x;
				Q[rear++] = i;
				//map[x][i] = 0;
			}
		}
	}
}

int main()
{
	scanf("%d %d", &n,&m);
	//n = 8, m = 13;
	n++;
	for (int i = 0; i < m; i++)
	{
		int p,q,r;
		scanf("%d %d %d", &p,&q,&r);
		if(q==1)
			q = n;
		map[p][q] = r;

	}
	/*map[1][2] = 5;
	map[1][3] = 4;
	map[2][5] = 2;
	map[2][6] = 1;
	map[3][6] = 3;
	map[5][6] = 7;
	map[5][8] = 9;
	map[6][8] = 3;
	map[4][9] = 6;
	map[6][4] = 8;
	map[7][4] = 5;
	map[6][7] = 2;
	map[8][7] = 4;*/

	for (int i = 2; i < n; i++)
	{
		if (map[1][i] != 0)
		{
			Q[rear++] = i;
			arr[i][0] = map[1][i];
			arr[i][1] = 1;
		}
	}

	while (front < rear)
	{
		int pop = Q[front++];
		bfs(pop);
	}

	printf("%d\n", arr[n][0]);
	
	int resIdx = 0;

	int x = arr[n][1];
	res[resIdx++] = x;
	while (x!=1)
	{
		//printf("%d ",arr[x][1]);
		res[resIdx++] = arr[x][1];
		x = arr[x][1];
	}
	
	for (int i = resIdx - 1; i >= 0; i--)
		printf("%d ",res[i]);
	printf("1\n");


	return 0;
}