/*
 Ek bir fonksiyon kullanmadan listeye ekledigimiz her eleman,
 BOY siralamasina gore yerini bulup oraya yerlesecek.
*/

#include <stdio.h>
#include <stdlib.h>

struct ornek{
	int boy;
	char isim[20];
	struct ornek * next;
};

typedef struct ornek node;

node * ekle (node *,int);
void goster(node *);

int main(){
	int sayi,i,x;
	node * root;
	root = NULL;
	
	printf("kac eleman ekleyeceksin : "); 
	scanf("%d",&sayi);
	
	for(i=0; i<sayi; i++){
		printf("\n\nboy gir : "); scanf("%d",&x);
		root = ekle(root,x);
	}
	system("cls");
	
	goster(root);
	
	return 0;
}

node * ekle(node *head,int x){
	node *temp,*iter,*iter2;
	iter = head;
	
	if(head == NULL){              // ilk elemani ekleme
		head = (node *) malloc(sizeof(node));
		head->next = NULL;
		printf("isim giriniz : "); scanf("%s",head->isim);
		head->boy = x;
		return head;
	}
	
	else{
		temp = (node *) malloc(sizeof(node));
		printf("isim giriniz : "); scanf("%s",head->isim);
		temp->boy = x;
		
		if(head->boy > temp->boy){     	// Girilen boy en kucukse, ekleme basa yapilir
			temp->next = iter;
			head = temp;
			return head;
		}
		
		else{
			
			while(iter->next != NULL && iter->boy < temp->boy){
				iter2 = iter;
				iter = iter->next;
			}
			
			if(iter->boy > temp->boy){      // Girilen boy ortada bi degere sahipse, uygun yer bulunup araya ekleme yapilir
				iter2->next = temp;
				temp->next = iter;
				return head;
			}
			else{
				iter->next = temp;			  // Girilen boy listedeki elemanlarin boyundan buyukse, ekleme sona yapilir
				temp->next = NULL;
				return head;
			}	
		}
	}
}

void goster(node *head){
	node *iter;
	iter = head;
	
	while(iter != NULL){
		printf("isim : %s \nboy : %d\n\n",iter->isim,iter->boy);
		iter = iter->next;
	}
}
