#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//a, b�� ū �� �����ִ� ��ũ�� �Լ�
#define MAX(a,b) (((a)>(b))? (a):(b))
//MAX_DEGREE �� ��ũ�η� ����
#define MAX_DEGREE 101

//���׽� ����ü
typedef struct {
	int degree;             //����
	int coef[MAX_DEGREE];   //���
}polynomial;

//���׽ĳ��� ���ϴ� �Լ�
polynomial poly_add(polynomial, polynomial);
//���׽Ŀ� x ���� ������ ����ϴ� �Լ�
int poly_cal(polynomial, int);

int main()
{
	FILE *fp;           //���� ������
	int x;              //x��
	polynomial p, q, r; //���׽� p,q,r

	//�б� ���� �� ���� ����, poly1.txt, poly2.txt, poly3.txt
	fp = fopen("poly3.txt", "r");
	//���Ͽ��� ó�� ����, p�� ���� �� �б�
	fscanf(fp, "%d", &p.degree);
	//�׸��� p�� ����� �о�ͼ� �迭�� ����
	for (int i = 0; i <= p.degree; i++) {
		fscanf(fp, "%d", &p.coef[i]);
	}

	//���Ͽ��� q�� ���� �� �б�
	fscanf(fp, "%d", &q.degree);
	//�׸��� q�� ����� �о�ͼ� �迭�� ����
	for (int j = 0; j <= q.degree; j++) {
		fscanf(fp, "%d", &q.coef[j]);
	}
	
	//x�� �о����
	fscanf(fp, "%d", &x);

	//�� �о������ ���� �ݱ�
	fclose(fp);

	//���׽� p�� q�� ���ؼ� ���׽� r ���
	r = poly_add(p, q);
	//�׸��� r�� x�� �����ؼ� ��� ���
	int result = poly_cal(r, x);

	//���׽� p ���
	printf("p(x) = ");
	for (int i = 0; i <= p.degree; i++) {
		printf("%dx^%d", p.coef[i], i);
		if (i != p.degree) printf(" + ");
	}
	printf("\n");
	//���׽� q ���
	printf("q(x) = ");
	for (int i = 0; i <= q.degree; i++) {
		printf("%dx^%d", q.coef[i], i);
		if (i != q.degree) printf(" + ");
	}
	printf("\n\n");
	//���׽� r ���
	printf("r(x) = ");
	for (int i = 0; i <= r.degree; i++) {
		printf("%dx^%d", r.coef[i], i);
		if (i != r.degree) printf(" + ");
	}
	printf("\n");
	//x���� r�� ����� �� ���
	printf("r(%d) = %d", x, result);
}

//���׽� ���ϴ� �Լ�
polynomial poly_add(polynomial p, polynomial q) {
	//��� ���׽� r
	polynomial r;

	//p, q, r ���׽��� index��
	int pindex = 0, qindex = 0, rindex = 0;
	//r�� ���� ���
	r.degree = MAX(p.degree, q.degree);
	//���⼭ ����� p�� q�� ���� ��
	int p_degree = p.degree;
	int q_degree = q.degree;

	//index���� �������� �۰ų� ���� �� ������ �ݺ�
	while (pindex <= p.degree && qindex <= q.degree) {
		//q�������� p������ Ŭ ��
		if (p_degree > q_degree) {
			//�׶� p���� �״�� r�� ����
			r.coef[r.degree-rindex++] = p.coef[p.degree-pindex++];
			p_degree--;  //�׸��� ���� p ������ �Ѿ��
		}
		//p������ q ������ ���� ��
		else if (p_degree == q_degree) {
			//������ ���� ���� p�� q�� ��� �� ���ؼ� r�� ��� ���ϱ�
			r.coef[r.degree-rindex++] = p.coef[p.degree-pindex++] + q.coef[q.degree-qindex++];
			p_degree--; q_degree--; //�׸��� ���� p�� q ������ �Ѿ��
		}
		//p�������� q������ Ŭ ��
		else {
			//�� �� q���� �״�� r�� ����
			r.coef[r.degree-rindex++] = q.coef[q.degree-qindex++];
			q_degree--;   //�׸��� ���� q ������ �Ѿ��
		}
	}
	//����� r �� ��ȯ
	return r;
}

//���׽Ŀ� x ���� ������ ����ϴ� �Լ�
int poly_cal(polynomial poly, int x) {
	//ó�� poly�� ����� ���p�� ���� �־��ֱ�
	int p = poly.coef[0];
	//����� ������ x ��
	int xpower = 1;
	//poly�� ���� ��ŭ �ݺ�
	for (int i = 1; i <= poly.degree; i++) {
		//x�� ���
		xpower = xpower * x;
		//������� x�� ���ؼ� ����� ���ϱ�
		p += poly.coef[i] * xpower;
	}
	//����� ��ȯ
	return p;
}