#include <stdio.h>
#include <math.h>

int main()
{
	int input;
	
	scanf("%d",&input);
	while(input!=1)
	{
		printf("%d ",input);
		if(input%2==1)
			input=input*3+1;
		else
			input/=2;
	}
	printf("%d ",input);
	return 0;
}