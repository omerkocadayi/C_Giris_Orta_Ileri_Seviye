#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 10

struct node{
	int data;
	struct node *next;
};

typedef struct node node;

typedef struct{
	int cnt;
	node *front;
	node *rear;
}queue;

void initialization(queue *q){
	q->cnt = 0;
	q->front = q->rear = NULL;
}

void enqueue(queue *q, int c){
	if(q->cnt == QUEUE_SIZE)
		printf("Queue is full\n");
	
	else{
		node *temp = (node *)malloc(sizeof(node));
		temp->data = c;
		temp->next = NULL;
				
		if(q->cnt == 0)
			q->front = q->rear = temp;
			
		else{
			q->rear->next = temp;
			q->rear = temp;
		}
		q->cnt++;
	}
}

int dequeue(queue *q){
	if(q->cnt != 0){
		node *temp = q->front;
		int x;
		x = temp->data;
		q->front = temp->next;
		free(temp);
		q->cnt--;
		return x;
	}
	else{
		printf("Queue is empty\n");
		return -1000;
	}
}

int main(){
	int entry,secim;
	queue q;
	initialization(&q);
	
	while(1){
		printf("\n1 -- Enqueue\n");
		printf("2 -- Dequeue\n");
		printf("3 -- Exit\n");
		printf("Make your choice : "); scanf("%d",&secim);
		
		switch(secim){
			case 1:
				printf("\nPLS enter queue's data : "); scanf("%d",&entry);
				enqueue(&q,entry);
				break;
			
			case 2:
				printf("\nDequeue --> %d",dequeue(&q));
				break;
				
			case 3:
				printf("\nExit !!\n");
				return 0;
			
			default:
				printf("Uncorrect selection ! Try Again !");
				break;
		}
	}
	
	return 0;
}
