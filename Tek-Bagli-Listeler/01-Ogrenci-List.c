#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct ogrenci{
	char ad[30];
	int no;
	int vize;
	int final;
	struct ogrenci *next;
};

typedef struct ogrenci ogrenci;
int kayitsayaci=0;


ogrenci* liste_olustur();      		       			// case 1
void liste_dolas(ogrenci *);					// case 2
ogrenci* dugum_ekle(ogrenci *);					// case 3
ogrenci* kayit_ekle(ogrenci *);					// case 4
void ogrenci_guncelle(ogrenci *);				// case 5
ogrenci* dugum_sil(ogrenci *);					// case 6
void sinif_ortalamasi(ogrenci *);				// case 7
void en_basarili(ogrenci *);					// case 8


int main(){
	ogrenci *head;
	int secim;
	head = NULL;
	
	while(1){		
		if(kayitsayaci > 0){
			printf("\nBir tusa basana kadar ekranda kalacaktir..");
			getch();
	
			system("cls");
			printf("\n*** ISLEM TAMAMLANDI ***\n\n");
		}
		
		printf("1 ==> Liste Olustur\n2 ==> Kayit Listele\n3 ==> Liste Arasina Yeni Kayit Ekle\n4 ==> Liste Sonuna Yeni Kayit Ekle\n5 ==> Ogrenci Guncelle\n");
		printf("6 ==> Ogrenci Sil \n7 ==> Sinif Ortalamasi\n8 ==> En Basarili Ogrenci\n9 ==> Cikis\n");
		printf("\nSecimini Yap : "); scanf("%d",&secim);
		
		system("cls");
		
		switch(secim){
			case 1:
				head = liste_olustur();
				break;
				
			case 2:
				liste_dolas(head);
				break;
			
			case 3:
				head = dugum_ekle(head);
				break;
			
			case 4:
				head = kayit_ekle(head);
				break;
			
			case 5:
				ogrenci_guncelle(head);
				break;
			
			case 6:
				head = dugum_sil(head);
				break;
			
			case 7:
				sinif_ortalamasi(head);
				break;
			
			case 8:
				en_basarili(head);
				break;
			
			case 9:
				free(head);
				system("cls");
				printf("\n*** CIKIS YAPILDI ***\n");
				return 0;
			
			default:
				printf("Hatali Giris Yaptiniz..");
				break;
		
		}	
	}
}

ogrenci * liste_olustur(){
	ogrenci *ptr, *h;
	int sayi, i, sayac=0;
	
	if(sayac > 0){
		printf("*** Son olusturdugunuz liste hafizada tutulacaktir ***\n\n");
	}
	
	printf("Kac kayit ekleyeceksin : "); scanf("%d",&sayi);
	
	for(i=0; i<sayi; i++){
		
		if(i==0){    // ILK DUGUM ICIN..
			ptr = (ogrenci *) malloc(sizeof(ogrenci));
			h = ptr;
		}
		
		else{
			ptr->next = (ogrenci *) malloc(sizeof(ogrenci));
			ptr = ptr->next;
		}
		
		printf("\n\nIsim gir : "); scanf("%s",ptr->ad);
		printf("No gir : "); scanf("%d",&ptr->no);
		printf("Vize gir : "); scanf("%d",&ptr->vize);
		printf("Final gir : "); scanf("%d",&ptr->final);
		
		kayitsayaci++;
	}
	
	ptr->next = NULL;
	sayac++;
	return h;
}


void liste_dolas(ogrenci *h){
	ogrenci *ptr;
	ptr = h;
	
	printf("Toplam %d adet kayit bulundu\n\n",kayitsayaci);
	
	while(ptr != NULL){
		printf("Isim : %s\nNo : %d \t\t Vize : %d \t\t Final : %d\n\n\n\n",ptr->ad,ptr->no,ptr->vize,ptr->final);
		ptr = ptr->next;	
	}

}



ogrenci* dugum_ekle(ogrenci *h){
	ogrenci *p, *q, *yeni;
	int no;
	
	printf("Hangi kayittan once ekleme yapmak istiyorsun ?");
	printf("\nOgrenci no gir : "); scanf("%d",&no);
	
	yeni = (ogrenci *) malloc(sizeof(ogrenci));

	printf("\n\nIsim gir : "); scanf("%s",yeni->ad);
	printf("No gir : "); scanf("%d",&yeni->no);
	printf("Vize gir : "); scanf("%d",&yeni->vize);
	printf("Final gir : "); scanf("%d",&yeni->final);

	p = h;
	
	if(p->no == no){   // Basa ekleme
		yeni->next = p;
		h = yeni;
	}
	
	else{
		while(p->no != no && p->next != NULL){   // Dugumler arasi dolasma
			q = p;
			p = p->next;
		}
		
		if(p->no == no){   // Araya ekleme
			q->next = yeni;
			yeni->next = p;
		}
		
		else if(p->next == NULL){   // Sona ekleme
			printf("Listenin sonuna ekleme yapiliyor..\n\n");
			p->next = yeni;
			yeni->next = NULL;
		}
	}
	
	kayitsayaci++;
	return h;
}


ogrenci* kayit_ekle(ogrenci *h){
	ogrenci *p, *yeni;
	
	yeni = (ogrenci *) malloc(sizeof(ogrenci));

	printf("\n\nIsim gir : "); scanf("%s",yeni->ad);
	printf("No gir : "); scanf("%d",&yeni->no);
	printf("Vize gir : "); scanf("%d",&yeni->vize);
	printf("Final gir : "); scanf("%d",&yeni->final);
	
	kayitsayaci++;
	p = h;
		
	if(p == NULL){
		h = yeni;		
		yeni->next = NULL;
	}
	
	else{
		while(p->next != NULL){
			p = p->next;
		}
		
		p->next = yeni;
		yeni->next = NULL;
	}
	
	return h;
}


void ogrenci_guncelle(ogrenci *h) {
	ogrenci *p;
	int no;
	p = h;	
	
	printf("\nGuncellenecek ogrencinin numarasini gir : "); scanf("%d", &no);

	while (p != NULL) {
		if (p->no == no) {
			
			printf("Yeni ad gir : "); scanf("%s", p->ad);
			printf("Yeni vize gir : "); scanf("%d", &p->vize);
			printf("Yeni final gir : "); scanf("%d",&p->final);	
			break;
		}
		
		p = p->next;
	}

	if(p == NULL)
		printf("\n*** ARADIGINIZ OGRENCİ NO BULUNAMADI ***\n");

}


ogrenci* dugum_sil(ogrenci *h){
	ogrenci *p, *q;
	int no;
	
	printf("Hangi kaydi silmek istiyorsun ?");
	printf("\n\nOgrenci no gir : "); scanf("%d",&no);
	
	p = h;
	
	if(p->no == no){   // Bastakini silme
		h = p->next;
		kayitsayaci--;
		free(p);
	}
	
	else{
		while(p->no != no && p->next != NULL){   // Dugumler arasi dolasma
			q = p;
			p = p->next;
		}
		
		if(p->no == no){   // Aradan ve sondan silme
			q->next = p->next;
			kayitsayaci--;
			free(p);
		}
		
		else if(p->next == NULL){
			printf("\n*** ARADIGINIZ OGRENCİ NO BULUNAMADI ***\n");
		}
	}
	
	return h;
}


void sinif_ortalamasi(ogrenci *h){
	ogrenci *p;
	int vize_top=0, final_top=0;
	float vize_ort, final_ort, agirlikli_ort;
	
	p = h;
	
	while(p != NULL){
		vize_top += p->vize;
		final_top += p->final;
		p = p->next;
	}
	
	vize_ort = vize_top / kayitsayaci;
	final_ort = final_top / kayitsayaci;
	agirlikli_ort = (vize_ort*0.4)+(final_ort*0.6);
	
	printf("\n\nSinifin vize ortalamasi : %.2f",vize_ort);	
	printf("\nSinifin final ortalamasi : %.2f",final_ort);	
	printf("\nSinifin agirlikli not ortalamasi : %.2f\n\n",agirlikli_ort);	
	
}


void en_basarili(ogrenci *h){
	ogrenci *p,*en_basarili;
	int secim;
	
	p = h;
	en_basarili = p;
	p = p->next;
	
	printf("1 ==> Vizenin en basarilisi\n2 ==> Finalin en basarilisi\n3 ==> Ortalamanin en basarilisi\n");
	printf("\nSecimini Yap : "); scanf("%d",&secim);
	
	if(secim == 1){
		while(p != NULL){
			if(p->vize > en_basarili->vize){
				en_basarili = p;
			}
	
			p = p->next;
		}
		
		printf("Vizesi En Yuksek Olan Ogrenci\n");
		printf("Isim : %s\nNo : %d \t\t Vize : %d \t\t Final : %d\n\n\n",en_basarili->ad,en_basarili->no,en_basarili->vize,en_basarili->final);
	}
	
	else if(secim == 2){
		while(p != NULL){
			if(p->final > en_basarili->final){
				en_basarili = p;
			}
	
			p = p->next;
		}
		
		printf("Finali En Yuksek Olan Ogrenci\n");
		printf("Isim : %s\nNo : %d \t\t Vize : %d \t\t Final : %d\n\n\n",en_basarili->ad,en_basarili->no,en_basarili->vize,en_basarili->final);
	}
	
	else if(secim == 3){
		float ort_p, ort_en;
	
		while(p != NULL){
			ort_p = (p->vize*0.4) + (p->final*0.6);
			ort_en =  (en_basarili->vize*0.4) + (en_basarili->final*0.6);
			
			if(ort_p > ort_en){
				en_basarili = p;
			}
	
			p = p->next;
		}
		
		printf("Ortalamasi En Yuksek Olan Ogrenci\n");
		printf("\nIsim : %s \t\t No : %d",en_basarili->ad,en_basarili->no);
		printf("\nVize : %d \t\t Final : %d \t\t Ortalama : %d\n\n\n",en_basarili->vize,en_basarili->final,ort_en);
	}
	
	else
		printf("\nHATALI GIRIS YAPTINIZ\n");
}
