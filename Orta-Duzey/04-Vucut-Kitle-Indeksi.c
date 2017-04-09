// vucut kitle indeksi ==> Kilo / Boyun Karesi     seklinde hesaplanir.
#include <stdio.h>

int indeks(float, int);

int main(){
	float boy;
	int kilo, kitleindeks;

	printf("boy giriniz : "); scanf("%f",&boy);
	printf("kilo giriniz : "); scanf("%d",&kilo);
	boy = boy/100;  //metre cinsine cevirmek icin
	
	kitleindeks=indeks(boy,kilo);
	
	if(kitleindeks==1)
		printf("Zayif");
	
	else if(kitleindeks==2)
		printf("Normal");
	
	else if(kitleindeks==3)
		printf("Kilolu");
	
	else if(kitleindeks==4)
		printf("Obez");
}

int indeks(float boy, int kilo){
	float sonuc;
	boy=boy*boy;
	sonuc=kilo/boy;
	
	if(sonuc<=18)
		return 1;

	else if(sonuc<=25)
		return 2;
	
	else if(sonuc<=30)
		return 3;

	else
		return 4;
}
