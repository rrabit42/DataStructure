#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//��ũ�� �Լ� ����
#define INF 1000        //���Ѵ� ��
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 20 //�ִ� ���� ����

//���� ����
int distance[MAX_VERTICES]; //�����������κ����� �ִ� ��� �Ÿ�
int found[MAX_VERTICES];    //�湮�� ���� ǥ��

//�ʿ��� �Լ� ��� ����
void shortest_path(int, int, int**);
int choose(int[], int, int[]);

int main() {
	//���� ����
	FILE *fp = fopen("sp3.txt", "r");
	//���Ͽ��� �迭 ũ�� �Է¹ޱ�
	int n = 0; int m = 0;
	fscanf(fp, "%d", &n);
	fscanf(fp, "%d", &m);

	//�迭 ����
	int **weight;
	weight = (int**)malloc(sizeof(int*)*n);
	for (int i = 0; i < n; i++) {
		weight[i] = (int*)malloc(sizeof(int)*n);
	}

	//�迭 �ʱ�ȭ
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			weight[i][j] = INF;
		}
	}

	//���� ������ ����ġ �Է¹ޱ�
	int v0, v1, num;
	for (int i = 0; i < m; i++) {
		fscanf(fp, "%d", &v0);
		fscanf(fp, "%d", &v1);
		fscanf(fp, "%d", &num);
		weight[v0][v1] = num;
	}
	fclose(fp);
	
	//��� ���
	printf("�Է����� = \"sp3.txt\"");
	printf("\nv0�κ����� �ִܰ�� :");
	shortest_path(0, n, weight);
	for (int i = 0; i < n; i++) {
		printf("%d ", distance[i]);
	}
}

//Dijkstra�� �ִܰ�� ã�� �Լ�
void shortest_path(int start, int n, int** weight) {
	int i, u, w;
	//�����������κ����� distance ������Ʈ
	for (i = 0; i < n; i++) {
		distance[i] = weight[start][i];
		found[i] = FALSE;
	}

	//���� ���� ���� ���� �ʱ�ȭ
	found[start] = TRUE;
	distance[start] = 0;

	//�� ���� found�� �����ϰ� �� ���� �������� distance ������Ʈ
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

//�������� �� distance �ּ��� ���� ã��
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