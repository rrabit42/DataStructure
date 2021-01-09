#include <stdio.h>
#include <stdlib.h>

//Ʈ����� ����ü
typedef struct TreeNode {
	int data;                      //������
	struct TreeNode *left, *right; //���� ��带 ����Ű�� ������, ������ ��带 ����Ű�� ������
} TreeNode;

//�Լ� ����
void inorder(TreeNode *);
void preorder(TreeNode *);
void postorder(TreeNode *);
void triple_order(TreeNode *);

int main()
{
	//����Ʈ�� ��1
	/*
	TreeNode n1 = { 'a', NULL, NULL };
	TreeNode n2 = { 'b', NULL, NULL };
	TreeNode n3 = { '*', &n1, &n2 };
	TreeNode n4 = { 'c', NULL, NULL };
	TreeNode n5 = { 'd', NULL, NULL };
	TreeNode n6 = { '/', &n4, &n5 };
	TreeNode n7 = { '+', &n3, &n6 }; 
	TreeNode *root1 = &n7;          //��Ʈ ��� ����Ű�� ������

	//��� ���
	printf("inorder of ��1 = ");
	inorder(root1);                 //�߼��� ����
	printf("\npreorder of ��1 = ");
	preorder(root1);                //������ ����
	printf("\npostorder of ��1 = ");
	postorder(root1);               //�ļ��� ����
	printf("\ntriple order of ��1 = ");
	triple_order(root1);            //triple order ����
	*/

	//����Ʈ�� ��2
	TreeNode n1 = { '3', NULL, NULL };
	TreeNode n2 = { '2', NULL, NULL };
	TreeNode n3 = { '*', &n1, &n2 };
	TreeNode n4 = { '4', NULL, NULL };
	TreeNode n5 = { '2', NULL, NULL };
	TreeNode n6 = { '/', &n4, &n5 };
	TreeNode n7 = { '+', &n3, &n6 };
	TreeNode n8 = { '2', NULL, NULL };
	TreeNode n9 = { '3', NULL, NULL };
	TreeNode n10 = { '5', NULL, NULL };
	TreeNode n11 = { '*', &n9, &n10 };
	TreeNode n12 = { '2', NULL, NULL };
	TreeNode n13 = { '+', &n11, &n12 };
	TreeNode n14 = { '+', &n8, &n13 };
	TreeNode n15 = { '*', &n7, &n14 };
	TreeNode *root2 = &n15;               //��Ʈ ��� ����Ű�� ������

	printf("inorder of ��2 = ");
	inorder(root2);                       //�߼��� ����
	printf("\npreorder of ��2 = ");
	preorder(root2);                      //������ ����
	printf("\npostorder of ��2 = ");
	postorder(root2);                     //�ļ��� ����
	printf("\ntriple order of ��2 = ");
	triple_order(root2);                  //triple_order ����
}

//�߼��� ����
void inorder(TreeNode *root)
{
	if (root) {                    //root ��� �����Ͱ� NULL �ƴ� �� ����
		inorder(root->left);       //���� �κ� Ʈ�� �߼��� ����
		printf("%c ", root->data); //root �����Ͱ� ���
		inorder(root->right);      //������ �κ� Ʈ�� �߼��� ����
	}
}

//������ ����
void preorder(TreeNode *root)
{
	if (root) {                    //root��� �����Ͱ� NULL�� �ƴ� �� ����
		printf("%c ", root->data); //root �����Ͱ� ���
		preorder(root->left);      //���� �κ� Ʈ�� ������ ����
		preorder(root->right);     //������ �κ� Ʈ�� ������ ����
	}
}

//�ļ��� ����
void postorder(TreeNode *root)
{
	if (root) {                    //root ��� �����Ͱ� NULL�� �ƴ� �� ����
		postorder(root->left);     //���� �κ� Ʈ�� �ļ��� ����
		postorder(root->right);    //������ �κ� Ʈ�� �ļ��� ����
		printf("%c ", root->data); //root �����Ͱ� ���
	}
}

void triple_order(TreeNode *root)
{
	if (root != NULL) {            //root ��� �����Ͱ� NULL�� �ƴ� �� ����
		printf("%c ", root->data); //root �����Ͱ� ���
		triple_order(root->left);  //���� �κ� Ʈ�� triple order ����
		printf("%c ", root->data); //�ٽ� root �����Ͱ� ���
		triple_order(root->right); //������ �κ� Ʈ�� triple order ����
		printf("%c ", root->data); //�ٽ� root �����Ͱ� ���
	}
}
