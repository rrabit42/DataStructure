#include <stdio.h>
#include <string.h>
#include <ctime>
#include <math.h>
// 피보나치 수열 함수
int fib(int);

int main()
{
	// 사용자한테 n 입력 받기
	int n;
	printf("n = ");
	scanf_s("%d", &n);

	// 시간 잴 변수
	clock_t start, end;
	
	// 피보나치 결과 값 받을 변수
	long result;

	// ms단위로 시간 측정해서
	// 피보나치 함수 시간 측정
	start = clock();
	result = fib(n);
	end = clock();

	// 결과 출력
	printf("The %d-th Fibonacci number = %ld\n", n, result);
	printf("The execution time = %.2lf nsec\n", (long double)(end - start));

}

// 피보나치 함수 계산
int fib(int n)
{
	if (n == 0 || n == 1) return n;
	else {
		return fib(n - 1) + fib(n - 2); //재귀 함수 이용해서
	}
}