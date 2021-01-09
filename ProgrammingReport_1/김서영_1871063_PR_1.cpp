#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 연결 리스트의 노드의 구조
typedef struct ListNode {
	int coef;                //계수
	int exp;                 //차수
	struct ListNode *link;   //다음 노드
} ListNode;

// 연결 리스트 헤더
typedef struct ListHeader {
	int length;              //연결리스트 노드의 개수
	ListNode *head;          //첫 노드
	ListNode *tail;          //마지막 노드
} ListHeader;

//필요한 함수들 선언
void init(ListHeader *);
void insert_node_last(ListHeader *, int, int);
ListHeader* poly_read(FILE *fp, ListHeader *);
ListHeader* poly_add(ListHeader *, ListHeader *, ListHeader *);
int poly_eval(ListHeader*, int);
void poly_print(ListHeader*);

//메인 함수
int main(void)
{
	ListHeader p_hn, q_hn, r_hn;    //차례로 p(x), q(x), r(x)의 헤드 노드
	ListHeader *p_hp, *q_hp, *r_hp; //차례로 p, q, r 다항식의 헤드 노드를 가리키는 헤드포인터
	int p, q, r;                    //p(x), q(x), r(x) 다항식에 인자로 넣을 값들
	
	//연결리스트의 초기화
	init(&p_hn); init(&q_hn); init(&r_hn);

	//읽기 모드로 열 파일 결정, poly1.txt, poly2.txt, poly3.txt
	FILE *fp = fopen("poly4.txt", "r");//읽기모드로 파일 열기
	p_hp = poly_read(fp, &p_hn);         //p(x)
	q_hp = poly_read(fp, &q_hn);         //q(x)
	fscanf(fp, "%d", &p);                //p(x)에 인자로 넣을 x값
	fscanf(fp, "%d", &q);                //q(x)에 인자로 넣을 x값
	fscanf(fp, "%d", &r);                //r(x)에 인자로 넣을 x값
	fclose(fp);                        //파일 닫기

	//p(x)와 q(x)의 합으로 r(x) 계산
	r_hp = poly_add(p_hp, q_hp, &r_hn);

	//다항식 출력
	printf("p(x) = "); poly_print(p_hp);     //p(x)
	printf("\nq(x) = "); poly_print(q_hp);   //q(x)
	printf("\nr(x) = "); poly_print(r_hp);   //r(x)
	//다항식에 인자 대입한 결과값 출력
	printf("\np(%d) = %d", p, poly_eval(p_hp, p)); //p(x)
	printf("\nq(%d) = %d", q, poly_eval(q_hp, q)); //q(x)
	printf("\nr(%d) = %d", r, poly_eval(r_hp, r)); //r(x)
}


//초기화 함수
void init(ListHeader *hp)
{
	//해당 연결 리스트를 초기화 시킨다
	hp->length = 0;
	hp->head = hp->tail = NULL;
}


//연결리스트에 노드를 last에 추가하는 함수
void insert_node_last(ListHeader *hp, int coef, int exp)
{
	ListNode *temp = (ListNode *)malloc(sizeof(ListNode)); //노드를 위한 공간 할당
	//예외처리: 공간을 할당 받지 못했을 경우 비정상 종료
	if (temp == NULL) {
		exit(1);
	}
	//노드에 값 추가
	temp->coef = coef;         //계수
	temp->exp = exp;           //차수
	temp->link = NULL;         //다음 노드는 아직 NULL

	if (hp->tail == NULL) {             //첫 node일 경우
		hp->head = hp->tail = temp;     //헤드노드의 head과 tail이 모두 temp를 가리킴
	}
	else {
		hp->tail->link = temp;         //원래 마지막이었던 node가 temp를 가리키고
		hp->tail = temp;               //마지막 node가 temp가 됨
	}
	hp->length++;               //연결 리스트의 길이 +1
}


//외부 파일로부터 값을 읽어서 연결리스트로 다항식 만드는 함수
ListHeader* poly_read(FILE *fp, ListHeader* hp)
{
	int num = 0;             //다항식의 0이 아닌 항의 개수
	fscanf(fp, "%d", &num);  //항 개수 읽어오기
	
	//항 개수 만큼 다항식의 계수, 차수들 읽어오기
	for (int i = 0; i < num; i++) {
		int temp_coef = 0, temp_exp = 0;
		fscanf(fp, "%d", &temp_coef);              //계수
		fscanf(fp, "%d", &temp_exp);               //차수
		insert_node_last(hp, temp_coef, temp_exp); //읽어온 계수와 차수로 노드 만들기
	}
	return hp;        //연결리스트의 헤드노드 포인터 리턴
}

//두 다항식을 더하여 새로운 다항식 만드는 함수
ListHeader* poly_add(ListHeader *hp1, ListHeader *hp2, ListHeader *hp3)
{
	ListNode *p = hp1->head;      //다항식1의 노드들을 살펴볼 포인터
	ListNode *q = hp2->head;      //다항식2의 노드들을 살펴볼 포인터
	int sum;                      //계수들의 합

	//두 다항식 중 하나가 다음 노드가 없을 경우까지 반복
	while (p && q) {
		//다항식1 차수 == 다항식2 차수
		if (p->exp == q->exp) {
			sum = p->coef + q->coef;                          //계수 더해서
			if (sum != 0) insert_node_last(hp3, sum, p->exp); //노드 추가
			p = p->link; q = q->link;                         //다음 노드로 이동
		}
		//다항식1 차수 > 다항식2 차수
		else if (p->exp > q->exp) {
			insert_node_last(hp3, p->coef, p->exp);           //다항식1 노드 그대로 노드 추가
			p = p->link;                                      //다항식1의 다음 노드로 이동
		}
		//다항식1 차수 < 다항식2 차수
		else {
			insert_node_last(hp3, q->coef, q->exp);           //다항식2 노드 그대로 노드 추가
			q = q->link;                                      //다항식2의 다음 노드로 이동
		}
	}
	//p나 q중의 하나가 먼저 끝나게 되면 남아있는 항들을 모두
	//결과 다항식으로 복사
	for (; p != NULL; p = p->link)              //p(x)항이 남았을 경우
		insert_node_last(hp3, p->coef, p->exp);
	for (; q != NULL; q = q->link)              //q(x)항이 남았을 경우
		insert_node_last(hp3, q->coef, q->exp);

	return hp3;                //새로운 다항식의 헤더 노드를 가리키는 포인터 반환
}

//주어진 정수값 x에 대하여 다항식의 값을 계산하는 함수
int poly_eval(ListHeader *hp, int n)
{
	int sum = 0;              //결과값
	ListNode *now = hp->head; //노드들을 살펴볼 포인터

	//노드 포인터가 NULL일때까지 반복
	for (; now != NULL; now = now->link) {
		//만약 정수값이 0이면
		if (n == 0) {
			now = hp->tail;
			//차수가 0인 항의 계수가 결과값
			if (now->exp == 0) return now->coef;
			//차수가 0인 항이 없으면 결과값은 0
			else return 0;
		}
		//만약 정수값이 1이면 결과값은 모두 계수들을 더한 값
		else if (n == 1) {
			sum += now->coef;
		}
		//그 외는 계수*정수값**차수
		else {
			sum += ((now->coef) * pow(n, (now->exp)));
		}
	}

	return sum;     //결과값 반환
}

//주어진 다항식을 출력
void poly_print(ListHeader *hp)
{
	if (hp->length == 0) {          //만약 리스트 길이가 0이면 살펴볼 필요 없이
		printf("0");                //0 리턴
	}
	else {                          //그 외
		ListNode *now = hp->head;       //노드들을 살펴볼 포인터
		for (int i = 0; i < hp->length - 1; i++) {
			printf("%dx^%d + ", now->coef, now->exp); //포인터 이동하면서 항과 +기호 출력
			now = now->link;
		}
		printf("%dx^%d", now->coef, now->exp);        //마지막항은 +가 없어야 하므로 따로 출력
	}
}

