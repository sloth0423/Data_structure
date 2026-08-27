#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char name[20];
typedef struct ListNodeTag {
	name data;
	struct ListNodeTag *link;
}ListNode;

void insert_first(ListNode **head, const char *data) {
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	if (p == NULL) {
		fprintf(stderr, "allocation error!");
		exit(1);
	}
	strcpy_s(p->data, sizeof(p->data), data);
	if (*head == NULL) {
		*head = p;
		p->link = *head;
	}
	else {
		p->link = (*head)->link;
		(*head)->link = p;
	}
}
void insert_last(ListNode **head, const char *data) {
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	if (p == NULL) {
		fprintf(stderr, "allocation error!");
		exit(1);
	}
	strcpy_s(p->data, sizeof(p->data), data);
	if (*head == NULL) {
		*head = p;
		p->link = *head;
	}
	else {
		p->link = (*head)->link;
		(*head)->link = p;
		(*head) = p;
	}
}
int get_length(ListNode *head) {
	if (head == NULL) return 0;
	int rslt = 0;
	ListNode *p = head->link;
	do {
		p = p->link;
		rslt++;
	} while (p != head->link);
	return rslt;
}
void print_list(ListNode *head) {
	if (head == NULL) return;
	ListNode *p = head->link;
	do {
		printf("%s->", p->data);
		p = p->link;
	} while (p != head->link);
	printf("\n");
}
void free_list(ListNode **head) {
	if (head == NULL || *head == NULL) return;
	ListNode *p = (*head)->link;
	ListNode *q = NULL;
	while (p != *head) {
		q = p;
		p = p->link;
		free(q);
	}
	free(*head);
	*head = NULL;
}

int main() {
	ListNode *head = NULL;
	insert_last(&head, "KIM");
	insert_last(&head, "PARK");
	insert_last(&head, "CHOI");

	ListNode *p = head->link;
	for (int i = 0; i < 10; i++) {
		printf("현재 차례 = %s\n", p->data);
		p = p->link;
	}
	free_list(&head);
	return 0;
}

//#include <stdio.h>
//#include <stdlib.h>
//
//typedef int element;
//typedef struct ListNodeTag {
//	element data;
//	struct ListNodeTag *link;
//}ListNode;
//
//void insert_first(ListNode **head, element data) {
//	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
//	if (p == NULL) {
//		fprintf(stderr, "allocation error!");
//		exit(1);
//	}
//	p->data = data;
//	if (*head == NULL) {
//		*head = p;
//		p->link = *head;
//	}
//	else {
//		p->link = (*head)->link;
//		(*head)->link = p;
//	}
//}
//void insert_last(ListNode **head, element data) {
//	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
//	if (p == NULL) {
//		fprintf(stderr, "allocation error!");
//		exit(1);
//	}
//	p->data = data;
//	if (*head == NULL) {
//		*head = p;
//		p->link = *head;
//	}
//	else {
//		p->link = (*head)->link;
//		(*head)->link = p;
//		(*head) = p;
//	}
//}
//int get_length(ListNode *head) {
//	if (head == NULL) return 0;
//	int rslt = 0;
//	ListNode *p = head->link;
//	do {
//		p = p->link;
//		rslt++;
//	} while (p != head->link);
//	return rslt;
//}
//void print_list(ListNode *head) {
//	if (head == NULL) return;
//	ListNode *p = head->link;
//	do {
//		printf("%d->", p->data);
//		p = p->link;
//	} while (p != head->link);
//	printf("\n");
//}
//void free_list(ListNode **head) {
//	if (head == NULL || *head == NULL) return;
//	ListNode *p = (*head)->link;
//	ListNode *q = NULL;
//	while (p != *head) {
//		q = p;
//		p = p->link;
//		free(q);
//	}
//	free(*head);
//	*head = NULL;
//}
//
//int main() {
//	ListNode *head = NULL;
//
//	insert_first(&head, 3);
//	insert_first(&head, 4);
//	insert_last(&head, 2);
//	insert_last(&head, 1);
//	print_list(head);
//	free_list(&head);
//
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//typedef int element;
//typedef struct ListNodeTag {
//	element data;
//	struct ListNodeTag *link;
//}ListNode;
//
//void insert_first(ListNode **head, element data) {
//	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
//	if (p == NULL) {
//		fprintf(stderr, "allocation error!");
//		exit(1);
//	}
//	p->data = data;
//	if (*head == NULL) {
//		*head = p;
//		p->link = *head;
//	}
//	else {
//		p->link = (*head)->link;
//		(*head)->link = p;
//	}
//}
//void insert_last(ListNode **head, element data) {
//	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
//	if (p == NULL) {
//		fprintf(stderr, "allocation error!");
//		exit(1);
//	}
//	p->data = data;
//	if (*head == NULL) {
//		*head = p;
//		p->link = *head;
//	}
//	else {
//		p->link = (*head)->link;
//		(*head)->link = p;
//		(*head) = p;
//	}
//}
//void print_list(ListNode *head) {
//	if (head == NULL) return;
//	ListNode *p = head->link;
//	do {
//		printf("%d->", p->data);
//		p = p->link;
//	} while (p != head->link);
//	printf("\n");
//}
//void free_list(ListNode **head) {
//	if (head == NULL||*head == NULL) return;
//	ListNode *p = (*head)->link;
//	ListNode *q = NULL;
//	while (p != *head) {
//		q = p;
//		p = p->link;
//		free(q);
//	}
//	free(*head);
//	*head = NULL;
//}
//
//int main() {
//	ListNode *head = NULL;
//
//	insert_first(&head, 3);
//	insert_first(&head, 4);
//	insert_last(&head, 2);
//	insert_last(&head, 1);
//	print_list(head);
//	free_list(&head);
//
//	return 0;
//}