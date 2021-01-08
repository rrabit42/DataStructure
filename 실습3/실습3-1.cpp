#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//a, b중 큰 값 돌려주는 매크로 함수
#define MAX(a,b) (((a)>(b))? (a):(b))
//MAX_DEGREE 값 매크로로 지정
#define MAX_DEGREE 101

//다항식 구조체
typedef struct {
	int degree;             //차수
	int coef[MAX_DEGREE];   //계수
}polynomial;

//다항식끼리 더하는 함수
polynomial poly_add(polynomial, polynomial);
//다항식에 x 값을 대입해 계산하는 함수
int poly_cal(polynomial, int);

int main()
{
	FILE *fp;           //파일 포인터
	int x;              //x값
	polynomial p, q, r; //다항식 p,q,r

	//읽기 모드로 열 파일 결정, poly1.txt, poly2.txt, poly3.txt
	fp = fopen("poly3.txt", "r");
	//파일에서 처음 숫자, p의 차수 값 읽기
	fscanf(fp, "%d", &p.degree);
	//그리고 p의 계수들 읽어와서 배열에 저장
	for (int i = 0; i <= p.degree; i++) {
		fscanf(fp, "%d", &p.coef[i]);
	}

	//파일에서 q의 차수 값 읽기
	fscanf(fp, "%d", &q.degree);
	//그리고 q의 계수들 읽어와서 배열에 저장
	for (int j = 0; j <= q.degree; j++) {
		fscanf(fp, "%d", &q.coef[j]);
	}
	
	//x값 읽어오기
	fscanf(fp, "%d", &x);

	//다 읽어왔으니 파일 닫기
	fclose(fp);

	//다항식 p와 q를 더해서 다항식 r 계산
	r = poly_add(p, q);
	//그리고 r에 x값 대입해서 결과 계산
	int result = poly_cal(r, x);

	//다항식 p 출력
	printf("p(x) = ");
	for (int i = 0; i <= p.degree; i++) {
		printf("%dx^%d", p.coef[i], i);
		if (i != p.degree) printf(" + ");
	}
	printf("\n");
	//다항식 q 출력
	printf("q(x) = ");
	for (int i = 0; i <= q.degree; i++) {
		printf("%dx^%d", q.coef[i], i);
		if (i != q.degree) printf(" + ");
	}
	printf("\n\n");
	//다항식 r 출력
	printf("r(x) = ");
	for (int i = 0; i <= r.degree; i++) {
		printf("%dx^%d", r.coef[i], i);
		if (i != r.degree) printf(" + ");
	}
	printf("\n");
	//x값을 r에 계산한 값 출력
	printf("r(%d) = %d", x, result);
}

//다항식 더하는 함수
polynomial poly_add(polynomial p, polynomial q) {
	//결과 다항식 r
	polynomial r;

	//p, q, r 다항식의 index값
	int pindex = 0, qindex = 0, rindex = 0;
	//r의 차수 계산
	r.degree = MAX(p.degree, q.degree);
	//여기서 사용할 p와 q의 차수 값
	int p_degree = p.degree;
	int q_degree = q.degree;

	//index값이 차수보다 작거나 같을 때 까지만 반복
	while (pindex <= p.degree && qindex <= q.degree) {
		//q차수보다 p차수가 클 때
		if (p_degree > q_degree) {
			//그때 p항은 그대로 r에 대입
			r.coef[r.degree-rindex++] = p.coef[p.degree-pindex++];
			p_degree--;  //그리고 다음 p 차수로 넘어가기
		}
		//p차수와 q 차수가 같을 때
		else if (p_degree == q_degree) {
			//차수가 같을 때는 p와 q의 계수 값 더해서 r의 계수 구하기
			r.coef[r.degree-rindex++] = p.coef[p.degree-pindex++] + q.coef[q.degree-qindex++];
			p_degree--; q_degree--; //그리고 다음 p와 q 차수로 넘어가기
		}
		//p차수보다 q차수가 클 때
		else {
			//이 때 q항은 그대로 r에 대입
			r.coef[r.degree-rindex++] = q.coef[q.degree-qindex++];
			q_degree--;   //그리고 다음 q 차수로 넘어가기
		}
	}
	//계산한 r 값 반환
	return r;
}

//다항식에 x 값을 대입해 계산하는 함수
int poly_cal(polynomial poly, int x) {
	//처음 poly의 계수를 결과p에 먼저 넣어주기
	int p = poly.coef[0];
	//계수와 곱해줄 x 값
	int xpower = 1;
	//poly의 차수 만큼 반복
	for (int i = 1; i <= poly.degree; i++) {
		//x값 계산
		xpower = xpower * x;
		//계수값에 x값 곱해서 결과에 더하기
		p += poly.coef[i] * xpower;
	}
	//결과값 반환
	return p;
}