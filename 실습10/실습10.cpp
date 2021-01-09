#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100

//필요한 함수 헤더 선언
void dfs_mat(int **array, int n, int i);
void find_connected_component(int **array, int n);

//전역변수
int count = 0;              //연결성분 구분 count값
int visited[MAX_VERTICES];  //방문한 vertex
int v = 0;                  //시작 vertex값

//연결성분 찾는 함수
void find_connected_component(int **array, int n) {
	visited[v] = count;            //정점 i의 방문 표시
	for (v = 0; v < n; v++) {  //인접 정점 탐색
		if (!visited[v]) {
			printf("\n");
			count++;
			printf("연결성분%d: ", count);
			dfs_mat(array, n, v);
		}
	}
}

//인접 행렬로 표현된 그래프에 대한 깊이 우선 탐색
void dfs_mat(int **array, int n, int i) {
	int w;
	printf("%d ", i);
	visited[i] = count;
	for (w = 0; w < n; w++) {
		if (array[i][w] && !visited[w])  //edge로 연결이 되어 있고, 한번도 visited 되지 않은 vertex면
			dfs_mat(array, n, w);
	}
}

int main() {
	//파일 열기
	FILE *fp = fopen("graph3.txt", "r");

	//파일에서 배열 크기 입력받기
	int n = 0; int m = 0;
	fscanf(fp, "%d", &n);
	fscanf(fp, "%d", &m);

	//파일에서 배열 원소 입력받기
	int **array = new int*[n];
	for (int i = 0; i < n; i++) {
		array[i] = new int[n];
	}

	//배열 초기화
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			array[i][j] = 0;
		}
	}

	//edge들 입력받기(m만큼 돌기)
	int v0; int v1;
	while (!feof(fp)) {
		fscanf(fp, "%d", &v0);
		fscanf(fp, "%d", &v1);
		array[v0][v1] = 1;
	}

	//파일 닫기
	fclose(fp);

	//결과 출력
	printf("입력파일 = \"graph3.txt\"");
	find_connected_component(array, n);
}