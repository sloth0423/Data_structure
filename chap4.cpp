#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100
#define MAZE_SIZE 10

typedef struct elementTag {
	short r;
	short c;
}element;

typedef struct StackTypeTag {
	element* data;
	int capacity;
	int top;
}StackType;

void init_stack(StackType* s) {
	s->top = -1;
	s->capacity = 1;
	s->data = (element*)malloc(s->capacity * sizeof(element));
	if (s->data == NULL) {
		fprintf(stderr, "error!\n");
		exit(1);
	}
}
void delete1(StackType* s) {
	free(s->data);
}
int is_empty(StackType* s) {
	return (s->top == -1);
}
int is_full(StackType* s) {
	return (s->top == (s->capacity) - 1);
}
void push(StackType* s, element item) {
	if (is_full(s)) {
		s->capacity *= 2;
		element* temp = (element*)realloc(s->data, s->capacity * sizeof(element));
		if (temp == NULL) {
			fprintf(stderr, "error!");
			delete1(s);
			exit(1);
		}
		s->data = temp;
	}
	s->data[++(s->top)] = item;
}
element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "error!");
		delete1(s);
		exit(1);
	}
	return s->data[(s->top)--];
}
element peek(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "error!");
		delete1(s);
		exit(1);
	}
	return s->data[s->top];
}

element here = { 1,0 }, entry = { 1,0 };

char maze[MAZE_SIZE][MAZE_SIZE] = {
	{'1','1','1','1','1','1','1','1','1','1'},
	{'e','0','0','0','1','0','0','0','0','1'},
	{'1','0','0','0','1','0','0','0','0','1'},
	{'1','0','1','1','1','0','0','1','0','1'},
	{'1','0','0','0','1','0','0','1','0','1'},
	{'1','0','1','0','1','0','0','1','0','1'},
	{'1','0','1','0','1','0','0','1','0','1'},
	{'1','0','1','0','1','0','0','1','0','1'},
	{'1','0','1','0','0','0','0','1','0','x'},
	{'1','1','1','1','1','1','1','1','1','1'}
};
void push_loc(StackType* s, int r, int c) {
	if (r < 0 || c < 0) return;
	if (maze[r][c] != '1' && maze[r][c] != '.') {
		element tmp;
		tmp.r = r;
		tmp.c = c;
		push(s, tmp);
	}
}
void maze_print(char maze[MAZE_SIZE][MAZE_SIZE]) {
	printf("\n");
	for (int r = 0; r < MAZE_SIZE; r++) {
		for (int c = 0; c < MAZE_SIZE; c++) {
			printf("%c", maze[r][c]);
		}
		printf("\n");
	}
}

int main() {
	int r, c;
	StackType s;

	init_stack(&s);
	here = entry;
	while (maze[here.r][here.c] != 'x') {
		r = here.r;
		c = here.c;
		maze[r][c] = '.';
		maze_print(maze);
		push_loc(&s, r - 1, c);
		push_loc(&s, r + 1, c);
		push_loc(&s, r, c - 1);
		push_loc(&s, r, c + 1);
		if (is_empty(&s)) {
			printf("실패\n");
			return 1;
		}
		else
			here = pop(&s);
	}
	printf("성공\n");
	return 0;
}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
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
//		element* temp = (element*)realloc(s->data, s->capacity * sizeof(element));
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
//int prec(char op) {
//	switch (op) {
//	case'(': case ')': return 0;
//	case '+': case '-': return 1;
//	case '*': case '/': return 2;
//	}
//	return -1;
//}
//char *infix_to_postfix(const char *exp) {
//	StackType s;
//	char *result = (char *)malloc(100 * sizeof(char));
//	size_t len = strlen(exp);
//	size_t len2 = 0;
//	init_stack(&s);
//
//	for (int i = 0; i < len; i++) {
//		if (exp[i] == '*' || exp[i] == '+' || exp[i] == '/' || exp[i] == '-') {
//			for (;!(is_empty(&s)) && (prec(peek(&s)) >= prec(exp[i]));) {
//				result[len2] = pop(&s);
//				len2++;
//			}
//			push(&s, exp[i]);
//		}
//		else if (exp[i] == '(') {
//			push(&s, exp[i]);
//		}
//		else if (exp[i] == ')') {
//			while (s.data[s.top] != '(') {
//				result[len2] = pop(&s);
//				len2++;
//			}
//			pop(&s);
//		}
//		else {
//			result[len2] = exp[i];
//			len2++;
//		}
//	}
//	while (!(is_empty(&s))) {
//		result[len2] = pop(&s);
//		len2++;
//	}
//	result[len2] = '\0';
//	delete1(&s);
//	return result;
//}
//
//int eval(const char *exp) {
//	int value = 0;
//	int op1, op2 = 0;
//	char ch;
//	size_t len = strlen(exp);
//	StackType s;
//	init_stack(&s);
//	for (int i = 0; i < len; i++) {
//		if (exp[i] == '*' || exp[i] == '/' || exp[i] == '+' || exp[i] == '-') {
//			ch = exp[i];
//			op1 = pop(&s);
//			op2 = pop(&s);
//			switch (ch) {
//			case '*':
//				push(&s, op2 * op1);
//				break;
//			case '/':
//				push(&s, op2 / op1);
//				break;
//			case '+':
//				push(&s, op2 + op1);
//				break;
//			case '-':
//				push(&s, op2 - op1);
//				break;
//			}
//		}
//		else {
//			value = exp[i] - '0';
//			push(&s, value);
//		}
//	}
//	int result = pop(&s);
//	delete1(&s);
//	return result;
//}
//int main() {
//	int result;
//	printf("후위표기식은 82/3-32*+\n");
//	result = eval("82/3-32*+");
//	printf("결과 값은 %d\n", result);
//	char *rslt = infix_to_postfix("a+b*c");
//	printf("%s\n", rslt);
//	free(rslt);
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
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
//		element* temp = (element*)realloc(s->data, s->capacity * sizeof(element));
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
//int eval(const char *exp) {
//	int value = 0;
//	int op1, op2 = 0;
//	char ch;
//	size_t len = strlen(exp);
//	StackType s;
//	init_stack(&s);
//	for (int i = 0; i < len; i++) {
//		if (exp[i] == '*' || exp[i] == '/' || exp[i] == '+' || exp[i] == '-') {
//			ch = exp[i];
//			op1 = pop(&s);
//			op2 = pop(&s);
//			switch (ch) {
//			case '*':
//				push(&s, op2 * op1);
//				break;
//			case '/':
//				push(&s, op2 / op1);
//				break;
//			case '+':
//				push(&s, op2 + op1);
//				break;
//			case '-':
//				push(&s, op2 - op1);
//				break;
//			}
//		}
//		else {
//			value = exp[i] - '0';
//			push(&s, value);
//		}
//	}
//	int result = pop(&s);
//	delete1(&s);
//	return result;
//}
//int main() {
//	int result;
//	printf("후위표기식은 82/3-32*+\n");
//	result = eval("82/3-32*+");
//	printf("결과 값은 %d\n", result);
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#define MAX_STACK_SIZE 100
//
//typedef char element;
//typedef struct StackTypeTag {
//	element *data;
//	int capacity;
//	int top;
//}StackType;
//
//void init_stack(StackType *s) {
//	s->top = -1;
//	s->capacity = 1;
//	s->data = (element*)malloc(s->capacity * sizeof(element));
//	if (s->data == NULL) {
//		fprintf(stderr, "error!\n");
//		exit(1);
//	}
//}
//void delete1(StackType *s) {
//	free(s->data);
//}
//int is_empty(StackType *s) {
//	return (s->top == -1);
//}
//int is_full(StackType *s) {
//	return (s->top == (s->capacity) - 1);
//}
//void push(StackType *s, element item) {
//	if (is_full(s)) {
//		s->capacity *= 2;
//		element *temp = (element *)realloc(s->data, s->capacity * sizeof(element));
//		if (temp == NULL) {
//			fprintf(stderr, "error!");
//			delete1(s);
//			exit(1);
//		}
//		s->data = temp;
//	}
//	s->data[++(s->top)] = item;
//}
//element pop(StackType *s) {
//	if (is_empty(s)) {
//		fprintf(stderr, "error!");
//		delete1(s);
//		exit(1);
//	}
//	return s->data[(s->top)--];
//}
//element peek(StackType *s) {
//	if (is_empty(s)) {
//		fprintf(stderr, "error!");
//		delete1(s);
//		exit(1);
//	}
//	return s->data[s->top];
//}
//int check_matching(const char *expr) {
//	StackType s;
//	element ch, open_ch;
//	init_stack(&s);
//	for(int i = 0; i < strlen(expr); i++) {
//		ch = expr[i];
//		switch (ch) {
//		case '(': case '[': case '{':
//			push(&s, ch);
//			break;
//		case ')': case ']': case '}':
//			if (is_empty(&s)) {
//				delete1(&s);
//				return 0;
//			}
//			open_ch = pop(&s);
//			if ((ch != ')' && open_ch == '(') || (ch != '}' && open_ch == '{') || (ch != ']' && open_ch == '[')) {
//				delete1(&s);
//				return 0;
//			}
//			break;
//		}
//	}
//	if (!is_empty(&s)) {
//		delete1(&s);
//		return 0;
//	}
//	delete1(&s);
//	return 1;
//}
//int main() {
//	StackType expr;
//	init_stack(&expr);
//	push(&expr, '{');
//	push(&expr, ' ');
//	push(&expr, 'A');
//	push(&expr, '[');
//	push(&expr, '(');
//	push(&expr, 'i');
//	push(&expr, '+');
//	push(&expr, '1');
//	push(&expr, ')');
//	push(&expr, ']');
//	push(&expr, '=');
//	push(&expr, '0');
//	push(&expr, ';');
//	push(&expr, ' ');
//	push(&expr, '}');
//	push(&expr, '\0');
//
//	if (check_matching(expr.data) == 1) {
//		printf("%s 괄호 검사 성공\n", expr.data);
//	}
//	else {
//		printf("%s 괄호 검사 실패\n", expr.data);
//	}
//	delete1(&expr);
//	return 0;
//}

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