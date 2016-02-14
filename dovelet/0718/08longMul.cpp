#include <stdio.h>

int res[410] = { 0, };


int strlen(char arr[])
{
	int len = 0;
	while (arr[len] != '\0')
		len++;

	return len;
}

void longMul(char arr1[], char arr2[], int len1, int len2)
{
	
	for (int i = len1; i >= 0; i--)
	{
		for (int j = len2; j >= 0; j--)
		{
			int index = (len1 - i) + (len2 - j);
			res[index] += arr1[i] * arr2[j];
			if (res[index] >= 10)
			{
				res[index + 1] += res[index] / 10;
				res[index] %= 10;
			}
		}
	}
	int index = len1 + len2 + 2;
	while (res[index] == 0)
		index--;

	for (int i = index; i >=0; i--)
		printf("%d",res[i]);

}

int main()
{
	char input1[201], input2[201];
	int len1, len2;

	scanf("%s", input1);	scanf("%s", input2);
	len1 = strlen(input1), len2 = strlen(input2);

	if (((len1 == 1) && (input1[0] == '0')) || ((len2 == 1) && (input2[0] == '0')))
	{
		printf("0\n");
		return 0;
	}


	for (int i = 0; i < len1; i++)
		input1[i] -= '0';
	for (int i = 0; i < len2; i++)
		input2[i] -= '0';

	longMul(input1, input2, len1 - 1, len2 - 1);

	return 0;
}