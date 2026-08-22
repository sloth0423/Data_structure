// 미완성
#include <stdio.h>
#include <stdlib.h>
typedef int element;
typedef struct ListNodeTag {
	element data;
	struct ListNodeTag *link;
}ListNode;
typedef struct ListTypeTag {
	int size;
	ListNode *head;
	ListNode *tail;
}ListType;
void add(ListType *list, element item) {
	if (list == NULL) return;
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	ListNode *q;
	if (p == NULL) {
		fprintf(stderr, "alloc error!");
		exit(1);
	}
	p->data = item;
	if (list->head == NULL) {
		p->link = NULL;
		list->head = p;
		list->tail = p;
		list->size++;
		return;
	}
	q = list->head;
	if (q->data >= item) {
		p->link = q;
		list->head = p;
		list->size++;
		return;
	}
	while (q->link != NULL && q->link->data < item) { 
		q = q->link;
	}
	p->link = q->link;
	q->link = p;
	if (p->link == NULL) {
		list->tail = p;
	}
	list->size++;
}
void del_element(ListType *list, element item) {
	if (list->head == NULL) return;
	ListNode *p = list->head;
	ListNode *q = NULL;

	while (p != NULL && p->data != item) {
		q = p;
		p = p->link;
}
	if (p == NULL) return; // 찾는 값이 없을 때
	if (p == list->head) {
		if (list->size == 1) { // 리스트에 단 하나의 노드만 있을 때
			list->head = NULL;
			list->tail = NULL;
			free(p);
			list->size--;
			return;
		}
		list->head = p->link; // 여러 개의 노드가 있는데 첫 번째 노드를 지울 때
		free(p);
		list->size--;
		return;
	}
	q->link = p->link;
	free(p);
	list->size--;
	if (q->link == NULL) {
		list->tail = q;
	}
	return;
}
int main() {
	
	return 0;
}
// 짜느라 정말 오래걸렸는데 이렇게 할 필요가 없던 코드
// 모든 상황을 if-else문으로 처리하려다 보니
// 자꾸 꼬이고 코드를 짜기 매우 어려웠다.
//void del_element(ListType *list, element item) {
//	if (list->head == NULL) return;
//	ListNode *p = list->head;
//	if (p->data == item) { 
//		if (list->size == 1) { // 리스트에 혼자 남은 거 지우기
//			free(p);
//			list->head = NULL;
//			list->tail = NULL;
//			list->size--;
//			return;
//		}
//		else{ // 그냥 처음 거 지우기
//			list->head = p->link;
//			free(p);
//			list->size--;
//			return;
//		}
//	}
//	if (p->link != NULL) p = p->link;
//	else return;
//	if (p->data == item) {
//		list->head->link = p->link;
//		free(p);
//		list->size--;
//		return;
//	}
//	while (p->link != NULL) {
//		if (p->link->data == item) {
//			ListNode *q = p->link;
//			p->link = p->link->link;
//			free(q);
//			list->size--;
//			return;
//		}
//		p = p->link;
//	}
//	if (p->data == item) { // 마지막 거 지우기
//		ListNode *q = list->head;
//		for (int i = 0; i < list->size - 2;i++) {
//			q = q->link;
//		}
//		q->link = NULL;
//		list->tail = q;
//		free(p);
//		list->size--;
//		return;
//	}
//}

//#include <stdio.h>
//#include <stdlib.h>
//#define MAX_ARRAY_SIZE 100
//typedef int element;
//typedef struct arrayTag{
//	element data[MAX_ARRAY_SIZE];
//	int size;
//}array;
//
//void add(array *arr, element item) {
//	if (arr->size >= MAX_ARRAY_SIZE) {
//		fprintf(stderr, "리스트가 포화상태입니다.");
//		exit(1);
//	}
//	for (int i = 0; i < arr->size; i++) {
//		if (arr->data[i] >= item) {
//			for (int j = arr->size; j > i; j--) {
//				arr->data[j] = arr->data[j - 1];
//			}
//			arr->data[i] = item;
//			arr->size++;
//			return;
//		}
//	}
//	arr->data[arr->size++] = item;
//}
//void delete_element(array *arr, element item) {
//	for (int i = 0; i < arr->size; i++) {
//		if (item == arr->data[i]) {
//			for (int j = i; j < arr->size - 1; j++) {
//				arr->data[j] = arr->data[j + 1];
//			}
//			arr->size--;
//			return;
//		}
//	}
//}
//void clear(array *arr) { // clear함수이자 초기화 함수
//	if (arr == NULL) return;
//	arr->size = 0;
//}
//void is_in_list(array *arr, element item) {
//	//is_in_list(list, item)연산은 인자로 받는 list가 정렬되어 있기 때문에
//	// 이진 탐색을 이용하면 시간 복잡도를 O(log n)으로 줄일 수 있으나 
//	// 이진 탐색은 chap13에서 다루는 것 같아 일단은 선형 탐색으로 구현하였다.
//	for (int i = 0; i < arr->size; i++) {
//		if (item == arr->data[i]) {
//			printf("리스트 안에 %d가 있습니다.\n", item);
//			return;
//		}
//	}
//	printf("리스트 안에 %d가 없습니다.\n", item);
//}
//int get_length(array *arr) {
//	return arr->size;
//}
//void is_empty(array *arr) {
//	if (arr->size == 0) {
//		printf("리스트가 공백상태입니다.\n");
//	}
//	else {
//		printf("리스트가 공백상태가 아닙니다.\n");
//	}
//}
//void is_full(array *arr) {
//	if (arr->size == MAX_ARRAY_SIZE) {
//		printf("리스트가 포화상태입니다.\n");
//	}
//	else {
//		printf("리스트가 포화상태가 아닙니다.\n");
//	}
//}
//void display(array *arr) {
//	for (int i = 0; i < arr->size; i++) {
//		printf("%d ", arr->data[i]);
//	}
//	printf("\n");
//}
//int main() {
//	array arr = {};
//	clear(&arr);
//	add(&arr, 1);
//	display(&arr);
//	add(&arr, 2);
//	display(&arr);
//	add(&arr, 3);
//	display(&arr);
//	add(&arr, 5);
//	display(&arr);
//	add(&arr, 6);
//	display(&arr);
//	add(&arr, 7);
//	display(&arr);
//	add(&arr, 4);
//	display(&arr);
//	delete_element(&arr, 4);
//	display(&arr);
//	is_in_list(&arr, 4);
//	is_in_list(&arr, 5);
//	printf("이 리스트의 길이는 %d입니다.\n", get_length(&arr));
//	is_empty(&arr);
//	is_full(&arr);
//	clear(&arr);
//	display(&arr);
//	is_empty(&arr);
//	return 0;
//}
//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct elementTag {
//	int coef;
//	int expon;
//}element;
//typedef struct ListNodeTag {
//	element data;
//	struct ListNodeTag *link;
//}ListNode;
//typedef struct ListTypeTag {
//	int size;
//	ListNode *head;
//	ListNode *tail;
//}ListType;
//
//void error(const char *message) {
//	fprintf(stderr, "%s\n", message);
//	exit(1);
//}
//ListType *create_list() {
//	ListType *list = (ListType *)malloc(sizeof(ListType));
//	if (list == NULL) error("메모리 할당 오류");
//	list->size = 0;
//	list->head = NULL;
//	list->tail = NULL;
//	return list;
//}
//void ins_last(ListType *list, element *item) {
//	ListNode *node = (ListNode *)malloc(sizeof(ListNode));
//	if (node == NULL) error("메모리 할당 오류");
//	node->data.coef = item->coef;
//	node->data.expon = item->expon;
//	node->link = NULL;
//	if (list->tail == NULL) {
//		list->head = node;
//		list->tail = node;
//	}
//	else {
//		list->tail->link = node;
//		list->tail = node;
//	}
//	list->size++;
//}
//void free_list(ListType *list) {
//	if (list == NULL) return;
//	ListNode *p = list->head;
//	while (p != NULL) {
//		ListNode *next = p->link;
//		free(p);
//		p = next;
//	}
//	free(list);
//}
//void add_poly(ListType *a, ListType *b, ListType *c) {
//	element item;
//	if (a == NULL || b == NULL || c == NULL) error("error!");
//	ListNode *p = a->head;
//	ListNode *q = b->head;
//	while (p != NULL && q != NULL) {
//		if (p->data.expon == q->data.expon) {
//			item.coef = p->data.coef + q->data.coef;
//			if (item.coef == 0) {
//				p = p->link;
//				q = q->link;
//				continue;
//			}
//			item.expon = p->data.expon;
//			ins_last(c, &item);
//			p = p->link;
//			q = q->link;
//		}
//		else if (p->data.expon < q->data.expon) {
//			item.coef = q->data.coef;
//			item.expon = q->data.expon;
//			ins_last(c, &item);
//			q = q->link;
//		}
//		else {
//			item.coef = p->data.coef;
//			item.expon = p->data.expon;
//			ins_last(c, &item);
//			p = p->link;
//		}
//	}
//	while (p != NULL) {
//		item.coef = p->data.coef;
//		item.expon = p->data.expon;
//		ins_last(c, &item);
//		p = p->link;
//	}
//	while (q != NULL) {
//		item.coef = q->data.coef;
//		item.expon = q->data.expon;
//		ins_last(c, &item);
//		q = q->link;
//	}
//}
//int poly_eval(ListType *poly, int var) {
//	if (poly->head == NULL) return -1;
//	ListNode *p = poly->head;
//	int rslt = 0;
//	while (p != NULL) {
//		int tmp = 1;
//		for (int i = 0; i < p->data.expon; i++)
//			tmp *= var;
//		tmp *= p->data.coef;
//		rslt += tmp;
//		p = p->link;
//	}
//	return rslt;
//}
//void poly_print(ListType *a) {
//	if (a == NULL) error("parameter error");
//	ListNode *p = a->head;
//	printf("%dx^%d", p->data.coef, p->data.expon);
//	p = p->link;
//	while (p != NULL) {
//		printf(" + ");
//		printf("%dx^%d", p->data.coef, p->data.expon);
//		p = p->link;
//	}
//	printf("\n");
//}
//
//int main() {
//	ListType *a;
//	a = create_list();
//	element item = { 1, 3 };
//	ins_last(a, &item);
//	item = { 2, 1 };
//	ins_last(a, &item);
//	item = { 6, 0 };
//	ins_last(a, &item);
//	poly_print(a);
//	printf("%d\n", poly_eval(a, 2));
//
//	free_list(a);
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct elementTag {
//	int coef;
//	int expon;
//}element;
//typedef struct ListNodeTag {
//	element data;
//	struct ListNodeTag *link;
//}ListNode;
//typedef struct ListTypeTag {
//	int size;
//	ListNode *head;
//	ListNode *tail;
//}ListType;
//
//void error(const char *message) {
//	fprintf(stderr, "%s\n", message);
//	exit(1);
//}
//ListType *create_list() {
//	ListType *list = (ListType *)malloc(sizeof(ListType));
//	if (list == NULL) error("메모리 할당 오류");
//	list->size = 0;
//	list->head = NULL;
//	list->tail = NULL;
//	return list;
//}
//void ins_last(ListType *list, element *item) {
//	ListNode *node = (ListNode *)malloc(sizeof(ListNode));
//	if (node == NULL) error("메모리 할당 오류");
//	node->data.coef = item->coef;
//	node->data.expon = item->expon;
//	node->link = NULL;
//	if (list->tail == NULL) {
//		list->head = node;
//		list->tail = node;
//	}
//	else {
//		list->tail->link = node;
//		list->tail = node;
//	}
//	list->size++;
//}
//void free_list(ListType *list) {
//	if (list == NULL) return;
//	ListNode *p = list->head;
//	while (p != NULL) {
//		ListNode *next = p->link;
//		free(p);
//		p = next;
//	}
//	free(list);
//}
//void add_poly(ListType *a, ListType *b, ListType *c) {
//	element item;
//	if (a == NULL || b == NULL || c == NULL) error("error!");
//	ListNode *p = a->head;
//	ListNode *q = b->head;
//	while (p != NULL && q != NULL) {
//		if (p->data.expon == q->data.expon) {
//			item.coef = p->data.coef + q->data.coef;
//			if (item.coef == 0) {
//				p = p->link;
//				q = q->link;
//				continue;
//			}
//			item.expon = p->data.expon;
//			ins_last(c, &item);
//			p = p->link;
//			q = q->link;
//		}
//		else if (p->data.expon < q->data.expon) {
//			item.coef = q->data.coef;
//			item.expon = q->data.expon;
//			ins_last(c, &item);
//			q = q->link;
//		}
//		else {
//			item.coef = p->data.coef;
//			item.expon = p->data.expon;
//			ins_last(c, &item);
//			p = p->link;
//		}
//	}
//	while (p != NULL) {
//		item.coef = p->data.coef;
//		item.expon = p->data.expon;
//		ins_last(c, &item);
//		p = p->link;
//	}
//	while (q != NULL) {
//		item.coef = q->data.coef;
//		item.expon = q->data.expon;
//		ins_last(c, &item);
//		q = q->link;
//	}
//}
//void poly_print(ListType *a) {
//	if (a == NULL) error("parameter error");
//	ListNode *p = a->head;
//	printf("%dx^%d", p->data.coef, p->data.expon);
//	p = p->link;
//	while (p != NULL) {
//		printf(" + ");
//		printf("%dx^%d", p->data.coef, p->data.expon);
//		p = p->link;
//	}
//	printf("\n");
//}
//
//int main() {
//	ListType *a;
//	ListType *b;
//	ListType *c;
//	a = create_list();
//	b = create_list();
//	c = create_list();
//	element item = { 3, 6 };
//	ins_last(a, &item);
//	item = { 7, 3 };
//	ins_last(a, &item);
//	item = { -2, 2 };
//	ins_last(a, &item);
//	item = { -9, 0 };
//	ins_last(a, &item);
//	item = { -2, 6 };
//	ins_last(b, &item);
//	item = { -4, 4 };
//	ins_last(b, &item);
//	item = { 6, 2 };
//	ins_last(b, &item);
//	item = { 6, 1 };
//	ins_last(b, &item);
//	item = { 1, 0 };
//	ins_last(b, &item);
//	add_poly(a, b, c);
//	poly_print(a);
//	poly_print(b);
//	poly_print(c);
//
//	free_list(a);
//	free_list(b);
//	free_list(c);
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//typedef int element;
//typedef struct ListNodeTag {
//	element data;
//	ListNodeTag *link;
//}ListNode;
//
//ListNode *ins_first(ListNode *head, element item) {
//	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
//	if (p == NULL) return head;
//	p->data = item;
//	p->link = head;
//	head = p;
//	return head;
//}
//ListNode *ins(ListNode *head, ListNode *pre, element item) {
//	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
//	if (p == NULL) return head;
//	p->data = item;
//	p->link = pre->link;
//	pre->link = p;
//	return head;
//}
//ListNode *del_first(ListNode *head) {
//	ListNode *p;
//	if (head == NULL) return NULL;
//	p = head;
//	head = head->link;
//	free(p);
//	return head;
//}
//ListNode *del(ListNode *head, ListNode *pre) {
//	ListNode *p;
//	if (pre->link == NULL) return head;
//	p = pre->link;
//	pre->link = p->link;
//	free(p);
//	return head;
//}
//element get_entry(ListNode *head, int index) {
//	ListNode *p;
//	if (index < 0 || head == NULL) return -1;
//	p = head;
//	for (int i = 0; i < index; i++) {
//		if (p->link == NULL) return -1;
//		p = p->link;
//	}
//	return p->data;
//}
//ListNode *reverse_list(ListNode *head) {
//	if (head == NULL) return NULL;
//	ListNode *p1, *p2, *p3;
//	p1 = head;
//	p2 = NULL;
//	while (p1 != NULL) {
//		p3 = p2;
//		p2 = p1;
//		p1 = p1->link;
//		p2->link = p3;
//	}
//	return p2;
//}
//void split(ListNode *C, ListNode **A, ListNode **B) {
//	ListNode *p = C;
//	ListNode *q = NULL;
//	ListNode *r = NULL;
//	ListNode *s = NULL;
//	int num = 1;
//	while (p != NULL) {
//		if(num % 2 == 1){ // 홀수 일 때
//			s = (ListNode *)malloc(sizeof(ListNode));
//			s->data = p->data;
//			s->link = NULL;
//			if (*A == NULL) {
//				*A = s;
//			}
//			else {
//				q->link = s;
//			}
//			q = s;
//		}
//		else { // 짝수 일 때
//			s = (ListNode *)malloc(sizeof(ListNode));
//			s->data = p->data;
//			s->link = NULL;
//			if (*B == NULL) {
//				*B = s;
//			}
//			else {
//				r->link = s;
//			}
//			r = s;
//		}
//		p = p->link;
//		num++;
//	}
//}
//
//void print_list(ListNode *head) {
//	if (head == NULL) return;
//	ListNode *p = head;
//	printf("%d", p->data);
//	p = p->link;
//	while (p != NULL) {
//		printf("->");
//		printf("%d", p->data);
//		p = p->link;
//	}
//	printf("\n");
//}
//
//int main() {
//	ListNode *head1 = NULL;
//	ListNode *head2 = NULL;
//	ListNode *head3 = NULL;
//	head1 = ins_first(head1, 123213);
//	head1 = ins_first(head1, 8);
//	head1 = ins_first(head1, 3);
//	head1 = ins_first(head1, 2);
//	head1 = ins_first(head1, -123123);
//	print_list(head1);
//	split(head1, &head2, &head3);
//	print_list(head2);
//	print_list(head3);
//	while (head1 != NULL) {
//		head1 = del_first(head1);
//	}
//	while (head2 != NULL) {
//		head2 = del_first(head2);
//	}
//	while (head3 != NULL) {
//		head3 = del_first(head3);
//	}
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//typedef int element;
//typedef struct ListNodeTag {
//	element data;
//	ListNodeTag *link;
//}ListNode;
//
//ListNode *ins_first(ListNode *head, element item) {
//	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
//	if (p == NULL) return head;
//	p->data = item;
//	p->link = head;
//	head = p;
//	return head;
//}
//ListNode *ins(ListNode *head, ListNode *pre, element item) {
//	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
//	if (p == NULL) return head;
//	p->data = item;
//	p->link = pre->link;
//	pre->link = p;
//	return head;
//}
//ListNode *del_first(ListNode *head) {
//	ListNode *p;
//	if (head == NULL) return NULL;
//	p = head;
//	head = head->link;
//	free(p);
//	return head;
//}
//ListNode *del(ListNode *head, ListNode *pre) {
//	ListNode *p;
//	if (pre->link == NULL) return head;
//	p = pre->link;
//	pre->link = p->link;
//	free(p);
//	return head;
//}
//element get_entry(ListNode *head, int index) {
//	ListNode *p;
//	if (index < 0 || head == NULL) return -1;
//	p = head;
//	for (int i = 0; i < index; i++) {
//		if (p->link == NULL) return -1;
//		p = p->link;
//	}
//	return p->data;
//}
//ListNode *reverse_list(ListNode *head) {
//	if (head == NULL) return NULL;
//	ListNode *p1, *p2, *p3;
//	p1 = head;
//	p2 = NULL;
//	while (p1 != NULL) {
//		p3 = p2;
//		p2 = p1;
//		p1 = p1->link;
//		p2->link = p3;
//	}
//	return p2;
//}
//ListNode *merge(ListNode *head1, ListNode *head2) {
//	if (head1 == NULL) return head2;
//	if (head2 == NULL) return head1;
//
//	ListNode *head3 = NULL;
//	ListNode *p = head1;
//	ListNode *q = head2;
//	ListNode *r = NULL;
//	while (p != NULL && q != NULL) {
//		if (p->data > q->data) {
//			if (q != NULL) {
//				if (head3 == NULL) {
//					head3 = q;
//					r = q;
//				}
//				else {
//					r->link = q;
//					r = q;
//				}
//				q = q->link;
//			}
//		}
//		else if (p->data <= q->data) {
//			if (p != NULL) {
//				if (head3 == NULL) {
//					head3 = p;
//					r = p;
//				}
//				else {
//					r->link = p;
//					r = p;
//				}
//				p = p->link;
//			}
//		}
//	}
//	if (p != NULL) r->link = p;
//	else if (q != NULL) r->link = q;
//	return head3;
//}
//
//void print_list(ListNode *head) {
//	if (head == NULL) return;
//	ListNode *p = head;
//	printf("%d", p->data);
//	p = p->link;
//	while (p != NULL) {
//		printf("->");
//		printf("%d", p->data);
//		p = p->link;
//	}
//	printf("\n");
//}
//
//int main() {
//	ListNode *head1 = NULL;
//	ListNode *head2 = NULL;
//	ListNode *head3 = NULL;
//	head1 = ins_first(head1, 123213);
//	head1 = ins_first(head1, 8);
//	head1 = ins_first(head1, 3);
//	head1 = ins_first(head1, 2);
//	head1 = ins_first(head1, -123123);
//	print_list(head1);
//	head2 = ins_first(head2, 488);
//	head2 = ins_first(head2, 122);
//	head2 = ins_first(head2, 114);
//	print_list(head2);
//	head3 = merge(head1, head2);
//	print_list(head3);
//	while (head3 != NULL) {
//		head3 = del_first(head3);
//	}
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//typedef int element;
//typedef struct ListNodeTag {
//	element data;
//	ListNodeTag *link;
//}ListNode;
//
//ListNode *ins_first(ListNode *head, element item) {
//	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
//	if (p == NULL) return head;
//	p->data = item;
//	p->link = head;
//	head = p;
//	return head;
//}
//ListNode *ins(ListNode *head, ListNode *pre, element item) {
//	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
//	if (p == NULL) return head;
//	p->data = item;
//	p->link = pre->link;
//	pre->link = p;
//	return head;
//}
//ListNode *del_first(ListNode *head) {
//	ListNode *p;
//	if (head == NULL) return NULL;
//	p = head;
//	head = head->link;
//	free(p);
//	return head;
//}
//ListNode *del(ListNode *head, ListNode *pre) {
//	ListNode *p;
//	if (pre->link == NULL) return head;
//	p = pre->link;
//	pre->link = p->link;
//	free(p);
//	return head;
//}
//element get_entry(ListNode *head, int index) {
//	ListNode *p;
//	if (index < 0 || head == NULL) return -1;
//	p = head;
//	for (int i = 0; i < index; i++) {
//		if (p->link == NULL) return -1;
//		p = p->link;
//	}
//	return p->data;
//}
//ListNode *reverse_list(ListNode *head) {
//	if (head == NULL) return NULL;
//	ListNode *p1, *p2, *p3;
//	p1 = head;
//	p2 = NULL;
//	while (p1 != NULL) {
//		p3 = p2;
//		p2 = p1;
//		p1 = p1->link;
//		p2->link = p3;
//	}
//	return p2;
//}
//ListNode *alternate(ListNode *head1, ListNode *head2) {
//	// 17번 문제를 다시 보니 노드들을 새로운 리스트로 옮기는 문제여서 다시 풀어보았다.
//  // 옮겼다기 보다는 공유하는 것 같긴 하다.
	//ListNode *head3 = NULL;
	//ListNode *p = head1;
	//ListNode *q = head2;
	//ListNode *r = NULL;
	//while (p != NULL || q != NULL) {
	//	if (p != NULL) {
	//		if (head3 == NULL) {
	//			head3 = p;
	//			r = p;
	//		}
	//		else {
	//			r->link = p;
	//			r = p;
	//		}
	//		p = p->link;
	//	}
	//	if (q != NULL) {
	//		if (head3 == NULL) {
	//			head3 = q;
	//			r = q;
	//		}
	//		else {
	//			r->link = q;
	//			r = q;
	//		}
	//		q = q->link;
	//	}
	//}
	//return head3;
//}
////ListNode *concat_list(ListNode *head1, ListNode *head2) {
////	if (head1 == NULL) return head2;
////	if (head2 == NULL) return head1;
////	ListNode *p = head1;
////	while (p->link != NULL) {
////		p = p->link;
////	}
////	p->link = head2;
////	return head1;
////}
//void print_list(ListNode *head) {
//	if (head == NULL) return;
//	ListNode *p = head;
//	printf("%d", p->data);
//	p = p->link;
//	while (p != NULL) {
//		printf("->");
//		printf("%d", p->data);
//		p = p->link;
//	}
//	printf("\n");
//}
//
//int main() {
//	ListNode *head1 = NULL;
//	ListNode *head2 = NULL;
//	ListNode *head3 = NULL;
//	head1 = ins_first(head1, 2);
//	head1 = ins_first(head1, 123213);
//	head1 = ins_first(head1, -123123);
//	head1 = ins_first(head1, 3);
//	head1 = ins_first(head1, 8);
//	print_list(head1);
//	head2 = ins_first(head2, 488);
//	head2 = ins_first(head2, 122);
//	head2 = ins_first(head2, 114);
//	print_list(head2);
//	head3 = alternate(head1, head2);
//	print_list(head3);
//	while (head3 != NULL) {
//		head3 = del_first(head3);
//	}
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//typedef int element;
//typedef struct ListNodeTag {
//	element data;
//	ListNodeTag *link;
//}ListNode;
//
//ListNode *ins_first(ListNode *head, element item) {
//	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
//	if (p == NULL) return head;
//	p->data = item;
//	p->link = head;
//	head = p;
//	return head;
//}
//ListNode *ins(ListNode *head, ListNode *pre, element item) {
//	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
//	if (p == NULL) return head;
//	p->data = item;
//	p->link = pre->link;
//	pre->link = p;
//	return head;
//}
//ListNode *del_first(ListNode *head) {
//	ListNode *p;
//	if (head == NULL) return NULL;
//	p = head;
//	head = head->link;
//	free(p);
//	return head;
//}
//ListNode *del(ListNode *head, ListNode *pre) {
//	ListNode *p;
//	if (pre->link == NULL) return head;
//	p = pre->link;
//	pre->link = p->link;
//	free(p);
//	return head;
//}
//element get_entry(ListNode *head, int index) {
//	ListNode *p;
//	if (index < 0 || head == NULL) return -1;
//	p = head;
//	for (int i = 0; i < index; i++) {
//		if (p->link == NULL) return -1;
//		p = p->link;
//	}
//	return p->data;
//}
//ListNode *reverse_list(ListNode *head) {
//	if (head == NULL) return NULL;
//	ListNode *p1, *p2, *p3;
//	p1 = head;
//	p2 = NULL;
//	while (p1 != NULL) {
//		p3 = p2;
//		p2 = p1;
//		p1 = p1->link;
//		p2->link = p3;
//	}
//	return p2;
//}
//ListNode *alternate(ListNode *head1, ListNode *head2) {
//	ListNode *head3 = NULL;
//	ListNode *s = NULL;
//	ListNode *p = head1;
//	ListNode *q = head2;
//	while (p != NULL || q != NULL) { 
//		// 둘 다 NULL이면 바로 head3(NULL)을 리턴한다.
//		if (p != NULL) {
//			ListNode *r = (ListNode *)malloc(sizeof(ListNode));
//			r->data = p->data;
//			r->link = NULL;
//			if (head3 == NULL) head3 = r;
//			else s->link = r;
//			s = r;
//			p = p->link;
//		}
//		if (q != NULL) {
//			ListNode *r = (ListNode *)malloc(sizeof(ListNode));
//			r->data = q->data;
//			r->link = NULL;
//			if (head3 == NULL) head3 = r;
//			else s->link = r;
//			s = r;
//			q = q->link;
//		}
//	}
//	return head3;
//}
////ListNode *alternate(ListNode *head1, ListNode *head2) { 
//// 처음에 만든 alternate 함수
//// 모든 경우에 if-else문을 사용해 코드가 길고 보기 힘들다.
//// 처음 head를 만들 때도 head3 == NULL을 사용하여 
//// 조건문 안에서 처리하면 됐는데 생각을 못했다.
////	if (head1 == NULL && head2 == NULL) return NULL;
////	ListNode *p = head1;
////	ListNode *q = head2;
////	ListNode *head3 = NULL;
////	ListNode *s = NULL;
////	ListNode *r = NULL;
////	// 초기 동작
////	if (p != NULL && q == NULL) { // p는 NULL이 아닌데 q만 NULL일때
////		head3 = (ListNode *)malloc(sizeof(ListNode));
////		head3->data = p->data;
////		head3->link = NULL;
////		p = p->link;
////		s = head3;
////	}
////	else if (q != NULL && p == NULL) { // q는 NULL이 아닌데 p만 NULL일때
////		head3 = (ListNode *)malloc(sizeof(ListNode));
////		head3->data = q->data;
////		head3->link = NULL;
////		q = q->link;
////		s = head3;
////	}
////	else { //둘 다 NULL이 아닐 때
////		head3 = (ListNode *)malloc(sizeof(ListNode));
////		head3->data = p->data;
////		head3->link = NULL;
////		p = p->link;
////		s = head3;
////		r = (ListNode *)malloc(sizeof(ListNode));
////		r->data = q->data;
////		r->link = NULL;
////		s->link = r;
////		q = q->link;
////		s = s->link;
////	}
////	while (p != NULL && q != NULL) {
////		r = (ListNode *)malloc(sizeof(ListNode));
////		r->data = p->data;
////		r->link = NULL;
////		s->link = r;
////		p = p->link;
////		s = s->link;
////		r = (ListNode *)malloc(sizeof(ListNode));
////		r->data = q->data;
////		r->link = NULL;
////		s->link = r;
////		q = q->link;
////		s = s->link;
////	}
////	while (p != NULL) {
////		r = (ListNode *)malloc(sizeof(ListNode));
////		r->data = p->data;
////		r->link = NULL;
////		s->link = r;
////		p = p->link;
////		s = s->link;
////	}
////	while (q != NULL) {
////		r = (ListNode *)malloc(sizeof(ListNode));
////		r->data = q->data;
////		r->link = NULL;
////		s->link = r;
////		q = q->link;
////		s = s->link;
////	}
////	return head3;
////}
//void print_list(ListNode *head) {
//	if (head == NULL) return;
//	ListNode *p = head;
//	printf("%d", p->data);
//	p = p->link;
//	while (p != NULL) {
//		printf("->");
//		printf("%d", p->data);
//		p = p->link;
//	}
//	printf("\n");
//}
//int main() {
//	ListNode *head1 = NULL;
//	ListNode *head2 = NULL;
//	ListNode *head3 = NULL;
//	head1 = ins_first(head1, 2);
//	head1 = ins_first(head1, 123213);
//	head1 = ins_first(head1, -123123);
//	head1 = ins_first(head1, 3);
//	head1 = ins_first(head1, 8);
//	print_list(head1);
//	head2 = ins_first(head2, 488);
//	head2 = ins_first(head2, 122);
//	head2 = ins_first(head2, 114);
//	print_list(head2);
//	head3 = alternate(head1, head2);
//	print_list(head3);
//	while (head1 != NULL) {
//		head1 = del_first(head1);
//	}
//	while (head2 != NULL) {
//		head2 = del_first(head2);
//	}
//	while (head3 != NULL) {
//		head3 = del_first(head3);
//	}
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//typedef int element;
//typedef struct ListNodeTag {
//	element data;
//	ListNodeTag *link;
//}ListNode;
//
//ListNode *ins_first(ListNode *head, element item) {
//	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
//	if (p == NULL) return head;
//	p->data = item;
//	p->link = head;
//	head = p;
//	return head;
//}
//ListNode *ins(ListNode *head, ListNode *pre, element item) {
//	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
//	if (p == NULL) return head;
//	p->data = item;
//	p->link = pre->link;
//	pre->link = p;
//	return head;
//}
//ListNode *del_first(ListNode *head) {
//	ListNode *p;
//	if (head == NULL) return NULL;
//	p = head;
//	head = head->link;
//	free(p);
//	return head;
//}
//ListNode *del(ListNode *head, ListNode *pre) {
//	ListNode *p;
//	if (pre->link == NULL) return head;
//	p = pre->link;
//	pre->link = p->link;
//	free(p);
//	return head;
//}
//element get_entry(ListNode *head, int index) {
//	ListNode *p;
//	if (index < 0 || head == NULL) return -1;
//	p = head;
//	for (int i = 0; i < index; i++) {
//		if (p->link == NULL) return -1;
//		p = p->link;
//	}
//	return p->data;
//}
//ListNode *reverse_list(ListNode *head) {
//	if (head == NULL) return NULL;
//	ListNode *p1, *p2, *p3;
//	p1 = head;
//	p2 = NULL;
//	while (p1 != NULL) {
//		p3 = p2;
//		p2 = p1;
//		p1 = p1->link;
//		p2->link = p3;
//	}
//	return p2;
//}
//ListNode *del_even_node(ListNode *head) {
//	if (head == NULL) return NULL;
//	ListNode *p = head;
//	while (p != NULL && p->link != NULL) {
//		ListNode *q = p->link;
//		p->link = q->link;
//		p = p->link;
//		free(q);
//	}
//	return head;
//}
//void print_list(ListNode *head) {
//	if (head == NULL) return;
//	ListNode *p = head;
//	printf("%d", p->data);
//	p = p->link;
//	while (p != NULL) {
//		printf("->");
//		printf("%d", p->data);
//		p = p->link;
//	}
//	printf("\n");
//}
//int main() {
//	ListNode *head1 = NULL;
//
//	head1 = ins_first(head1, 2);
//	head1 = ins_first(head1, 123213);
//	head1 = ins_first(head1, -123123);
//	head1 = ins_first(head1, 3);
//	head1 = ins_first(head1, 8);
//	print_list(head1);
//	head1 = del_even_node(head1);
//	print_list(head1);
//	while (head1 != NULL) {
//		head1 = del_first(head1);
//	}
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//typedef int element;
//typedef struct rsltTag{
//	int max;
//	int min;
//}rslt;
//typedef struct ListNodeTag {
//	element data;
//	ListNodeTag *link;
//}ListNode;
//
//ListNode *ins_first(ListNode *head, element item) {
//	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
//	if (p == NULL) return head;
//	p->data = item;
//	p->link = head;
//	head = p;
//	return head;
//}
//ListNode *ins(ListNode *head, ListNode *pre, element item) {
//	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
//	if (p == NULL) return head;
//	p->data = item;
//	p->link = pre->link;
//	pre->link = p;
//	return head;
//}
//ListNode *del_first(ListNode *head) {
//	ListNode *p;
//	if (head == NULL) return NULL;
//	p = head;
//	head = head->link;
//	free(p);
//	return head;
//}
//ListNode *del(ListNode *head, ListNode *pre) {
//	ListNode *p;
//	if (pre->link == NULL) return head;
//	p = pre->link;
//	pre->link = p->link;
//	free(p);
//	return head;
//}
//element get_entry(ListNode *head, int index) {
//	ListNode *p;
//	if (index < 0 || head == NULL) return -1;
//	p = head;
//	for (int i = 0; i < index; i++) {
//		if (p->link == NULL) return -1;
//		p = p->link;
//	}
//	return p->data;
//}
//ListNode *reverse_list(ListNode *head) {
//	if (head == NULL) return NULL;
//	ListNode *p1, *p2, *p3;
//	p1 = head;
//	p2 = NULL;
//	while (p1 != NULL) {
//		p3 = p2;
//		p2 = p1;
//		p1 = p1->link;
//		p2->link = p3;
//	}
//	return p2;
//}
//int search_max_min(ListNode *head, rslt* rslt) {
//	if (head == NULL || rslt == NULL) return -1;
//	rslt->min = head->data;
//	rslt->max = head->data;
//	ListNode *p = head->link;
//	while (p != NULL) {
//		if (rslt->min > p->data) {
//			rslt->min = p->data;
//		}
//		if (rslt->max < p->data) {
//			rslt->max = p->data;
//		}
//		p = p->link;
//	}
//	return 0;
//}
//void print_list(ListNode *head) {
//	if (head == NULL) return;
//	ListNode *p = head;
//	printf("%d", p->data);
//	p = p->link;
//	while (p != NULL) {
//		printf("->");
//		printf("%d", p->data);
//		p = p->link;
//	}
//}
//int main() {
//	ListNode *head1 = NULL;
//	rslt rslt1;
//	head1 = ins_first(head1, 2);
//	head1 = ins_first(head1, 123213);
//	head1 = ins_first(head1, -123123);
//	head1 = ins_first(head1, 3);
//	head1 = ins_first(head1, 8);
//	if (search_max_min(head1, &rslt1) == 0) {
//		printf("연결 리스트의 값들 중 최솟값은 %d이고 최댓값은 %d입니다.\n", rslt1.min, rslt1.max);
//	}
//	while (head1 != NULL) {
//		head1 = del_first(head1);
//	}
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//typedef struct elementTag {
//	const char* name;
//	int age;
//	float height;
//}element;
//typedef struct ListNodeTag {
//	element data;
//	struct ListNodeTag *link;
//}ListNode;
//
//ListNode *ins_first(ListNode *head, element item) {
//	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
//	if (p == NULL) return head;
//	p->data = item;
//	p->link = head;
//	head = p;
//	return head;
//}
//ListNode *ins(ListNode *head, ListNode *pre, element item) {
//	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
//	if (p == NULL) return head;
//	p->data = item;
//	p->link = pre->link;
//	pre->link = p;
//	return head;
//}
//ListNode *del_first(ListNode *head) {
//	ListNode *p;
//	if (head == NULL) return NULL;
//	p = head;
//	head = head->link;
//	free(p);
//	return head;
//}
//ListNode *del(ListNode *head, ListNode *pre) {
//	ListNode *p;
//	if (pre->link == NULL) return head;
//	p = pre->link;
//	pre->link = p->link;
//	free(p);
//	return head;
//}
////element get_entry(ListNode *head, int index) {
////	ListNode *p;
////	if (index < 0 || head == NULL) return -1;
////	p = head;
////	for (int i = 0; i < index; i++) {
////		if (p->link == NULL) return -1;
////		p = p->link;
////	}
////	return p->data;
////}
//ListNode *reverse_list(ListNode *head) {
//	if (head == NULL) return NULL;
//	ListNode *p1, *p2, *p3;
//	p1 = head;
//	p2 = NULL;
//	while (p1 != NULL) {
//		p3 = p2;
//		p2 = p1;
//		p1 = p1->link;
//		p2->link = p3;
//	}
//	return p2;
//}
//void print_list(ListNode *head) {
//	if (head == NULL) return;
//	ListNode *p = head;
//	printf("%s ", p->data.name);
//	printf("%d ", p->data.age);
//	printf("%lf", p->data.height);
//	p = p->link;
//	while (p != NULL) {
//		printf("->");
//		printf("%s ", p->data.name);
//		printf("%d ", p->data.age);
//		printf("%lf", p->data.height);
//		p = p->link;
//	}
//}
//
//int main() {
//	ListNode *head1 = NULL;
//	element s = {"choi", 30, 1.3};
//	head1 =ins_first(head1, s);
//	s = { "lee", 48, 1.4 };
//	head1 = ins_first(head1, s);
//	s = { "park", 27, 1.2 };
//	head1 = ins_first(head1, s);
//	s = { "kim", 34, 1.7 };
//	head1 = ins_first(head1, s);
//	print_list(head1);
//	while (head1 != NULL) {
//		head1 = del_first(head1);
//	}
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//typedef int element;
//typedef struct ListNodeTag {
//	element data;
//	ListNodeTag *link;
//}ListNode;
//
//ListNode *ins_first(ListNode *head, element item) {
//	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
//	if (p == NULL) return head;
//	p->data = item;
//	p->link = head;
//	head = p;
//	return head;
//}
//ListNode *ins(ListNode *head, ListNode *pre, element item) {
//	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
//	if (p == NULL) return head;
//	p->data = item;
//	p->link = pre->link;
//	pre->link = p;
//	return head;
//}
//ListNode *del_first(ListNode *head) {
//	ListNode *p;
//	if (head == NULL) return NULL;
//	p = head;
//	head = head->link;
//	free(p);
//	return head;
//}
//ListNode *del(ListNode *head, ListNode *pre) {
//	ListNode *p;
//	if (pre->link == NULL) return head;
//	p = pre->link;
//	pre->link = p->link;
//	free(p);
//	return head;
//}
//element get_entry(ListNode *head, int index) {
//	ListNode *p;
//	if (index < 0 || head == NULL) return -1;
//	p = head;
//	for (int i = 0; i < index; i++) {
//		if (p->link == NULL) return -1;
//		p = p->link;
//	}
//	return p->data;
//}
//int get_length(ListNode *head) {
//	int len = 0;
//	ListNode *p = head;
//	while (p != NULL) {
//		len++;
//		p = p->link;
//	}
//	return len;
//}
//int get_sum(ListNode *head) {
//	int sum = 0;
//	if (head == NULL) return -1;
//	ListNode *p = head;
//	while (p != NULL) {
//		sum += p->data;
//		p = p->link;
//	}
//	return sum;
//}
//void count_element(ListNode *head) {
//	int num, count = 0;
//	printf("탐색할 값을 입력하시오: ");
//	scanf_s("%d", &num);
//	if (head == NULL) return;
//	ListNode *p = head;
//	while (p != NULL) {
//		if (p->data == num) count++;
//		p = p->link;
//	}
//	printf("%d는 연결 리스트에서 %d번 나타납니다.",num,count);
//}
//ListNode *search_element(ListNode *head, element item) {
//	ListNode *p;
//	if (head == NULL) return NULL;
//	p = head;
//	while (p != NULL) {
//		if (p->data == item) return p;
//		p = p->link;
//	}
//	return NULL;
//}
//ListNode *del_element(ListNode *head, element item) {
//	if (head == NULL) return NULL;
//	if (head->data == item) {
//		ListNode *q;
//		q = head;
//		head = head->link;
//		free(q);
//		return head;
//	}
//	ListNode *p = head;
//	while (p->link != NULL) {
//		if (p->link->data == item) {
//			ListNode *q = p->link;
//			p->link = q->link;
//			free(q);
//			return head;
//		}
//		p = p->link;
//	}
//	return head;
//}
//
//ListNode *concat_list(ListNode *head1, ListNode *head2) {
//	if (head1 == NULL) return head2;
//	if (head2 == NULL) return head1;
//	ListNode *p = head1;
//	while (p->link != NULL) {
//		p = p->link;
//	}
//	p->link = head2;
//	return head1;
//}
//ListNode *reverse_list(ListNode *head) {
//	if (head == NULL) return NULL;
//	ListNode *p1, *p2, *p3;
//	p1 = head;
//	p2 = NULL;
//	while (p1 != NULL) {
//		p3 = p2;
//		p2 = p1;
//		p1 = p1->link;
//		p2->link = p3;
//	}
//	return p2;
//}
//void print_list(ListNode *head) {
//	if (head == NULL) return;
//	ListNode *p = head;
//	printf("%d", p->data);
//	p = p->link;
//	while (p != NULL) {
//		printf("->");
//		printf("%d", p->data);
//		p = p->link;
//	}
//}
//ListNode *create_list(ListNode *head) {
//	ListNode *p = head;
//	int num1 = 0;
//	element num2 = 0;
//	printf("노드의 개수: ");
//	scanf_s("%d", &num1);
//	for (int i = 1; i <= num1; i++) {
//		printf("노드 #%d 데이터: ", i);
//		scanf_s("%d", &num2);
//		head = ins_first(head, num2);
//	}
//	count_element(head);
//	printf("\n");
//	return head;
//}
//
//int main() {
//	ListNode *head1 = NULL;
//	head1 = create_list(head1);
//	printf("%d",get_entry(head1, 3));
//	while (head1 != NULL) {
//		head1 = del_first(head1);
//	}
//	return 0;
//}

///*
//* 아래의 프로그램?은 다항식 덧셈을 구현한 것이다.
//* 책에서는 ins_last에 직접 계수와 지수를 인자로 주었지만
//* 나는 둘을 element로 묶어서 인자로 주었다.
//* 그랬더니 코드가 길어지고 깔끔하지 못하게 되었다.
//*/
//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct elementTag {
//	int coef;
//	int expon;
//}element;
//typedef struct ListNodeTag {
//	element data;
//	struct ListNodeTag *link;
//}ListNode;
//typedef struct ListTypeTag {
//	int size;
//	ListNode *head;
//	ListNode *tail;
//}ListType;
//
//void error(const char *message) {
//	fprintf(stderr, "%s\n", message);
//	exit(1);
//}
//ListType *create_list() {
//	ListType *list = (ListType *)malloc(sizeof(ListType));
//	if (list == NULL) error("메모리 할당 오류");
//	list->size = 0;
//	list->head = NULL;
//	list->tail = NULL;
//	return list;
//}
//void ins_last(ListType *list, element *item) {
//	ListNode *node = (ListNode *)malloc(sizeof(ListNode));
//	if (node == NULL) error("메모리 할당 오류");
//	node->data.coef = item->coef;
//	node->data.expon = item->expon;
//	node->link = NULL;
//	if (list->tail == NULL) {
//		list->head = node;
//		list->tail = node;
//	}
//	else {
//		list->tail->link = node;
//		list->tail = node;
//	}
//	list->size++;
//}
//void free_list(ListType *list) {
//	if (list == NULL) return;
//	ListNode *p = list->head;
//	while (p != NULL) {
//		ListNode *next = p->link;
//		free(p); 
//		p = next;
//	}
//	free(list); 
//}
//void add_poly(ListType *a, ListType *b, ListType *c){
//	element item;
//	if (a == NULL || b == NULL || c == NULL) error("error!");
//	ListNode *p = a->head;
//	ListNode *q = b->head;
//	while (p != NULL && q != NULL) {
//		if (p->data.expon == q->data.expon) {
//			item.coef = p->data.coef + q->data.coef;
//			if (item.coef == 0) {
//				p = p->link;
//				q = q->link;
//				continue;
//			}
//			item.expon = p->data.expon;
//			ins_last(c, &item);
//			p = p->link;
//			q = q->link;
//		}
//		else if (p->data.expon < q->data.expon) {
//			item.coef = q->data.coef;
//			item.expon = q->data.expon;
//			ins_last(c, &item);
//			q = q->link;
//		}
//		else {
//			item.coef = p->data.coef;
//			item.expon = p->data.expon;
//			ins_last(c, &item);
//			p = p->link;
//		}
//	}
//		while (p != NULL) {
//			item.coef = p->data.coef;
//			item.expon = p->data.expon;
//			ins_last(c, &item);
//			p = p->link;
//		}
//		while (q != NULL) {
//			item.coef = q->data.coef;
//			item.expon = q->data.expon;
//			ins_last(c, &item);
//			q = q->link;
//		}
//}
//void poly_print(ListType *a) {
//	if (a == NULL) error("parameter error");
//	ListNode *p = a->head;
//	printf("%dx^%d", p->data.coef, p->data.expon);
//	p = p->link;
//	while (p != NULL) {
//		printf(" + ");
//		printf("%dx^%d", p->data.coef, p->data.expon);
//		p = p->link;
//	}
//	printf("\n");
//}
//
//int main() {
//	ListType *a;
//	ListType *b;
//	ListType *c;
//	a = create_list();
//	b = create_list();
//	c = create_list();
//	element item = { 3, 12 };
//	ins_last(a, &item);
//	item = { 2, 8 };
//	ins_last(a, &item);
//	item = { 1, 0 };
//	ins_last(a, &item);
//	item = { 8, 12 };
//	ins_last(b, &item);
//	item = { -3, 10 };
//	ins_last(b, &item);
//	item = { 10, 6 };
//	ins_last(b, &item);
//	add_poly(a, b, c);
//	poly_print(a);
//	poly_print(b);
//	poly_print(c);
//
//	free_list(a);
//	free_list(b);
//	free_list(c);
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//typedef int element;
//typedef struct ListNodeTag {
//	element data;
//	ListNodeTag *link;
//}ListNode;
//
//ListNode *ins_first(ListNode *head, element item) {
//	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
//	if (p == NULL) return head;
//	p->data = item;
//	p->link = head;
//	head = p;
//	return head;
//}
//ListNode *ins(ListNode *head, ListNode *pre, element item) {
//	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
//	if (p == NULL) return head;
//	p->data = item;
//	p->link = pre->link;
//	pre->link = p;
//	return head;
//}
//ListNode *del_first(ListNode *head) {
//	ListNode *p;
//	if (head == NULL) return NULL;
//	p = head;
//	head = head->link;
//	free(p);
//	return head;
//}
//ListNode *del(ListNode *head, ListNode *pre) {
//	ListNode *p;
//	if (pre->link == NULL) return head;
//	p = pre->link;
//	pre->link = p->link;
//	free(p);
//	return head;
//}
//element get_entry(ListNode *head, int index) {
//	ListNode *p;
//	if (index < 0 || head == NULL) return -1;
//	p = head;
//	for (int i = 0; i < index; i++) {
//		if (p->link == NULL) return -1;
//		p = p->link;
//	}
//	return p->data;
//}
//int get_length(ListNode *head) {
//	int len = 0;
//	ListNode *p = head;
//	while (p != NULL) {
//		len++;
//		p = p->link;
//	}
//	return len;
//}
//ListNode *search_element(ListNode *head, element item) {
//	ListNode *p;
//	if (head == NULL) return NULL;
//	p = head;
//	while (p != NULL) {
//		if (p->data == item) return p;
//		p = p->link;
//	}
//	return NULL;
//}
//ListNode *concat_list(ListNode *head1, ListNode *head2) {
//	if (head1 == NULL) return head2;
//	if (head2 == NULL) return head1;
//	ListNode *p = head1;
//	while (p->link != NULL) {
//		p = p->link;
//	}
//	p->link = head2;
//	return head1;
//}
//ListNode *reverse_list(ListNode *head) {
//	if (head == NULL) return NULL;
//	ListNode *p1, *p2, *p3;
//	p1 = head;
//	p2 = NULL;
//	while (p1 != NULL) {
//		p3 = p2;
//		p2 = p1;
//		p1 = p1->link;
//		p2->link = p3;
//	}
//	return p2;
//}
//
////ListNode *reverse_list(ListNode *head) {
////	// chap2에서 배운 재귀를 복습하기 위해
////	// 재귀적으로 만들어 본 reverse_list
////	// N을 1과 N-1로 나눌 수 있을 것 같아 만들어 보았다.
////	if (head == NULL || head->link == NULL) {
////		return head;
////	}
////	ListNode *new_head = reverse_list(head->link);
////
////	head->link->link = head;
////	head->link = NULL;
////	return new_head;
////}
//
//void print_list(ListNode *head) {
//	ListNode *p = head;
//	while (p != NULL) {
//		printf("%d->", p->data);
//		p = p->link;
//	}
//	printf("NULL \n");
//}
//
//int main() {
//	ListNode *head1 = NULL;
//	head1 = ins_first(head1, 10);
//	head1 = ins_first(head1, 20);
//	head1 = ins_first(head1, 30);
//	print_list(head1);
//	head1 = reverse_list(head1);
//	print_list(head1);
//	for (int i = 0; i < 3; i++) {
//		head1 = del_first(head1);
//	}
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//typedef int element;
//typedef struct ListNodeTag {
//	element data;
//	ListNodeTag *link;
//}ListNode;
//
//ListNode *ins_first(ListNode *head, element item) {
//	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
//	if (p == NULL) return head;
//	p->data = item;
//	p->link = head;
//	head = p;
//	return head;
//}
//ListNode *ins(ListNode *head, ListNode *pre, element item) {
//	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
//	if (p == NULL) return head;
//	p->data = item;
//	p->link = pre->link;
//	pre->link = p;
//	return head;
//}
//ListNode *del_first(ListNode *head) {
//	ListNode *p;
//	if (head == NULL) return NULL;
//	p = head;
//	head = head->link;
//	free(p);
//	return head;
//}
//ListNode *del(ListNode *head, ListNode *pre) {
//	ListNode *p;
//	if (pre->link == NULL) return head;
//	p = pre->link;
//	pre->link = p->link;
//	free(p);
//	return head;
//}
//element get_entry(ListNode *head, int index) {
//	ListNode *p;
//	if (index < 0 || head == NULL) return -1;
//	p = head;
//	for (int i = 0; i < index; i++) {
//		if (p->link == NULL) return -1;
//		p = p->link;
//	}
//	return p->data;
//}
//int get_length(ListNode *head) {
//	int len = 0;
//	ListNode *p = head;
//	while (p != NULL) {
//		len++;
//		p = p->link;
//	}
//	return len;
//}
//ListNode *search_element(ListNode *head, element item) {
//	ListNode *p;
//	if (head == NULL) return NULL;
//	p = head;
//	while (p != NULL) {
//		if (p->data == item) return p;
//		p = p->link;
//	}
//	return NULL;
//}
//void print_list(ListNode *head) {
//	ListNode *p = head;
//	while (p != NULL) {
//		printf("%d->", p->data);
//		p = p->link;
//	}
//	printf("NULL \n");
//}
//
//int main() {
//	ListNode *head = NULL;
//	int num = 30;
//	head = ins_first(head, 10);
//	print_list(head);
//	head = ins_first(head, 20);
//	print_list(head);
//	head = ins_first(head, 30);
//	print_list(head);
//	if (search_element(head, num) != NULL) printf("리스트에서 %d을 찾았습니다.\n",num);
//	else printf("리스트에서 %d을 찾지 못했습니다.\n", num);
//
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//typedef struct elementTag {
//	char name[100];
//}element;
//typedef struct ListNodeTag {
//	element data;
//	ListNodeTag *link;
//}ListNode;
//
//ListNode *ins_first(ListNode *head, element item) {
//	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
//	if (p == NULL) return head;
//	p->data = item;
//	p->link = head;
//	head = p;
//	return head;
//}
//ListNode *ins(ListNode *head, ListNode *pre, element item) {
//	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
//	if (p == NULL) return head;
//	p->data = item;
//	p->link = pre->link;
//	pre->link = p;
//	return head;
//}
//ListNode *del_first(ListNode *head) {
//	ListNode *p;
//	if (head == NULL) return NULL;
//	p = head;
//	head = head->link;
//	free(p);
//	return head;
//}
//ListNode *del(ListNode *head, ListNode *pre) {
//	ListNode *p;
//	if (pre->link == NULL) return head;
//	p = pre->link;
//	pre->link = p->link;
//	free(p);
//	return head;
//}
////element get_entry(ListNode *head, int index) {
////	ListNode *p;
////	if (index < 0 || head == NULL) return -1;
////	p = head;
////	for (int i = 0; i < index; i++) {
////		if (p->link == NULL) return -1;
////		p = p->link;
////	}
////	return p->data;
////}
//int get_length(ListNode *head) {
//	int len = 0;
//	ListNode *p = head;
//	while (p != NULL) {
//		len++;
//		p = p->link;
//	}
//	return len;
//}
//void print_list(ListNode *head) {
//	ListNode *p = head;
//	while (p != NULL) {
//		printf("%s->", p->data.name);
//		p = p->link;
//	}
//	printf("NULL \n");
//}
//
//int main() {
//	ListNode *head = NULL;
//	element data;
//
//	strcpy_s(data.name, "APPLE");
//	head = ins_first(head, data);
//	print_list(head);
//	strcpy_s(data.name, "KIWI");
//	head = ins_first(head, data);
//	print_list(head);
//	strcpy_s(data.name, "BANANA");
//	head = ins_first(head, data);
//	print_list(head);
//	for (int i = 0; i < 3; i++) {
//		head = del_first(head);
//	}
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//typedef int element;
//typedef struct ListNodeTag {
//	element data;
//	ListNodeTag *link;
//}ListNode;
//
//ListNode *ins_first(ListNode *head, element item) {
//	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
//	if (p == NULL) return head;
//	p->data = item;
//	p->link = head;
//	head = p;
//	return head;
//}
//ListNode *ins(ListNode *head, ListNode *pre, element item) {
//	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
//	if (p == NULL) return head;
//	p->data = item;
//	p->link = pre->link;
//	pre->link = p;
//	return head;
//}
//ListNode *del_first(ListNode *head) {
//	ListNode *p;
//	if (head == NULL) return NULL;
//	p = head;
//	head = head->link;
//	free(p);
//	return head;
//}
//ListNode *del(ListNode *head, ListNode *pre) {
//	ListNode *p;
//	if (pre->link == NULL) return head;
//	p = pre->link;
//	pre->link = p->link;
//	free(p);
//	return head;
//}
//element get_entry(ListNode *head, int index) {
//	ListNode *p;
//	if (index < 0 || head == NULL) return -1;
//	p = head;
//	for (int i = 0; i < index; i++) {
//		if (p->link == NULL) return -1;
//		p = p->link;
//	}
//	return p->data;
//}
//int get_length(ListNode *head) {
//	int len = 0;
//	ListNode *p = head;
//	while (p != NULL) {
//		len++;
//		p = p->link;
//	}
//	return len;
//}
//void print_list(ListNode *head) {
//	ListNode *p = head;
//	while (p != NULL) {
//		printf("%d->", p->data);
//		p = p->link;
//	}
//	printf("NULL \n");
//}
//
//int main() {
//	ListNode *head = NULL;
//	for (int i = 0; i < 5; i++) {
//		head = ins_first(head, i);
//		print_list(head);
//	}
//	for (int i = 0; i < 5; i++) {
//		head = del_first(head);
//		print_list(head);
//	}
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//typedef int element;
//typedef struct ListNodeTag {
//	element data;
//	ListNodeTag *link;
//}ListNode;
//
//ListNode *ins_first(ListNode *head, element item) { 
//	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
//	if (p == NULL) return head;
//	p->data = item;
//	p->link = head;
//	head = p;
//	return head;
//}
//ListNode *ins(ListNode *head, ListNode *pre, element item) { 
//	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
//	if (p == NULL) return head;
//	p->data = item;
//	p->link = pre->link;
//	pre->link = p;
//	return head;
//}
//ListNode *del_first(ListNode *head) {
//	ListNode *p;
//	if (head == NULL) return NULL;
//	p = head;
//	head = head->link;
//	free(p);
//	return head;
//}
//ListNode *del(ListNode *head, ListNode *pre) {
//	ListNode *p;
//	if (pre->link == NULL) return head;
//	p = pre->link;
//	pre->link = p->link;
//	free(p);
//	return head;
//}
//void print_list(ListNode *head) {
//	ListNode *p = head;
//	while (p != NULL) {
//		printf("%d->", p->data);
//		p = p->link;
//	}
//	printf("NULL \n");
//}
//
//int main() {
//	ListNode *head = NULL;
//	for (int i = 0; i < 5; i++) {
//		head = ins_first(head, i);
//		print_list(head);
//	}
//	for (int i = 0; i < 5; i++) {
//		head = del_first(head);
//		print_list(head);
//	}
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#define MAX_LIST_SIZE 100
//
//typedef int element;
//typedef struct ArrayListTypeTag {
//	element *array;
//	int size;
//}ArrayListType;
//void error(const char *message) {
//	fprintf(stderr, "%s\n", message);
//	exit(1);
//}
//void init_list(ArrayListType *L) {
//	L->array = (element *)malloc(sizeof(element) * MAX_LIST_SIZE);
//	L->size = 0;
//}
//int is_empty(ArrayListType *L) {
//	return L->size == 0;
//}
//int is_full(ArrayListType *L) {
//	return L->size == MAX_LIST_SIZE;
//}
//element get_entry(ArrayListType *L, int pos) {
//	if (pos < 0 || pos >= L->size) error("위치 오류\n");
//	return L->array[pos];
//}
//void print_list(ArrayListType *L) {
//	for (int i = 0; i < L->size; i++) {
//		printf("%d->", L->array[i]);
//	}
//	printf("\n");
//}
//void insert_last(ArrayListType *L, element item) {
//	if (is_full(L)) {
//		error("리스트가 포화상태입니다.");
//	}
//	L->array[(L->size)++] = item;
//}
//void insert_first(ArrayListType *L, element item) {
//	if (is_full(L)) {
//		error("리스트가 포화상태입니다.");
//	}
//	for (int i = L->size - 1; i >= 0; i--) {
//		L->array[i + 1] = L->array[i];
//	}
//	L->array[0] = item;
//	L->size++;
//}
//void ins(ArrayListType *L, element item, int pos) {
//	if (is_full(L))error("리스트가 포화상태입니다.");
//	if (pos < 0 || pos > L->size) error("위치 오류");
//	if (!is_full(L) && (pos >= 0) && (pos <= L->size)) {
//		for (int i = L->size - 1; i >= pos; i--) {
//			L->array[i + 1] = L->array[i];
//		}
//	}
//	L->array[pos] = item;
//	L->size++;
//}
//element del(ArrayListType *L, int pos) {
//	if (pos < 0 || pos >= L->size) error("위치 오류\n");
//	element item = L->array[pos];
//	for (int i = pos; i < L->size - 1; i++) {
//		L->array[i] = L->array[i + 1];
//	}
//	L->size--;
//	return item;
//}
//void replace(ArrayListType *L, element item, int pos) {
//	if (pos < 0 || pos >= L->size) error("위치 오류\n");
//	L->array[pos] = item;
//}
//int get_length(ArrayListType *L) {
//	return L->size;
//}
//void clear(ArrayListType *L) {
//	free(L->array);
//}
//
//int main() {
//	ArrayListType list;
//	init_list(&list);
//
//	ins(&list, 10, list.size); print_list(&list);
//	ins(&list, 20, list.size); print_list(&list);
//	ins(&list, 30, list.size); print_list(&list);
//	clear(&list);
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#define MAX_LIST_SIZE 100
//
//typedef int element;
//typedef struct ArrayListTypeTag {
//	element *array;
//	int size;
//}ArrayListType;
//void error(const char *message) {
//	fprintf(stderr, "%s\n", message);
//	exit(1);
//}
//void init_list(ArrayListType *L) {
//	L->array = (element *)malloc(sizeof(element) * MAX_LIST_SIZE);
//	L->size = 0;
//}
//int is_empty(ArrayListType *L) {
//	return L->size == 0;
//}
//int is_full(ArrayListType *L) {
//	return L->size == MAX_LIST_SIZE;
//}
//element get_entry(ArrayListType *L, int pos) {
//	if (pos < 0 || pos >= L->size) error("위치 오류\n");
//	return L->array[pos];
//}
//void print_list(ArrayListType *L) {
//	for (int i = 0; i < L->size; i++) {
//		printf("%d->", L->array[i]);
//	}
//	printf("\n");
//}
//void insert_last(ArrayListType *L, element item) {
//	if (is_full(L)) {
//		error("리스트가 포화상태입니다.");
//	}
//	L->array[(L->size)++] = item;
//}
//void insert_first(ArrayListType *L, element item) {
//	if (is_full(L)) {
//		error("리스트가 포화상태입니다.");
//	}
//	for (int i = L->size - 1; i >= 0; i--) {
//		L->array[i + 1] = L->array[i];
//	}
//	L->array[0] = item;
//	L->size++;
//}
//void ins(ArrayListType *L, element item, int pos) {
//	if (!is_full(L) && (pos >= 0) && (pos <= L->size)) {
//		for (int i = L->size - 1; i >= pos; i--) {
//			L->array[i + 1] = L->array[i];
//		}
//	}
//	L->array[pos] = item;
//	L->size++;
//}
//element del(ArrayListType *L, int pos) {
//	if (pos < 0 || pos >= L->size) error("위치 오류\n");
//	element item = L->array[pos];
//	for (int i = pos; i < L->size - 1; i++) {
//		L->array[i] = L->array[i + 1];
//	}
//	L->size--;
//	return item;
//}
//
//
//int main() {
//	ArrayListType list;
//	init_list(&list);
//
//	ins(&list, 10, list.size); print_list(&list);
//	ins(&list, 20, list.size); print_list(&list);
//	ins(&list, 30, list.size); print_list(&list);
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#define MAX_LIST_SIZE 100
//
//typedef int element;
//typedef struct ArrayListTypeTag {
//	element array[MAX_LIST_SIZE];
//	int size;
//}ArrayListType;
//void error(const char *message) {
//	fprintf(stderr, "%s\n", message);
//	exit(1);
//}
//void init_list(ArrayListType *L) {
//	L->size = 0;
//}
//int is_empty(ArrayListType *L) {
//	return L->size == 0;
//}
//int is_full(ArrayListType *L) {
//	return L->size == MAX_LIST_SIZE;
//}
//element get_entry(ArrayListType *L, int pos) {
//	if (pos < 0 || pos >= L->size) error("위치 오류\n");
//	return L->array[pos];
//}
//void print_list(ArrayListType *L) {
//	for (int i = 0; i < L->size; i++) {
//		printf("%d->", L->array[i]);
//	}
//	printf("\n");
//}
//void insert_last(ArrayListType *L, element item) {
//	if (is_full(L)) {
//		error("리스트가 포화상태입니다.");
//	}
//	L->array[(L->size)++] = item;
//}
//void insert_first(ArrayListType *L, element item) {
//	if (is_full(L)) {
//		error("리스트가 포화상태입니다.");
//	}
//	for (int i = L->size - 1; i >= 0; i--) {
//		L->array[i + 1] = L->array[i];
//	}
//	L->array[0] = item;
//	L->size++;
//}
//void ins(ArrayListType *L, element item, int pos) {
//	if (!is_full(L) && (pos >= 0) && (pos <= L->size)) {
//		for (int i = L->size - 1; i >= pos; i--) {
//			L->array[i + 1] = L->array[i];
//		}
//	}
//	L->array[pos] = item;
//	L->size++;
//}
//element del(ArrayListType *L, int pos) {
//	if (pos < 0 || pos >= L->size) error("위치 오류\n");
//	element item = L->array[pos];
//	for (int i = pos; i < L->size - 1; i++) {
//		L->array[i] = L->array[i + 1];
//	}
//	L->size--;
//	return item;
//}
//
//
//int main() {
//	ArrayListType list;
//	init_list(&list);
//
//	ins(&list, 10, 0); print_list(&list);
//	ins(&list, 20, 0); print_list(&list);
//	ins(&list, 30, 0); print_list(&list);
//	insert_last(&list, 40); print_list(&list);
//	del(&list, 0); print_list(&list);
//	insert_first(&list, 50); print_list(&list);
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#define MAX_LIST_SIZE 100
//
//typedef int element;
//typedef struct ArrayListTypeTag {
//	element array[MAX_LIST_SIZE];
//	int size;
//}ArrayListType;
//void error(const char* message) {
//	fprintf(stderr, "%s\n", message);
//	exit(1);
//}
//void init_list(ArrayListType *L) {
//	L->size = 0;
//}
//int is_empty(ArrayListType *L) {
//	return L->size == 0;
//}
//int is_full(ArrayListType *L) {
//	return L->size == MAX_LIST_SIZE;
//}
//element get_entry(ArrayListType* L, int pos) {
//	if (pos < 0 || pos >= L->size) error("위치 오류\n");
//	return L->array[pos];
//}
//void print_list(ArrayListType *L){
//	for (int i = 0; i < L->size; i++) {
//		printf("%d->", L->array[i]);
//	}
//	printf("\n");
//}
//void insert_last(ArrayListType *L, element item) {
//	if (is_full(L)) {
//		error("리스트가 포화상태입니다.");
//	}
//	L->array[(L->size)++] = item;
//}
//void ins(ArrayListType *L, element item, int pos) {
//	if (!is_full(L) && (pos >= 0) && (pos <= L->size)) {
//		for (int i = L->size - 1; i >= pos; i--) {
//			L->array[i + 1] = L->array[i];
//		}
//	}
//	L->array[pos] = item;
//	L->size++;
//}
//element del(ArrayListType *L, int pos) {
//	if (pos < 0 || pos >= L->size) error("위치 오류\n");
//	element item = L->array[pos];
//	for (int i = pos; i < L->size - 1; i++) {
//		L->array[i] = L->array[i + 1];
//	}
//	L->size--;
//	return item;
//}
//
//
//int main() {
//	ArrayListType list;
//	init_list(&list);
//
//	ins(&list, 10, 0); print_list(&list);
//	ins(&list, 20, 0); print_list(&list);
//	ins(&list, 30, 0); print_list(&list);
//	insert_last(&list, 40); print_list(&list);
//	del(&list, 0); print_list(&list);
//	return 0;
//}