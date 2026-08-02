#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct testTag {
	int value;
	char str[20];
}test;
int main() {
	test* p = (test*)malloc(sizeof(test));
	if (p == NULL) {
		fprintf(stderr, "error!");
		exit(1);
	}
	p->value = 100;
	strcpy_s(p->str, sizeof(p->str), "just testing");
	printf("%d, %s\n", p->value, p->str);
	free(p);
	return 0;
}

//#include <stdio.h>
//
//int array[50];
//int items = 0;
//void insert(int arr[], int loc, int value) {
//	if(loc < items){
//		for (int i = items; i > loc; i--) {
//			arr[i] = arr[i - 1];
//		}
//	}
//	items++;
//	arr[loc] = value;
//}
//void delete1(int arr[], int loc) {
//	for (int i = loc; i < items-1; i++) {
//		arr[i] = arr[i + 1];
//	}
//	items--;
//  arr[items] = NULL;
//}
//int main() {
//	for (int i = 0; i < 10; i++) {
//		array[i] = i;
//		items++;
//	}
//	for (int i = 0; i < 10; i++) {
//		printf("%d", array[i]);
//	}
//	printf("\n");
//	insert(array, 2, 7);
//	
//	for (int i = 0; i <= 10; i++) {
//		printf("%d", array[i]);
//	}
//	printf("\n");
//	delete1(array, 2);
//	for (int i = 0; i < 10; i++) {
//		printf("%d", array[i]);
//	}
//	printf("\n%d\n", items);
//	return 0;
//}


//#include <stdio.h>
//
//typedef struct complexTag {
//	float real;
//	float imaginary;
//}complex;
//complex complex_add(complex a, complex b) {
//	complex c;
//	c.real = a.real + b.real;
//	c.imaginary = a.imaginary + b.imaginary;
//	return c;
//}
//int main() {
//	complex c1 = { 12.12, 12.34 };
//	complex c2 = { 12.34, 12.12 };
//	complex c3 = complex_add(c1, c2);
//
//	printf("%f, %f\n", c3.real, c3.imaginary);
//	return 0;
//}

//#include <stdio.h>
//
//typedef struct complexTag{
//	float real;
//	float imaginary;
//}complex;
//int main() {
//	complex c1 = { 12.12, 12.34 };
//	complex c2 = { 12.34, 12.12 };
//	printf("%f, %f\n", c1.real, c2.imaginary);
//	return 0;
//}

//#include <stdio.h>
//
//struct person{
//	char name[10];
//	int age;
//	float salary;
//};
//int main() {
//	struct person s = { "ymg", 26, 0 };
//	printf("%s, %d", s.name, s.age);
//	return 0;
//}

//#include <stdio.h>
//int two[10];
//
//int main() {
//	for (int i = 0; i < 10; i++) {
//		two[i] = 1;
//		for (int j = 0; j < i; j++) {
//			two[i] *= 2;
//		}
//	}
//	for (int i = 0; i < 10; i++) {
//		printf("%d\n", two[i]);
//	}
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//typedef struct studentTag {
//	char name[10];
//	int age;
//	double gpa;
//}student;
//
//int main() {
//	student *s = (student *)malloc(sizeof(student));
//	if (s == NULL) {
//		fprintf(stderr, "error!\n");
//		exit(1);
//	}
//	strcpy_s(s->name, sizeof(s->name), "Park");
//	s->age = 20;
//	s->gpa = 4.38;
//
//	printf("%s, %d, %lf", s->name, s->age, s->gpa);
//	free(s);
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#define SIZE 10
//
//int main() {
//	int* p = (int*)malloc(10 * sizeof(int));
//	if (p == NULL) {
//		fprintf(stderr, "error!\n");
//		exit(1);
//	}
//	for (int i = 0; i < SIZE; i++) {
//		p[i] = i;
//	}
//	for (int i = 0; i < SIZE; i++) {
//		printf("%d\n", *(p + i));
//	}
//	free(p);
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#define SIZE 10
//
//int main() {
//	int *p = (int*)malloc(10 * sizeof(int));
//	if (p == NULL) {
//		fprintf(stderr, "error!\n");
//		exit(1);
//	}
//	for (int i = 0; i < SIZE; i++) {
//		p[i] = i;
//	}
//	for (int i = 0; i < SIZE; i++) {
//		printf("%d\n", *(p + i));
//	}
//	free(p);
//	return 0;
//}

//#include <stdio.h>
//#define SIZE 6
//void get_integers(int list[]) {
//	for (int i = 0; i < SIZE; i++) {
//		scanf_s("%d", &list[i]);
//	}
//}
//int main() {
//	int list[6];
//	get_integers(list);
//	for (int i = 0; i < SIZE; i++) {
//		printf("%d", list[i]);
//	}
//	return 0;
//}

//#include <stdio.h>
//void swap(int *a, int *b) {
//	int temp;
//	temp = *a;
//	*a = *b;
//	*b = temp;
//}
//int main() {
//	int a, b;
//	a = 100;
//	b = 200;
//	swap(&a, &b);
//	printf("%d,%d\n", a, b);
//	return 0;
//}

//#include <stdio.h>
//#define ROWS 3
//#define COLS 3
//
//void add_matrix(int A[ROWS][COLS], int B[ROWS][COLS], int C[ROWS][COLS]) {
//	for (int i = 0; i < ROWS; i++) {
//		for (int j = 0; j < COLS; j++) {
//			C[i][j] = A[i][j] + B[i][j];
//		}
//	}
//}
//void matrix_print(int A[ROWS][COLS]) {
//	printf("======================\n");
//	for (int i = 0; i < ROWS; i++) {
//		for (int j = 0; j < COLS; j++) {
//			printf("%d", A[i][j]);
//		}
//		printf("\n");
//	}
//	printf("=======================\n");
//}
//int main() {
//	int array1[ROWS][COLS] = { {2, 3, 0},{8, 9, 1},{7,0,5} };
//	int array2[ROWS][COLS] = { {1,2,3},{3,2,5},{8,3,1} };
//	int array3[ROWS][COLS];
//	add_matrix(array1, array2,array3);
//	matrix_print(array1);
//	matrix_print(array2);
//	matrix_print(array3);
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#define MAX_TERMS 100
//
//typedef struct elementTag{
//	int row;
//	int col;
//	int value;
//}element;
//typedef struct SparseMatrixTag {
//	element data[MAX_TERMS];
//	int rows;
//	int cols;
//	int terms;
//}SparseMatrix;
//
//SparseMatrix matrix_transepose2(SparseMatrix a) {
//	SparseMatrix b;
//	int bindex = 0;
//	b.rows = a.cols;
//	b.cols = a.rows;
//	b.terms = a.terms;
//
//	for (int i = 0; i < a.cols; i++) {
//		for (int j = 0; j < a.terms; j++) {
//			if (a.data[j].col == i) {
//				b.data[bindex].row = a.data[j].col;
//				b.data[bindex].col = a.data[j].row;
//				b.data[bindex].value = a.data[j].value;
//				bindex++;
//			}
//		}
//	}
//	
//	return b;
//}
//
//void matrix_print(SparseMatrix a) {
//	printf("==================================\n");
//	for (int i = 0; i < a.terms; i++) {
//		printf("(%d,%d,%d)\n", a.data[i].row, a.data[i].col, a.data[i].value);
//	}
//	printf("==================================\n");
//}
//
//int main() {
//	SparseMatrix m = { { {0,3,7},{1,0,9},{1,5,8},{3,0,6},{3,1,5},{4,5,1},{5,2,2} }, 6, 6, 7 };
//	SparseMatrix rslt;
//
//	rslt = matrix_transepose2(m);
//	matrix_print(rslt);
//
//	return 0;
//}

//#include <stdio.h>
//#define ROWS 3
//#define COLS 3
//
//void matrix_transpose(int A[ROWS][COLS], int B[COLS][ROWS]) {
//	for (int i = 0; i < ROWS; i++) {
//		for (int j = 0; j < COLS; j++) {
//			B[j][i] = A[i][j];
//		}
//	}
//}
//void matrix_print(int A[ROWS][COLS]) {
//	printf("======================\n");
//	for (int i = 0; i < ROWS; i++) {
//		for (int j = 0; j < COLS; j++) {
//			printf("%d", A[i][j]);
//		}
//		printf("\n");
//	}
//	printf("=======================\n");
//}
//int main() {
//	int array1[ROWS][COLS] = { {2, 3, 0},{8, 9, 1},{7,0,5} };
//	int array2[COLS][ROWS];
//	matrix_transpose(array1, array2);
//	matrix_print(array1);
//	matrix_print(array2);
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#define MAX_TERMS 101
//
//struct {
//	float coef;
//	int expon;
//} terms[MAX_TERMS] = { {8,3}, {7,1}, {1,0}, {10, 3}, {3,2}, {1,0} };
//int avail = 6;
//
//float poly_eval(int As, int Ae, int x) {
//	float rslt = 0;
//	for (int i = As; i <=  Ae; i++) {
//		int start = 1;
//		for (int j = terms[i].expon; j > 0; j--) {
//			start *= x;
//		}
//		rslt += terms[i].coef * start;
//	}
//	return rslt;
//}
//
//int main() {
//	int As = 0, Ae = 2, Bs = 3, Be = 5, Cs, Ce;
//	float a = poly_eval(As, Ae, 2);
//	printf("%f\n", a);
//	return 0;
//}

//#include <stdio.h>
//#define MAX(a,b) ((a) > (b))?(a):(b)
//#define MAX_DEGREE 101
//
//typedef struct polynomialTag {
//	int degree;
//	float coef[MAX_DEGREE];
//}polynomial;
//
//float poly_eval(polynomial A, int x) {
//	float rslt = 0;
//	for (int i = 0; i < A.degree; i++) {
//		rslt += A.coef[i];
//		rslt *= x;
//	}
//	rslt += A.coef[A.degree];
//	return rslt;
//}
//
//
//
//int main() {
//	polynomial a = { 7, {-1, 3, 10, 0, 0, 0, 6, 3} };
//	polynomial b = { 7 , {1, -3, -10, 4, 1, 2, 4, 8} };
//
//	float A = poly_eval(a, 2);
//	printf("%lf\n", A);
//
//
//	return 0;
//}

//#include <stdio.h>
//#define MAX(a,b) ((a) > (b))?(a):(b)
//#define MAX_DEGREE 101
//
//typedef struct polynomialTag {
//	int degree;
//	float coef[MAX_DEGREE];
//}polynomial;
//
//float poly_eval(polynomial A,int x) {
//	float rslt = 0;
//	int start;
//	for (int i = A.degree; i > 0; i--) {
//		start = 1;
//		for (int j = i; j > 0; j--) {
//			start *= x;
//		}
//		rslt += A.coef[A.degree - i] * start;
//	}
//	rslt += A.coef[A.degree];
//	return rslt;
//}
//
//
//
//int main() {
//	polynomial a = { 7, {-1, 3, 10, 0, 0, 0, 6, 3} };
//	polynomial b = { 7 , {1, -3, -10, 4, 1, 2, 4, 8} };
//
//	float A = poly_eval(a, 2);
//	printf("%lf\n", A);
//
//	
//	return 0;
//}

//#include <stdio.h>
//#define MAX(a,b) ((a) > (b))?(a):(b)
//#define MAX_DEGREE 101
//
//typedef struct polynomialTag {
//	int degree;
//	float coef[MAX_DEGREE];
//}polynomial;
//
//polynomial poly_add1(polynomial A, polynomial B) { 
//	polynomial C;
//	int Apos = 0, Bpos = 0, Cpos = 0;
//	int degree_a = A.degree;
//	int degree_b = B.degree;
//	int shift = 0;
//	C.degree = MAX(A.degree, B.degree);
//
//	while (Apos <= A.degree && Bpos <= B.degree) {
//		if (degree_a > degree_b) {
//			C.coef[Cpos++] = A.coef[Apos++];
//			degree_a--;
//		}
//		else if (degree_a == degree_b) {
//			C.coef[Cpos++] = A.coef[Apos++] + B.coef[Bpos++];
//			degree_a--;
//			degree_b--;
//		}
//		else {
//			C.coef[Cpos++] = B.coef[Bpos++];
//			degree_b--;
//		}
//	}
//	while (shift < C.degree && C.coef[shift] == 0) {
//		shift++;
//	}
//	if (shift > 0) {
//		for (int i = 0; i <= C.degree - shift; i++) {
//			C.coef[i] = C.coef[i + shift];
//		}
//		C.degree -= shift;
//	}
//	
//	return C;
//}
//void poly_read(polynomial A) {
//	int first = 1;
//	for (int i = 0; i <= A.degree; i++) {
//		if (A.coef[i] == 0) continue;
//		if (!first) {
//			printf("+");
//		}
//		if (A.degree - i == 0) {
//			printf("%3.1f", A.coef[i]);
//		}
//		else {
//			printf("%3.1fx^%d", A.coef[i], A.degree - i);
//		}
//		first = 0;
//	}
//	if (first) printf("0.0");
//	printf("\n");
//}
//
//int main() {
//	polynomial a = { 7, {-1, 3, 10, 0, 0, 0, 6, 3} };
//	polynomial b = { 7 , {1, -3, -10, 4, 1, 2, 4, 8} };
//
//	polynomial c = poly_add1(a, b);
//
//	printf("결과 다항식 차수: %d\n", c.degree);
//	printf("계수 목록: ");
//	for (int i = 0; i <= c.degree; i++) {
//		printf("%.0f ", c.coef[i]);
//	}
//	printf("\n");
//	poly_read(a);
//	poly_read(c);
//	return 0;
//}
//
//#include <stdio.h>
//#include <stdlib.h>
//#define MAX_TERMS 101
//
//struct {
//	float coef;
//	int expon;
//} terms[MAX_TERMS] = { {8,3}, {7,1}, {1,0}, {10, 3}, {3,2}, {1,0} };
//int avail = 6;
//char compare(int a, int b) {
//	if (a > b) return '>';
//	else if (a == b) return '=';
//	else return '<';
//}
//void attach(float coef, int expon) {
//	if (avail >= MAX_TERMS) {
//		fprintf(stderr, "항의 개수가 너무 많음");
//		exit(1);
//	}
//	terms[avail].coef = coef;
//	terms[avail].expon = expon;
//	avail++;
//}
//void poly_add2(int As, int Ae, int Bs, int Be, int *Cs, int *Ce) {
//	float tempcoef;
//	*Cs = avail;
//	while (As <= Ae && Bs <= Be) {
//		switch (compare(terms[As].expon, terms[Bs].expon)) {
//		case '>':
//			attach(terms[As].coef, terms[As].expon);
//			As++;
//			break;
//		case '=':
//			tempcoef = terms[As].coef + terms[Bs].coef;
//			if (tempcoef)
//				attach(tempcoef, terms[As].expon);
//			As++;
//			Bs++;
//			break;
//		case '<':
//			attach(terms[Bs].coef, terms[Bs].expon);
//			Bs++;
//			break;
//		}
//	}
//	for (;As <= Ae; As++) 
//		attach(terms[As].coef, terms[As].expon);
//	for (;Bs <= Be; Bs++)
//		attach(terms[Bs].coef, terms[Bs].expon);
//	*Ce = avail - 1;	
//} 
//
//void print_poly(int s, int e) {
//	for (int i = s; i < e; i++)
//		printf("%3.1fx^%d + ", terms[i].coef, terms[i].expon);
//	printf("%3.1fx^%d\n", terms[e].coef, terms[e].expon);
//}
//
//int main() {
//	int As = 0, Ae = 2, Bs = 3, Be = 5, Cs, Ce;
//	poly_add2(As, Ae, Bs, Be, &Cs, &Ce);
//	print_poly(As, Ae);
//	print_poly(Bs, Be);
//	printf("------------------------------------------------\n");
//	print_poly(Cs, Ce);
//	return 0;
//}

//#include <stdio.h>
//#define MAX(a,b) ((a) > (b))?(a):(b)
//#define MAX_DEGREE 101
//
//typedef struct polynomialTag {
//	int degree;
//	float coef[MAX_DEGREE];
//}polynomial;
//
//polynomial poly_add1(polynomial A, polynomial B) { 
//	polynomial C;
//	int Apos = 0, Bpos = 0, Cpos = 0;
//	int degree_a = A.degree;
//	int degree_b = B.degree;
//	int shift = 0;
//	C.degree = MAX(A.degree, B.degree);
//
//	while (Apos <= A.degree && Bpos <= B.degree) {
//		if (degree_a > degree_b) {
//			C.coef[Cpos++] = A.coef[Apos++];
//			degree_a--;
//		}
//		else if (degree_a == degree_b) {
//			C.coef[Cpos++] = A.coef[Apos++] + B.coef[Bpos++];
//			degree_a--;
//			degree_b--;
//		}
//		else {
//			C.coef[Cpos++] = B.coef[Bpos++];
//			degree_b--;
//		}
//	}
//	while (shift < C.degree && C.coef[shift] == 0) {
//		shift++;
//	}
//	if (shift > 0) {
//		for (int i = 0; i <= C.degree - shift; i++) {
//			C.coef[i] = C.coef[i + shift];
//		}
//		C.degree -= shift;
//	}
//	
//	return C;
//}
//
//int main() {
//	polynomial a = { 7, {-1, 3, 10, 0, 0, 0, 6, 3} };
//	polynomial b = { 7 , {1, -3, -10, 4, 1, 2, 4, 8} };
//
//	polynomial c = poly_add1(a, b);
//
//	printf("결과 다항식 차수: %d\n", c.degree);
//	printf("계수 목록: ");
//	for (int i = 0; i <= c.degree; i++) {
//		printf("%.0f ", c.coef[i]);
//	}
//	printf("\n");
//	return 0;
//}

//#include <stdio.h>
//#define MAX(a,b) ((a) > (b))?(a):(b)
//#define MAX_DEGREE 101
//
//typedef struct polynomialTag {
//	int degree;
//	float coef[MAX_DEGREE];
//}polynomial;
//
//polynomial poly_add1(polynomial A, polynomial B) { 
//	polynomial C;
//	int Apos = 0, Bpos = 0, Cpos = 0;
//	int degree_a = A.degree;
//	int degree_b = B.degree;
//	C.degree = MAX(A.degree, B.degree);
//
//	while (Apos <= A.degree && Bpos <= B.degree) {
//		if (degree_a > degree_b) {
//			C.coef[Cpos++] = A.coef[Apos++];
//			degree_a--;
//		}
//		else if (degree_a == degree_b) {
//			C.coef[Cpos++] = A.coef[Apos++] + B.coef[Bpos++];
//			degree_a--;
//			degree_b--;
//		}
//		else {
//			C.coef[Cpos++] = B.coef[Bpos++];
//			degree_b--;
//		}
//	}
//	return C;
//}
//
//int main() {
//	polynomial a = { 7, {3, 3, 10, 0, 0, 0, 6, 3} };
//	polynomial b = { 7 , {5, 2, 3, 4, 1, 2, 4, 8} };
//
//	polynomial c = poly_add1(a, b);
//
//	printf("결과 다항식 차수: %d\n", c.degree);
//	printf("계수 목록: ");
//	for (int i = 0; i <= c.degree; i++) {
//		printf("%.0f ", c.coef[i]);
//	}
//	printf("\n");
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <math.h>
//#define MAX_DEGREE 101
//
//typedef struct polynomialTag {
//	int degree;
//	float coef[MAX_DEGREE];
//}polynomial;
//
//polynomial poly_add1(polynomial A, polynomial B) { // 내가 만들어 본 함수
//	polynomial C;
//	int Adegree;
//	int Bdegree;
//	int dist;
//	if (A.degree >= B.degree) {
//		dist = A.degree - B.degree;
//		C = B;
//	}
//	else {
//		dist = B.degree - A.degree;
//		C = A;
//		A = B;
//	}
//	for (int i = C.degree; i >= 0; i--) {
//		C.coef[i + dist] = C.coef[i];
//	}
//	for (int i = 0; i < dist; i++) {
//		C.coef[i] = 0;
//	}
//	for (int i = 0; i <= A.degree; i++) {
//		C.coef[i] += A.coef[i];
//	}
//	C.degree = A.degree;
//	return C;
//}
//
//int main() {
//	polynomial a = { 7, {3, 3, 10, 0, 0, 0, 6, 3} };
//	polynomial b = { 7 , {5, 2, 3, 4, 1, 2, 4, 8} };
//
//	polynomial c = poly_add1(a, b);
//
//	printf("결과 다항식 차수: %d\n", c.degree);
//	printf("계수 목록: ");
//	for (int i = 0; i <= c.degree; i++) {
//		printf("%.0f ", c.coef[i]);
//	}
//	printf("\n");
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <math.h>
//#define MAX_DEGREE 101
//
//typedef struct polynomialTag {
//	int degree;
//	float coef[MAX_DEGREE];
//}polynomial;
//
//
//int main() {
//	polynomial a = { 5, {10, 0, 0, 0, 6, 3} };
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <math.h>
//
//typedef struct pointTag {
//	int x;
//	int y;
//}Point;
//double get_distance(Point start, Point end) {
//	return sqrt(pow(start.x - end.x, 2) + pow(start.y - end.y, 2));
//}
//int main() {
//	Point p1;
//	Point p2;
//	p1 = { 1, 2 };
//	p2 = { 9, 8 };
//	printf("%f\n",get_distance(p1, p2));
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//typedef struct studentTag {
//	char name[10];
//	int age;
//	double gpa;
//}student;
// 
//int main() {
//	student ymg = { "ymg", 26, 4.38 };
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//struct studentTag{
//	char name[10];
//	int age;
//	double gpa;
//};
// 
//int main() {
//	struct studentTag ymg = { "ymg", 26, 4.38 };
//
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//struct studentTag{
//	char name[10];
//	int age;
//	double gpa;
//};
// 
//int main() {
//	struct studentTag ymg;
//	strcpy(ymg.name, "ymg");
//	ymg.age = 26;
//	ymg.gpa = 4.38;
//
//	return 0;
//}