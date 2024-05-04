//202112894 이경원 3주차 qz1-2: 다항식의 뺄셈 2

#include <stdio.h>
#include <stdlib.h>

#define max_terms 101

typedef struct {
	float coef;
	int expon;
} polynomial;

polynomial terms[max_terms] = { { 8,3 },{ 7,1 },{ 1,0 },{ 10,3 },{ 3,2 },{ 1,0 } };
int avail = 6;

char compare(int a, int b) {
	if (a > b) return'>';
	else if (a == b) return '=';
	else return '<';
}

void attach(float coef, int expon) {
	if (avail > max_terms) {
		fprintf(stderr, "항의 개수가 너무 많음.\n");
		exit(1);
	}
	terms[avail].coef = coef;
	terms[avail].expon = expon;
	avail++;
}

void poly_sub2(int astart, int aend, int bstart, int bend, int* cstart, int* cend) {
	float tempcoef;
	*cstart = avail;
	while (astart <= aend && bstart <= bend) {
		switch (compare(terms[astart].expon, terms[bstart].expon)) {
		case '>':
			attach(terms[astart].coef, terms[astart].expon);
			astart++;
			break;
		case '=':
			tempcoef = terms[astart].coef - terms[bstart].coef;
			if (tempcoef)
				attach(tempcoef, terms[astart].expon);
			astart++;
			bstart++;
			break;
		case '<': 
			attach(terms[bstart].coef, terms[bstart].expon);
			bstart++;
			break;
		}
	}

	for (; astart <= aend; astart++)
		attach(terms[astart].coef, terms[astart].expon);
	for (; bstart <= bend; bstart++)
		attach(terms[bstart].coef, terms[bstart].expon);
	*cend = avail - 1;
}

void print_poly(int start, int end) {
	for (int i = start; i < end; i++)
		printf("%3.1fx^%d + ", terms[i].coef, terms[i].expon);
	printf("%3.1fx^%d\n", terms[end].coef, terms[end].expon);
}

int main(void) {
	int astart = 0, aend = 2, bstart = 3, bend = 5, cstart, cend;
	poly_sub2(astart, aend, bstart, bend, &cstart, &cend);
	print_poly(astart, aend);
	print_poly(bstart, bend);
	printf("-----------------------------------------------------------------------------\n");
	print_poly(cstart, cend);
	return 0;
}