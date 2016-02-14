#include <stdio.h>
#include <math.h>

#define SWAP(x,y,t) ((t)=(x)),((x)=(y)),((y)=(t))

int get_big_digit(int num[])
{
	int ret = num[3]*1000+num[2]*100+num[1]*10+num[0];

	return ret;
}
int get_small_digit(int num[])
{
	int ret = num[0]*1000+num[1]*100+num[2]*10+num[3];

	return ret;
}

int main()
{
	int input;
	int count=0;

	scanf("%d",&input);
	
	while(input!=6174)
	{
		int temp;
		int arr[4];
		int big=0,small=0;
		arr[3]=input%10;
		arr[2]=(input%100)/10;
		arr[1]=(input%1000)/100;
		arr[0]=input/1000;

		for(int i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
			{
				if(arr[i]<arr[j])
					SWAP(arr[i],arr[j],temp);
			}
		}
		big=get_big_digit(arr);
		small=get_small_digit(arr);

		input=big-small;
		count++;
	}

	printf("%d",count);	

	return 0;
}