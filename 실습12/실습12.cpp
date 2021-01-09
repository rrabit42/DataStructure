#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 10000 //MAX값 지정 매크로 함수

//배열에 소수 10000개 대입
void prime_generate(int *array) {
	int i, j;
	int count = 0; //배열에 10000개가 들어갔는지 확인해 주는 변수
	//소수 계산하기
	for (i = 2; count < 10000; i++) {
		for (j = 2; j <= i; j++) {
			if (i%j == 0)
				break;
		}
		if (i == j) {
			array[count++] = i; //소수면 배열에 넣기
		}
	}
}

//이진 탐색
long bin_count = 0; //비교 횟수 변수
int search_binary(int *array, int key, int low, int high) {
	int middle; //중간 인덱스 계산
	while (low <= high) {
		middle = (low + high) / 2;
		//키와 middle의 비교로 키의 위치 추정
		if (key == array[middle]) { //middle인덱스 값이 키면
			bin_count++;
			return middle; //리턴
		}
		else if (key > array[middle]) {
			low = middle + 1;
		}
		else {
			high = middle - 1;
		}
		bin_count++;
	}
	return -1; //탐색 실패
}

//보간 탐색
long inter_count = 0; //비교 횟수 변수
int search_interpolation(int *array, int key, int n) {
	int low, high, j;
	low = 0;
	high = n - 1;
	//다음 비교 위치 계산
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
		return (low);  //탐색 성공
	}
	else {
		inter_count++;
		return -1;     //탐색 실패
	}
}

int main() {
	//일차원 배열 선언
	int array[MAX];

	//배열 값을 소수로 초기화
	prime_generate(array);

	//키 값 입력받기
	int key;
	printf("Key = ");
	scanf("%d", &key);
	printf("\n\n");

	//이진 탐색 결과 값 출력
	printf("Binary search\n");
	int bin_index = search_binary(array, key, 0, MAX);
	printf("\tIndex = %d\n", bin_index);
	printf("\tThe number of comparisons = %ld\n\n", bin_count);


	//보간 탐색 결과 값 출력
	printf("Interpolation search\n");
	int inter_index = search_interpolation(array, key, MAX);
	printf("\tIndex = %d\n", inter_index);
	printf("\tThe number of comparisons = %ld\n\n", inter_count);
}
