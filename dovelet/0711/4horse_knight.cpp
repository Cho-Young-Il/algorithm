#pragma warning(disable:4996)

#include <stdio.h>

int arr_horse[1000][1000] = { 0 };
int arr_night[1000][1000] = { 0 };
int Queue[1000000][2] = { 0 };
int front = 0;
int rear = 0;

int N, K;

//범위가 벗어나는지 검사하는 함수
bool isOutRange(int x, int y)
{
	if (x >= N || x < 0 || y >= N || y < 0)
		return false;
	return true;
}

//나이트와 마가 움직이는 함수
void bfs(int x, int y,bool isHorse)
{
	if (isOutRange(x-2,y-1))			//이동할 위치가 범위를 벗어났는지 체크
	{		
		if (!isHorse&&arr_night[x - 2][y - 1] == -2)			//나이트일때 이동할 위치가 비어있는 상태면
		{
			arr_night[x - 2][y - 1] = arr_night[x][y] + 1;		//현재 움직인 횟수 + 1
			Queue[rear][0] = x - 2, Queue[rear][1] = y - 1;		//큐에 이동할 위치를 넣는다
			rear++;
		}
		if (isHorse&&arr_horse[x - 1][y] != -1 && arr_horse[x - 2][y - 1] == -2)		//마일때 이동경로에 장애물이 없고 이동할 위치가 비어있는 상태면
		{
			arr_horse[x - 2][y - 1] = arr_horse[x][y] + 1;								//현재 움직인 횟수 + 1
			Queue[rear][0] = x - 2, Queue[rear][1] = y - 1;								//큐에 이동할 위치를 넣는다
			rear++;
		}
	}
	if (isOutRange(x-2,y+1))															//여기서부터 끝까지 위의 이프문 반복
	{
		if (!isHorse&&arr_night[x - 2][y + 1] == -2)
		{
			arr_night[x - 2][y + 1] = arr_night[x][y] + 1;
			Queue[rear][0] = x - 2, Queue[rear][1] = y + 1;
			rear++;
		}
		if (isHorse&&arr_horse[x - 1][y] != -1 && arr_horse[x - 2][y + 1] == -2)
		{
			arr_horse[x - 2][y + 1] = arr_horse[x][y] + 1;
			Queue[rear][0] = x - 2, Queue[rear][1] = y + 1;
			rear++;
		}
	}
	if (isOutRange(x - 1, y - 2))
	{
		if (!isHorse&&arr_night[x - 1][y - 2] == -2)
		{
			arr_night[x - 1][y - 2] = arr_night[x][y] + 1;
			Queue[rear][0] = x - 1, Queue[rear][1] = y - 2;
			rear++;
		}
		if (isHorse&&arr_horse[x][y - 1] != -1 && arr_horse[x - 1][y - 2] == -2)
		{
			arr_horse[x - 1][y - 2] = arr_horse[x][y] + 1;
			Queue[rear][0] = x - 1, Queue[rear][1] = y - 2;
			rear++;
		}
	}
	if (isOutRange(x - 1, y + 2))
	{
		if (!isHorse&&arr_night[x - 1][y + 2] == -2)
		{
			arr_night[x - 1][y + 2] = arr_night[x][y] + 1;
			Queue[rear][0] = x - 1, Queue[rear][1] = y + 2;
			rear++;
		}
		if (isHorse&&arr_horse[x][y + 1] != -1 && arr_horse[x - 1][y + 2] == -2)
		{
			arr_horse[x - 1][y + 2] = arr_horse[x][y] + 1;
			Queue[rear][0] = x - 1, Queue[rear][1] = y + 2;
			rear++;
		}
	}
	if (isOutRange(x+1,y-2))
	{
		if (!isHorse&&arr_night[x + 1][y - 2] == -2)
		{
			arr_night[x + 1][y - 2] = arr_night[x][y] + 1;
			Queue[rear][0] = x + 1, Queue[rear][1] = y - 2;
			rear++;
		}
		if (isHorse&&arr_horse[x][y - 1] != -1 && arr_horse[x + 1][y - 2] == -2)
		{
			arr_horse[x + 1][y - 2] = arr_horse[x][y] + 1;
			Queue[rear][0] = x + 1, Queue[rear][1] = y - 2;
			rear++;
		}
	}
	if (isOutRange(x+1,y+2))
	{
		if (!isHorse&&arr_night[x + 1][y + 2] == -2)
		{
			arr_night[x + 1][y + 2] = arr_night[x][y] + 1;
			Queue[rear][0] = x + 1, Queue[rear][1] = y + 2;
			rear++;
		}
		if (isHorse&&arr_horse[x][y + 1] != -1 && arr_horse[x + 1][y + 2] == -2)
		{
			arr_horse[x + 1][y + 2] = arr_horse[x][y] + 1;
			Queue[rear][0] = x + 1, Queue[rear][1] = y + 2;
			rear++;
		}
	}
	if (isOutRange(x+2,y-1))
	{
		if (!isHorse&&arr_night[x + 2][y - 1] == -2)
		{
			arr_night[x + 2][y - 1] = arr_night[x][y] + 1;
			Queue[rear][0] = x + 2, Queue[rear][1] = y - 1;
			rear++;
		}
		if (isHorse&&arr_horse[x + 1][y] != -1 && arr_horse[x + 2][y - 1] == -2)
		{
			arr_horse[x + 2][y - 1] = arr_horse[x][y] + 1;
			Queue[rear][0] = x + 2, Queue[rear][1] = y - 1;
			rear++;
		}
	}
	if (isOutRange(x+2,y+1))
	{
		if (!isHorse&&arr_night[x + 2][y + 1] == -2)
		{
			arr_night[x + 2][y + 1] = arr_night[x][y] + 1;
			Queue[rear][0] = x + 2, Queue[rear][1] = y + 1;
			rear++;
		}
		if (isHorse&&arr_horse[x + 1][y] != -1 && arr_horse[x + 2][y + 1] == -2)
		{
			arr_horse[x + 2][y + 1] = arr_horse[x][y] + 1;
			Queue[rear][0] = x + 2, Queue[rear][1] = y + 1;
			rear++;
		}
	}
}


int main()
{

	scanf("%d %d", &N,&K);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int input;
			scanf("%d",&input);
			arr_horse[i][j] = input - 2;
			arr_night[i][j] = input - 2;
		}
	}
	int startx, starty;
	scanf("%d %d", &startx, &starty);
	startx--, starty--;				
	
	arr_night[startx][starty] = 0;
	Queue[rear][0] = startx, Queue[rear][1] = starty;
	rear++;

	
	while (front < rear)						//스택이 빌때까지 
	{
		int pop_x = Queue[front][0],pop_y = Queue[front][1];
		front++;
		bfs(pop_x, pop_y, false);				//bfs실행
	}

	front = 0;
	rear = 0;
	arr_horse[startx][starty] = 0;
	Queue[rear][0] = startx, Queue[rear][1] = starty;
	rear++;

	while (front < rear)
	{
		int pop_x = Queue[front][0], pop_y = Queue[front][1];
		front++;
		bfs(pop_x, pop_y, true);
	}

	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arr_horse[i][j] < 0)
				arr_horse[i][j] = 999;
			if (arr_night[i][j] < 0)
				arr_night[i][j] = 999;

			if ((arr_night[i][j] < arr_horse[i][j]))
				sum++;
			
		}
	}

	printf("%d",sum);
	return 0;
}