#include <stdio.h>
#include <string.h>
#include <ctime>
#include <math.h>
// 팩토리얼 함수
int factorial(int);

int main()
{
	//사용자한테 n 입력 받기
	int n;
	printf("n = ");
	scanf_s("%d", &n);

	//시간 담을 변수
	clock_t start, end;

	//팩토리얼 결과 담을 변수
	long result;

	// ms단위로 시간 측정해서 팩토리얼 계산
	start = clock();
	result = factorial(n);
	end = clock();

	//결과 출력
	printf("The factorial of %d = %ld\n", n, result);
	printf("The execution time = %.2f nsec\n", (double)(end - start) / pow(10.0, 3.0));

}

//팩토리얼 함수
int factorial(int n)
{
	//팩토리얼 계산
	if (n == 0 || n == 1) return 1;
	else {
		return n * factorial(n - 1); //재귀함수를 이용해
	}
}