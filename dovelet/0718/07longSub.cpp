#include <stdio.h>




int strlen(char arr[])
{
	int len = 0;
	while (arr[len] != '\0')
		len++;

	return len;
}

void longSub(char arr1[],char arr2[],int len1,int len2)
{
	int res[101] = { 0, }, cnt = 0;
	for (int i = len2; i >= 0; i--)
	{
		res[cnt] += arr1[len1--] - arr2[i];
		if (res[cnt] < 0)
		{
			res[cnt] += 10;
			res[cnt + 1] -= 1;
		}
		cnt++;
	}
	while (len1 >= 0)
	{
		res[cnt] += arr1[len1];
		if (res[cnt] < 0)
		{
			res[cnt] += 10;
			res[cnt + 1] -= 1;
		}
		cnt++;
		len1--;
	}

	cnt--;
	while (res[cnt] == 0)
		cnt--;

	for (int i = cnt; i >= 0; i--)
	{
		printf("%d", res[i]);
	}


}

int main()
{
	bool isMinus = false;
	char input1[101], input2[101];
	int len1, len2;

	scanf("%s", input1);	scanf("%s", input2);
	len1 = strlen(input1),	len2 = strlen(input2);

	if (len2 > len1)
		isMinus = true;
	else if (len2 == len1)
	{
		int index = 0;
		while (index < len1)
		{
			if (input1[index] > input2[index])
				break;
			else if (input1[index] < input2[index])
			{
				isMinus = true;
				break;
			}
			index++;
			if (index == len1)
				printf("0\n");
		}		
	}

	for (int i = 0; i < len1; i++)
		input1[i] -= '0';
	for (int i = 0; i < len2; i++)
		input2[i] -= '0';


	if (isMinus)
	{
		printf("-");
		longSub(input2,input1,len2-1,len1-1);
	}
	else	
		longSub(input1,input2,len1-1,len2-1);

	return 0;
}