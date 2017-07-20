#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 20
 
typedef struct{
    char top;
    char data[STACK_SIZE];
}stack;
 
void initialization(stack *stk){
    stk->top = -1;
}
 
void push(stack *stk,char c){
    if(stk->top == STACK_SIZE -1){
        printf("Stack is full\n");
     	return;
    }
	stk->top++;
	stk->data[stk->top] = c;
	printf("Push -- %c\n\n",c);
}
 
char pop(stack *stk){
	if(stk->top == -1){
    	printf("Stack is empty\n");
	}
 
    char c = stk->data[stk->top];
	stk->top--;
	return c;
}

void print_error(){
	printf("\n\nHatali Parantez Kullanimi Yaptiniz !!!\n\n");
	exit(1);
}

int main(){
	char key;
	stack stk;
    initialization(&stk);
    FILE *fptr;
 
	if( (fptr = fopen("02 - kontrol.txt","r")) == NULL){
    	printf("Boyle bir dosya yok\n");
    	return 0;
	}
 
    else{
    	while ( !feof(fptr) ){
        	key = getc(fptr);
 
        	switch(key){
            	case '(':
                	push(&stk,key);
                	break;
 
                case ')':
                	if(pop(&stk) == '('){
                		printf("Pop -- %c\n\n",key);
                		continue;
					}
                    else
						print_error();
                	break;
 
            	case '{':
                	push(&stk,key);
                	break;
 
                case '}':
                	if(pop(&stk) == '{'){
                		printf("Pop -- %c\n\n",key);
                		continue;
					}	
                    else
                        print_error();
                	break;
 
            	case '[':
                	push(&stk,key);
                	break;
 
            	case ']':
                	if(pop(&stk) == '['){
                		printf("Pop -- %c\n\n",key);
                		continue;                		
					}
                    else
                        print_error();
                	break;
            }
        }
    }
 
    if(stk.top==-1)
		printf("\n\nHatali Parantez Kullanimi Yok !!");
 
	else
    	printf("\n\nHatali Parantez Kullanimi Yaptiniz !!!\n\n");
 
	fclose(fptr);
	return 0;
}
