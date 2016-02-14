#include <stdio.h>

int bin[8] = { 0, };


void hexToBin(char hex1,char hex0)
{
	int ret1 = 0,ret0;
	
	if (hex1 <= '9')		ret1 = hex1 - '0';
	else					ret1 = hex1 - 'A'+10;
	
	if (hex0 <= '9')		ret0 = hex0 - '0';
	else					ret0 = hex0 - 'A'+10;

	int len = 3;
	while (len >= 0)
	{
		bin[len--] = ret1 % 2;
		ret1 /= 2;
	}
	
	len = 7;
	while (len >= 4)
	{
		bin[len--] = ret0 % 2;
		ret0 /= 2;
	}
	
	for (int i = 0; i < 4; i++)
	{
		int temp = bin[i];
		bin[i] = bin[7 - i];
		bin[7 - i] = temp;
	}

	len = 3;
	int t = 1;
	while (len >= 0)
	{
		ret1 += bin[len--] * t;
		t *= 2;
	}

	len = 7;
	t = 1;
	while (len >= 4)
	{
		ret0 += bin[len--] * t;
		t *= 2;
	}

	if (ret1 <= 9)		hex1 = ret1 + '0';
	else				hex1 = ret1 + 'A'-10;

	if (ret0 <= 9)		hex0 = ret0 + '0';
	else				hex0 = ret0 + 'A'-10;

	printf("%c%c\n",hex1,hex0);

}

int main()
{
	char hex1,hex0;
	scanf("%c%c", &hex1,&hex0);

	hexToBin(hex1,hex0);

	printf("");
	return 0;
}