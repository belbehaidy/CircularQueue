/*Implementation of Circular Queue header file functions*/

#define CIRCULAR_QUEUE_C

#ifndef CIRCULAR_QUEUE_H
#include "CircularQueue.h"
#endif

void QueueInit(sQueue_t *Queue)
{
	Queue->front=0;
	Queue->rear=-1;
	Queue->direction=straight;
}
int isFull(sQueue_t *Queue)
{
	int status=0;
	if(Queue->direction == straight)
	{
		if((Queue->rear == QUEUE_SIZE-1) && (Queue->front >0 ))
		{
			Queue->rear = -1;
			Queue->direction=circular;
		}
		else status=(Queue->rear==QUEUE_SIZE-1);
	}
	else status=(Queue->rear == (Queue->front)-1);

	return(status);
}
int isEmpty(sQueue_t *Queue)
{
	int status=0;
	
	if(Queue->direction == straight)
	{
		if(Queue->front > Queue->rear) status=1;
	}
	else if(Queue->front == QUEUE_SIZE && Queue->rear == -1) status=1; 
	else if(Queue->front == QUEUE_SIZE) Queue->front =0;
	else if(Queue->rear == (Queue->front)-1) status=1;
		
	if(status==1) QueueInit(Queue);	
		
	return status;
}
int enque(sQueue_t *Queue,int data)
{
	int status =1;
	if(!isFull(Queue))
	{
		Queue->data[++(Queue->rear)] = data;
	}
	else status = 0;
	return status;
}
int deque(sQueue_t *Queue,int *data)
{
	int status =1;
	if(!isEmpty(Queue))
	{
		*data = Queue->data[(Queue->front)++];
	}
	else status = 0;
	return status;
}
int peek(sQueue_t *Queue,int *data)
{
	int status =1;
	if(!isEmpty(Queue))
	{
		*data = Queue->data[Queue->front];
	}
	else status = 0;
	return status;
}