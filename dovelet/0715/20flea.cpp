#include <stdio.h>
int S, x, y, dx, dy;

bool isBlackFunc()
{
	bool ret = false;
	if (((x / S) % 2 == 1) && ((y / S) % 2 == 1))
		ret = true;
	else if (((x / S) % 2 == 0) && (y / S) % 2 == 0)
		ret = true;

	if (((x%S == 0) || (y%S == 0)))
		ret = false;

	return ret;
}

int main()
{

	bool isBlack = false;
	int count = 0;
	scanf("%d %d %d %d %d", &S, &x, &y, &dx, &dy);


	if ((isBlackFunc()) && (((S%dx == 0) && ((S%dy == 0)))) && ((dx != 1) && (dy != 1)))
	{
		printf("The flea cannot escape from black squares.\n");
		return 0;
	}
	else if (!isBlackFunc() && ((S%dx == 0) && (dx != 1)) && ((S%dy == 0)))
	{
		printf("After %d jumps the flea lands at (%d, %d).\n", count, x, y);
		return 0;
	}

	while (isBlackFunc())
	{
		x += dx;
		y += dy;
		count++;

		if (x%S == 0 || y%S == 0)
		{
			x += dx;
			y += dy;
			count++;
		}
	}

	if (count == 0)
		printf("The flea cannot escape from black squares.\n");
	else
		printf("After %d jumps the flea lands at (%d, %d).\n", count, x, y);

	return 0;
}
