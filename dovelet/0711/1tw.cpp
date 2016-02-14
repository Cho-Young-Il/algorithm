#pragma warning(disable:4996)

#include <stdio.h>

int stack[10000];			//스택처럼 활용할 배열
int index[10000];			//답을 출력하기 위해 필요한 스택의 인덱스를 저장할 배열
int top = -1;				//스택의 탑을 가리키는 변수

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
			if (stack[top] < input)			//스택의 탑에 있는 값보다 입력값이 크다면
			{
				stack[top] = input;			//스택의 탑에 있는 값을 바꾸고
				index[top] = i;				//인덱스 배열의 값도 바꾸고
				top--;						//스택의 값을 뺀다.
			}
			else							//스택의 탑에 있는 값보다 작다면
			{
				printf("%d ", index[top] + 1);	//인덱스를 출력하고
				stack[top+1] = input;			//스택의 탑+1에 입력값을 저장하고
				index[top + 1] = i;				//인덱스배열에 현재 입력값의 인덱스를 넣어준다.
				top++;							//top이 가리키는 값 증가
				break;
			}
		}
		if (top==-1)				//스택이 비어있으면
		{
			printf("0 ");			//0을 출력하고
			stack[0] = input;		//입력값을 넣고
			index[0] = i;			//스택에 현재 인덱스를 넣고
			top = 0;				//top이 가리키는 값이 현재 스택의 top위치인 0
		}
	}
	return 0;
}