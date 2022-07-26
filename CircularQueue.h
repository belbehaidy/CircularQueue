/*Circular Queue declerations header file*/

#define CIRCULAR_QUEUE_H

#define QUEUE_SIZE 5

typedef enum {straight,circular} Direction_t;

typedef struct
{
	Direction_t direction;
	int front, rear;
	int data[QUEUE_SIZE];
}sQueue_t;

void QueueInit(sQueue_t *Queue);
int isFull(sQueue_t *Queue);
int isEmpty(sQueue_t *Queue);
int enque(sQueue_t *Queue,int data);
int deque(sQueue_t *Queue,int *data);
int peek(sQueue_t *Queue,int *data);