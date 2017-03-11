//     TABAN VE KUVVET GIRIYORUZ. SONUCU FONKSIYONLA YAPIYORUZ. (ÖRNEK TABAN=3,KUVVET=4  ,  SONUC = 3*3*3*3)

#include <stdio.h>

int power(int,int);

int main(){
	int taban,kuvvet,sonuc;
	printf("Taban Giriniz : "); scanf("%d",&taban);
	printf("Kuvvet Giriniz : "); scanf("%d",&kuvvet);
	
	sonuc=power(taban,kuvvet);
	printf("Sonucunuz : %d",sonuc);
	
	return 0;
}

int power(int taban,int kuvvet){
	int result;
	result=taban;
	
	for(int i=1;i<kuvvet;i++){
		result=result*taban;
	}
	
	return result;
}
