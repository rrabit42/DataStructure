#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100

//�ʿ��� �Լ� ��� ����
void dfs_mat(int **array, int n, int i);
void find_connected_component(int **array, int n);

//��������
int count = 0;              //���Ἲ�� ���� count��
int visited[MAX_VERTICES];  //�湮�� vertex
int v = 0;                  //���� vertex��

//���Ἲ�� ã�� �Լ�
void find_connected_component(int **array, int n) {
	visited[v] = count;            //���� i�� �湮 ǥ��
	for (v = 0; v < n; v++) {  //���� ���� Ž��
		if (!visited[v]) {
			printf("\n");
			count++;
			printf("���Ἲ��%d: ", count);
			dfs_mat(array, n, v);
		}
	}
}

//���� ��ķ� ǥ���� �׷����� ���� ���� �켱 Ž��
void dfs_mat(int **array, int n, int i) {
	int w;
	printf("%d ", i);
	visited[i] = count;
	for (w = 0; w < n; w++) {
		if (array[i][w] && !visited[w])  //edge�� ������ �Ǿ� �ְ�, �ѹ��� visited ���� ���� vertex��
			dfs_mat(array, n, w);
	}
}

int main() {
	//���� ����
	FILE *fp = fopen("graph3.txt", "r");

	//���Ͽ��� �迭 ũ�� �Է¹ޱ�
	int n = 0; int m = 0;
	fscanf(fp, "%d", &n);
	fscanf(fp, "%d", &m);

	//���Ͽ��� �迭 ���� �Է¹ޱ�
	int **array = new int*[n];
	for (int i = 0; i < n; i++) {
		array[i] = new int[n];
	}

	//�迭 �ʱ�ȭ
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			array[i][j] = 0;
		}
	}

	//edge�� �Է¹ޱ�(m��ŭ ����)
	int v0; int v1;
	while (!feof(fp)) {
		fscanf(fp, "%d", &v0);
		fscanf(fp, "%d", &v1);
		array[v0][v1] = 1;
	}

	//���� �ݱ�
	fclose(fp);

	//��� ���
	printf("�Է����� = \"graph3.txt\"");
	find_connected_component(array, n);
}