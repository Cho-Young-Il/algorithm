#include <stdio.h>


int main()
{
	for (int a = 1; a <= 9; a++)
	{
		for (int b = 0; b <= 9; b++)
		{
			for (int c = 0; c <= 9; c++)
			{
				int numA = a*a*a;
				int numB = b*b*b;
				int numC = c*c*c;
				int cmpNum = 100 * a + 10 * b + c;

				if (cmpNum == (numA + numB + numC))
					printf("%d%d%d\n", a, b, c);
			}
		}
	}

	return 0;
}