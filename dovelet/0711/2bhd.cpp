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
	stack[stack_top++] = 1000000001;			//스택이 -인덱스로가서 오버플로우 나는것을 막기 위해

	for (int i = 0; i < N; i++)
	{
		int input;								
		scanf("%d", &input);					//입력을 받아서
		while (stack[stack_top - 1] <= input)	//만약 입력값이 현재 스택의 최대값보다 크거나 같다면
		{
			stack_top--;						//스택을 하나빼주고(그 값은 현재 입력값의 머리를 볼 수 없으니까
		}
		sum += stack_top - 1;					//와일문이 종료 될 때의 스택 탑 = 현재 나를 볼 수 있는 소의 숫자
		stack[stack_top++] = input;				//스택에 입력값을 넣는다
	}
	printf("%lld", sum);						//합 출력
	return 0;
}