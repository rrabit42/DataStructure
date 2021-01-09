#include <stdio.h>
#include <stdlib.h>
#define swap(a, b) { int t; t = a; a = b; b = t; } //swap �Լ� ����

//�ʿ��� �Լ� ����
void adjust(int a[], int root, int n);
void heapSort(int a[], int n);

//���� Ƚ�� ���� ����
int count = 0;

int main() {
	//���� ����
	FILE *fp = fopen("input6.txt", "r");

	//���Ͽ��� �� ũ�� �Է¹ޱ�
	int num = 0;
	fscanf(fp, "%d", &num);

	//���Ͽ��� �� ���� �Է¹ޱ�
	int *array = (int*)malloc(sizeof(int) * num);
	for (int i = 0; i < num; i++) {
		fscanf(fp, "%d", &array[i]);
	}
	fclose(fp);

	//������������ �� ����
	heapSort(array, num);

	//���İ�� ���
	printf("���� ��� = ");
	for (int i = 0; i < 10; i++) {           //�� ���� 10�� ���
		printf("%d ", array[i]);
	}
	printf("... ");
	for (int i = num - 11; i < num; i++) {   //�� ���� 10�� ���
		printf("%d ", array[i]);
	}
	
	//��Ƚ�� ���
	printf("\n�� Ƚ�� = %d", count);
}

//�� �������� ���� �Լ�, ��, �� ��Ʈ�� �ε���, �� ũ�� ���ڷ� �ޱ�
void adjust(int a[], int root, int n)
{
	//���� �ڽ� ���� ��Ʈ ���� ���� ����
	int child, rootkey;

	//��Ʈ ��
	rootkey = a[root];
	//�ڽ� ��
	child = 2 * root + 1;

	//downheap
	while (child <= n - 1) {
		if ((child < n - 1) && (a[child] < a[child + 1])) {
			child++;
			count++;
		}
		if (rootkey > a[child]) {
			count++;
			break;
		}
		else {
			a[(child - 1) / 2] = a[child];
			child = 2 * child + 1;
		}
	}
	a[(child - 1) / 2] = rootkey;
}

//�� ���� �Լ�, ���� �� ũ�⸦ ���ڷ� �޴´�
void heapSort(int a[], int n)
{
	int i;

	//�ʱ� �ִ� heap ����
	for (i = (n - 1) / 2; i >= 0; i--)
		adjust(a, i, n);

	//��Ʈ�� �ڸ� ��ȯ�� �� �籸��(������������)
	for (i = n - 2; i >= 0; i--) {
		swap(a[0], a[i + 1]);
		adjust(a, 0, i+1);
	}
}

