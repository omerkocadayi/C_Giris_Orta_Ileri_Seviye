#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 25


typedef struct{
	int top;
	char data[SIZE];
}stack;

typedef struct{
	int front, rear, cnt;
	int data[SIZE];
}queue;

void stk_initialize(stack *stk){
	stk->top = -1;
}

void push(stack *stk, char c){
	if(stk->top == SIZE-1){
		printf("Stack Is Full\n");
		return;
	}
	
	stk->top++;
	stk->data[stk->top] = c;	
}

char pop(stack *stk){
	if(stk->top == -1)
		printf("Stack is empty\n");
	
	char c = stk->data[stk->top];
	stk->top--;
	return c;
}

void q_initialize(queue *q){
	q->front = 0;
	q->rear = -1;
	q->cnt = 0;
}

void enqueue(queue *q, char c){
	if(q->cnt != SIZE){
		q->rear++;
		q->cnt++;
		
		if(q->rear == SIZE)
			q->rear = 0;
		
		q->data[q->rear] = c;
	}
	else
		printf("Queue is full\n");
}

char dequeue(queue *q){
	if(q->cnt != 0){
		int x = q->data[q->front];
		q->front++;
		q->cnt--;
		
		if(q->front == SIZE)
			q->front = 0;
		
		return x;
	}else{
		printf("Queue is empty\n");
		return 0;
	}
}

void find_single(queue q, stack stk, char string[], int l){
	int i;
	
	for(i=0; i<l; i++){
		enqueue(&q,string[i]);		
	}

	for(i=(l-1); i<(l*2)-1; i++){
		push(&stk,string[i]);		
	}
	
	for(i=0; i<l; i++){
		if(dequeue(&q) != pop(&stk)){
			printf("\n----- This string is not palindrome\n");
			exit(1);			
		}
	}
}

void find_double(queue q,stack stk, char string[], int l){
	int i;
	
	for(i=0; i<l; i++){
		enqueue(&q,string[i]);		
	}
		
	for(i=l; i<(l*2); i++){
		push(&stk,string[i]);
	}
		
	for(i=0; i<l; i++){
		if(dequeue(&q) != pop(&stk)){
			printf("\n----- This string is not palindrome\n");
			exit(1);			
		}
	}	
}

int main(){
	int i, l;
	char string[50];
	stack stk;
	queue q;
	stk_initialize(&stk);
	q_initialize(&q);
	
	printf("Enter your string : "); gets(string);
	l = strlen(string);
	
	if(l%2 == 1){
		find_single(q, stk, string, (l/2)+1);		
	}
	else{
		find_double(q, stk, string, l/2);	
	}

	printf("\n+++++ This string is palindrome\n");
	return 0;
}
