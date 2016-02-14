#include <stdio.h>

long long gcd_func(long long a, long long b)
{
	if (a == 0)
		return 0;
	if (b == 0)
		return a;
	return gcd_func(b, a%b);
}

int main()
{
	long long w, l, div;
	scanf("%lld %lld", &w, &l);

	if (w < l)
	{
		int temp = w;
		w = l;
		l = temp;
	}

	div = gcd_func(w, l);

	printf("%lld", (w / div)*(l / div));


	return 0;
}
