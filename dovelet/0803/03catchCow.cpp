#include <stdio.h>

int Q[3000000];
int front = 0, rear = 0, n, k;
int visit[200001] = { 0, };

void bfs(int x)
{
	if (x<0 || x>100000)		return;
	if (!visit[x * 2])
	{
		Q[rear++] = x * 2;
		visit[x * 2] = visit[x] + 1;
	}
	if (!visit[x + 1])
	{
		Q[rear++] = x + 1;
		visit[x + 1] = visit[x] + 1;
	}
	if (!visit[x - 1])
	{
		Q[rear++] = x - 1;
		visit[x - 1] = visit[x] + 1;
	}
}

int main()
{
	int cnt = 0;
	scanf("%d %d", &n, &k);

	Q[rear++] = n;
	visit[n] = 1;
	while (front<rear)
	{
		int pop = Q[front++];
		bfs(pop);
		if (pop == k)
			break;
	}
	printf("%d\n", visit[k] - 1);
	return 0;
}