#include <stdio.h>
#include <stdlib.h>
#define swap(a, b) { float t; t = a; a = b; b = t; } //swap 함수 선언
void insertion_sort(float[], int);
void quick_sort(float[], int, int);
int partition(float[], int, int);

int count_insert = 0;
int count_quick = 0;

int main() {
	//파일 열기
	FILE *fp = fopen("d_data1.txt", "r");

	//파일에서 배열 크기 입력받기
	int num = 0;
	fscanf(fp, "%d", &num);

	//파일에서 배열 원소 입력받기
	float *array1 = (float*)malloc(sizeof(float) * num);  //array1은 삽입정렬에 쓸 배열
	float *array2 = (float*)malloc(sizeof(float) * num);  //array2은 퀵정렬에 쓸 배열

	float element;
	for (int i = 0; i < num; i++) {
		fscanf(fp, "%f", &element);
		array1[i] = element;
		array2[i] = element;
	}
	fclose(fp);

	//삽입 정렬
	insertion_sort(array1, num);
	//퀵 정렬
	quick_sort(array2, 0, num-1);

	//정렬결과 출력
	printf("입력 파일 = d_data1.txt (n=%d)", num);
	//삽입 정렬
	printf("\n삽입 정렬 결과 = ");
	for (int i = 0; i < 10; i++) {           //앞 원소 10개 출력
		printf("%f ", array1[i]);
	}
	printf("... ");
	for (int i = num - 11; i < num; i++) {   //뒤 원소 10개 출력
		printf("%f ", array1[i]);
	}
	printf("\n삽입 정렬 비교 횟수 = %d", count_insert); //비교횟수 출력

	  //퀵 정렬
	printf("\n\n퀵 정렬 결과 = ");
	for (int i = 0; i < 10; i++) {           //앞 원소 10개 출력
		printf("%f ", array2[i]);
	}
	printf("... ");
	for (int i = num - 11; i < num; i++) {   //뒤 원소 10개 출력
		printf("%f ", array2[i]);
	}
	printf("\n비교 횟수 = %d", count_quick); //비교횟수 출력

}

//삽입 정렬
void insertion_sort(float list[], int n)
{
	//key는 위치를 바꿀 값의 인덱스
	int i, j;
	float key;
	for (i = 1; i < n; i++) {                         //정렬은 인덱스 1부터 시작
		key = list[i];                                //key값은 i부터
		for (j = i - 1; j >= 0 && list[j] > key; j--, count_insert++) { //j는 key와 비교할 값의 인덱스
					list[j + 1] = list[j];                    //list[j]>key면 list[j]를 오른쪽으로 한칸 이동
		}
		list[j + 1] = key;                         //list[j]<key면 list[j+1]자리가 key의 자리
	}
}

//퀵 정렬
void quick_sort(float list[], int left, int right) {
	if (left < right) {
		int q = partition(list, left, right);  //축 정하기
		quick_sort(list, left, q - 1);         //재귀로 왼쪽 부분 퀵 정렬
		quick_sort(list, q + 1, right);        //재귀로 오른쪽 부분 퀵 정렬
	}
}

//퀵 정렬에서 쓰이는 분할 함수
int partition(float list[], int left, int right) {
	float pivot;   //축
	int low, high;

	low = left;
	high = right + 1;
	pivot = list[left];

	do {
		//축보다 큰 값 찾기
		do {
			low++;
			count_quick++;
		} while (low <= right && list[low] < pivot);
		//축보다 작은 값 찾기
		do {
			high--;
			count_quick++;
		} while (high >= left && list[high] > pivot);
		
		//축값 기준으로 큰범위, 작은 범위로 나누기
		if (low < high) swap(list[low], list[high]);
	} while (low < high);

	//축값과 list[high] 바꾸기
	swap(list[left], list[high]);

	//축값 인덱스 리턴
	return high;
}
