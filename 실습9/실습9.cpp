#include <stdio.h>
#include <stdlib.h>
#define swap(a, b) { float t; t = a; a = b; b = t; } //swap �Լ� ����
void insertion_sort(float[], int);
void quick_sort(float[], int, int);
int partition(float[], int, int);

int count_insert = 0;
int count_quick = 0;

int main() {
	//���� ����
	FILE *fp = fopen("d_data1.txt", "r");

	//���Ͽ��� �迭 ũ�� �Է¹ޱ�
	int num = 0;
	fscanf(fp, "%d", &num);

	//���Ͽ��� �迭 ���� �Է¹ޱ�
	float *array1 = (float*)malloc(sizeof(float) * num);  //array1�� �������Ŀ� �� �迭
	float *array2 = (float*)malloc(sizeof(float) * num);  //array2�� �����Ŀ� �� �迭

	float element;
	for (int i = 0; i < num; i++) {
		fscanf(fp, "%f", &element);
		array1[i] = element;
		array2[i] = element;
	}
	fclose(fp);

	//���� ����
	insertion_sort(array1, num);
	//�� ����
	quick_sort(array2, 0, num-1);

	//���İ�� ���
	printf("�Է� ���� = d_data1.txt (n=%d)", num);
	//���� ����
	printf("\n���� ���� ��� = ");
	for (int i = 0; i < 10; i++) {           //�� ���� 10�� ���
		printf("%f ", array1[i]);
	}
	printf("... ");
	for (int i = num - 11; i < num; i++) {   //�� ���� 10�� ���
		printf("%f ", array1[i]);
	}
	printf("\n���� ���� �� Ƚ�� = %d", count_insert); //��Ƚ�� ���

	  //�� ����
	printf("\n\n�� ���� ��� = ");
	for (int i = 0; i < 10; i++) {           //�� ���� 10�� ���
		printf("%f ", array2[i]);
	}
	printf("... ");
	for (int i = num - 11; i < num; i++) {   //�� ���� 10�� ���
		printf("%f ", array2[i]);
	}
	printf("\n�� Ƚ�� = %d", count_quick); //��Ƚ�� ���

}

//���� ����
void insertion_sort(float list[], int n)
{
	//key�� ��ġ�� �ٲ� ���� �ε���
	int i, j;
	float key;
	for (i = 1; i < n; i++) {                         //������ �ε��� 1���� ����
		key = list[i];                                //key���� i����
		for (j = i - 1; j >= 0 && list[j] > key; j--, count_insert++) { //j�� key�� ���� ���� �ε���
					list[j + 1] = list[j];                    //list[j]>key�� list[j]�� ���������� ��ĭ �̵�
		}
		list[j + 1] = key;                         //list[j]<key�� list[j+1]�ڸ��� key�� �ڸ�
	}
}

//�� ����
void quick_sort(float list[], int left, int right) {
	if (left < right) {
		int q = partition(list, left, right);  //�� ���ϱ�
		quick_sort(list, left, q - 1);         //��ͷ� ���� �κ� �� ����
		quick_sort(list, q + 1, right);        //��ͷ� ������ �κ� �� ����
	}
}

//�� ���Ŀ��� ���̴� ���� �Լ�
int partition(float list[], int left, int right) {
	float pivot;   //��
	int low, high;

	low = left;
	high = right + 1;
	pivot = list[left];

	do {
		//�ຸ�� ū �� ã��
		do {
			low++;
			count_quick++;
		} while (low <= right && list[low] < pivot);
		//�ຸ�� ���� �� ã��
		do {
			high--;
			count_quick++;
		} while (high >= left && list[high] > pivot);
		
		//�ప �������� ū����, ���� ������ ������
		if (low < high) swap(list[low], list[high]);
	} while (low < high);

	//�ప�� list[high] �ٲٱ�
	swap(list[left], list[high]);

	//�ప �ε��� ����
	return high;
}
