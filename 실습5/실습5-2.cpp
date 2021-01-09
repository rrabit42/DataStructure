#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 10 //최대 큐 크기

//함수 선언
void enqueue(char);
void dequeue();
void peek();

//큐 구조체
struct queue {
	char array[MAX_QUEUE_SIZE]; //배열로 만든 환형 큐
	int front = 0; //front 인덱스
	int rear = 0; //rear 인덱스
} queue;

int main(void)
{
	//예1
	printf("예1\n");
	enqueue('A'); peek(); enqueue('B'); peek(); enqueue('C'); peek(); dequeue(); dequeue();
	enqueue('D'); peek(); enqueue('E'); peek(); dequeue(); dequeue(); dequeue(); dequeue();

	//예2
	printf("\n\n예2\n");
	queue.rear = queue.front = 0; //큐 초기화
	enqueue('A'); dequeue(); enqueue('B'); dequeue(); enqueue('C'); dequeue(); dequeue();
	printf("\n");
	queue.rear = queue.front = 0; //큐 초기화
	enqueue('A'); enqueue('B'); enqueue('C'); enqueue('D'); enqueue('E'); enqueue('F');
	enqueue('G'); enqueue('H'); enqueue('I'); dequeue(); peek(); enqueue('J'); enqueue('K');

}

//큐 원소 삽입 함수
void enqueue(char newone)
{
	//큐가 포화 상태면 overflow라고 알려주기
	if (queue.front == (queue.rear + 1) % MAX_QUEUE_SIZE)
		printf("\"queue overflow\" ");
	//포화상태 아니면 rear index 1 늘려서 거기에 원소 추가
	else {
		queue.rear = (queue.rear + 1) % MAX_QUEUE_SIZE;
		queue.array[queue.rear] = newone;
	}
}

//큐 원소 삭제 함수
void dequeue()
{
	//큐가 비어있으면 큐가 비어있다고 알려주기
	if (queue.front == queue.rear)
		printf("\"queue empty\" ");
	//빈게 아니라면 front 인덱스 1 추가해서 삭제할 원소 출력
	else {
		queue.front = (queue.front + 1) % MAX_QUEUE_SIZE;
		printf("%c ", queue.array[queue.front]);
	}
}

//다음에 삭제할 원소 출력
void peek()
{
	//큐가 비어있으면 비어있다고 알려주기
	if (queue.front == queue.rear)
		printf("\"queue empty\" ");
	//큐가 안비어있으면 다음에 삭제할 원소 알려주기
	else {
		printf("%c ", queue.array[queue.front + 1]);
	}
}