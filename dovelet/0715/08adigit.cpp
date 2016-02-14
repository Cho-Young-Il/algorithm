#include <stdio.h>
#include <math.h>

int main()
{
	int input;
	int sum[3] = { 0, };
	for (int i = 0; i < 7; i++)
	{
		scanf("%d",&input);
		if ((input / 100) != 0)
			sum[2] += input;
		else if ((input / 10) != 0)
			sum[1] += input;
		else
			sum[0] += input;
	}
	for (int i = 0; i < 3; i++)
		printf("%d ", sum[i]);



	return 0;
}