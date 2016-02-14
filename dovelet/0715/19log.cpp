#pragma warning(disable:4996)

#include <stdio.h>

int main()
{
	int input, sum = 0, i;

	scanf("%d", &input);

	for (i = 1; sum < input; i++)
	{
		sum += i;
	}
	i--;
	printf("%d ", i);


	sum -= input;
	for (i = 1; sum > i; i++)
	{
		sum -= i;
	}
	if (i == sum)
		printf("%d", i + 1);
	else
		printf("%d", i - sum);

	return 0;
}