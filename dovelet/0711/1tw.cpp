#pragma warning(disable:4996)

#include <stdio.h>

int stack[10000];			//����ó�� Ȱ���� �迭
int index[10000];			//���� ����ϱ� ���� �ʿ��� ������ �ε����� ������ �迭
int top = -1;				//������ ž�� ����Ű�� ����

int main()
{
	int N;
	
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++)
	{
		int input;
		scanf("%d", &input);
		while (top >= 0)
		{
			if (stack[top] < input)			//������ ž�� �ִ� ������ �Է°��� ũ�ٸ�
			{
				stack[top] = input;			//������ ž�� �ִ� ���� �ٲٰ�
				index[top] = i;				//�ε��� �迭�� ���� �ٲٰ�
				top--;						//������ ���� ����.
			}
			else							//������ ž�� �ִ� ������ �۴ٸ�
			{
				printf("%d ", index[top] + 1);	//�ε����� ����ϰ�
				stack[top+1] = input;			//������ ž+1�� �Է°��� �����ϰ�
				index[top + 1] = i;				//�ε����迭�� ���� �Է°��� �ε����� �־��ش�.
				top++;							//top�� ����Ű�� �� ����
				break;
			}
		}
		if (top==-1)				//������ ���������
		{
			printf("0 ");			//0�� ����ϰ�
			stack[0] = input;		//�Է°��� �ְ�
			index[0] = i;			//���ÿ� ���� �ε����� �ְ�
			top = 0;				//top�� ����Ű�� ���� ���� ������ top��ġ�� 0
		}
	}
	return 0;
}