#include <stdio.h>



//struct boy{				//�Է� ������ �����ϴ� �迭
//	int arr[100];		//�ҳ��� ���° �ҳ��̶� ���ߴ��� �����ϴ� �迭
//	bool big[100];		//�ҳ��� ū�� ������ ���� ũ�� 1 ������ 0
//	int count;			//�ҳ��� ����̶� �񱳸� �ߴ���
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