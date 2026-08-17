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

//ListNode *reverse_list(ListNode *head) {
//	// chap2에서 배운 재귀를 복습하기 위해
//	// 재귀적으로 만들어 본 reverse_list
//	// N을 1과 N-1로 나눌 수 있을 것 같아 만들어 보았다.
//	if (head == NULL || head->link == NULL) {
//		return head;
//	}
//	ListNode *new_head = reverse_list(head->link);
//
//	head->link->link = head;
//	head->link = NULL;
//	return new_head;
//}

void print_list(ListNode *head) {
	ListNode *p = head;
	while (p != NULL) {
		printf("%d->", p->data);
		p = p->link;
	}
	printf("NULL \n");
}

int main() {
	ListNode *head1 = NULL;
	head1 = ins_first(head1, 10);
	head1 = ins_first(head1, 20);
	head1 = ins_first(head1, 30);
	print_list(head1);
	head1 = reverse_list(head1);
	print_list(head1);
	for (int i = 0; i < 3; i++) {
		head1 = del_first(head1);
	}
	return 0;
}

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