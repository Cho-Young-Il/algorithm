#include <stdio.h>
#include <math.h>

int main()
{
	int input;
	int i;
	int sum=0;
	
	for(i=0;i<5;i++)
	{
		scanf("%d",&input);
		sum+=input*input;
	}
	printf("%d\n",sum%10);

	return 0;
}