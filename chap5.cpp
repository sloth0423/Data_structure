#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_DEQUE_SIZE 20

typedef int element;
typedef struct DequeTypeTag {
	int front;
	int rear;
	element data[MAX_DEQUE_SIZE];
}DequeType;

void error(const char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}
void init_deque(DequeType* q) {
	q->front = 0;
	q->rear = 0;
}
int is_empty(DequeType* q) {
	return (q->front == q->rear);
}
int is_full(DequeType* q) {
	return ((q->rear + 1) % MAX_DEQUE_SIZE == q->front);
}
void add_front(DequeType* q, element item) {
	if (is_full(q)) {
		error("덱이 포화상태입니다.");
		return;
	}
	q->data[q->front] = item;
	q->front = (q->front - 1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
	// 음수가 되면 %연산이 안되기 때문에 MAX_DEQUE_SIZE를 더해준다.
}
void add_rear(DequeType* q, element item) {
	if (is_full(q)) {
		error("덱이 포화상태입니다.");
		return;
	}
	q->rear = (q->rear + 1) % MAX_DEQUE_SIZE;
	q->data[q->rear] = item;
}
element delete_front(DequeType* q) {
	if (is_empty(q)) {
		error("덱이 공백상태입니다.");
		return -1;
	}
	q->front = (q->front + 1) % MAX_DEQUE_SIZE;
	element item = q->data[q->front];
	return item;
}
element delete_rear(DequeType* q) {
	if (is_empty(q)) {
		error("덱이 공백상태입니다.");
		return -1;
	}
	element item = q->data[q->rear];
	q->rear = (q->rear - 1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
	// 음수가 되면 %연산이 안되기 때문에 MAX_DEQUE_SIZE를 더해준다.
	return item;
}
element get_front(DequeType* q) {
	if (is_empty(q)) {
		error("덱이 공백상태입니다.");
		return -1;
	}
	element item = q->data[(q->front + 1) % MAX_DEQUE_SIZE];
	return item;
}
element get_rear(DequeType* q) {
	if (is_empty(q)) {
		error("덱이 공백상태입니다.");
		return -1;
	}
	element item = q->data[q->rear];
	return item;
}
int get_count(DequeType* d) {
	if (d->front > d->rear) {
		return MAX_DEQUE_SIZE + d->rear - d->front;
	}
	return d->rear - d->front;
}

void print_deque(DequeType* q) {
	printf("front=%d rear=%d = ", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % MAX_DEQUE_SIZE;
			printf("%d | ", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	printf("\n");
}

int main() {
	DequeType d1, d2, d3;
	init_deque(&d1);
	init_deque(&d2);
	init_deque(&d3);
	int simulation_times = 30;
	int clock = 0;
	srand(time(NULL));
	int d1_qty = rand() % 15;
	int d2_qty = rand() % 15;
	int d3_qty = rand() % 15;
	for (int i = 0; i < d1_qty; i++) {
		add_rear(&d1, i);
	}
	for (int i = 0; i < d2_qty; i++) {
		add_rear(&d2, i);
	}
	for (int i = 0; i < d3_qty; i++) {
		add_rear(&d3, i);
	}
	for(; clock < simulation_times; clock++){
		if (is_empty(&d1) && is_empty(&d2) && is_empty(&d3))
			break;
		if (is_empty(&d1)) {
			(get_count(&d2) > get_count(&d3)) ? add_rear(&d1, delete_rear(&d2)):add_rear(&d1, delete_rear(&d3));
		}
		if (is_empty(&d2)) {
			(get_count(&d1) > get_count(&d3)) ? add_rear(&d2, delete_rear(&d1)) : add_rear(&d2, delete_rear(&d3));
		}
		if (is_empty(&d3)) {
			(get_count(&d1) > get_count(&d2)) ? add_rear(&d3, delete_rear(&d1)) : add_rear(&d3, delete_rear(&d2));
		}
		printf("일하기 전");
		print_deque(&d1);
		print_deque(&d2);
		print_deque(&d3);
		printf("\n");
		delete_front(&d1);
		delete_front(&d2);
		delete_front(&d3);
		printf("일한 후");
		print_deque(&d1);
		print_deque(&d2);
		print_deque(&d3);
		printf("\n");
	}

	return 0;
}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#define MAX_DEQUE_SIZE 100
//
//typedef char element;
//typedef struct DequeTypeTag {
//	int front;
//	int rear;
//	element data[MAX_DEQUE_SIZE];
//}DequeType;
//
//void error(const char* message) {
//	fprintf(stderr, "%s\n", message);
//	exit(1);
//}
//void init_deque(DequeType* q) {
//	q->front = 0;
//	q->rear = 0;
//}
//int is_empty(DequeType* q) {
//	return (q->front == q->rear);
//}
//int is_full(DequeType* q) {
//	return ((q->rear + 1) % MAX_DEQUE_SIZE == q->front);
//}
//void add_front(DequeType* q, element item) {
//	if (is_full(q)) {
//		error("덱이 포화상태입니다.");
//		return;
//	}
//	q->data[q->front] = item;
//	q->front = (q->front - 1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE; 
//	// 음수가 되면 %연산이 안되기 때문에 MAX_DEQUE_SIZE를 더해준다.
//}
//void add_rear(DequeType* q, element item) {
//	if (is_full(q)) {
//		error("덱이 포화상태입니다.");
//		return;
//	}
//	q->rear = (q->rear + 1) % MAX_DEQUE_SIZE;
//	q->data[q->rear] = item;
//}
//element delete_front(DequeType* q) {
//	if (is_empty(q)) {
//		error("덱이 공백상태입니다.");
//		return -1;
//	}
//	q->front = (q->front + 1) % MAX_DEQUE_SIZE;
//	element item = q->data[q->front];
//	return item;
//}
//element delete_rear(DequeType* q) {
//	if (is_empty(q)) {
//		error("덱이 공백상태입니다.");
//		return -1;
//	}
//	element item = q->data[q->rear];
//	q->rear = (q->rear - 1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
//	// 음수가 되면 %연산이 안되기 때문에 MAX_DEQUE_SIZE를 더해준다.
//	return item;
//}
//element get_front(DequeType* q) {
//	if (is_empty(q)) {
//		error("덱이 공백상태입니다.");
//		return -1;
//	}
//	element item = q->data[(q->front + 1) % MAX_DEQUE_SIZE];
//	return item;
//}
//element get_rear(DequeType* q) {
//	if (is_empty(q)) {
//		error("덱이 공백상태입니다.");
//		return -1;
//	}
//	element item = q->data[q->rear];
//	return item;
//}
//void check_palindrome(const char* str) {
//	DequeType d;
//	init_deque(&d);
//	int len = strlen(str);
//	char ch, ch_front, ch_rear;
//	for (int i = 0; i < len; i++) {
//		ch = str[i];
//			if (ch != '\0' && ch != ' ' && ch != '.' && ch != '\'' && ch != '"' && ch != ',') {
//				if (ch >= 'A' && ch <= 'Z') ch += 32;
//				add_rear(&d, ch);
//			}
//	}
//	while(!is_empty(&d)) {
//		ch_front = delete_front(&d);
//		if (is_empty(&d)) break;
//		ch_rear = delete_rear(&d);
//		if (ch_front != ch_rear) {
//			printf("회문이 아닙니다.\n");
//			return;
//		}
//	}
//	printf("회문입니다.\n");
//}
//void print_deque(DequeType* q) {
//	printf("front=%d rear=%d = ", q->front, q->rear);
//	if (!is_empty(q)) {
//		int i = q->front;
//		do {
//			i = (i + 1) % MAX_DEQUE_SIZE;
//			printf("%c | ", q->data[i]);
//			if (i == q->rear)
//				break;
//		} while (i != q->front);
//	}
//	printf("\n");
//}
//
//int main() {
//	DequeType q;
//	init_deque(&q);
//	
//	check_palindrome("madam, I'm Adam");
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#define MAX_QUEUE_SIZE 5
//
//typedef int element;
//
//typedef struct QueueTypeTag {
//	int front;
//	int rear;
//	element data[MAX_QUEUE_SIZE];
//}QueueType;
//void error(const char* message) {
//	fprintf(stderr, "%s\n", message);
//	exit(1);
//}
//void init_queue(QueueType* q) {
//	q->front = 0;
//	q->rear = 0;
//}
//int is_empty(QueueType* q) {
//	return (q->front == q->rear);
//}
//int is_full(QueueType* q) {
//	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
//}
//void enqueue(QueueType* q, element item) {
//	if (is_full(q)) {
//		error("큐가 포화상태입니다.");
//		return;
//	}
//	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
//	q->data[q->rear] = item;
//}
//element dequeue(QueueType* q) {
//	if (is_empty(q)) {
//		error("큐가 공백상태입니다.");
//		return -1;
//	}
//	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
//	element item = q->data[q->front];
//	return item;
//}
//element peek(QueueType* q) {
//	if (is_empty(q)) {
//		error("큐가 공백상태입니다.");
//		return -1;
//	}
//	element item = q->data[(q->front + 1) % MAX_QUEUE_SIZE];
//	return item;
//}
//void print_queue(QueueType* q) {
//	printf("front=%d rear=%d = ", q->front, q->rear);
//	if (!is_empty(q)) {
//		int i = q->front;
//		do {
//			i = (i + 1) % MAX_QUEUE_SIZE;
//			printf("%d | ", q->data[i]);
//			if (i == q->rear)
//				break;
//		} while (i != q->front);
//	}
//	printf("\n");
//}
//element fib(int arg) {
//	QueueType q;
//	init_queue(&q);
//
//	enqueue(&q, 0);
//	enqueue(&q, 1);
//	if (arg == 0) return 0;
//	if (arg == 1) return 1;
//	int var1, var2, rslt= 0;
//	for (int i = 1; i < arg; i++) {
//		var1 = dequeue(&q);
//		var2 = peek(&q);
//		rslt = var1 + var2;
//		enqueue(&q, rslt);
//	}
//	return rslt;
//}
//
//int main() {
//	printf("%d\n", fib(3));
//	printf("%d\n", fib(4));
//
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#define MAX_STACK_SIZE 100
//#define MAZE_SIZE 10
//
//typedef struct elementTag {
//	char ch;
//	int num;
//}element;
//typedef struct StackTypeTag {
//	element* data;
//	int capacity;
//	int top;
//}StackType;
//
//typedef struct QueueTypeTag {
//	StackType s1;
//	StackType s2;
//}QueueType;
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
//void enqueue(QueueType* q, element item) {
//	push(&(q->s1), item);
//}
//element dequeue(QueueType* q) {
//	if (is_empty(&(q->s2))){
//		while (!is_empty(&(q->s1))) {
//			push(&(q->s2), pop(&(q->s1)));
//		}
//	}
//	if (is_empty(&(q->s2))) {
//		fprintf(stderr, "error!");
//		exit(1);
//	}
//	return pop(&(q->s2));
//}
//
//int main(){
//	QueueType q;
//	
//	init_stack(&q.s1);
//	init_stack(&q.s2);
//
//	element e1 = { '1', 1 };
//	enqueue(&q, e1);
//	element e2 = { '2', 2 };
//	enqueue(&q, e2);
//	element e3 = dequeue(&q);
//	printf("%c, %d\n", e3.ch, e3.num);
//	element e4 = dequeue(&q);
//	printf("%c, %d\n", e4.ch, e4.num);
//	delete1(&q.s1);
//	delete1(&q.s2);
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#define MAX_QUEUE_SIZE 5
//
//typedef int element;
//
//typedef struct QueueTypeTag {
//	int front;
//	int rear;
//	element data[MAX_QUEUE_SIZE];
//}QueueType;
//void error(const char* message) {
//	fprintf(stderr, "%s\n", message);
//	exit(1);
//}
//void init_queue(QueueType* q) {
//	q->front = 0;
//	q->rear = 0;
//}
//int is_empty(QueueType* q) {
//	return (q->front == q->rear);
//}
//int is_full(QueueType* q) {
//	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
//}
//void enqueue(QueueType* q, element item) {
//	if (is_full(q)) {
//		error("큐가 포화상태입니다.");
//		return;
//	}
//	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
//	q->data[q->rear] = item;
//}
//element dequeue(QueueType* q) {
//	if (is_empty(q)) {
//		error("큐가 공백상태입니다.");
//		return -1;
//	}
//	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
//	element item = q->data[q->front];
//	return item;
//}
//element peek(QueueType* q) {
//	if (is_empty(q)) {
//		error("큐가 공백상태입니다.");
//		return -1;
//	}
//	element item = q->data[(q->front + 1) % MAX_QUEUE_SIZE];
//	return item;
//}
//void print_queue(QueueType* q) {
//	printf("front=%d rear=%d = ", q->front, q->rear);
//	if (!is_empty(q)) {
//		int i = q->front;
//		do {
//			i = (i + 1) % MAX_QUEUE_SIZE;
//			printf("%d | ", q->data[i]);
//			if (i == q->rear)
//				break;
//		} while (i != q->front);
//	}
//	printf("\n");
//}
//
//int get_count(QueueType* q) {
//	if (q->front > q->rear) {
//		return MAX_QUEUE_SIZE + q->rear - q->front;
//	}
//	return q->rear - q->front;
//}
// 
//// 내가 만든 print_queue() 
//// (front값을 저장해놓은 뒤 rear값이 될때까지 올리면 되는데
//// 출력해야할 원소의 개수를 구하는 것에 매몰되어 버렸다.)
////void print_queue(QueueType* q) {
////	printf("front = %d rear = %d = ", q->front, q->rear);
////	if (!is_empty(q)) {
////		int num;
////		int idx = q->front;
////		if (q->front > q->rear) num = MAX_QUEUE_SIZE - (q->front - q->rear);
////		else num = q->rear - q->front;
////		for (int i = 0; i < num; i++) {
////			idx = (idx + 1) % MAX_QUEUE_SIZE;
////			printf("%d |", q->data[idx]);
////		}
////	}
////	printf("\n");
////}
//
//int main() {
//	int item;
//	QueueType q;
//
//	init_queue(&q);
//
//	enqueue(&q, 10);
//	print_queue(&q);
//	enqueue(&q, 20);
//	print_queue(&q);
//	enqueue(&q, 30);
//	print_queue(&q);
//	enqueue(&q, 40);
//	print_queue(&q);
//	item = dequeue(&q);
//	print_queue(&q);
//	item = dequeue(&q);
//	print_queue(&q);
//	item = dequeue(&q);
//	print_queue(&q);
//	enqueue(&q, 50);
//	print_queue(&q);
//	enqueue(&q, 60);
//	print_queue(&q);
//	enqueue(&q, 70);
//	print_queue(&q);
//	item = dequeue(&q);
//	print_queue(&q);
//	item = dequeue(&q);
//	print_queue(&q);
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#define MAX_QUEUE_SIZE 5
//
//typedef struct elementTag {
//	int id;
//	int arrival_time;
//	int service_time;
//}element;
//
//typedef struct QueueTypeTag {
//	int front;
//	int rear;
//	element data[MAX_QUEUE_SIZE];
//}QueueType;
//void error(const char* message) {
//	fprintf(stderr, "%s\n", message);
//	exit(1);
//}
//void init_queue(QueueType* q) {
//	q->front = 0;
//	q->rear = 0;
//}
//int is_empty(QueueType* q) {
//	return (q->front == q->rear);
//}
//int is_full(QueueType* q) {
//	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
//}
//void enqueue(QueueType* q, element item) {
//	if (is_full(q)) {
//		error("큐가 포화상태입니다.");
//		return;
//	}
//	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
//	q->data[q->rear] = item;
//}
//element dequeue(QueueType* q) {
//	if (is_empty(q)) {
//		error("큐가 공백상태입니다.");
//	}
//	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
//	element item = q->data[q->front];
//	return item;
//}
//element peek(QueueType* q) {
//	if (is_empty(q)) {
//		error("큐가 공백상태입니다.");
//	}
//	element item = q->data[(q->front + 1) % MAX_QUEUE_SIZE];
//	return item;
//
////void print_queue(QueueType* q) {
////	printf("front=%d rear=%d = ", q->front, q->rear);
////	if (!is_empty(q)) {
////		int i = q->front;
////		do {
////			i = (i + 1) % MAX_QUEUE_SIZE;
////			printf("%d | ", q->data[i]);
////			if (i == q->rear)
////				break;
////		} while (i != q->front);
////	}
////	printf("\n");
////}
//
//int main() {
//	int minutes = 60;
//	int complete_customers = 0;
//	int total_wait = 0;
//	int total_customers = 0;
//	int service_time = 0;
//	int service_time2 = 0;
//	int service_customer;
//	int service_customer2;
//	QueueType q;
//	init_queue(&q);
//	QueueType q2;
//	init_queue(&q2);
//
//	srand(time(NULL));
//
//	for (int clock = 0; clock < minutes; clock++) {
//		printf("현재시각 %d\n", clock);
//		if ((rand() % 10) < 3) { // 고객 큐에 넣기
//			element customer;
//			customer.id = total_customers++;
//			customer.arrival_time = clock;
//			customer.service_time = (rand() % 3) + 1;
//			if (num_of_element(&q) <= (num_of_element(&q2))) {
//				enqueue(&q, customer);
//			}
//			else {
//				enqueue(&q2, customer);
//			}
//			printf("고객 %d번분이 %d분에 들어오십니다. 업무처리시간 %d분\n", customer.id, customer.arrival_time, customer.service_time);
//		}
//		if (service_time > 0) { // 업무 처리 중일 때
//			printf("고객 %d번분의 업무를 처리중입니다.\n", service_customer);
//			service_time--;
//		}
//		else {
//			if (!is_empty(&q)) {
//				element customer = dequeue(&q);
//				service_customer = customer.id;
//				service_time = customer.service_time;
//				printf("고객 %d번분이 %d분에 업무를 시작합니다. 대기시간은 %d분이었습니다.\n", customer.id, clock, clock - customer.arrival_time);
//				total_wait += clock - customer.arrival_time;
//				complete_customers++;
//			}
//		}
//		if (service_time2 > 0) {
//			printf("고객 %d번분의 업무를 처리중입니다.\n", service_customer2);
//			service_time2--;
//		}
//		else { // 고객 큐에서 빼기(업무 처리 시작 시키기)
//			if (!is_empty(&q2)) {
//				element customer = dequeue(&q2);
//				service_customer2 = customer.id;
//				service_time2 = customer.service_time;
//				printf("고객 %d번분이 %d분에 업무를 시작합니다. 대기시간은 %d분이었습니다.\n", customer.id, clock, clock - customer.arrival_time);
//				total_wait += clock - customer.arrival_time;
//				complete_customers++;
//			}
//		}
//	}
//	printf("전체 대기 시간 = %d\n", total_wait);
//	printf("평균 대기 시간 = %d\n", total_wait / complete_customers);
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#define MAX_QUEUE_SIZE 5
//
//typedef struct elementTag {
//	int id;
//	int arrival_time;
//	int service_time;
//}element;
//
//typedef struct QueueTypeTag {
//	int front;
//	int rear;
//	element data[MAX_QUEUE_SIZE];
//}QueueType;
//void error(const char* message) {
//	fprintf(stderr, "%s\n", message);
//	exit(1);
//}
//void init_queue(QueueType* q) {
//	q->front = 0;
//	q->rear = 0;
//}
//int is_empty(QueueType* q) {
//	return (q->front == q->rear);
//}
//int is_full(QueueType* q) {
//	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
//}
//void enqueue(QueueType* q, element item) {
//	if (is_full(q)) {
//		error("큐가 포화상태입니다.");
//		return;
//	}
//	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
//	q->data[q->rear] = item;
//}
//element dequeue(QueueType* q) {
//	if (is_empty(q)) {
//		error("큐가 공백상태입니다.");
//	}
//	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
//	element item = q->data[q->front];
//	return item;
//}
//element peek(QueueType* q) {
//	if (is_empty(q)) {
//		error("큐가 공백상태입니다.");
//	}
//	element item = q->data[(q->front + 1) % MAX_QUEUE_SIZE];
//	return item;
//}
////void print_queue(QueueType* q) {
////	printf("front=%d rear=%d = ", q->front, q->rear);
////	if (!is_empty(q)) {
////		int i = q->front;
////		do {
////			i = (i + 1) % MAX_QUEUE_SIZE;
////			printf("%d | ", q->data[i]);
////			if (i == q->rear)
////				break;
////		} while (i != q->front);
////	}
////	printf("\n");
////}
//
//int main() {
//	int minutes = 60;
//	int complete_customers = 0;
//	int total_wait = 0;
//	int total_customers = 0;
//	int service_time = 0;
//	int service_customer;
//	QueueType q;
//	init_queue(&q);
//
//	srand(time(NULL));
//
//	for (int clock = 0; clock < minutes; clock++) {
//		printf("현재시각 %d\n", clock);
//		if ((rand() % 10) < 3) { // 고객 큐에 넣기
//			element customer;
//			customer.id = total_customers++;
//			customer.arrival_time = clock;
//			customer.service_time = (rand() % 3) + 1;
//			enqueue(&q, customer);
//			printf("고객 %d번분이 %d분에 들어오십니다. 업무처리시간 %d분\n", customer.id, customer.arrival_time, customer.service_time);
//		}
//		if (service_time > 0) { // 업무 처리 중일 때
//			printf("고객 %d번분의 업무를 처리중입니다.\n", service_customer);
//			service_time--;
//		}
//		else { // 고객 큐에서 빼기(업무 처리 시작 시키기)
//			if (!is_empty(&q)) {
//				element customer = dequeue(&q);
//				service_customer = customer.id;
//				service_time = customer.service_time;
//				printf("고객 %d번분이 %d분에 업무를 시작합니다. 대기시간은 %d분이었습니다.\n",customer.id, clock, clock- customer.arrival_time);
//				total_wait += clock - customer.arrival_time;
//				complete_customers++;
//			}
//		}
//	}
//	printf("전체 대기 시간 = %d\n", total_wait);
//	printf("평균 대기 시간 = %d\n", total_wait / service_customer);
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#define MAX_DEQUE_SIZE 5
//
//typedef int element;
//typedef struct DequeTypeTag {
//	int front;
//	int rear;
//	element data[MAX_DEQUE_SIZE];
//}DequeType;
//
//void error(const char* message) {
//	fprintf(stderr, "%s\n", message);
//	exit(1);
//}
//void init_deque(DequeType* q) {
//	q->front = 0;
//	q->rear = 0;
//}
//int is_empty(DequeType* q) {
//	return (q->front == q->rear);
//}
//int is_full(DequeType* q) {
//	return ((q->rear + 1) % MAX_DEQUE_SIZE == q->front);
//}
//void add_front(DequeType* q, element item) {
//	if (is_full(q)) {
//		error("덱이 포화상태입니다.");
//		return;
//	}
//	q->data[q->front] = item;
//	q->front = (q->front - 1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE; 
//	// 음수가 되면 %연산이 안되기 때문에 MAX_DEQUE_SIZE를 더해준다.
//}
//void add_rear(DequeType* q, element item) {
//	if (is_full(q)) {
//		error("덱이 포화상태입니다.");
//		return;
//	}
//	q->rear = (q->rear + 1) % MAX_DEQUE_SIZE;
//	q->data[q->rear] = item;
//}
//element delete_front(DequeType* q) {
//	if (is_empty(q)) {
//		error("덱이 공백상태입니다.");
//		return -1;
//	}
//	q->front = (q->front + 1) % MAX_DEQUE_SIZE;
//	element item = q->data[q->front];
//	return item;
//}
//element delete_rear(DequeType* q) {
//	if (is_empty(q)) {
//		error("덱이 공백상태입니다.");
//		return -1;
//	}
//	element item = q->data[q->rear];
//	q->rear = (q->rear - 1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
//	// 음수가 되면 %연산이 안되기 때문에 MAX_DEQUE_SIZE를 더해준다.
//	return item;
//}
//element get_front(DequeType* q) {
//	if (is_empty(q)) {
//		error("덱이 공백상태입니다.");
//		return -1;
//	}
//	element item = q->data[(q->front + 1) % MAX_DEQUE_SIZE];
//	return item;
//}
//element get_rear(DequeType* q) {
//	if (is_empty(q)) {
//		error("덱이 공백상태입니다.");
//		return -1;
//	}
//	element item = q->data[q->rear];
//	return item;
//}
//void print_deque(DequeType* q) {
//	printf("front=%d rear=%d = ", q->front, q->rear);
//	if (!is_empty(q)) {
//		int i = q->front;
//		do {
//			i = (i + 1) % MAX_DEQUE_SIZE;
//			printf("%d | ", q->data[i]);
//			if (i == q->rear)
//				break;
//		} while (i != q->front);
//	}
//	printf("\n");
//}
//
//int main() {
//	DequeType q;
//	init_deque(&q);
//
//	for (int i = 0; i < 3; i++) {
//		add_front(&q, i);
//		print_deque(&q);
//	}
//	for (int i = 0; i < 3; i++) {
//		delete_rear(&q);
//		print_deque(&q);
//	}
//	
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#define MAX_QUEUE_SIZE 5
//
//typedef int element;
//
//typedef struct QueueTypeTag {
//	int front;
//	int rear;
//	element data[MAX_QUEUE_SIZE];
//}QueueType;
//void error(const char* message) {
//	fprintf(stderr, "%s\n", message);
//	exit(1);
//}
//void init_queue(QueueType* q) {
//	q->front = 0;
//	q->rear = 0;
//}
//int is_empty(QueueType* q) {
//	return (q->front == q->rear);
//}
//int is_full(QueueType* q) {
//	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
//}
//void enqueue(QueueType* q, element item) {
//	if (is_full(q)) {
//		error("큐가 포화상태입니다.");
//		return;
//	}
//	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
//	q->data[q->rear] = item;
//}
//element dequeue(QueueType* q) {
//	if (is_empty(q)) {
//		error("큐가 공백상태입니다.");
//		return -1;
//	}
//	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
//	element item = q->data[q->front];
//	return item;
//}
//element peek(QueueType* q) {
//	if (is_empty(q)) {
//		error("큐가 공백상태입니다.");
//		return -1;
//	}
//	element item = q->data[(q->front + 1) % MAX_QUEUE_SIZE];
//	return item;
//}
//void print_queue(QueueType* q) {
//	printf("front=%d rear=%d = ", q->front, q->rear);
//	if (!is_empty(q)) {
//		int i = q->front;
//		do {
//			i = (i + 1) % MAX_QUEUE_SIZE;
//			printf("%d | ", q->data[i]);
//			if (i == q->rear)
//				break;
//		} while (i != q->front);
//	}
//	printf("\n");
//}
//
//// 내가 만든 print_queue() 
//// (front값을 저장해놓은 뒤 rear값이 될때까지 올리면 되는데
//// 출력해야할 원소의 개수를 구하는 것에 매몰되어 버렸다.)
////void print_queue(QueueType* q) {
////	printf("front = %d rear = %d = ", q->front, q->rear);
////	if (!is_empty(q)) {
////		int num;
////		int idx = q->front;
////		if (q->front > q->rear) num = MAX_QUEUE_SIZE - (q->front - q->rear);
////		else num = q->rear - q->front;
////		for (int i = 0; i < num; i++) {
////			idx = (idx + 1) % MAX_QUEUE_SIZE;
////			printf("%d |", q->data[idx]);
////		}
////	}
////	printf("\n");
////}
//
//int main() {
//	int item;
//	QueueType q;
//
//	init_queue(&q);
//
//	enqueue(&q, 10);
//	print_queue(&q);
//	enqueue(&q, 20);
//	print_queue(&q);
//	enqueue(&q, 30);
//	print_queue(&q);
//	enqueue(&q, 40);
//	print_queue(&q);
//	item = dequeue(&q);
//	print_queue(&q);
//	item = dequeue(&q);
//	print_queue(&q);
//	item = dequeue(&q);
//	print_queue(&q);
//	enqueue(&q, 50);
//	print_queue(&q);
//	enqueue(&q, 60);
//	print_queue(&q);
//	enqueue(&q, 70);
//	print_queue(&q);
//	item = dequeue(&q);
//	print_queue(&q);
//	item = dequeue(&q);
//	print_queue(&q);
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#define MAX_QUEUE_SIZE 5
//
//typedef int element;
//typedef struct QueueTypeTag {
//	int front;
//	int rear;
//	element data[MAX_QUEUE_SIZE];
//}QueueType;
//void error(const char *message) {
//	fprintf(stderr, "%s\n", message);
//	exit(1);
//}
//void init_queue(QueueType *q) {
//	q->front = -1;
//	q->rear = -1;
//}
//int is_empty(QueueType *q) {
//	if (q->front == q->rear) {
//		return 1;
//	}
//	return 0;
//}
//int is_full(QueueType* q) {
//	if (q->rear == MAX_QUEUE_SIZE - 1) {
//		return 1;
//	}
//	return 0;
//}
//void enqueue(QueueType* q, element item) {
//	if (is_full(q)) {
//		error("큐가 포화상태입니다.");
//		return;
//	}
//	q->data[++(q->rear)] = item;
//}
//element dequeue(QueueType* q) {
//	if (is_empty(q)) {
//		error("큐가 공백상태입니다.");
//		return -1;
//	}
//	element item = q->data[++(q->front)];
//	return item;
//}
//element peek(QueueType* q) {
//	if (is_empty(q)) {
//		error("큐가 공백상태입니다.");
//		return -1;
//	}
//	element item = q->data[q->front + 1];
//	return item;
//}
//void print_queue(QueueType* q) {
//	for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
//		if (i <= q->front || i > q->rear) {
//			printf("   | ");
//		}
//		else
//			printf("%d | ", q->data[i]);
//	}
//	printf("\n");
//}
//int main() {
//	int item;
//	QueueType q;
//
//	init_queue(&q);
//
//	enqueue(&q, 10);
//	print_queue(&q);
//	enqueue(&q, 20);
//	print_queue(&q);
//	enqueue(&q, 30);
//	print_queue(&q);
//	item = dequeue(&q);
//	print_queue(&q);
//	item = dequeue(&q);
//	print_queue(&q);
//	item = dequeue(&q);
//	print_queue(&q);
//	return 0;
//}