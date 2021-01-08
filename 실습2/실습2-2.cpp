#include <stdio.h>
#include <string.h>
#include <ctime>
#include <math.h>
// �Ǻ���ġ ���� �Լ�
int fib(int);

int main()
{
	// ��������� n �Է� �ޱ�
	int n;
	printf("n = ");
	scanf_s("%d", &n);

	// �ð� �� ����
	clock_t start, end;
	
	// �Ǻ���ġ ��� �� ���� ����
	long result;

	// ms������ �ð� �����ؼ�
	// �Ǻ���ġ �Լ� �ð� ����
	start = clock();
	result = fib(n);
	end = clock();

	// ��� ���
	printf("The %d-th Fibonacci number = %ld\n", n, result);
	printf("The execution time = %.2lf nsec\n", (long double)(end - start));

}

// �Ǻ���ġ �Լ� ���
int fib(int n)
{
	if (n == 0 || n == 1) return n;
	else {
		return fib(n - 1) + fib(n - 2); //��� �Լ� �̿��ؼ�
	}
}