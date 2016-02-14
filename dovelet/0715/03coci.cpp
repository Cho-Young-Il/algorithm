#include <stdio.h>
#include <math.h>

int main()
{
	int A[8];
	scanf("%d %d %d %d %d %d %d %d",&A[0],&A[1],&A[2],&A[3],&A[4],&A[5],&A[6],&A[7]);

	if(A[0]==1&&A[1]==2&&A[2]==3&&A[3]==4&&A[4]==5&&A[5]==6&&A[6]==7&&A[7]==8)
	{
		printf("ascending\n");
	}
	else if(A[0]==8&&A[1]==7&&A[2]==6&&A[3]==5&&A[4]==4&&A[5]==3&&A[6]==2&&A[7]==1)
	{
		printf("descending\n");
	}
	else
	{
		printf("mixed\n");
	}
	

	return 0;
}