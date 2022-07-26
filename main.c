/*main file to test implementation of Circular Queue functions*/

#include<stdio.h>

#ifndef CIRCULAR_QUEUE_C
#include "CircularQueue.c"
#endif

#ifndef CIRCULAR_QUEUE_H
#include "CircularQueue.h"
#endif

#define PRINT_QUEUE printf("\nFront->");\
					for(int i=0;i<QUEUE_SIZE;i++) printf("%d->",Queue.data[i]);\
					printf("Rear\n")\

int main(void)
{
	int status,data;
	sQueue_t Queue;
	
	QueueInit(&Queue);
	
	enque(&Queue,10);
	enque(&Queue,20);
	enque(&Queue,30);
	enque(&Queue,40);
	enque(&Queue,50);
	
	PRINT_QUEUE;
	
	status=peek(&Queue,&data);
	if(status) printf("\nPeeked data = %d ",data);
	else printf("\nQueue is Empty.");
	
	status=peek(&Queue,&data);
	if(status) printf("\nPeeked data = %d ",data);
	else printf("\nQueue is Empty.");
	
	status=enque(&Queue,75);
	if(status) printf("\ndata enqued successfully");
	else printf("\nQueue is Full.");
	PRINT_QUEUE;
	
	status=deque(&Queue,&data);
	if(status) printf("\ndequed data = %d ",data);
	else printf("\nQueue is Empty.");
	
	status=deque(&Queue,&data);
	if(status) printf("\ndequed data = %d ",data);
	else printf("\nQueue is Empty.");
	
	PRINT_QUEUE;
	
	printf("Start of circular");
	enque(&Queue,100);
	
	PRINT_QUEUE;
	
	status=deque(&Queue,&data);
	if(status) printf("\ndequed data = %d ",data);
	else printf("\nQueue is Empty.");
	
	status=deque(&Queue,&data);
	if(status) printf("\ndequed data = %d ",data);
	else printf("\nQueue is Empty.");
	
	status=deque(&Queue,&data);
	if(status) printf("\ndequed data = %d ",data);
	else printf("\nQueue is Empty.");
	
	status=deque(&Queue,&data);
	if(status) printf("\ndequed data = %d ",data);
	else printf("\nQueue is Empty.");
	
	status=deque(&Queue,&data);
	if(status) printf("\ndequed data = %d ",data);
	else printf("\nQueue is Empty.");
	
	PRINT_QUEUE;
}