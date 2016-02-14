#include <stdio.h>


int main()
{
	int x, y;

	scanf("%d %d",&x,&y);
	if((x-y>2||y-x>2)||x<y)
	{
		printf("No Number\n");
		return 0;
	}

	if(x%2==1 && y%2==1 )
		printf("%d\n",x+y-1);
	else if(x%2==0 && y%2==0)
		printf("%d\n",x+y);
	else
		printf("No Number\n");
	return 0;
}