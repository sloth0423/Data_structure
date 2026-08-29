#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct StackNodeTag {
	element data;
	struct StackNodeTag *link;
}StackNode;
/* 책에서 연결리스트로 구현한 스택에 관련된
   데이터는 top포인터뿐이지만 일관성을 위하여
   구조체로 만든다고 하였는데
   이중 포인터를 사용하지 않기 위해서라는 합리적 의심을...
   그냥 StackNode *를 인자로 주면
   포인터 변수가 가지고 있는 주소를 바꿔야 하기 때문에
   이중 포인터를 사용해야 하지만
   구조체를 만든 뒤 구조체 포인터를 인자로 주면
   이중 포인터를 사용하지 않아도 된다.
   포인터 변수의 주소를 준 것과
   포인터 변수를 담은 구조체의 주소를 준 것의 차이긴 하다...*/
typedef struct LinkedStackTypeTag {
	StackNode *top;
}LinkedStackType;

void init(LinkedStackType *s) {
	s->top = NULL;
}
int is_empty(LinkedStackType *s) {
	return(s->top == NULL);
}
void push(LinkedStackType *s, element item) {
	StackNode *tmp = (StackNode *)malloc(sizeof(StackNode));
	if (tmp == NULL) {
		fprintf(stderr, "Allocation Error!");
		exit(1);
	}
	tmp->data = item;	
	tmp->link = s->top;
	s->top = tmp;
}
element pop(LinkedStackType *s) {
	if (is_empty(s)) {
		fprintf(stderr, "stack is empty!");
		exit(1);
	}
	else {
		StackNode *tmp = s->top;
		int data = tmp->data;
		s->top = s->top->link;
		free(tmp);
		return data;
	}	
}
element peek(LinkedStackType *s) {
	if (is_empty(s)) {
		fprintf(stderr, "stack is empty!");
		exit(1);
	}
	else {
		return s->top->data;
	}
}
void print_stack(LinkedStackType *s) {
	StackNode *p = s->top;
	while (p != NULL) {
		printf("%d->",p->data);
		p = p->link;
	}
	printf("NULL\n");
}

int main() {
	LinkedStackType s;
	init(&s);
	push(&s, 1); 
	print_stack(&s);
	push(&s, 2); 
	print_stack(&s);
	push(&s, 3); 
	print_stack(&s);
	pop(&s); 
	print_stack(&s);
	pop(&s); 
	print_stack(&s);
	pop(&s); 
	print_stack(&s);
	return 0;
}
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//typedef char name[20];
//typedef struct DListNodeTag {
//	struct DListNodeTag *flink;
//	name song;
//	struct DListNodeTag *blink;
//}DListNode;
//
//DListNode *curr;
//
//void init(DListNode *head) {
//	head->blink = head;
//	head->flink = head;
//}
//void ins(DListNode *before, const char *str) {
//	DListNode *p = (DListNode *)malloc(sizeof(DListNode));
//	if (p == NULL) {
//		fprintf(stderr, "Allocation error!");
//		exit(1);
//	}
//	strcpy_s(p->song, sizeof(p->song), str); 
//	p->flink = before;
//	p->blink = before->blink;
//	before->blink = p;
//	p->blink->flink = p;
//}
//void del(DListNode *head, DListNode *removed) {
//	if (head == removed) return;
//	removed->flink->blink = removed->blink;
//	removed->blink->flink = removed->flink;
//	free(removed);
//}
//void print_list(DListNode *head) {
//	DListNode *p = head->blink;
//	while (p != head) {
//		if (p == curr) {
//			printf("<- | #%s# | -> ", p->song);
//		}
//		else {
//			printf("<- | %s | -> ", p->song);
//		}
//		p = p->blink;
//	}
//	printf("\n");
//}
//
//int main() {
//	char ch;
//	DListNode *head = (DListNode *)malloc(sizeof(DListNode));
//	init(head);
//	ins(head, "Fernando");
//	ins(head, "Dancing Queen");
//	ins(head, "Mamamia");
//	curr = head->blink;
//	print_list(head);
//	do {
//		printf("명령어를 입력하시오(<,>,q): ");
//		ch = getchar();
//		while (getchar() != '\n');
//		switch (ch) {
//		case '>':
//			curr = curr->blink;
//			if (curr == head)
//				curr = curr->blink;
//			break;
//		case '<':
//			curr = curr->flink;
//			if (curr == head)
//				curr = curr->flink;
//			break;
//		}	
//		print_list(head);
//	} while (ch != 'q');
//	del(head, head->blink);
//	del(head, head->blink);
//	del(head, head->blink);
//	free(head);
//	return 0;
//}
//#include <stdio.h>
//#include <stdlib.h>
//
//typedef int element;
//typedef struct DListNodeTag {
//	struct DListNodeTag *flink;
//	element data;
//	struct DListNodeTag *blink;
//}DListNode;
//
//void init(DListNode *head) {
//	head->blink = head;
//	head->flink = head;
//}
//void ins(DListNode *before, element data) {
//	DListNode *p = (DListNode *)malloc(sizeof(DListNode));
//	if (p == NULL) {
//		fprintf(stderr, "Allocation error!");
//		exit(1);
//	}
//	p->data = data;
//	p->flink = before;
//	p->blink = before->blink;
//	before->blink = p;
//	p->blink->flink = p;
//}
//void del(DListNode *head, DListNode *removed) {
//	// 이전에 단일 연결 리스트나 원형 연결 리스트를 만들 때는
//	// 삭제할 노드의 포인터 변수를 인자로 넣지 않았는데
//	// 그 이유는 삭제할 노드의 주소를 알아도 앞 노드로 이동해
//	// 앞 노드의 링크를 바꿀 방법이 처음부터 순회해서 앞 노드를 찾는 방법 밖에 없었기 때문이다.
//	if (head == removed) return;
//	removed->flink->blink = removed->blink;
//	removed->blink->flink = removed->flink;
//	free(removed);
//}
//void print_list(DListNode *head) {
//	DListNode *p = head->blink;
//	while (p != head) {
//		printf("<-| |%d| |-> ", p->data);
//		p = p->blink;
//	}
//	printf("\n");
//}
//
//int main() {
//	DListNode *head = (DListNode *)malloc(sizeof(DListNode));
//	if (head == NULL) {
//		fprintf(stderr, "Allocation error!");
//		exit(1);
//	}
//	init(head);
//
//	for (int i = 0; i < 5; i++) {
//		ins(head, i);
//		print_list(head);
//	}
//
//	for (int i = 0; i < 5; i++) {
//		print_list(head);
//		del(head, head->blink);
//	}
//	free(head);
//	return 0;
//}
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//typedef char name[20];
//typedef struct ListNodeTag {
//	name data;
//	struct ListNodeTag *link;
//}ListNode;
//
//void insert_first(ListNode **head, const char *data) {
//	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
//	if (p == NULL) {
//		fprintf(stderr, "allocation error!");
//		exit(1);
//	}
//	strcpy_s(p->data, sizeof(p->data), data);
//	if (*head == NULL) {
//		*head = p;
//		p->link = *head;
//	}
//	else {
//		p->link = (*head)->link;
//		(*head)->link = p;
//	}
//}
//void insert_last(ListNode **head, const char *data) {
//	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
//	if (p == NULL) {
//		fprintf(stderr, "allocation error!");
//		exit(1);
//	}
//	strcpy_s(p->data, sizeof(p->data), data);
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
//		printf("%s->", p->data);
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
//	insert_last(&head, "KIM");
//	insert_last(&head, "PARK");
//	insert_last(&head, "CHOI");
//
//	ListNode *p = head->link;
//	for (int i = 0; i < 10; i++) {
//		printf("현재 차례 = %s\n", p->data);
//		p = p->link;
//	}
//	free_list(&head);
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