#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct ogrenci{
	char ad[50];
	int no;
	int vize;
	int final;
};

typedef struct ogrenci ogr;
int kayitsayaci=0;
ogr *ptr;

void yeni_kayit();
void kayit_listele();
void kayit_guncelle();
void ortalama_hesapla();
void enbasarili();
void ogrenci_goster(int);


int main(){
	int secim,sayac=0;
	
	while(1){
		if(kayitsayaci > 0){
			system("CLS");
			printf("** ISLEM TAMAMLANDI **\n\n");
		}			
			
		printf("1-Yeni Kayit Ekleme\n2-Kayit Listeleme\n3-Kayit Guncelleme\n");
		printf("4-Sinif Ortalamasi Hesapla\n5-Ortalamaya Gore En Basarili Ogrenci Bilgisini Goster\n6-Cikis");
		printf("\n\nSecimini Yap : "); scanf("%d",&secim);
		
		switch(secim){
			case 1:
				yeni_kayit();
				break;
			case 2: 
				kayit_listele();
				break;
			case 3:
				kayit_guncelle();
				break;
			case 4:
				ortalama_hesapla();
				break;
			case 5:
				enbasarili();
				break;
			case 6:
				printf("\n\n*** CIKIS YAPILDI *** \a\a");
				free(ptr);
				return 0;
			default:
				printf("Hatali giris \a\a");
				break;
		}
	}	
}


void yeni_kayit(){
	ogr ogr1;
	
	if(kayitsayaci==0)
		ptr= (ogr *)malloc(sizeof(ogr));
	
	else
		ptr= (ogr *)realloc(ptr,(kayitsayaci+1)*sizeof(ogr));
		
	if(ptr!=NULL){
		printf("\nAd gir : "); scanf("%s",ogr1.ad);
		printf("Numara gir : "); scanf("%d",&ogr1.no);
		printf("Vize gir : "); scanf("%d",&ogr1.vize);
		printf("Final gir : "); scanf("%d",&ogr1.final);	
		*(ptr+kayitsayaci) = ogr1;
		kayitsayaci++;		
	}
	else
		printf("Yeterli Hafiza Yok..");
	
}


void kayit_listele(){
	int i,secim,no;
	ogr ogr1;
	printf("\n\nTumunu Listele ==> 1\nNumaraya Gore Listele ==> 2");
	printf("\n\nSecim : "); scanf("%d",&secim);
	system("CLS");
	
	if(secim==1){
		for(i=0;i<kayitsayaci;i++){
			ogr1=*(ptr+i);
		
			printf("\n\nAd : %s\t\tNumara : %d",ogr1.ad,ogr1.no);
			printf("\nVize : %d\t\tFinal : %d\n\n",ogr1.vize,ogr1.final);
		}	
	}
	
	else if(secim==2){
		printf("\nOgrenci numarasi giriniz : "); scanf("%d",&no);
		ogrenci_goster(no);
	}
	
	else
		printf("%d numarali ogrenci bulunamadi..",no);
	
   printf("\n\nBir tusa basana kadar ekranda kalacaktir..   ");
	getch();
	
}


void kayit_guncelle(){
	int i,ogrenci_no;
	ogr ogr1;
	system("CLS");
	printf("Guncellemek istedigin ogrencinin numarasi : "); scanf("%d",&ogrenci_no);
	
	for(i=0;i<kayitsayaci;i++){
		ogr1=*(ptr+i);
		
		if(ogrenci_no == ogr1.no){
			printf("\nYeni ad gir : "); scanf("%s",ogr1.ad);
			printf("\nYeni numara gir : "); scanf("%d",&ogr1.no);
			printf("\nYeni vize gir : "); scanf("%d",&ogr1.vize);
			printf("\nYeni final gir : "); scanf("%d",&ogr1.final);
		
			*(ptr+i)=ogr1;
		}
	}
}


void ortalama_hesapla(){
	int vize_top=0,final_top=0,basari_top=0;
	float v_ort=0,f_ort=0,b_ort=0;
	ogr ogr1;
	
	for(int i=0;i<kayitsayaci;i++){
		ogr1=*(ptr+i);
		vize_top += ogr1.vize;
		final_top += ogr1.final;
		basari_top += (ogr1.vize*0.4) + (ogr1.final*0.6);
	}
	
	v_ort=vize_top/kayitsayaci;
	f_ort=final_top/kayitsayaci;
	b_ort=basari_top/kayitsayaci;
	
	printf("\n\nVize Ortalamasi : %.2f",v_ort);
	printf("\nFinal Ortalamasi : %.2f",f_ort);
	printf("\nAgirlikli Basari Ortalamasi : %.2f",b_ort);
	
	printf("\n\nBir tusa basana kadar ekranda kalacaktir..   ");
	getch();
	
}


void enbasarili(){
	int secim,i;
	float max=0.0;
	ogr ogr1;
	printf("\nVize Basarisi icin ==> 1");
	printf("\nFinal Basarisi icin ==> 2");
	printf("\nAgirlikli Ort. Basarisi icin ==> 3");
	printf("\n\nSecimini yap : "); scanf("%d",&secim);
	
	system("CLS");
	
	if(secim==1){
		for(i=0;i<kayitsayaci;i++){
			ogr1=*(ptr+i);
			
			if(ogr1.vize > max){
				max=ogr1.vize;
			}
		}
		
		for(i=0;i<kayitsayaci;i++){
			ogr1=*(ptr+i);
			if(ogr1.vize == max){
				ogrenci_goster(ogr1.no);
			}
		}
		
		printf("Vizesi en yuksek ogrencinin notu : %.2f",max);
	}
	
	else if(secim==2){
		for(i=0;i<kayitsayaci;i++){
			ogr1=*(ptr+i);
			
			if(ogr1.final > max){
				max=ogr1.final;
			}
		}
		
		for(i=0;i<kayitsayaci;i++){
			ogr1=*(ptr+i);
			if(ogr1.final == max){
				ogrenci_goster(ogr1.no);
			}
		}
		
		printf("Finali en yuksek ogrencinin notu : %.2f",max);
	}
	
	else if(secim==3){
		float ort;
		
		for(i=0;i<kayitsayaci;i++){
			ogr1=*(ptr+i);
			ort = ((ogr1.vize)*0.4) + ((ogr1.final)*0.6);
			
			if(ort > max)
				max=ort;
		}
		
		for(i=0;i<kayitsayaci;i++){
			ogr1=*(ptr+i);
			ort = ((ogr1.vize)*0.4) + ((ogr1.final)*0.6);
			
			if(max == ort){
				ogrenci_goster(ogr1.no);
			}
		}
		
		printf("Ogrencinin ortalamasi : %.2f",max);
	}
	
	else{
		printf("Hatali Giris..");
	}
	
	printf("\n\nBir tusa basana kadar ekranda kalacaktir..   ");
	getch();
}


void ogrenci_goster(int no){
	int i;
	ogr ogr1;

	for(i=0;i<kayitsayaci;i++){
		ogr1=*(ptr+i);
		
		if(ogr1.no == no){
			printf("\n\nAd : %s\t\tNumara : %d",ogr1.ad,ogr1.no);
			printf("\nVize : %d\t\tFinal : %d\n\n",ogr1.vize,ogr1.final);
		}
	}
}

