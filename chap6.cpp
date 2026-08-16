#include <stdio.h>
#include <stdlib.h>
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
void print_list(ListNode *head) {
	ListNode *p = head;
	while (p != NULL) {
		printf("%d->", p->data);
		p = p->link;
	}
	printf("NULL \n");
}

int main() {
	ListNode *head = NULL;
	for (int i = 0; i < 5; i++) {
		head = ins_first(head, i);
		print_list(head);
	}
	for (int i = 0; i < 5; i++) {
		head = del_first(head);
		print_list(head);
	}
	return 0;
}

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