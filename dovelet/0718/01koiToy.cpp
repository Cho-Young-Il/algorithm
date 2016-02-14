#include <stdio.h>

int n, m;
int res[101];

struct toyInfo{
	int basisArr[100];
	int basisNum[100];
	int count;
};

bool isBasis[101] = { false, };	//false면 기본부품 true면 중간 혹은 완제품

toyInfo toy[101];

void toyFunc(int x,int cnt)
{
	for (int i = 0; i < toy[x].count; i++)
	{
		int index = toy[x].basisArr[i];
		int value = toy[x].basisNum[i]*cnt;
		res[index] += value;
		if (isBasis[index])
		{
			toyFunc(index, value);
		}
	}
}

int main()
{
	int cnt = 0;
	scanf("%d %d", &n,&m);

	for (int i = 1; i <= n; i++)
		toy[i].count = 0;


	for (int i = 0; i < m; i++)
	{
		int x, y, k;
		scanf("%d %d %d", &x, &y, &k);
		isBasis[x] = true;
		toy[x].basisArr[toy[x].count] = y;
		toy[x].basisNum[toy[x].count++] = k;
	}
	toyFunc(n,1);

	
	for (int i = 1; i <= n; i++)
	{
		if (!isBasis[i])
			cnt++;
	}
	printf("%d\n", cnt);
	for (int i = 1; i <= n; i++)
	{
		if (!isBasis[i])
			printf("%d %d\n", i, res[i]);
	}
	return 0;
}