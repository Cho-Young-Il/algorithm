#include <stdio.h>
#include <stdlib.h>
//int arr[100]={3,1,5,6,7,8,9,10,2,11,3,1,5,6,7,8,9,10,2,11,3,1,5,6,7,8,9,10,2,11,3,1,5,
//	6,7,8,9,10,2,11,3,1,5,6,7,8,9,10,2,11,3,1,5,6,7,8,9,10,2,11,3,1,5,6,7,8,9,10,2,11,
//	3,1,5,6,7,8,9,10,2,11,3,1,5,6,7,8,9,10,2,11,3,1,5,6,7,8,9,10,2,11};

int arr[100000];

//int arr[9]={41,62,13,84,35,96,57,28,79};
int n=9;

int count=0;
void print()
{
	for(int i=0;i<n;i++)
		printf("%d ",arr[i]);

	printf("\n");
}

void quickSort(int left,int right)
{
	if(left+1>=right)
		return;

	//int pivot = left;
	int pivot = (left+right)/2;


	//printf("pivot : %d  left : %d  right : %d\n",pivot,left,right);
	//print();


	int temp=arr[pivot];
	arr[pivot]=arr[left];
	arr[left]=temp;
	
	pivot=left;
	int j=right-1;
	int i=left;
	bool chk=true;
	while(i<j)
	{
		count++;
		if(chk)
		{
			if(arr[pivot]<arr[j])
				j--;
			else
			{
				temp=arr[j];
				arr[j]=arr[pivot];
				arr[pivot]=temp;
				pivot=j;
				i++;
				chk=false;
			}
		}
		else
		{
			if(arr[pivot]>arr[i])
				i++;
			else
			{
				temp=arr[pivot];
				arr[pivot]=arr[i];
				arr[i]=temp;
				pivot=i;
				j--;
				chk=true;
			}
		}
	}
	//print();
	//printf("-----------------------------------------------\n");

	quickSort(left,i);
	quickSort(i+1,right);
}

int main()
{
	for(int i=0;i<100000;i++)
		arr[i]=rand()%100;
	n=100000;
	quickSort(0,n);

	print();
	printf("\ncount : %d\n",count);
	return 0;
}