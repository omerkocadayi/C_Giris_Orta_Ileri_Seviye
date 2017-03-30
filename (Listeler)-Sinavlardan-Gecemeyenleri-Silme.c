#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct ogrenci{
	int no;
	int vize;
	int final;
	float ort;
	char isim[30];
	struct ogrenci *next;
};

typedef struct ogrenci node;
int hesaplandi=0;
int kayit_sayisi=0;

node *create_list();
node *add_node(node *);
node *delete_node(node *);
void calculate_avarage(head);
node *delete_unpass(node *);
void show_list(node *);


int main(){
	int secim;
	node *head;
	head = NULL;
				
	while(1){
		printf("\nDevam etmek icin bir tusa bas..");
		getch();
		
		if(kayit_sayisi > 0){
			system("cls");
			printf("\n*** ISLEM  TAMAMLANDI ***\n");
		}
		printf("\n1 ==> Liste Olustur\n2 ==> Ogrenci Ekle\n3 ==> Ogrenci Sil");
		printf("\n4 ==> Ortalamalari Hesapla\n5 ==> Gecemeyenleri Sil\n6 ==> Listeyi Gor\n7 ==> Cikis\n");
		printf("\nSecimini Yap : "); scanf("%d",&secim);
		
		switch(secim){
			case 1:
				head = create_list();
				break;
			
			case 2:
				head = add_node(head);
				show_list(head);
				break;
			
			case 3:
				head = delete_node(head);
				show_list(head);
				break;
				
			case 4:
				calculate_avarage(head);
				show_list(head);
				break;
			
			case 5:
				head = delete_unpass(head);
				show_list(head);
				break;
			
			case 6:
				show_list(head);
				break;
			
			case 7:
				printf("\n*** CIKIS YAPILDI ***");
				free(head);
				return 0;
			
			default:
				printf("\n*** HATALI GIRIS ***");
				break;
		}
	}
}

node *create_list(){
	int sayi,i;
	node *root,*iter;
	printf("Listede kac ogrenci olacak ? : "); scanf("%d",&sayi);
	
	for(i=0;i<sayi;i++){
		
		if(i==0){
			root = (node *) malloc(sizeof(node));
			iter = root;
		}
		
		else{
			iter->next = (node *) malloc(sizeof(node));
			iter = iter->next;
		}
	
		printf("\n\n%d. ogrencinin ismi : ",i+1); scanf("%s",iter->isim);
		printf("%d. ogrencinin numarasi : ",i+1); scanf("%d",&iter->no);
		printf("%d. ogrencinin vizesi : ",i+1); scanf("%d",&iter->vize);
		printf("%d. ogrencinin finali : ",i+1); scanf("%d",&iter->final);
		
		kayit_sayisi++;
	}
	
	iter->next = NULL;	
	return root;
}

node *add_node(node *root){
	int numara;
	node *iter,*iter2,*temp;	
	printf("\nHangi ogrenciden once kayit ekleyeceksin (numara gir) : "); scanf("%d",&numara);
	
	temp = (node *) malloc(sizeof(node));
	printf("\n\nIsim gir : "); scanf("%s",temp->isim);
	printf("Numara gir : "); scanf("%d",&temp->no);
	printf("Vize gir : "); scanf("%d",&temp->vize);
	printf("Final gir : "); scanf("%d",&temp->final);
		
	iter = root;
	
	if(root->no == numara){  // Basa ekleme
		temp->next = iter;
		root = temp;
	}
	
	else{
		while(iter->no != numara && iter->next != NULL){
			iter2 = iter;
			iter = iter->next;
		}
		
		if(iter->no == numara){  // Araya ekleme
			iter2->next = temp;
			temp->next = iter;
		}
		
		else if(iter->next == NULL){  // Sona ekleme
			printf("\n*** Girdigin no bulunamadi. Ekleme sona yapiliyor. ***\n");
			iter->next = temp;
			temp->next = NULL;
		}
		
	}
	
	kayit_sayisi++;
	return root;
}

node *delete_node(node *root){
	int numara;
	node *iter,*iter2;
	printf("\nHangi ogrenciyi sileceksin (numara gir) : "); scanf("%d",&numara);
	iter = root;
	
	if(root->no == numara){
		root = iter->next;
		kayit_sayisi--;
		free(iter);
	}
	
	else{
		while(iter->no != numara && iter->next != NULL){
			iter2 = iter;
			iter = iter->next;
		}
		
		if(iter->no == numara){
			iter2->next = iter->next;
			kayit_sayisi--;
			free(iter);
		}
		
		else{
			printf("\n*** OGRENCÝ NO BULUNAMADI ***");
		}
	}
	
	return root;
}

void calculate_avarage(node *root){
	node *iter;
	iter = root;
	
	while(iter != NULL){
		iter->ort = (iter->vize * 0.4) + (iter->final * 0.6);
		iter = iter->next;
	}
	hesaplandi++;
}

node *delete_unpass(node *root){
	node *iter,*iter2;
	iter = root;
	iter2 = root;
	
	if(hesaplandi == 0){
		calculate_avarage(root);
	}
	
	else{
		if(iter->ort < 60){
			root = iter->next;
			kayit_sayisi--;
			free(iter);
		}
		
		else{
			while(iter != NULL){
			
				if(iter->ort < 60){
					iter2->next = iter->next;
					kayit_sayisi--;
					free(iter);
				}
				
				iter2 = iter;
				iter = iter->next;
			}
		}
	}
	
	return root;
}

void show_list(node *root){
	int sayac=1,secim;
	node *iter;
	iter = root;
		
	if(hesaplandi == 0){
		printf("Ortalamalar henuz hesaplanmadi. Hesaplamak ister misin ? (Evet = 1) : "); scanf("%d",&secim);
	}
	if(secim == 1){
		calculate_avarage(root);
	}
	
	printf("\n** %d adet kayit bulundu **\n",kayit_sayisi);
	
	while(iter != NULL){
		printf("\n%d. Kisi",sayac);
		printf("\nIsim : %s\t\t\tNumara : %d",iter->isim,iter->no);
		printf("\nVize : %d\t\t\tFinal : %d\t\t\tOrtalama : %.2f\n\n",iter->vize,iter->final,iter->ort);
		
		sayac++;
		iter = iter->next;
	}
	
}
