#include <stdio.h>

long long Fibo[42];


int main()
{
	int n, testCase = 1;
	Fibo[1] = 1, Fibo[2] = 1;

	for (int i = 3; i < 42; i++)
		Fibo[i] = Fibo[i - 2] + Fibo[i - 1];

	scanf("%d", &n);

	while (n >= 2)
	{
		if (n % 2 == 0)
			printf("Case #%d:\n%lld, %lld\n", testCase, Fibo[n + 1], Fibo[n]);
		else
			printf("Case #%d:\n%lld, %lld\n", testCase, Fibo[n], Fibo[n + 1]);
		scanf("%d", &n);
	}

	return 0;
}
