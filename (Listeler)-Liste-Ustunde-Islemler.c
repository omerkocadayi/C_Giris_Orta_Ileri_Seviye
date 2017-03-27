/*
 Ilk olarak liste olusturuyoruz.
 cut_las_add_head		fonksiyonunda listenin son dugumunu en basa getiriyoruz.
 delete_node	 fonksiyonunda eger YAS degeri birbirine esit olan kisiler varsa, ilk kisiyi tutup sonra gelenleri siliyoruz.
*/

#include <stdio.h>
#include <stdlib.h>

struct student{
	int no;
	char name[40];
	int age;
	struct student *next;
};

typedef struct student node;

node* createList(){
	int n,k;
	node *head,*p;
	printf("Listede kac ogrenci olacak ? : "); scanf("%d",&n);
	
	for(k=0;k<n;k++){
		if(k==0){
			head = (node *) malloc(sizeof(node));
			p = head;
		}
		else{
			p->next = (node *) malloc(sizeof(node));
			p = p->next;
		}
	
		printf("\n\n%d. ogrencinin numarasi : ",k+1); scanf("%d",&p->no);
		printf("%d. ogrencinin ismi : ",k+1); scanf("%s",p->name);
		printf("%d. ogrencinin yasi : ",k+1); scanf("%d",&p->age);
	}
	
	p->next = NULL;	
	return head;
}


node * delete_node(node *root,int yas){
	int counter = 1;
	node *iter,*iter2;
	iter = root;
	
	while(iter != NULL){
		if(iter->age == yas){              
			if(counter > 1){						// ayni yasa sahip 2. kisiyi bulmak icin sayac kullandik.
				iter2->next = iter->next;		// sayac 2 olup if bloguna girdiginde islemi tamamlamis olacagiz.
				free(iter);
			}
			counter++;
		}
		iter2 = iter;
		iter = iter->next;
	}

	return root;
}


void liste_dolas(node *root){
	node *iter;
	iter = root;
	
	while(iter != NULL){
		printf("Isim : %s\nNo : %d \t\t Yas : %d\n\n",iter->name,iter->no,iter->age);
		iter = iter->next;	
	}
}


node * cut_last_add_head(node *root){
	node *iter,*iter2;
	iter = root;
	
	while(iter->next != NULL){
		iter2 = iter;
		iter = iter->next;
	}
	
	iter->next = root;      // sondaki elemanin next'ini bastaki eleman yaptik.
	iter2->next = NULL;		// sondan bi onceki elemanin next'i NULL'u gostersin dedik.
	root = iter;				// listenin basini, sondan basa getirdigimiz eleman yaptik.
	
	return root;	
}


int main(void){
	node *head;
	int secim,sayi;	
	
	while(1){	
		printf("\n1.Liste Olustur\n2.Sondakini Kesip Basa At\n3.Dugum sil\n4.Cikis\n");
		printf("Secim [1-4]?"); scanf("%d",&secim);
	
		switch(selection){
			case 1:
				head = createList();
				break;
		
			case 2:
				head = cut_last_add_head(head);
				liste_dolas(root);
				break;
		
			case 3: 
				printf("yas gir : "); scanf("%d",&sayi);
				head = delete_node(head,sayi);
				liste_dolas(root);
				break;				
		
			case 4:
				exit(0);
				break;
				return 0;
		}
	}
}
