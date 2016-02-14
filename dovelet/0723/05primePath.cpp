#include <stdio.h>

int Q[100000];
int visit[10000] = { 0, };

int front = 0, rear = 0;

bool isPrime(int value)
{
	if (value % 2 == 0 && value != 2)
		return false;

	for (int i = 3; i*i <= value; i += 2)
	{
		if (value%i == 0)
			return false;
	}

	return true;
}

int changeNum(int value,int disit,int change)
{
	int arr[4] = { 0, };

	arr[0] = value / 1000;
	arr[1] = value / 100 - arr[0] * 10;
	arr[2] = value / 10 - arr[1] * 10 - arr[0] * 100;
	arr[3] = value % 10;

	if ((arr[disit] != change)&&!(disit==0&&change==0))
		arr[disit] = change;

	return arr[0] * 1000 + arr[1] * 100 + arr[2] * 10 + arr[3];
}


void bfs(int value)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			int ret = changeNum(value, i, j);
			if (isPrime(ret) && visit[ret] == 0&&ret!=value)
			{
				Q[rear++] = ret;
				visit[ret] = visit[value] + 1;
			}
		}
	}


}

int main()
{
	int src, dst, cnt = 0;;

	scanf("%d %d",&src,&dst);
	
	Q[rear++] = src;

	while (front<rear)
	{
		int pop = Q[front++];
		
		if (pop == dst)
			break;

		bfs(pop);
	}

	printf("%d\n", visit[dst]);

	return 0;
}