#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//매크로 함수 정의
#define INF 1000        //무한대 값
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 20 //최대 점점 개수

//전역 변수
int distance[MAX_VERTICES]; //시작정점으로부터의 최단 경로 거리
int found[MAX_VERTICES];    //방문한 정점 표시

//필요한 함수 헤더 정의
void shortest_path(int, int, int**);
int choose(int[], int, int[]);

int main() {
	//파일 열기
	FILE *fp = fopen("sp3.txt", "r");
	//파일에서 배열 크기 입력받기
	int n = 0; int m = 0;
	fscanf(fp, "%d", &n);
	fscanf(fp, "%d", &m);

	//배열 생성
	int **weight;
	weight = (int**)malloc(sizeof(int*)*n);
	for (int i = 0; i < n; i++) {
		weight[i] = (int*)malloc(sizeof(int)*n);
	}

	//배열 초기화
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			weight[i][j] = INF;
		}
	}

	//방향 에지와 가중치 입력받기
	int v0, v1, num;
	for (int i = 0; i < m; i++) {
		fscanf(fp, "%d", &v0);
		fscanf(fp, "%d", &v1);
		fscanf(fp, "%d", &num);
		weight[v0][v1] = num;
	}
	fclose(fp);
	
	//결과 출력
	printf("입력파일 = \"sp3.txt\"");
	printf("\nv0로부터의 최단경로 :");
	shortest_path(0, n, weight);
	for (int i = 0; i < n; i++) {
		printf("%d ", distance[i]);
	}
}

//Dijkstra의 최단경로 찾는 함수
void shortest_path(int start, int n, int** weight) {
	int i, u, w;
	//시작정점으로부터의 distance 업데이트
	for (i = 0; i < n; i++) {
		distance[i] = weight[start][i];
		found[i] = FALSE;
	}

	//시작 정점 관련 값들 초기화
	found[start] = TRUE;
	distance[start] = 0;

	//새 정점 found에 포함하고 그 정점 기준으로 distance 업데이트
	for (i = 0; i < n - 2; i++){
		u = choose(distance, n, found);
		found[u] = TRUE;
		for (w = 0; w < n; w++) {
			if (!found[w])
				if (distance[u] + weight[u][w] < distance[w])
					distance[w] = distance[u] + weight[u][w];
		}
	}
}

//인접정점 중 distance 최소인 정점 찾기
int choose(int distance[], int n, int found[]) {
	int i, min, minpos;
	min = INT_MAX;
	minpos = -1;
	for (i = 0; i < n; i++) {
		if (distance[i] < min && !found[i]) {
			min = distance[i];
			minpos = i;
		}
	}
	return minpos;
}