#include <stdio.h>
#include <math.h>

int main()
{
	int A[4],B[4];
	
	scanf("%d %d %d %d %d %d %d %d",&A[0],&A[1],&A[2],&A[3],&B[0],&B[1],&B[2],&B[3]);
	
	if(A[0]>B[2]||A[2]<B[0]||A[1]>B[3]||A[3]<B[1])
		printf("No overlap");
	else
		printf("Overlap");

	return 0;
}