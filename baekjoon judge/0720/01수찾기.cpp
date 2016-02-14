#include <stdio.h>
#include <algorithm>

using namespace std;

int arr[100000]={0};

bool binSearch(int value,int n)
{
	int start=0;
	int end = n-1;
	int mid=(start+end)/2;

	while(end>start)
	{
		if(arr[mid]==value)
			return true;

		if(arr[mid]>value)
		{
			end=mid-1;
			mid = (start+end)/2;
		}
		else if(arr[mid]<value)
		{
			start=mid+1;
			mid = (start+end)/2;
		}
	}
	if(arr[mid]==value)
			return true;
	return false;
}
void quicksort(int left,int right)
{
	if(left+1>=right)
		return;

	//int pivot = left;
	int pivot = (left+right)/2;

	//printf("pivot : %d  left : %d  right : %d\n",pivot,left,right);
	//print();

	int temp=arr[pivot];	arr[pivot]=arr[left];	arr[left]=temp;
	
	pivot=left;		int j=right-1;		int i=left;		bool chk=true;
	while(i<j)
	{
		if(chk)
		{
			if(arr[pivot]<arr[j])
				j--;
			else
			{
				temp=arr[j];	arr[j]=arr[pivot];	arr[pivot]=temp;
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
				temp=arr[pivot];	arr[pivot]=arr[i];	arr[i]=temp;
				pivot=i;
				j--;
				chk=true;
			}
		}
	}
	//print();
	//printf("-----------------------------------------------\n");

	quicksort(left,i);
	quicksort(i+1,right);
}

int main()
{
	int n,m,input;
	scanf("%d",&n);

	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);

	quicksort(0,n);
	
	scanf("%d",&m);

	for(int i=0;i<m;i++)
	{
		scanf("%d",&input);
		if(binSearch(input,n))
			printf("1\n");
		else
			printf("0\n");	
	}
}