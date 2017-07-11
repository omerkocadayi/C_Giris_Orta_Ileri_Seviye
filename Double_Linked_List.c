#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node{
	int data;
	struct node *next;
	struct node *prev;
};

struct node *add_head(struct node *,int);
struct node *add_last(struct node *,int);
struct node *delete_node(struct node *,int);
void print_list(struct node *);
int count_elements(struct node *);


int main(){
	struct node *head;
	head = NULL;
	int secim, key, counter;
	
	while(1){		
		printf("Press Any Key for Continue.. ");
		getch();
		system("CLS");
		
		printf("1 ==> Add Head \n2 ==> Add Last\n");
		printf("3 ==> Print List \n4 ==> Count Elements\n");
		printf("5 ==> Delete Node \n6 ==> Exit\n");
		printf("\nMake Your Choice : "); scanf("%d",&secim);
		
		system("CLS");
		
		switch(secim){
			case 1:
				printf("Please enter node's data : "); scanf("%d",&key);
				head = add_head(head,key);
				break;
				
			case 2:
				printf("Please enter node's data : "); scanf("%d",&key);
				head = add_last(head,key);
				break;
			
			case 3:
				if(head == NULL){
					printf("List is empty..\n");
				}	
				else{
					print_list(head);
				}
				break;
			
			case 4:
				counter = count_elements(head);
				printf("There are %d elements in your list\n",counter);
				break;
			
			case 5:
				printf("Please enter node's data : "); scanf("%d",&key);
				head = delete_node(head,key);
				break;
			
			case 6:
				printf("Exited !!");
				return 0;
			
			default:
				printf("Wrong choice !! Try Again !!");
				break;
		
		}	
	}
}

struct node *add_head(struct node *head,int key){
	if (head == NULL){
		head = (struct node *) malloc(sizeof(struct node));
		head->data = key;
		head->next = NULL;
		head->prev = NULL;
	}
	else{
		struct node *temp;
		temp = (struct node *)malloc(sizeof(struct node));
		temp->data = key;
		temp->next = head;
		temp->prev = NULL;
		head->prev = temp;
		head = temp;
	}
	return head;
}

struct node *add_last(struct node *head,int key){
	if (head == NULL){
		head = (struct node *) malloc(sizeof(struct node));
		head->data = key;
		head->next = NULL;
		head->prev = NULL;
	}
	else{
		struct node *temp,*tail;
		temp = (struct node *)malloc(sizeof(struct node));
		tail = head;
		
		while(tail->next != NULL)
			tail = tail->next;
		
		temp->data = key;
		temp->next = NULL;
		tail->next = temp;
		temp->prev = tail;
		
	}
	return head;
}

void print_list(struct node *head){
	if(head == NULL)
		return;
	printf("%d\n",head->data);
	print_list(head->next);
}

int count_elements(struct node *head){
	if(head == NULL)
		return 0;
	
	return 1+count_elements(head->next);
}

struct node *delete_node(struct node *head,int key){

	if(head->data == key){
		head = head->next;
		free(head->prev);
		head->prev = NULL;
	}
	else{
		struct node *temp = head;
		
		while(temp->data != key)
			temp = temp->next;
		
		if(temp->next->data == key){
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			free(temp);		
		}
	}	
	return head;
}
