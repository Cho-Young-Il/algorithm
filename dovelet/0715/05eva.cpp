#include <stdio.h>
#include <math.h>

int main()
{
	int a,b,c,d;
	scanf("%d %d %d %d",&a,&b,&c,&d);

	if(b-a==c-b)
		printf("%d %d %d %d %d\n",a,b,c,d,d+b-a);
	else
		printf("%d %d %d %d %d\n",a,b,c,d,d*(c/b));
	return 0;
}