// kelime sayisini bulmak icin; kelimeler arasindaki bosluklarin sayisini bulup +1 yapmamiz gerekir.

#include <stdio.h>
#include <string.h>

int kelimesayisi(char[]);

int main(){
	int sayi;
	char cumle[100];
	puts("Cumlenizi giriniz : "); gets(cumle);
	sayi=kelimesayisi(cumle);
	
	printf("Cumlenizdeki kelime sayisi : %d ",sayi);
	
	return 0;
}

int kelimesayisi(char cumle[]){
	int i;
	int uzunluk,sayac=0;
	uzunluk=strlen(cumle);
	
        for(i=0;i<uzunluk;i++){
    	
		if(cumle[i]==' '){
			sayac++;
		}
		
	}
	return (sayac+1);
}

