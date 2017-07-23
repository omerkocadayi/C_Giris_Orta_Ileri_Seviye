#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 5

struct node{
	int data;
	struct node *next;
};

typedef struct node node;

typedef struct{
	int counter;
	node *top;
}stack;



void reset(stack *stk){
	stk->counter = 0;
	stk->top = NULL;
}

void push(stack *stk, int c){
	stk = (node *)malloc(sizeof(node));
	if(stk->counter == STACK_SIZE){
		printf("Stack is full\n");
		return;
	}
	node *temp;
	temp = (node *)malloc(sizeof(node));
	temp->data = c;
	temp->next = stk->top;
	stk->top = temp;
	stk->counter++;
}


int pop(stack *stk){
	if(stk->counter == 0){
		printf("Stack is empty\n");
		return -1000;
	}
	node *temp = stk->top;
	int x = temp->data;
	stk->top = stk->top->next;
	free(temp);
	stk->counter--;
	return x;
}

int main(){
	int secim,deleted,c;
	stack stk;
	reset(&stk);
	
	while(1){
		printf("Push ==> 1\nPop ==> 2\nReset ==> 3\n");
		printf("\n\nMake Your Choice : "); scanf("%d",&secim);
		
		switch(secim){
			case 1:
				printf("\nEnter a data : "); scanf("%d",&c);
				push(&stk,c);
				break;
			
			case 2:
				deleted = pop(&stk);
				printf("This data has been deleted : %d",deleted);
				break;
				
			case 3:
				reset(&stk);
				break;
			
			default:
				printf("Uncorrect entry !!");
				break;
		}
	}	
	return 0;
}
