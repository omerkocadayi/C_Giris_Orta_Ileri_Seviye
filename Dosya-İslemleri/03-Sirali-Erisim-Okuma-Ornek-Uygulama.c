#include <stdio.h>
#include <conio.h>

/*  YAPILAN ISLEMLERIN AKILDA DAHA KALICI OLABILMESI ICIN BENZER ISLEMLERI AYRI AYRI FONKSIYONLARLA YAPTIM.
AYRI FONKSIYONLAR KULLANMADAN 3 SECENEGI DE MAIN FONKSIYONU ICINDE DAHA KISA BIR SEKILDE YAZABILIRSINIZ.   */

void parasi_olmayanlar();
void parasi_olanlar();
void borclular();
	
int main(){
	int secim;
	
	while(1){
		system("CLS");
		printf("Hesapta parasi olmayanlar icin ==> 1'e bas\nHesapta parasi olanlar icin ==> 2'ye bas\n");
		printf("Borcu olanlar icin ==> 3'e bas\nCikmak icin ==> 4'e bas\n");
		printf("\nSecimini Yap : "); scanf("%d", &secim);
		
		switch(secim){
			case 1:
				parasi_olmayanlar();
				break;
			
			case 2:
				parasi_olanlar();
				break;
			
			case 3:
				borclular();
				break;
				
			case 4:
				printf("\nCikis Yapildi !!");
				return 0;
			
			default:
				printf("\nHatali Giris !! (Devam icin bir tusa bas)");
				getch();
				break;
		}		
	}
}

void parasi_olmayanlar(){
	int hesap_no;
	double bakiye;
	char ad[20];
	FILE *fptr;
	
	if((fptr = fopen("03-Sirali-Okuma-Islemleri.txt", "r")) != NULL){
	
		while( !feof(fptr) ){
			fscanf(fptr, "%d%s%lf", &hesap_no, ad, &bakiye);
			
			if(bakiye == 0)
				printf("%-5d %-10s %10.2f\n", hesap_no, ad, bakiye);
		}	
	}
	
	else
		printf("Dosya Acilamadi !!");
		
	fclose(fptr);
	printf("\n\nDevam icin bir tusa bas");
	getch();
}

void parasi_olanlar(){
	int hesap_no;
	double bakiye;
	char ad[20];
	FILE *fptr;
	
	if((fptr = fopen("03-Sirali-Okuma-Islemleri.txt", "r")) != NULL){
	
		while( !feof(fptr) ){
			fscanf(fptr, "%d%s%lf", &hesap_no, ad, &bakiye);
		
			if(bakiye > 0)
				printf("%-5d %-10s %10.2f\n", hesap_no, ad, bakiye);		
		}	
	}
	
	else
		printf("Dosya Acilamadi !!");
	
	fclose(fptr);
	printf("\n\nDevam icin bir tusa bas");
	getch();
}

void borclular(){
	int hesap_no;
	double bakiye;
	char ad[20];
	FILE *fptr;
	
	if((fptr = fopen("03-Sirali-Okuma-Islemleri.txt", "r")) != NULL){
	
		while( !feof(fptr) ){	
			fscanf(fptr, "%d%s%lf", &hesap_no, ad, &bakiye);
			if(bakiye > 0)
				printf("%-5d %-10s %10.2f\n", hesap_no, ad, bakiye);
		}	
	}
	
	else
		printf("Dosya Acilamadi !!");
		
	fclose(fptr);
	printf("\n\nDevam icin bir tusa bas");
	getch();
}
