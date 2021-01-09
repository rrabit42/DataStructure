#include <stdio.h>
#include <stdlib.h>
//최대 노드는 3개로 설정
#define MAX_VERTEX 30

//노드(정점) 타입
typedef struct GraphNode {
	int num;  //정점번호가 들어감
	GraphNode* link; //인접 정점 리스트
};

//인접 정점 배열
GraphNode *adj_list[MAX_VERTEX];


//결과 담을 스택
typedef struct StackType {
	int top;
	int array[MAX_VERTEX];
};
//스택에 값 push하는 함수
void push(StackType *stack, int num) {
	stack->array[++stack->top] = num;
}
//스택에서 값을 pop하는 함수
int pop(StackType *stack) {
	return stack->array[stack->top--];
}
//스택이 공백상태인지 확인
int is_empty(StackType *stack) {
	return (stack->top == -1);
}

//위상정렬이 가능한 그래프인지 체크
bool check(int *in_degree, int n) {
	bool result = false;
	for (int i = 0; i < n; i++) {
		if (in_degree[i] != 0) {
			printf("위상정렬이 불가능(Impossible)합니다.");
			return result;
		}
	}
	return true;
}


//위상 정렬 알고리즘
void top_sort(StackType *result, int v) {
	int i;
	GraphNode *node;
	int *in_degree = (int *)malloc(sizeof(int)*v);

	//DAG 구조의 진입 차수 값 초기화
	for (int i = 0; i < MAX_VERTEX; i++) {
		in_degree[i] = 0;
	}

	//진입 차수 계산
	for (i = 0; i < v; i++) {
		node = adj_list[i]; //정점 i에서 나오는 엣지들
		while (node != NULL) {
			in_degree[node->num]++;
			node = node->link;
		}
	}

	//진입 차수가 0인 정점을 스택에 삽입
	for (int i = 0; i < v; i++) {
		if (in_degree[i] == 0) push(result, i);
	}

	//위상 순서를 생성
	while (!is_empty(result)) {
		//스택에 있는 정점 1개 출력
		int w;
		w = pop(result);
		printf("%d ", w);

		//그에 따른 정점의 진입 차수 변경
		node = adj_list[w];
		while (node != NULL) {
			int u = node->num;
			in_degree[u]--;    //진입 차수 감소
			if (in_degree[u] == 0) push(result, u);
			node = node->link;  //다음 정점
		}
	}

	//그래프가 DAG인지 체크
	if (!check(in_degree, v)) {
		return;
	}
}

int main() {
	//1871063 사이버보안학과 김서영
	for (int i = 0; i < MAX_VERTEX; i++) {
		adj_list[i] = NULL;
	}

	//파일 열기
	FILE *fp = fopen("dag5.txt", "r");

	//정점의 수 v, 엣지의 수 e 입력 받기
	int v = 0; int e = 0;
	fscanf(fp, "%d %d", &v, &e);

	//정점 관계 입력 받기
	int v1; int v2;
	for (int i = 0; i < e; i++) {
		fscanf(fp, "%d %d", &v1, &v2);   //엣지 입력 받기
		//새 정점 관계 정보를 담을 node
		//node에 정보 입력
		GraphNode *node = (GraphNode *)malloc(sizeof(GraphNode));
		node->num = v2; node->link = NULL;

		GraphNode *here = adj_list[v1];
		//올바른 위치에 새 노드 삽입
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

	//결과를 저장할 스택
	StackType *result= new StackType;
	result->top = -1;
	
	//결과 출력
	printf("위상 정렬 결과 출력: ");
	top_sort(result, v);
}
