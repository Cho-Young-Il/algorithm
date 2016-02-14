#include <stdio.h>


int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	while (n != 1)
	{
		printf("%d ", m / n);

		int temp = n;
		n = m % n;
		m = temp;
		if (n == 0)
			break;
	}
	if (n != 0)
		printf("%d\n", m);


	return 0;
}