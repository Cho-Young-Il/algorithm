#include <stdio.h>
#include <math.h>

int main()
{
	int input;
	int sum=1;
	int i;
	scanf("%d",&input);
	
	for(i=2;i*i<input;i++)
	{
		if(input%i==0)
			sum=sum+i+input/i;
	}
	if(i*i==input)
		sum+=i;
	if(sum==input)
		printf("yes\n");
	else
		printf("no\n");

	return 0;
}