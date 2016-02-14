#include <stdio.h>
#include <math.h>

int main()
{
	int A, B;
	int a, b;
	int cnt = 0;
	scanf("%d %d", &A, &B);
	A--;

	a = (int)(sqrt((double)A));
	b = (int)(sqrt((double)B));

	cnt -= (A - a);
	cnt += (B - b);

	printf("%d", cnt);

	return 0;
}