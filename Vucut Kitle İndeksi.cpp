#include <stdio.h>
float indeks(float,float);
int main(){
	float boy,kilo,kitleindeks;
	printf("boy giriniz : "); scanf("%f",&boy);
	printf("kilo giriniz : "); scanf("%f",&kilo);
	
	kitleindeks=indeks(boy,kilo);
	
	if(kitleindeks==1){
		printf("Zayif");
	}
	else if(kitleindeks==2){
		printf("Normal");
	}
	else if(kitleindeks==3){
		printf("Kilolu");
	}
	else if(kitleindeks==4){
		printf("Obez");
	}
}

float indeks(float boy,float kilo){
	float sonuc;
	boy=boy*boy;
	sonuc=kilo/boy;
	
	if(sonuc<=10){
		sonuc=1;
	}
	else if(sonuc<=20){
		sonuc=2;
	}	
	else if(sonuc<=30){
		sonuc=3;
	}
	else
		sonuc=4;
	
	return sonuc;
}
