#include <stdio.h>

int main()
{
	int n, u, d;

	scanf("%d %d %d", &n, &u, &d);
	while (n != 0)
	{
		int cnt = 0;
		for (int move = 0;;)
		{
			move += u;
			cnt++;
			if (move >= n)
				break;
			move -= d;
			cnt++;
		}
		printf("%d\n", cnt);
		scanf("%d %d %d", &n, &u, &d);
	}
	return 0;
}