#include <stdio.h>
#include <conio.h>
#include <math.h>

int main(){
	float x,y;
	int secim;
	printf("islem yapmak istediginiz 1. sayiyi giriniz (x): "); scanf("%f",&x);
	printf("islem yapmak istediginiz 2. sayiyi giriniz (y): "); scanf("%f",&y);
	
	printf("\n\n(x+y) toplama icin        ==> 1'e bas\n");
	printf("(x-y) cikarma icin        ==> 2'ye bas\n");
	printf("(x*y) carpma icin         ==> 3'e bas \n");
	printf("(x/y) bolme icin          ==> 4'e bas \n");
	printf("(x^y) us almak icin       ==> 5'e bas \n");
	
	printf("\n\nHangi islemi yapmak istiyosun : "); scanf("%d",&secim);
	
	switch (secim){
		case 1 :
			printf("\nSonuc = %.2f",x+y);
			break;
		case 2 :
			printf("\nSonuc = %.2f",x-y);
			break;
		case 3 :
			printf("\nSonuc = %.2f",x*y);
			break;
		case 4 :
			printf("\nSonuc = %.2f",x/y);
			break;
		case 5 :
			printf("\nSonuc = %.2f",pow(x,y));
			break;
		default :
			printf("\n\n!!! HATALI GIRIS YAPILDI !!!\a\a");
			break;		
	}
	
	
	return 0;
}
