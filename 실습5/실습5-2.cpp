#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 10 //�ִ� ť ũ��

//�Լ� ����
void enqueue(char);
void dequeue();
void peek();

//ť ����ü
struct queue {
	char array[MAX_QUEUE_SIZE]; //�迭�� ���� ȯ�� ť
	int front = 0; //front �ε���
	int rear = 0; //rear �ε���
} queue;

int main(void)
{
	//��1
	printf("��1\n");
	enqueue('A'); peek(); enqueue('B'); peek(); enqueue('C'); peek(); dequeue(); dequeue();
	enqueue('D'); peek(); enqueue('E'); peek(); dequeue(); dequeue(); dequeue(); dequeue();

	//��2
	printf("\n\n��2\n");
	queue.rear = queue.front = 0; //ť �ʱ�ȭ
	enqueue('A'); dequeue(); enqueue('B'); dequeue(); enqueue('C'); dequeue(); dequeue();
	printf("\n");
	queue.rear = queue.front = 0; //ť �ʱ�ȭ
	enqueue('A'); enqueue('B'); enqueue('C'); enqueue('D'); enqueue('E'); enqueue('F');
	enqueue('G'); enqueue('H'); enqueue('I'); dequeue(); peek(); enqueue('J'); enqueue('K');

}

//ť ���� ���� �Լ�
void enqueue(char newone)
{
	//ť�� ��ȭ ���¸� overflow��� �˷��ֱ�
	if (queue.front == (queue.rear + 1) % MAX_QUEUE_SIZE)
		printf("\"queue overflow\" ");
	//��ȭ���� �ƴϸ� rear index 1 �÷��� �ű⿡ ���� �߰�
	else {
		queue.rear = (queue.rear + 1) % MAX_QUEUE_SIZE;
		queue.array[queue.rear] = newone;
	}
}

//ť ���� ���� �Լ�
void dequeue()
{
	//ť�� ��������� ť�� ����ִٰ� �˷��ֱ�
	if (queue.front == queue.rear)
		printf("\"queue empty\" ");
	//��� �ƴ϶�� front �ε��� 1 �߰��ؼ� ������ ���� ���
	else {
		queue.front = (queue.front + 1) % MAX_QUEUE_SIZE;
		printf("%c ", queue.array[queue.front]);
	}
}

//������ ������ ���� ���
void peek()
{
	//ť�� ��������� ����ִٰ� �˷��ֱ�
	if (queue.front == queue.rear)
		printf("\"queue empty\" ");
	//ť�� �Ⱥ�������� ������ ������ ���� �˷��ֱ�
	else {
		printf("%c ", queue.array[queue.front + 1]);
	}
}