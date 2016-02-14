#include <stdio.h>

int nineTodec(int input)
{
	int ret = input % 10;
	int mul = 9;
	input /= 10;
	if (ret > 3)
		ret--;
	while (input > 0)
	{
		int div = input % 10;
		if (div > 3)
			div--;
		ret += (div)*mul;
		mul *= 9;
		input /= 10;
	}


	return ret;
}

int main()
{
	int input, res;

	scanf("%d", &input);

	printf("%d: %d\n", input, nineTodec(input));
	return 0;
}