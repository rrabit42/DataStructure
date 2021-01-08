#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 1024

// ListNode 구조체 선언
typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode *link;
} ListNode;

//node 연결하는 함수
void insert_node(ListNode *p, ListNode *new_node);

int main() {
	//리스트 크기 받기
	int n;
	scanf_s("%d", &n);

	//리스트 값 받기
	int array[SIZE];
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &array[i]);
	}

	//키 값 받기(3개)
	int keys[3];
	for (int i = 0; i < 3; i++) {
		scanf_s("%d", &keys[i]);
	}

	//head pointer
	ListNode* head = NULL;
	//마지막 노드 가리킬 pointer
	ListNode* p = NULL;

	//첫번째 노드 생성
	ListNode *node;
	node = (ListNode*)malloc(sizeof(ListNode));
	node->data = array[0];
	node->link = NULL;
	head = node;
	p = head;

	//나머지 노드 생성
	for (int i = 1; i < n; i++) {
		ListNode *node2;
		node2 = (ListNode*)malloc(sizeof(ListNode));
		node2->data = array[i];
		node2->link = NULL;
		insert_node(p, node2);
		p = p->link;
	}

	//현재 연결 리스트 출력
	printf("\nn = %d\n", n);
	printf("List = ");
	p = head;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->link;
	}

	//키 값있으면 remove, 아니면 없다고 출력
	for(int i=0; i<3; i++){
		bool no = true;        //키 값 없는지 확인해줄 변수

		int key = keys[i];
		printf("\n\nKey = %d", key);
		p = head->link;
		ListNode *before = head;     //키 값 이전 node를 가리킬 포인터
		while (p != NULL) {
			//p가 key값 가리킬때
			if (p->data == key) {
				before->link = p->link;
				p->link = NULL;
				no = false;
				break;
			}
			//p는 두번째 노드부터 가리키므로, 첫번째 노드가 key일때
			else if(head->data == key) {
				head = head->link;
				before->link = NULL;
				no = false;
				break;
			}
			//아니면 다음 노드로 이동
			p = p->link;
			before = before->link;
		}
		//키와 연결 리스트 출력
		if (no==true) { printf(" \"키가 없음\""); }
		printf("\nList = ");
		p = head;
		while (p != NULL) {
			printf("%d ", p->data);
			p = p->link;
		}
	}
}

//노드 연결하는 함수
void insert_node(ListNode *p, ListNode *new_node) {
	p->link = new_node;
}
