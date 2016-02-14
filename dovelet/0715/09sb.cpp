#include <stdio.h>
#include <math.h>

int main()
{
	int input;
	int max=0,index=0;;

	for(int i=0;i<7;i++)
	{
		scanf("%d",&input);
		if(max<input)
		{
			max=input;
			index=i+1;
		}
	}
	printf("%d ",index);
	
	return 0;
}