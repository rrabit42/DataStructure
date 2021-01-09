#include <stdio.h>
#include <stdlib.h>
//�ִ� ���� 3���� ����
#define MAX_VERTEX 30

//���(����) Ÿ��
typedef struct GraphNode {
	int num;  //������ȣ�� ��
	GraphNode* link; //���� ���� ����Ʈ
};

//���� ���� �迭
GraphNode *adj_list[MAX_VERTEX];


//��� ���� ����
typedef struct StackType {
	int top;
	int array[MAX_VERTEX];
};
//���ÿ� �� push�ϴ� �Լ�
void push(StackType *stack, int num) {
	stack->array[++stack->top] = num;
}
//���ÿ��� ���� pop�ϴ� �Լ�
int pop(StackType *stack) {
	return stack->array[stack->top--];
}
//������ ����������� Ȯ��
int is_empty(StackType *stack) {
	return (stack->top == -1);
}

//���������� ������ �׷������� üũ
bool check(int *in_degree, int n) {
	bool result = false;
	for (int i = 0; i < n; i++) {
		if (in_degree[i] != 0) {
			printf("���������� �Ұ���(Impossible)�մϴ�.");
			return result;
		}
	}
	return true;
}


//���� ���� �˰���
void top_sort(StackType *result, int v) {
	int i;
	GraphNode *node;
	int *in_degree = (int *)malloc(sizeof(int)*v);

	//DAG ������ ���� ���� �� �ʱ�ȭ
	for (int i = 0; i < MAX_VERTEX; i++) {
		in_degree[i] = 0;
	}

	//���� ���� ���
	for (i = 0; i < v; i++) {
		node = adj_list[i]; //���� i���� ������ ������
		while (node != NULL) {
			in_degree[node->num]++;
			node = node->link;
		}
	}

	//���� ������ 0�� ������ ���ÿ� ����
	for (int i = 0; i < v; i++) {
		if (in_degree[i] == 0) push(result, i);
	}

	//���� ������ ����
	while (!is_empty(result)) {
		//���ÿ� �ִ� ���� 1�� ���
		int w;
		w = pop(result);
		printf("%d ", w);

		//�׿� ���� ������ ���� ���� ����
		node = adj_list[w];
		while (node != NULL) {
			int u = node->num;
			in_degree[u]--;    //���� ���� ����
			if (in_degree[u] == 0) push(result, u);
			node = node->link;  //���� ����
		}
	}

	//�׷����� DAG���� üũ
	if (!check(in_degree, v)) {
		return;
	}
}

int main() {
	//1871063 ���̹������а� �輭��
	for (int i = 0; i < MAX_VERTEX; i++) {
		adj_list[i] = NULL;
	}

	//���� ����
	FILE *fp = fopen("dag5.txt", "r");

	//������ �� v, ������ �� e �Է� �ޱ�
	int v = 0; int e = 0;
	fscanf(fp, "%d %d", &v, &e);

	//���� ���� �Է� �ޱ�
	int v1; int v2;
	for (int i = 0; i < e; i++) {
		fscanf(fp, "%d %d", &v1, &v2);   //���� �Է� �ޱ�
		//�� ���� ���� ������ ���� node
		//node�� ���� �Է�
		GraphNode *node = (GraphNode *)malloc(sizeof(GraphNode));
		node->num = v2; node->link = NULL;

		GraphNode *here = adj_list[v1];
		//�ùٸ� ��ġ�� �� ��� ����
		if (here == NULL) {
			adj_list[v1] = node;
		}
		else {
			GraphNode *here = adj_list[v1];
			while (here->link != NULL) {
				here = here->link;
			}
			here->link = node;
		}
	}
	fclose(fp);

	//����� ������ ����
	StackType *result= new StackType;
	result->top = -1;
	
	//��� ���
	printf("���� ���� ��� ���: ");
	top_sort(result, v);
}
