#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 5  //최대 스택 크기

//함수 선언
void push(char);
void pop();
void peek();

//스택 구조체
struct stack {
	char array[MAX_STACK_SIZE]; //배열로 스택 만들기
	int top = -1; //제거할 스택 원소 가리킴
} stack;

int main(void) {
	//예1
	printf("예1출력\n");
	push('A'); peek(); push('B'); peek(); push('C'); peek(); push('D'), push('E'), push('F'); pop(); pop(); push('D');
	peek(); push('E'); peek(); pop(); pop(); pop(); pop(); pop(); pop();

	stack.top = 0;  //다시 스택 초기화
	//예2
	printf("\n");
	printf("\n예2 출력\n");
	push('1'); pop(); push('2'); pop(); push('3'); pop();
	printf("\n");
	push('1'); push('2'); pop(); pop(); push('3'); pop();
	printf("\n");
	push('1'); pop(); push('2'); push('3'); pop(); pop();
	printf("\n");
	push('1'); push('2'); pop(); push('3'); pop(); pop();
	printf("\n");
	push('1'); push('2'); push('3'); pop(); pop(); pop();

	//3 1 2의 순서로 출력이 가능한가
}

//스택에 원소 넣기
void push(char newone)
{
	//스택이 꽉 차지 않으면
	if (stack.top < 4) {
		// 스택에 원소 삽입
		stack.top++;
		stack.array[stack.top] = newone;
	}
	else {
		//스택이 꽉 찼으면 오버플로우라고 알려주기
		printf("stack overflow ");
	}
}

//스택에서 원소 꺼내기
void pop() {
	//스택이 비어있으면
	if (stack.top == -1) {
		//비어있다고 알려주기
		printf("stack empty ");
	}
	//아니라면
	else{
		//스택 원소 하나 꺼내서 출력
		printf("%c ", stack.array[stack.top]);
		//원소 제거
		stack.top--;
	}
}

//스택의 top 원소 출력
void peek() {
	//스택 비어있으면 비어있다고 출력
	if (stack.top == -1) {
		printf("stack empty ");
	}
	//아니라면 top원소 출력
	else {
		printf("%c ", stack.array[stack.top]);
	}
}

