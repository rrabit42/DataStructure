#include <stdio.h>
#include <stdlib.h>
#define max(x,y) ((x)>(y)?(x):(y)); // x, y�߿� �ִ� ���ϴ� ��ũ�� �Լ�

//����Ʈ���� ��� ����
typedef struct TreeNode {
	int data;                       //Ʈ���� �����Ͱ�
	struct TreeNode *left, *right;  //��� ������
} TreeNode;

void insert_node(TreeNode **, int); //��� ���� �Լ�
void Inorder(TreeNode *); //�߼��� ���� �Լ�
int get_node_count(TreeNode *); //��� ���� ���ϴ� �Լ�
int get_height(TreeNode *); //���� ���ϴ� �Լ�

int main() {
	TreeNode *root;
	root = NULL;

	//Ʈ����� ���� �Է� �ޱ�
	int num = 0;
	printf("�Է��� Ʈ�� ��� ����: ");
	scanf("%d", &num);
	
	//Ʈ�� ��� �Է� �ޱ�
	for (int i = 0; i < num; i++) {
		int newdata;
		printf("\n\n���ο� ������(���)�� �Է��ϼ���: ");
		scanf("%d", &newdata);
		insert_node(&root, newdata);                     //�Է� ���� �����ͷ� �� ��� �����
		printf("��� ���� = %d", get_node_count(root));  //Ʈ���� ��� ���� ���
		printf("\n���� = %d", get_height(root));         //Ʈ�� ���� ���

		printf("\n�߼��� ���� = ");                      //Ʈ���� �߼��� ���� ��� ���
		Inorder(root);
	}
}

//�߼��� ����
void Inorder(TreeNode *root)
{
	if (root) {
		Inorder(root->left);
		printf(" %d", root->data);
		Inorder(root->right);
	}
}

//���� ���ϴ� �Լ�
int get_height(TreeNode *root)
{
	//root�� ���̰� 0 �̾�� �ϹǷ�
	int height = -1;
	if (root != NULL)
		height = 1 + max(get_height(root->left), get_height(root->right));
	return height;
}

//��� ���� ���ϴ� �Լ�
int get_node_count(TreeNode *root)
{
	int count = 0;
	if (root != NULL)
		count = 1 + get_node_count(root->left) + get_node_count(root->right);
	return count;
}

//��� ���� �Լ�
void insert_node(TreeNode **root, int key)
{
	TreeNode *p, *t; //p�� �θ���, t�� ���� ���
	TreeNode *n;     //n�� ������ ���ο� ���
	t = *root; p = NULL;

	//���� ��ġ ã���� Ž��
	while (t != NULL) {
		if (key == t->data) return;    //ksy�� �̹� Ʈ�� �ȿ� ������ ���� �ȵ�
		p = t;
		if (key < t->data) t = t->left;
		else t = t->right;
	}

	n = (TreeNode *)malloc(sizeof(TreeNode));
	if (n == NULL) return;
	n->data = key;             //������ ����
	n->left = n->right = NULL;

	if (p != NULL)            //�θ� ���� ��ũ ����
		if (key < p->data) p->left = n;
		else p->right = n;

	else *root = n;
}