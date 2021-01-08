#include <stdio.h>
#include <string.h>
#include <ctime>
#include <math.h>
// ���丮�� �Լ�
int factorial(int);

int main()
{
	//��������� n �Է� �ޱ�
	int n;
	printf("n = ");
	scanf_s("%d", &n);

	//�ð� ���� ����
	clock_t start, end;

	//���丮�� ��� ���� ����
	long result;

	// ms������ �ð� �����ؼ� ���丮�� ���
	start = clock();
	result = factorial(n);
	end = clock();

	//��� ���
	printf("The factorial of %d = %ld\n", n, result);
	printf("The execution time = %.2f nsec\n", (double)(end - start) / pow(10.0, 3.0));

}

//���丮�� �Լ�
int factorial(int n)
{
	//���丮�� ���
	if (n == 0 || n == 1) return 1;
	else {
		return n * factorial(n - 1); //����Լ��� �̿���
	}
}