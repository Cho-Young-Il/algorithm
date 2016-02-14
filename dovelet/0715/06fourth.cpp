	#include <stdio.h>
#include <math.h>

int main()
{
	int x[3],y[3];
	
	scanf("%d %d %d %d %d %d",&x[0],&y[0],&x[1],&y[1],&x[2],&y[2]);

	if(x[0]==x[1])
		printf("%d ",x[2]);
	else if(x[0]==x[2])
		printf("%d ",x[1]);
	else
		printf("%d ",x[0]);

	if(y[0]==y[1])
		printf("%d ",y[2]);
	else if(y[0]==y[2])
		printf("%d ",y[1]);
	else
		printf("%d ",y[0]);


	return 0;
}