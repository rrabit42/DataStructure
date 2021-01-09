#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 10000 //MAX�� ���� ��ũ�� �Լ�

//�迭�� �Ҽ� 10000�� ����
void prime_generate(int *array) {
	int i, j;
	int count = 0; //�迭�� 10000���� ������ Ȯ���� �ִ� ����
	//�Ҽ� ����ϱ�
	for (i = 2; count < 10000; i++) {
		for (j = 2; j <= i; j++) {
			if (i%j == 0)
				break;
		}
		if (i == j) {
			array[count++] = i; //�Ҽ��� �迭�� �ֱ�
		}
	}
}

//���� Ž��
long bin_count = 0; //�� Ƚ�� ����
int search_binary(int *array, int key, int low, int high) {
	int middle; //�߰� �ε��� ���
	while (low <= high) {
		middle = (low + high) / 2;
		//Ű�� middle�� �񱳷� Ű�� ��ġ ����
		if (key == array[middle]) { //middle�ε��� ���� Ű��
			bin_count++;
			return middle; //����
		}
		else if (key > array[middle]) {
			low = middle + 1;
		}
		else {
			high = middle - 1;
		}
		bin_count++;
	}
	return -1; //Ž�� ����
}

//���� Ž��
long inter_count = 0; //�� Ƚ�� ����
int search_interpolation(int *array, int key, int n) {
	int low, high, j;
	low = 0;
	high = n - 1;
	//���� �� ��ġ ���
	while ((array[high] >= key) && (key > array[low])) {
		inter_count += 2;
		j = ((float)(key - array[low]) / (array[high] - array[low])* (high - low)) + low;
		if (key > array[j]) {
			low = j + 1;
		}
		else if (key < array[j]) {
			high = j - 1;
		}
		else {
			low = j;
		}
	}
	inter_count++;
	if (array[low] == key) {
		inter_count++;
		return (low);  //Ž�� ����
	}
	else {
		inter_count++;
		return -1;     //Ž�� ����
	}
}

int main() {
	//������ �迭 ����
	int array[MAX];

	//�迭 ���� �Ҽ��� �ʱ�ȭ
	prime_generate(array);

	//Ű �� �Է¹ޱ�
	int key;
	printf("Key = ");
	scanf("%d", &key);
	printf("\n\n");

	//���� Ž�� ��� �� ���
	printf("Binary search\n");
	int bin_index = search_binary(array, key, 0, MAX);
	printf("\tIndex = %d\n", bin_index);
	printf("\tThe number of comparisons = %ld\n\n", bin_count);


	//���� Ž�� ��� �� ���
	printf("Interpolation search\n");
	int inter_index = search_interpolation(array, key, MAX);
	printf("\tIndex = %d\n", inter_index);
	printf("\tThe number of comparisons = %ld\n\n", inter_count);
}
