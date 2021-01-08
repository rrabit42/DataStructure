#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 1024

// ListNode ����ü ����
typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode *link;
} ListNode;

//node �����ϴ� �Լ�
void insert_node(ListNode *p, ListNode *new_node);

int main() {
	//����Ʈ ũ�� �ޱ�
	int n;
	scanf_s("%d", &n);

	//����Ʈ �� �ޱ�
	int array[SIZE];
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &array[i]);
	}

	//Ű �� �ޱ�(3��)
	int keys[3];
	for (int i = 0; i < 3; i++) {
		scanf_s("%d", &keys[i]);
	}

	//head pointer
	ListNode* head = NULL;
	//������ ��� ����ų pointer
	ListNode* p = NULL;

	//ù��° ��� ����
	ListNode *node;
	node = (ListNode*)malloc(sizeof(ListNode));
	node->data = array[0];
	node->link = NULL;
	head = node;
	p = head;

	//������ ��� ����
	for (int i = 1; i < n; i++) {
		ListNode *node2;
		node2 = (ListNode*)malloc(sizeof(ListNode));
		node2->data = array[i];
		node2->link = NULL;
		insert_node(p, node2);
		p = p->link;
	}

	//���� ���� ����Ʈ ���
	printf("\nn = %d\n", n);
	printf("List = ");
	p = head;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->link;
	}

	//Ű �������� remove, �ƴϸ� ���ٰ� ���
	for(int i=0; i<3; i++){
		bool no = true;        //Ű �� ������ Ȯ������ ����

		int key = keys[i];
		printf("\n\nKey = %d", key);
		p = head->link;
		ListNode *before = head;     //Ű �� ���� node�� ����ų ������
		while (p != NULL) {
			//p�� key�� ����ų��
			if (p->data == key) {
				before->link = p->link;
				p->link = NULL;
				no = false;
				break;
			}
			//p�� �ι�° ������ ����Ű�Ƿ�, ù��° ��尡 key�϶�
			else if(head->data == key) {
				head = head->link;
				before->link = NULL;
				no = false;
				break;
			}
			//�ƴϸ� ���� ���� �̵�
			p = p->link;
			before = before->link;
		}
		//Ű�� ���� ����Ʈ ���
		if (no==true) { printf(" \"Ű�� ����\""); }
		printf("\nList = ");
		p = head;
		while (p != NULL) {
			printf("%d ", p->data);
			p = p->link;
		}
	}
}

//��� �����ϴ� �Լ�
void insert_node(ListNode *p, ListNode *new_node) {
	p->link = new_node;
}
