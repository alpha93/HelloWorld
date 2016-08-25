#include <stdio.h>
#define SIZE 10

typedef struct {
	int x[SIZE];
	int front;
	int rear;
} queue;

int is_empty(queue *q) {
	if(q->front == -1)		//implies that q->rear = -1 also.
		return 1;
	else
		return 0;
}

int is_full(queue *q) {
	if((q->rear-q->front+1)%SIZE == 0)
		return 1;
	else
		return 0;
}

void enqueue(queue *q, int n) {
	if(is_empty(q)) {
		q->front++;
		q->rear++;
	} else if(!is_full(q)) {
		q->rear = (q->rear+1)%SIZE;
	} else {
		printf("cant enqueue...queue is full...\n");
		return;
	}

	q->x[q->rear] = n;
	printf("%i enqueued...\n", n);
}

int dequeue(queue *q) {
	if(is_empty(q)) {
		printf("cant dequeue...queue is empty...\n");
		return -1;
	} else {
		int x = q->x[q->front];
		q->x[q->front] = 0;

		if(q->front == q->rear)
			q->rear = q->front = -1;
		else
			q->front = (q->front+1)%SIZE;

		printf("%i dequeued...\n", x);
		return x;
	}
}


int main() {
	queue q = {{0}, -1, -1};
	if(is_empty(&q))
		printf("queue is empty\n");

	enqueue(&q, 3);
	enqueue(&q, 4);
	enqueue(&q, 8);
	enqueue(&q, 1);
	enqueue(&q, 2);

	puts("");
	for(int i=0; i<SIZE; i++)
		printf("%i ", q.x[i]);
	puts("");

	dequeue(&q);
	dequeue(&q);
	dequeue(&q);

	puts("");
	for(int i=0; i<SIZE; i++)
		printf("%i ", q.x[i]);
	puts("");	

	printf("front: %i rear: %i\n", q.front, q.rear);

	enqueue(&q, 13);
	enqueue(&q, 14);
	enqueue(&q, 18);
	enqueue(&q, 11);
	enqueue(&q, 12);	
	enqueue(&q, 19);
	enqueue(&q, 34);
	enqueue(&q, 12);
	enqueue(&q, 23);
	enqueue(&q, 52);

	puts("");
	for(int i=0; i<SIZE; i++)
		printf("%i ", q.x[i]);
	puts("");	

	printf("front: %i rear: %i\n", q.front, q.rear);

	dequeue(&q);
	dequeue(&q);
	dequeue(&q);
	dequeue(&q);
	dequeue(&q);
	dequeue(&q);
	dequeue(&q);
	dequeue(&q);

	puts("");
	for(int i=0; i<SIZE; i++)
		printf("%i ", q.x[i]);
	puts("");	

	printf("front: %i rear: %i\n", q.front, q.rear);	
}
