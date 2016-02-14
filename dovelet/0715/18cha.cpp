#include <stdio.h>
#include <math.h>

int main()
{
	int a,b,sub;
	scanf("%d %d",&a,&b);
	printf("%d %d ",a,b);
	sub=a-b;

	while(sub>=0)
	{
		printf("%d ",sub);
		a=b;
		b=sub;
		sub=a-b;
	}

	return 0;
}