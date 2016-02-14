#include <stdio.h>
#include <math.h>

#define SWAP(x,y,t) ((t)=(x)),((x)=(y)),((y)=(t))

int main()
{
	int input[3];
	int temp,sub1,sub2;
	for(int i=0;i<3;i++)
		scanf("%d",&input[i]);


	for(int i=0;i<3;i++)
	{
		for(int j=i;j<3;j++)
		{
			if(input[i]>input[j])
				SWAP (input[i],input[j],temp);
		}
	}
	sub1=input[2]-input[1];
	sub2=input[1]-input[0];

	if(sub1==sub2)
		printf("%d",input[2]+sub1);
	else if(sub1>sub2)
		printf("%d",input[2]-(sub1)/2);
	else
		printf("%d",input[1]-(sub2)/2);	

	return 0;
}