#include <stdio.h>
#include <stdlib.h>

//트리노드 구조체
typedef struct TreeNode {
	int data;                      //데이터
	struct TreeNode *left, *right; //왼쪽 노드를 가리키는 포인터, 오른쪽 노드를 가리키는 포인터
} TreeNode;

//함수 선언
void inorder(TreeNode *);
void preorder(TreeNode *);
void postorder(TreeNode *);
void triple_order(TreeNode *);

int main()
{
	//이진트리 예1
	/*
	TreeNode n1 = { 'a', NULL, NULL };
	TreeNode n2 = { 'b', NULL, NULL };
	TreeNode n3 = { '*', &n1, &n2 };
	TreeNode n4 = { 'c', NULL, NULL };
	TreeNode n5 = { 'd', NULL, NULL };
	TreeNode n6 = { '/', &n4, &n5 };
	TreeNode n7 = { '+', &n3, &n6 }; 
	TreeNode *root1 = &n7;          //루트 노드 가리키는 포인터

	//결과 출력
	printf("inorder of 예1 = ");
	inorder(root1);                 //중순위 운행
	printf("\npreorder of 예1 = ");
	preorder(root1);                //전순위 운행
	printf("\npostorder of 예1 = ");
	postorder(root1);               //후순위 운행
	printf("\ntriple order of 예1 = ");
	triple_order(root1);            //triple order 운행
	*/

	//이진트리 예2
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
	TreeNode *root2 = &n15;               //루트 노드 가리키는 포인터

	printf("inorder of 예2 = ");
	inorder(root2);                       //중순위 운행
	printf("\npreorder of 예2 = ");
	preorder(root2);                      //전순위 운행
	printf("\npostorder of 예2 = ");
	postorder(root2);                     //후순위 운행
	printf("\ntriple order of 예2 = ");
	triple_order(root2);                  //triple_order 운행
}

//중순위 운행
void inorder(TreeNode *root)
{
	if (root) {                    //root 노드 포인터가 NULL 아닐 때 까지
		inorder(root->left);       //왼쪽 부분 트리 중순위 운행
		printf("%c ", root->data); //root 데이터값 출력
		inorder(root->right);      //오른쪽 부분 트리 중순위 운행
	}
}

//전순위 운행
void preorder(TreeNode *root)
{
	if (root) {                    //root노드 포인터가 NULL이 아닐 때 까지
		printf("%c ", root->data); //root 데이터값 출력
		preorder(root->left);      //왼쪽 부분 트리 전순위 운행
		preorder(root->right);     //오른쪽 부분 트리 전순위 운행
	}
}

//후순위 운행
void postorder(TreeNode *root)
{
	if (root) {                    //root 노드 포인터가 NULL이 아닐 때 까지
		postorder(root->left);     //왼쪽 부분 트리 후순위 운행
		postorder(root->right);    //오른쪽 부분 트리 후순위 운행
		printf("%c ", root->data); //root 데이터값 출력
	}
}

void triple_order(TreeNode *root)
{
	if (root != NULL) {            //root 노드 포인터가 NULL이 아닐 때 까지
		printf("%c ", root->data); //root 데이터값 출력
		triple_order(root->left);  //왼쪽 부분 트리 triple order 운행
		printf("%c ", root->data); //다시 root 데이터값 출력
		triple_order(root->right); //오른쪽 부분 트리 triple order 운행
		printf("%c ", root->data); //다시 root 데이터값 출력
	}
}
