#include <stdio.h>


int main()
{
	bool check;

	for (int i = 1; i <= 10000; i++)
	{
		check = true;
		for (int j = 1; j*j < i; j++)
		{
			if (i%j != 0)
			{
				check = false;
				break;
			}
		}
		if (check)
			printf("%d\n", i);
	}

	return 0;
}