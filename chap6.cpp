#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;
typedef struct ListNodeTag {
	element data;
	ListNodeTag *link;
}ListNode;

ListNode *ins_first(ListNode *head, element item) {
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	if (p == NULL) return head;
	p->data = item;
	p->link = head;
	head = p;
	return head;
}
ListNode *ins(ListNode *head, ListNode *pre, element item) {
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	if (p == NULL) return head;
	p->data = item;
	p->link = pre->link;
	pre->link = p;
	return head;
}
ListNode *del_first(ListNode *head) {
	ListNode *p;
	if (head == NULL) return NULL;
	p = head;
	head = head->link;
	free(p);
	return head;
}
ListNode *del(ListNode *head, ListNode *pre) {
	ListNode *p;
	if (pre->link == NULL) return head;
	p = pre->link;
	pre->link = p->link;
	free(p);
	return head;
}
element get_entry(ListNode *head, int index) {
	ListNode *p;
	if (index < 0 || head == NULL) return -1;
	p = head;
	for (int i = 0; i < index; i++) {
		if (p->link == NULL) return -1;
		p = p->link;
	}
	return p->data;
}
int get_length(ListNode *head) {
	int len = 0;
	ListNode *p = head;
	while (p != NULL) {
		len++;
		p = p->link;
	}
	return len;
}
int get_sum(ListNode *head) {
	int sum = 0;
	ListNode *p = head;
	while (p != NULL) {
		sum += p->data;
		p = p->link;
	}
	return sum;
}
ListNode *search_element(ListNode *head, element item) {
	ListNode *p;
	if (head == NULL) return NULL;
	p = head;
	while (p != NULL) {
		if (p->data == item) return p;
		p = p->link;
	}
	return NULL;
}
ListNode *concat_list(ListNode *head1, ListNode *head2) {
	if (head1 == NULL) return head2;
	if (head2 == NULL) return head1;
	ListNode *p = head1;
	while (p->link != NULL) {
		p = p->link;
	}
	p->link = head2;
	return head1;
}
ListNode *reverse_list(ListNode *head) {
	if (head == NULL) return NULL;
	ListNode *p1, *p2, *p3;
	p1 = head;
	p2 = NULL;
	while (p1 != NULL) {
		p3 = p2;
		p2 = p1;
		p1 = p1->link;
		p2->link = p3;
	}
	return p2;
}
void print_list(ListNode *head) {
	if (head == NULL) return;
	ListNode *p = head;
	printf("%d", p->data);
	p = p->link;
	while (p != NULL) {
		printf("->");
		printf("%d", p->data);
		p = p->link;
	}
}
ListNode *create_list(ListNode *head) {
	ListNode *p = head;
	int num1 = 0;
	element num2 = 0;
	printf("노드의 개수: ");
	scanf_s("%d", &num1);
	for (int i = 1; i <= num1; i++) {
		printf("노드 #%d 데이터: ", i);
		scanf_s("%d", &num2);
		head = ins_first(head, num2);
	}
	printf("연결 리스트의 데이터 합: %d", get_sum(head));
	printf("\n");
	return head;
}

int main() {
	ListNode *head1 = NULL;
	head1 = create_list(head1);
	while (head1 != NULL) {
		head1 = del_first(head1);
	}
	return 0;
}

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