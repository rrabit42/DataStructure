#include <stdio.h>
#include <stdlib.h>
#define max(x,y) ((x)>(y)?(x):(y)); // x, y중에 최댓값 구하는 매크로 함수

//이진트리의 노드 구조
typedef struct TreeNode {
	int data;                       //트리의 데이터값
	struct TreeNode *left, *right;  //노드 포인터
} TreeNode;

void insert_node(TreeNode **, int); //노드 삽입 함수
void Inorder(TreeNode *); //중순위 운행 함수
int get_node_count(TreeNode *); //노드 개수 구하는 함수
int get_height(TreeNode *); //높이 구하는 함수

int main() {
	TreeNode *root;
	root = NULL;

	//트리노드 개수 입력 받기
	int num = 0;
	printf("입력할 트리 노드 개수: ");
	scanf("%d", &num);
	
	//트리 노드 입력 받기
	for (int i = 0; i < num; i++) {
		int newdata;
		printf("\n\n새로운 데이터(노드)를 입력하세요: ");
		scanf("%d", &newdata);
		insert_node(&root, newdata);                     //입력 받은 데이터로 새 노드 만들고
		printf("노드 개수 = %d", get_node_count(root));  //트리의 노드 개수 출력
		printf("\n높이 = %d", get_height(root));         //트리 높이 출력

		printf("\n중순위 운행 = ");                      //트리의 중순위 운행 결과 출력
		Inorder(root);
	}
}

//중순위 순행
void Inorder(TreeNode *root)
{
	if (root) {
		Inorder(root->left);
		printf(" %d", root->data);
		Inorder(root->right);
	}
}

//높이 구하는 함수
int get_height(TreeNode *root)
{
	//root의 높이가 0 이어야 하므로
	int height = -1;
	if (root != NULL)
		height = 1 + max(get_height(root->left), get_height(root->right));
	return height;
}

//노드 개수 구하는 함수
int get_node_count(TreeNode *root)
{
	int count = 0;
	if (root != NULL)
		count = 1 + get_node_count(root->left) + get_node_count(root->right);
	return count;
}

//노드 삽입 함수
void insert_node(TreeNode **root, int key)
{
	TreeNode *p, *t; //p는 부모노드, t는 현재 모드
	TreeNode *n;     //n은 삽입할 새로운 노드
	t = *root; p = NULL;

	//삽입 위치 찾으려 탐색
	while (t != NULL) {
		if (key == t->data) return;    //ksy가 이미 트리 안에 있으면 삽입 안됨
		p = t;
		if (key < t->data) t = t->left;
		else t = t->right;
	}

	n = (TreeNode *)malloc(sizeof(TreeNode));
	if (n == NULL) return;
	n->data = key;             //데이터 복사
	n->left = n->right = NULL;

	if (p != NULL)            //부모 노드와 링크 연결
		if (key < p->data) p->left = n;
		else p->right = n;

	else *root = n;
}