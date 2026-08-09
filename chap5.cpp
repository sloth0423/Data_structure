#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;

typedef struct QueueTypeTag {
	int front;
	int rear;
	element data[MAX_QUEUE_SIZE];
}QueueType;
void error(const char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}
void init_queue(QueueType* q) {
	q->front = 0;
	q->rear = 0;
}
int is_empty(QueueType* q) {
	return (q->front == q->rear);
}
int is_full(QueueType* q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}
void enqueue(QueueType* q, element item) {
	if (is_full(q)) {
		error("큐가 포화상태입니다.");
		return;
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}
element dequeue(QueueType* q) {
	if (is_empty(q)) {
		error("큐가 공백상태입니다.");
		return -1;
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	element item = q->data[q->front];
	return item;
}
element peek(QueueType* q) {
	if (is_empty(q)) {
		error("큐가 공백상태입니다.");
		return -1;
	}
	element item = q->data[(q->front + 1) % MAX_QUEUE_SIZE];
	return item;
}
void print_queue(QueueType* q) {
	printf("front=%d rear=%d = ", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % MAX_QUEUE_SIZE;
			printf("%d | ", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	printf("\n");
}

// 내가 만든 print_queue() 
// (front값을 저장해놓은 뒤 rear값이 될때까지 올리면 되는데
// 출력해야할 원소의 개수를 구하는 것에 매몰되어 버렸다.)
//void print_queue(QueueType* q) {
//	printf("front = %d rear = %d = ", q->front, q->rear);
//	if (!is_empty(q)) {
//		int num;
//		int idx = q->front;
//		if (q->front > q->rear) num = MAX_QUEUE_SIZE - (q->front - q->rear);
//		else num = q->rear - q->front;
//		for (int i = 0; i < num; i++) {
//			idx = (idx + 1) % MAX_QUEUE_SIZE;
//			printf("%d |", q->data[idx]);
//		}
//	}
//	printf("\n");
//}

int main() {
	int item;
	QueueType q;

	init_queue(&q);

	enqueue(&q, 10);
	print_queue(&q);
	enqueue(&q, 20);
	print_queue(&q);
	enqueue(&q, 30);
	print_queue(&q);
	enqueue(&q, 40);
	print_queue(&q);
	item = dequeue(&q);
	print_queue(&q);
	item = dequeue(&q);
	print_queue(&q);
	item = dequeue(&q);
	print_queue(&q);
	enqueue(&q, 50);
	print_queue(&q);
	enqueue(&q, 60);
	print_queue(&q);
	enqueue(&q, 70);
	print_queue(&q);
	item = dequeue(&q);
	print_queue(&q);
	item = dequeue(&q);
	print_queue(&q);
	return 0;
}

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