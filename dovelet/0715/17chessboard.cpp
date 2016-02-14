#include <stdio.h>
#include <math.h>


int main()
{
	int x, moveLen, moveDirection = 1;
	int input;
	scanf("%d", &input);

	x = (int)sqrt((double)input);

	moveLen = input - (x*x);

	if (moveLen >= x + 1)
	{
		moveLen %= (x + 1);
		moveDirection = 0;
	}



	if (x % 2 == 0)
	{
		if (x*x == input)
			printf("%d %d", x, 1);
		else if (moveDirection)
			printf("%d %d\n", x + 1, moveLen);
		else
			printf("%d %d\n", x + 1 - moveLen, x + 1);
	}
	else
	{
		if (x*x == input)
			printf("%d %d", 1, x);
		else if (moveDirection)
			printf("%d %d\n", moveLen, x + 1);
		else
			printf("%d %d\n", x + 1, x + 1 - moveLen);
	}

	//printf("No Number\n");
	return 0;
}