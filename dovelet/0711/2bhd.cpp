#pragma warning(disable:4996)

#include <stdio.h>

int stack[80000];								
int stack_top = 0;

int main()
{
	int N;

	int top = -1;
	long long sum = 0;

	scanf("%d", &N);
	stack[stack_top++] = 1000000001;			//������ -�ε����ΰ��� �����÷ο� ���°��� ���� ����

	for (int i = 0; i < N; i++)
	{
		int input;								
		scanf("%d", &input);					//�Է��� �޾Ƽ�
		while (stack[stack_top - 1] <= input)	//���� �Է°��� ���� ������ �ִ밪���� ũ�ų� ���ٸ�
		{
			stack_top--;						//������ �ϳ����ְ�(�� ���� ���� �Է°��� �Ӹ��� �� �� �����ϱ�
		}
		sum += stack_top - 1;					//���Ϲ��� ���� �� ���� ���� ž = ���� ���� �� �� �ִ� ���� ����
		stack[stack_top++] = input;				//���ÿ� �Է°��� �ִ´�
	}
	printf("%lld", sum);						//�� ���
	return 0;
}