#include <stdio.h>
#include <stdlib.h>

struct ogrenci{
	int no;
	int age;
	int final;
	char name[30];
	char school[30];	
	struct ogrenci *next;
};

typedef struct ogrenci node;
node *head;

node* create_list();
void print_list(node *);
void print_reverse(node *);
node* add_head_for_reverse(node *);
node* add_node(node *);
node* delete_node(node *);

int main(){
	int secim;
	head = NULL;
	
	while(1){
		system("cls");
		
		printf("1 ==> Liste Olustur \n2 ==> Listeyi Goster\n");
		printf("3 ==> Listeyi Tersten Goster \n4 ==> Listeye Eleman Ekle \n5 ==> Eleman Sil\n6 ==> Cikis\n");
		printf("\nSecimini Yap : "); scanf("%d",&secim);
	
		switch(secim){
			case 1:
				head = create_list();
				break;
		
			case 2:
				print_list(head);
				break;
		
			case 3:
				print_reverse(head);
				break;
			
			case 4:
				head = add_node(head);
				break;			
			
			case 5:
				head = delete_node(head);
				break;
				
			case 6:
				printf("\n*** CIKIS YAPILDI ***");
				free(head);
				return 0;
				
			default:
				printf("\n*** HATALI GIRIS YAPILDI *** (Tekrar Dene)\n");
				break;
		}	
	}
}


node* create_list(){
	int k,n;
	node *root,*iter;
	printf("\nListede kac ogrenci olacak ? : "); scanf("%d",&n);
	
	for(k=0;k<n;k++){
		if(k==0){
			root = (node *) malloc(sizeof(node));
			iter = root;
		}
		else{
			iter->next = (node *) malloc(sizeof(node));
			iter = iter->next;
		}
	
		printf("\n\n%d. ogrencinin ismi : ",k+1); scanf("%s",iter->name);
		printf("%d. ogrencinin okulu : ",k+1); scanf("%s",iter->school);
		printf("%d. ogrencinin numarasi : ",k+1); scanf("%d",&iter->no);
		printf("%d. ogrencinin notu : ",k+1); scanf("%d",&iter->final);
		printf("%d. ogrencinin yasi : ",k+1); scanf("%d",&iter->age);
		
	}
	
	iter->next = NULL;
	return root;
}

void print_list(node *root){
	int i=0;
	node *iter;
	iter = root;
	system("cls");
	
	while(iter != NULL){
		printf("%d. Kisi\nIsim : %s \t\t Okul : %s\n",i+1,iter->name,iter->school);
		printf("No : %d \t\t\t Not : %d \t\t Yas : %d\n\n\n",iter->no,iter->final,iter->age);
		printf("---------------------------------------------------\n");
		iter = iter->next;
		i++;
	}
	
	printf("\n*** Bir tusa basan kadar ekranda kalacaktir ***");
	getch();
}


void print_reverse(node *root){
	node *new_root,*iter;    // new_root ==> olusturacagimiz yeni listenin basini tutacak.
	new_root = NULL;
	iter = root;
	
	while(iter != NULL){
		new_root = add_head_for_reverse(new_root);
		iter = iter->next; 
	}																 

/* listeyi tersten yazdirmak icin yeni bir liste olusturup,
 ana listenin elemanlarini sirayla yeni listenin surekli basina ekleyecegiz.
 islemin sonunda ana listenin ters dizilimine sahip yeni listemiz elimizde olacak.
 ve onu yazdiracagiz. */

	
	print_list(new_root);
}

node *add_head_for_reverse(node * new_root){
	int i=0;
	node *temp,*iter,*iter2;
	iter = head;
	
	while(iter != NULL){
		if(i==0){
			new_root = (node *) malloc(sizeof(node));   // ilk olarak yeni listemize yer aldik.
			*new_root = *head;			    // ana listemizin ilk elemaninin datasini yeni listenin ilk eleman datasina kopyaladik.
			new_root->next = NULL;
			i++;
		}
		
		else{
			temp = (node *) malloc(sizeof(node)); 		  // ana listemizin sonraki elemanlarini tek tek tutmasi icin temp'e yer alýyoruz.
			*temp = *iter;					  // ana listemizin sonraki elemanlarinin datasini tempe kopyaliyoruz.
			temp->next = new_root;				  // temp'in nexti listenin basini gostersin diyoruz.
			new_root = temp;				  // ve son olarak listenin basini tutan new_root degiskenine. artik temp'i goster diyoruz.
		}	

		iter = iter->next;
	}
	
	free(temp);
	return new_root;
}


node* add_node(node *root){
	node *iter, *iter2, *new_node;
	int no;
	
	printf("Hangi kayittan once ekleme yapmak istiyorsun ?");
	printf("\nOgrenci no gir : "); scanf("%d",&no);
	
	new_node = (node *) malloc(sizeof(node));

	printf("\n\nIsim gir : "); scanf("%s",new_node->name);
	printf("Okul gir : "); scanf("%s",new_node->school);
	printf("No gir : "); scanf("%d",&new_node->no);
	printf("Not gir : "); scanf("%d",&new_node->final);
	printf("Yas gir : "); scanf("%d",&new_node->age);

	iter = root;
	
	if(iter->no == no){   // Basa ekleme
		new_node->next = iter;
		root = new_node;
	}
	
	else{
		while(iter->no != no && iter->next != NULL){   // Dugumler arasi dolasma
			iter2 = iter;
			iter = iter->next;
		}
		
		if(iter->no == no){   // Araya ekleme
			iter2->next = new_node;
			new_node->next = iter;
		}
		
		else if(iter->next == NULL){   // Aranan no bulunamadi. Sona ekleme
			printf("Listenin sonuna ekleme yapiliyor..\n\n");
			iter->next = new_node;
			new_node->next = NULL;
		}
	}
	
	return root;
}



node* delete_node(node *root){
	node *iter, *iter2;
	int no;
	
	printf("\nHangi kaydi silmek istiyorsun ?");
	printf("\n\nOgrenci no gir : "); scanf("%d",&no);
	
	iter = root;
	
	if(iter->no == no){   // Bastakini silme
		root = iter->next;
		free(iter);
	}
	
	else{
		while(iter->no != no && iter->next != NULL){   // Dugumler arasi dolasma
			iter2 = iter;
			iter = iter->next;
		}
		
		if(iter->no == no){   // Aradan ve sondan silme
			iter2->next = iter->next;
			free(iter);
		}
		
		else if(iter->next == NULL){
			printf("\n*** ARADIGINIZ OGRENCÝ NO BULUNAMADI ***\n");
		}
	}
	
	return root;
}
