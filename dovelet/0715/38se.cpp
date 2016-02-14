#include <stdio.h>

int seFunc(int value, int disit)
{
	int idx = 0;;
	int arr[10];

	while (value > 0)
	{
		arr[idx++] = value % 10;
		value /= 10;
	}

	return arr[idx - disit];
}

int main()
{
	int n, i, cnt = 0;
	int sub;
	scanf("%d", &n);

	for (i = 1; cnt < n; i++)
	{
		int temp = cnt;
		if (i < 10)
			cnt += 1;
		else if (i < 100)
			cnt += 2;
		else if (i< 1000)
			cnt += 3;
		else if (i< 10000)
			cnt += 4;
		else if (i< 100000)
			cnt += 5;
		else if (i< 10000000)
			cnt += 6;
		else if (i< 100000000)
			cnt += 7;
		sub = cnt - temp;
	}
	if (cnt == n)
		printf("%d", (i - 1) % 10);
	else if (cnt>n)
		printf("%d", seFunc(i - 1, (n - (cnt - sub))));

	return 0;
}