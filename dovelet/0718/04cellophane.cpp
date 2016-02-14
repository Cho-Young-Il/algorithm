#include <stdio.h>

bool cellophane[21][21][3] = { 0, };		//0»¡°­R		1³ë¶ûY		2ÆÄ¶ûB


void addColor(char color, int startx, int starty, int endx, int endy)
{
	for (int i = startx; i < endx; i++)
	{
		for (int j = starty; j < endy; j++)
		{
			if (color == 'R')
			{
				cellophane[i][j][0] = true;
			}
			if (color == 'Y')
			{
				cellophane[i][j][1] = true;
			}
			if (color == 'B')
			{
				cellophane[i][j][2] = true;
			}
		}
	}
}

char isColor(int x, int y)		//Èò0 »¡°­1 ³ë¶û2 ÆÄ¶û4
{
	int res = 0;
	if (cellophane[x][y][0])
		res += 1;
	if (cellophane[x][y][1])
		res += 2;
	if (cellophane[x][y][2])
		res += 4;

	if (res == 1)
		return 'R';
	if (res == 2)
		return 'Y';
	if (res == 3)
		return 'O';
	if (res == 4)
		return 'B';
	if (res == 5)
		return 'M';
	if (res == 6)
		return 'G';
	if (res == 7)
		return 'K';

	return 'W';
}

int checkColor(char color)
{
	int sum = 0;

	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (color == isColor(i, j))
				sum++;
		}
	}

	return sum;
}

int main()
{
	int n, startx, starty, endx, endy,res;
	char color;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("\n%c", &color);
		scanf("%d %d %d %d", &startx, &endy, &endx, &starty);

		addColor(color,startx,starty,endx,endy);
	}

	scanf("\n%c", &color);
	res = checkColor(color);

	printf("%d\n",res);

	return 0;
}