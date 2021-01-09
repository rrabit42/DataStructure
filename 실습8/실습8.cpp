#include <stdio.h>
#include <stdlib.h>
#define swap(a, b) { int t; t = a; a = b; b = t; } //swap 함수 선언

//필요한 함수 선언
void adjust(int a[], int root, int n);
void heapSort(int a[], int n);

//실행 횟수 세는 변수
int count = 0;

int main() {
	//파일 열기
	FILE *fp = fopen("input6.txt", "r");

	//파일에서 힙 크기 입력받기
	int num = 0;
	fscanf(fp, "%d", &num);

	//파일에서 힙 원소 입력받기
	int *array = (int*)malloc(sizeof(int) * num);
	for (int i = 0; i < num; i++) {
		fscanf(fp, "%d", &array[i]);
	}
	fclose(fp);

	//오름차순으로 힙 정렬
	heapSort(array, num);

	//정렬결과 출력
	printf("정렬 결과 = ");
	for (int i = 0; i < 10; i++) {           //앞 원소 10개 출력
		printf("%d ", array[i]);
	}
	printf("... ");
	for (int i = num - 11; i < num; i++) {   //뒤 원소 10개 출력
		printf("%d ", array[i]);
	}
	
	//비교횟수 출력
	printf("\n비교 횟수 = %d", count);
}

//힙 오름차순 정렬 함수, 힙, 힙 루트의 인덱스, 힙 크기 인자로 받기
void adjust(int a[], int root, int n)
{
	//각각 자식 값과 루트 값을 받을 변수
	int child, rootkey;

	//루트 값
	rootkey = a[root];
	//자식 값
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

//힙 정렬 함수, 힙과 힙 크기를 인자로 받는다
void heapSort(int a[], int n)
{
	int i;

	//초기 최대 heap 구성
	for (i = (n - 1) / 2; i >= 0; i--)
		adjust(a, i, n);

	//루트의 자리 교환과 힙 재구성(오름차순으로)
	for (i = n - 2; i >= 0; i--) {
		swap(a[0], a[i + 1]);
		adjust(a, 0, i+1);
	}
}

