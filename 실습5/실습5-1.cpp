#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 5  //�ִ� ���� ũ��

//�Լ� ����
void push(char);
void pop();
void peek();

//���� ����ü
struct stack {
	char array[MAX_STACK_SIZE]; //�迭�� ���� �����
	int top = -1; //������ ���� ���� ����Ŵ
} stack;

int main(void) {
	//��1
	printf("��1���\n");
	push('A'); peek(); push('B'); peek(); push('C'); peek(); push('D'), push('E'), push('F'); pop(); pop(); push('D');
	peek(); push('E'); peek(); pop(); pop(); pop(); pop(); pop(); pop();

	stack.top = 0;  //�ٽ� ���� �ʱ�ȭ
	//��2
	printf("\n");
	printf("\n��2 ���\n");
	push('1'); pop(); push('2'); pop(); push('3'); pop();
	printf("\n");
	push('1'); push('2'); pop(); pop(); push('3'); pop();
	printf("\n");
	push('1'); pop(); push('2'); push('3'); pop(); pop();
	printf("\n");
	push('1'); push('2'); pop(); push('3'); pop(); pop();
	printf("\n");
	push('1'); push('2'); push('3'); pop(); pop(); pop();

	//3 1 2�� ������ ����� �����Ѱ�
}

//���ÿ� ���� �ֱ�
void push(char newone)
{
	//������ �� ���� ������
	if (stack.top < 4) {
		// ���ÿ� ���� ����
		stack.top++;
		stack.array[stack.top] = newone;
	}
	else {
		//������ �� á���� �����÷ο��� �˷��ֱ�
		printf("stack overflow ");
	}
}

//���ÿ��� ���� ������
void pop() {
	//������ ���������
	if (stack.top == -1) {
		//����ִٰ� �˷��ֱ�
		printf("stack empty ");
	}
	//�ƴ϶��
	else{
		//���� ���� �ϳ� ������ ���
		printf("%c ", stack.array[stack.top]);
		//���� ����
		stack.top--;
	}
}

//������ top ���� ���
void peek() {
	//���� ��������� ����ִٰ� ���
	if (stack.top == -1) {
		printf("stack empty ");
	}
	//�ƴ϶�� top���� ���
	else {
		printf("%c ", stack.array[stack.top]);
	}
}

