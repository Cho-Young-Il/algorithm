#include <stdio.h>



//struct boy{				//입력 정보를 저장하는 배열
//	int arr[100];		//소년이 몇번째 소년이랑 비교했는지 저장하는 배열
//	bool big[100];		//소년이 큰지 작은지 내가 크면 1 작으면 0
//	int count;			//소년이 몇명이랑 비교를 했는지
//};
//bool visit[1000001] = { false, };

int n, m, front = 0, rear = 0;
int Q[500000000];
int start, end;
int cmp[1000001][2];
bool visit[1000001];
bool isPrintf = false;


void bfs_small(int x)			
{
	if (x == end)
		printf("yes\n"), isPrintf = true;
	for (int i = 0; i < m; i++)
	{
		if (!visit[i] && x == cmp[i][0])
		{
			Q[rear++] = cmp[i][1];
			visit[i] = true;
		}
	}
}

void bfs_big(int x)
{
	if (x == end)
		printf("no\n"), isPrintf = true;
	for (int i = 0; i < m; i++)
	{
		if (!visit[i] && x == cmp[i][1])
		{
			Q[rear++] = cmp[i][0];
			visit[i] = true;
		}
	}
}

int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++)
		scanf("%d %d", &cmp[i][0], &cmp[i][1]);

	scanf("%d %d", &start, &end);

	Q[rear++] = start;
	
	while (!isPrintf&&front < rear)
	{
		int pop = Q[front++];
		bfs_small(pop);
	}


	for (int i = 0; i < m; i++)
		visit[i] = false;

	rear = 0;
	front = 0;
	Q[rear++] = start;

	while (!isPrintf&& front < rear)
	{
		int pop = Q[front++];
		bfs_big(pop);
	}
	if (!isPrintf)
		printf("unknown\n");

	return 0;
}