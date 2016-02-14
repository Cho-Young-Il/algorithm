#include <stdio.h>
#include <math.h>

int main()
{
	int a,b,c;
	
	scanf("%d %d %d",&a,&b,&c);

	printf("0.");
	for(int i=0;i<c;i++)
	{
		a*=10;
		
		printf("%d",a/b);

		a %=b;
	}
	return 0;
}