#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100

typedef char element;
typedef struct StackTypeTag {
	element *data;
	int capacity;
	int top;
}StackType;

void init_stack(StackType *s) {
	s->top = -1;
	s->capacity = 1;
	s->data = (element*)malloc(s->capacity * sizeof(element));
	if (s->data == NULL) {
		fprintf(stderr, "error!\n");
		exit(1);
	}
}
void delete1(StackType *s) {
	free(s->data);
}
int is_empty(StackType *s) {
	return (s->top == -1);
}
int is_full(StackType *s) {
	return (s->top == (s->capacity) - 1);
}
void push(StackType *s, element item) {
	if (is_full(s)) {
		s->capacity *= 2;
		element *temp = (element *)realloc(s->data, s->capacity * sizeof(element));
		if (temp == NULL) {
			fprintf(stderr, "error!");
			delete1(s);
			exit(1);
		}
		s->data = temp;
	}
	s->data[++(s->top)] = item;
}
element pop(StackType *s) {
	if (is_empty(s)) {
		fprintf(stderr, "error!");
		delete1(s);
		exit(1);
	}
	return s->data[(s->top)--];
}
element peek(StackType *s) {
	if (is_empty(s)) {
		fprintf(stderr, "error!");
		delete1(s);
		exit(1);
	}
	return s->data[s->top];
}
int check_matching(const char *expr) {
	StackType s;
	element ch, open_ch;
	init_stack(&s);
	for(int i = 0; i < strlen(expr); i++) {
		ch = expr[i];
		switch (ch) {
		case '(': case '[': case '{':
			push(&s, ch);
			break;
		case ')': case ']': case '}':
			if (is_empty(&s)) {
				delete1(&s);
				return 0;
			}
			open_ch = pop(&s);
			if ((ch != ')' && open_ch == '(') || (ch != '}' && open_ch == '{') || (ch != ']' && open_ch == '[')) {
				delete1(&s);
				return 0;
			}
			break;
		}
	}
	if (!is_empty(&s)) {
		delete1(&s);
		return 0;
	}
	delete1(&s);
	return 1;
}
int main() {
	StackType expr;
	init_stack(&expr);
	push(&expr, '{');
	push(&expr, ' ');
	push(&expr, 'A');
	push(&expr, '[');
	push(&expr, '(');
	push(&expr, 'i');
	push(&expr, '+');
	push(&expr, '1');
	push(&expr, ')');
	push(&expr, ']');
	push(&expr, '=');
	push(&expr, '0');
	push(&expr, ';');
	push(&expr, ' ');
	push(&expr, '}');
	push(&expr, '\0');

	if (check_matching(expr.data) == 1) {
		printf("%s 괄호 검사 성공\n", expr.data);
	}
	else {
		printf("%s 괄호 검사 실패\n", expr.data);
	}
	delete1(&expr);
	return 0;
}

//#include <stdio.h>
//#include <stdlib.h>
//#define MAX_STACK_SIZE 100
//
//typedef int element;
//typedef struct StackTypeTag {
//	element* data;
//	int capacity;
//	int top;
//}StackType;
//
//void init_stack(StackType* s) {
//	s->top = -1;
//	s->capacity = 1;
//	s->data = (element*)malloc(s->capacity * sizeof(element));
//	if (s->data == NULL) {
//		fprintf(stderr, "error!\n");
//		exit(1);
//	}
//}
//void delete1(StackType* s) {
//	free(s->data);
//}
//int is_empty(StackType* s) {
//	return (s->top == -1);
//}
//int is_full(StackType* s) {
//	return (s->top == (s->capacity) - 1);
//}
//void push(StackType* s, element item) {
//	if (is_full(s)) {
//		s->capacity *= 2;
//		element *temp = (element*)realloc(s->data, s->capacity * sizeof(element));
//		if (temp == NULL) {
//			fprintf(stderr, "error!");
//			delete1(s);
//			exit(1);
//		}
//		s->data = temp;
//	}
//	s->data[++(s->top)] = item;
//}
//element pop(StackType* s) {
//	if (is_empty(s)) {
//		fprintf(stderr, "error!");
//		delete1(s);
//		exit(1);
//	}
//	return s->data[(s->top)--];
//}
//element peek(StackType* s) {
//	if (is_empty(s)) {
//		fprintf(stderr, "error!");
//		delete1(s);
//		exit(1);
//	}
//	return s->data[s->top];
//}
//
//int main() {
//	StackType s;
//	init_stack(&s);
//	push(&s, 1);
//	push(&s, 2);
//	push(&s, 3);
//	printf("%d\n", pop(&s));
//	printf("%d\n", pop(&s));
//	printf("%d\n", pop(&s));
//	delete1(&s);
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#define MAX_STACK_SIZE 100
//
//typedef int element;
//typedef struct StackTypeTag {
//	int data[MAX_STACK_SIZE];
//	int top;
//}StackType;
//
//void init_stack(StackType* s) {
//	s->top = -1;
//}
//int is_empty(StackType* s) {
//	return (s->top == -1);
//}
//int is_full(StackType* s) {
//	return (s->top == MAX_STACK_SIZE);
//}
//void push(StackType* s, element item) {
//	if (is_full(s)) {
//		fprintf(stderr, "error!");
//		return;
//	}
//	else s->data[++(s->top)] = item;
//}
//element pop(StackType* s) {
//	if (is_empty(s)) {
//		fprintf(stderr, "error!");
//		exit(1);
//	}
//	else return s->data[(s->top)--];
//}
//element peek(StackType* s) {
//	if (is_empty(s)) {
//		fprintf(stderr, "error!");
//		exit(1);
//	}
//	else return s->data[s->top];
//}
//int main() {
//	StackType *s1;
//	StackType* s2;
//	s1 = (StackType*)malloc(sizeof(StackType));
//	s2 = (StackType*)malloc(sizeof(StackType));
//
//	init_stack(s1);
//	init_stack(s2);
//	push(s1, 1);
//	push(s1, 2);
//	push(s1, 3);
//	push(s2, pop(s1));
//	push(s2, pop(s1));
//	push(s2, pop(s1));
//	printf("%d\n", pop(s2));
//	printf("%d\n", pop(s2));
//	printf("%d\n", pop(s2));
//	free(s1);
//	free(s2);
//	return 0;
//
//}

//#include <stdio.h>
//#include <stdlib.h>
//#define MAX_STACK_SIZE 100
//
//typedef int element;
//typedef struct StackTypeTag {
//	int data[MAX_STACK_SIZE];
//	int top;
//}StackType;
//
//void init_stack(StackType* s) {
//	s->top = -1;
//}
//int is_empty(StackType* s) {
//	return (s->top == -1);
//}
//int is_full(StackType* s) {
//	return (s->top == MAX_STACK_SIZE);
//}
//void push(StackType* s, element item) {
//	if (is_full(s)) {
//		fprintf(stderr, "error!");
//		return;
//	}
//	else s->data[++(s->top)] = item;
//}
//element pop(StackType* s) {
//	if (is_empty(s)) {
//		fprintf(stderr, "error!");
//		exit(1);
//	}
//	else return s->data[(s->top)--];
//}
//element peek(StackType* s) {
//	if (is_empty(s)) {
//		fprintf(stderr, "error!");
//		exit(1);
//	}
//	else return s->data[s->top];
//}
//int main() {
//	StackType s1;
//	StackType s2;
//
//
//	init_stack(&s1);
//	init_stack(&s2);
//	push(&s1, 1);
//	push(&s1, 2);
//	push(&s1, 3);
//	push(&s2, pop(&s1));
//	push(&s2, pop(&s1));
//	push(&s2, pop(&s1));
//	printf("%d\n", pop(&s2));
//	printf("%d\n", pop(&s2));
//	printf("%d\n", pop(&s2));
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#define MAX_STACK_SIZE 100
//
//typedef int element;
//typedef struct StackTypeTag {
//	int data[MAX_STACK_SIZE];
//	int top;
//}StackType;
//
//void init_stack(StackType *s) {
//	s->top = -1;
//}
//int is_empty(StackType *s) {
//	return (s->top == -1);
//}
//int is_full(StackType *s) {
//	return (s->top == MAX_STACK_SIZE);
//}
//void push(StackType* s, element item) {
//	if (is_full(s)) {
//		fprintf(stderr, "error!");
//		return;
//	}
//	else s->data[++(s->top)] = item;
//}
//element pop(StackType* s) {
//	if (is_empty(s)) {
//		fprintf(stderr, "error!");
//		exit(1);
//	}
//	else return s->data[(s->top)--];
//}
//element peek(StackType* s) {
//	if (is_empty(s)) {
//		fprintf(stderr, "error!");
//		exit(1);
//	}
//	else return s->data[s->top];
//}
//int main() {
//	StackType s;
//
//	init_stack(&s);
//	push(&s, 1);
//	push(&s, 2);
//	push(&s, 3);
//	printf("%d\n", pop(&s));
//	printf("%d\n", pop(&s));
//	printf("%d\n", pop(&s));
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#define MAX_STACK_SIZE 100
//#define MAX_STRING 100
//
//typedef struct elementTag {
//	int student_no;
//	char name[MAX_STRING];
//	char address[MAX_STRING];
//}element;
//
//element stack[MAX_STACK_SIZE];
//int top = -1;
//
// int is_empty() {
//	return (top == -1);
//}
// int is_full() {
//	 return (top == MAX_STACK_SIZE);
// }
// void push(element item) {
//	 if (is_full()) {
//		 fprintf(stderr, "error!");
//		 return;
//	 }
//	 stack[++top] = item;
// }
// element pop() {
//	 if (is_empty()) {
//		 fprintf(stderr, "error!");
//		 exit(1);
//	 }
//	 return stack[top--];
// }
// element peek() {
//	 if (is_empty()) {
//		 fprintf(stderr, "error!");
//		 exit(1);
//	 }
//	 return stack[top];
// }
//int main() {
//	element ie = { 20090001, "HONG", "Seoul" };
//	element oe;
//
//	push(ie);
//	oe = pop();
//
//	printf("%d\n", oe.student_no);
//	printf("%s\n", oe.name);
//	printf("%s\n", oe.address);
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#define MAX_STACK_SIZE 100
//
//int stack[MAX_STACK_SIZE];
//int top = -1;
//
//int is_empty() {
//	/*if (top == -1) return true;
//	else return false;*/
//	return (top == -1);
//}
//int is_full() {
//	/*if (top == MAX_STACK_SIZE - 1) return true;
//	else return false;*/
//	return (top == MAX_STACK_SIZE - 1);
//}
//void push(int item) {
//	if (is_full()) {
//		fprintf(stderr, "error!");
//		return;
//	}
//	stack[++top] = item;
//}
//int pop() {
//	if (is_empty()) {
//		fprintf(stderr, "error!");
//		exit(1);
//	}
//
//	int t = stack[top];
//	stack[top] = NULL;
//	top--;
//	return t;
//}
//int peek() {
//	if (is_empty()) {
//		fprintf(stderr, "error!");
//		exit(1);
//	}
//	return stack[top];
// }
//int main() {
//	push(1);
//	push(2);
//	push(3);
//	printf("%d\n", pop());
//	printf("%d\n", pop());
//	printf("%d\n", pop());
//	return 0;
//}