#include <stdio.h>


int main()
{
	bool check;

	for (int a = 1; a <= 9; a++)
	{
		for (int b = 1; b <= 9; b++)
		{
			for (int c = 1; c <= 9; c++)
			{
				int num1 = a * 100 + b * 10 + c;
				int num2 = c * 100 + c * 10 + a;
				int cmpNum = 1000 + 100 * a + 10 * b + 2;

				if (cmpNum == (num1 + num2))
					printf("%d%d%d\n", a, b, c);
			}
		}
	}

	return 0;
}