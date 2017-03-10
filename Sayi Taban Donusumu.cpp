// Sayi Taban Donusum
#include <stdio.h>
#include <stdlib.h>

void ikilik_taban(unsigned);
void sekizlik_taban(unsigned);

int main(){
	unsigned sayi,secim;
	
	printf("\tSayinizi giriniz : "); scanf("%u",&sayi);

 	printf("\n\t2'lik taban icin ==> 1'e bas");
 	printf("\n\t8'lik taban icin ==> 2'ye bas");
 	printf("\n\t16'lik taban icin ==> 3'e bas");
 	
 	
 	printf("\n\n\n\tHANGI TABANA DONUSUM YAPMAK ISTIYORSUN :"); scanf("%d", &secim);
 	
 	if(secim==1){
 		ikilik_taban(sayi);
	}
	
	else if(secim==2){
 		sekizlik_taban(sayi);
	}
	
	else if(secim==3){
		printf("\n\n\t* Sayinizin 16'lik tabanda karsiligi  :  ");
 		printf("%x", sayi);
	}
	
	else
		printf("\n\t!!!!  HATALI GIRIS YAPTINIZ  !!!!");

	return 0;
}

void ikilik_taban(unsigned x){
	int i=1,k;
	unsigned *p=&x;
	
	while(1){
		*(p+i)= x%2;
		x=x/2;
		
		if(x<2){
			*(p+i+1)=x;
			break;
		}
		i++;
	}
	printf("\n\n\t* Sayinizin 2'lik tabanda karsiligi  :  ");
	for(k=i+1;k>0;k--){
		printf("%d",*(p+k));
	}
}
void sekizlik_taban(unsigned x){
	int i=1,k;
	unsigned *p=&x;
	
	while(1){
		*(p+i)= x%8;
		x=x/8;
		
		if(x<8){
			*(p+i+1)=x;
			break;
		}
		i++;
	}
	printf("\n\n\t* Sayinizin 8'lik tabanda karsiligi  :  ");
	for(k=i+1;k>0;k--){
		printf("%d",*(p+k));
	}
}
