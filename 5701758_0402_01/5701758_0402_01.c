#include <stdio.h>
#include <stdlib.h>
#define MAX_DEGREE 101

typedef struct {
	int degree;
	float coef[MAX_DEGREE];
}polynomial;

void poly_print(polynomial a); // a, b�� ���� ������
void poly_mult(polynomial a, polynomial b, polynomial* c); // ��� �Լ�

void main()
{
	int max_index = 0; // �迭 a,b �� �� �ְ� ����
	srand(time(NULL));
	polynomial a = { 3 ,{4.0, 3.0, 2.0, 1.0} };
	polynomial b = { 2 ,{3.0, 2.0, 8.0} };
	polynomial c = { 0 }; //����� ����
	poly_mult(a, b, &c);

	poly_print(a);
	poly_print(b);
	printf("-------------------------------- \n");
	poly_print(c);

	printf("\n");
	
	polynomial d = { 6, {7.0, 0.0,0.0,5.0,9.0,0.0,1.0} };
	polynomial e = { 3, {5.0, 2.0, 1.0, 10.0} };
	polynomial f = { 0 }; //����� ����
	poly_mult(d, e, &f);
	
	poly_print(d);
	poly_print(e);
	printf("-------------------------------- \n");
	poly_print(f);
}


void poly_print(polynomial a)
{
	int i, index = a.degree;
	for (i = 0; i <= a.degree; i++)
	{
		printf("%2.0fx^%d", a.coef[i], index);
		index--;
		if (i < a.degree)
			printf(" + ");
	}
	printf("\n");
}

void poly_mult(polynomial a, polynomial b, polynomial* c)
{
	int i, j;
	c->degree = a.degree + b.degree; // 3�� 4���� 7���� �ְ�
	for (i = 0; i <= a.degree; i++)
	{
		for (j = 0; j <= b.degree; j++)
		{
			c->coef[i + j] += a.coef[i] * b.coef[j];
		}
	}

}
