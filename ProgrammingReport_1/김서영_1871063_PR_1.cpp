#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// ���� ����Ʈ�� ����� ����
typedef struct ListNode {
	int coef;                //���
	int exp;                 //����
	struct ListNode *link;   //���� ���
} ListNode;

// ���� ����Ʈ ���
typedef struct ListHeader {
	int length;              //���Ḯ��Ʈ ����� ����
	ListNode *head;          //ù ���
	ListNode *tail;          //������ ���
} ListHeader;

//�ʿ��� �Լ��� ����
void init(ListHeader *);
void insert_node_last(ListHeader *, int, int);
ListHeader* poly_read(FILE *fp, ListHeader *);
ListHeader* poly_add(ListHeader *, ListHeader *, ListHeader *);
int poly_eval(ListHeader*, int);
void poly_print(ListHeader*);

//���� �Լ�
int main(void)
{
	ListHeader p_hn, q_hn, r_hn;    //���ʷ� p(x), q(x), r(x)�� ��� ���
	ListHeader *p_hp, *q_hp, *r_hp; //���ʷ� p, q, r ���׽��� ��� ��带 ����Ű�� ���������
	int p, q, r;                    //p(x), q(x), r(x) ���׽Ŀ� ���ڷ� ���� ����
	
	//���Ḯ��Ʈ�� �ʱ�ȭ
	init(&p_hn); init(&q_hn); init(&r_hn);

	//�б� ���� �� ���� ����, poly1.txt, poly2.txt, poly3.txt
	FILE *fp = fopen("poly4.txt", "r");//�б���� ���� ����
	p_hp = poly_read(fp, &p_hn);         //p(x)
	q_hp = poly_read(fp, &q_hn);         //q(x)
	fscanf(fp, "%d", &p);                //p(x)�� ���ڷ� ���� x��
	fscanf(fp, "%d", &q);                //q(x)�� ���ڷ� ���� x��
	fscanf(fp, "%d", &r);                //r(x)�� ���ڷ� ���� x��
	fclose(fp);                        //���� �ݱ�

	//p(x)�� q(x)�� ������ r(x) ���
	r_hp = poly_add(p_hp, q_hp, &r_hn);

	//���׽� ���
	printf("p(x) = "); poly_print(p_hp);     //p(x)
	printf("\nq(x) = "); poly_print(q_hp);   //q(x)
	printf("\nr(x) = "); poly_print(r_hp);   //r(x)
	//���׽Ŀ� ���� ������ ����� ���
	printf("\np(%d) = %d", p, poly_eval(p_hp, p)); //p(x)
	printf("\nq(%d) = %d", q, poly_eval(q_hp, q)); //q(x)
	printf("\nr(%d) = %d", r, poly_eval(r_hp, r)); //r(x)
}


//�ʱ�ȭ �Լ�
void init(ListHeader *hp)
{
	//�ش� ���� ����Ʈ�� �ʱ�ȭ ��Ų��
	hp->length = 0;
	hp->head = hp->tail = NULL;
}


//���Ḯ��Ʈ�� ��带 last�� �߰��ϴ� �Լ�
void insert_node_last(ListHeader *hp, int coef, int exp)
{
	ListNode *temp = (ListNode *)malloc(sizeof(ListNode)); //��带 ���� ���� �Ҵ�
	//����ó��: ������ �Ҵ� ���� ������ ��� ������ ����
	if (temp == NULL) {
		exit(1);
	}
	//��忡 �� �߰�
	temp->coef = coef;         //���
	temp->exp = exp;           //����
	temp->link = NULL;         //���� ���� ���� NULL

	if (hp->tail == NULL) {             //ù node�� ���
		hp->head = hp->tail = temp;     //������� head�� tail�� ��� temp�� ����Ŵ
	}
	else {
		hp->tail->link = temp;         //���� �������̾��� node�� temp�� ����Ű��
		hp->tail = temp;               //������ node�� temp�� ��
	}
	hp->length++;               //���� ����Ʈ�� ���� +1
}


//�ܺ� ���Ϸκ��� ���� �о ���Ḯ��Ʈ�� ���׽� ����� �Լ�
ListHeader* poly_read(FILE *fp, ListHeader* hp)
{
	int num = 0;             //���׽��� 0�� �ƴ� ���� ����
	fscanf(fp, "%d", &num);  //�� ���� �о����
	
	//�� ���� ��ŭ ���׽��� ���, ������ �о����
	for (int i = 0; i < num; i++) {
		int temp_coef = 0, temp_exp = 0;
		fscanf(fp, "%d", &temp_coef);              //���
		fscanf(fp, "%d", &temp_exp);               //����
		insert_node_last(hp, temp_coef, temp_exp); //�о�� ����� ������ ��� �����
	}
	return hp;        //���Ḯ��Ʈ�� ����� ������ ����
}

//�� ���׽��� ���Ͽ� ���ο� ���׽� ����� �Լ�
ListHeader* poly_add(ListHeader *hp1, ListHeader *hp2, ListHeader *hp3)
{
	ListNode *p = hp1->head;      //���׽�1�� ������ ���캼 ������
	ListNode *q = hp2->head;      //���׽�2�� ������ ���캼 ������
	int sum;                      //������� ��

	//�� ���׽� �� �ϳ��� ���� ��尡 ���� ������ �ݺ�
	while (p && q) {
		//���׽�1 ���� == ���׽�2 ����
		if (p->exp == q->exp) {
			sum = p->coef + q->coef;                          //��� ���ؼ�
			if (sum != 0) insert_node_last(hp3, sum, p->exp); //��� �߰�
			p = p->link; q = q->link;                         //���� ���� �̵�
		}
		//���׽�1 ���� > ���׽�2 ����
		else if (p->exp > q->exp) {
			insert_node_last(hp3, p->coef, p->exp);           //���׽�1 ��� �״�� ��� �߰�
			p = p->link;                                      //���׽�1�� ���� ���� �̵�
		}
		//���׽�1 ���� < ���׽�2 ����
		else {
			insert_node_last(hp3, q->coef, q->exp);           //���׽�2 ��� �״�� ��� �߰�
			q = q->link;                                      //���׽�2�� ���� ���� �̵�
		}
	}
	//p�� q���� �ϳ��� ���� ������ �Ǹ� �����ִ� �׵��� ���
	//��� ���׽����� ����
	for (; p != NULL; p = p->link)              //p(x)���� ������ ���
		insert_node_last(hp3, p->coef, p->exp);
	for (; q != NULL; q = q->link)              //q(x)���� ������ ���
		insert_node_last(hp3, q->coef, q->exp);

	return hp3;                //���ο� ���׽��� ��� ��带 ����Ű�� ������ ��ȯ
}

//�־��� ������ x�� ���Ͽ� ���׽��� ���� ����ϴ� �Լ�
int poly_eval(ListHeader *hp, int n)
{
	int sum = 0;              //�����
	ListNode *now = hp->head; //������ ���캼 ������

	//��� �����Ͱ� NULL�϶����� �ݺ�
	for (; now != NULL; now = now->link) {
		//���� �������� 0�̸�
		if (n == 0) {
			now = hp->tail;
			//������ 0�� ���� ����� �����
			if (now->exp == 0) return now->coef;
			//������ 0�� ���� ������ ������� 0
			else return 0;
		}
		//���� �������� 1�̸� ������� ��� ������� ���� ��
		else if (n == 1) {
			sum += now->coef;
		}
		//�� �ܴ� ���*������**����
		else {
			sum += ((now->coef) * pow(n, (now->exp)));
		}
	}

	return sum;     //����� ��ȯ
}

//�־��� ���׽��� ���
void poly_print(ListHeader *hp)
{
	if (hp->length == 0) {          //���� ����Ʈ ���̰� 0�̸� ���캼 �ʿ� ����
		printf("0");                //0 ����
	}
	else {                          //�� ��
		ListNode *now = hp->head;       //������ ���캼 ������
		for (int i = 0; i < hp->length - 1; i++) {
			printf("%dx^%d + ", now->coef, now->exp); //������ �̵��ϸ鼭 �װ� +��ȣ ���
			now = now->link;
		}
		printf("%dx^%d", now->coef, now->exp);        //���������� +�� ����� �ϹǷ� ���� ���
	}
}

