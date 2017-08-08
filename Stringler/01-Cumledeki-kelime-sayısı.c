#include <stdio.h>
#include <string.h>

int kelimesayisi(char[]);

int main(){
	char cumle[100];
	puts("Cumlenizi giriniz : "); gets(cumle);	
	printf("Cumlenizdeki kelime sayisi : %d ",kelimesayisi(cumle));
	
	return 0;
}

int kelimesayisi(char cumle[]){
	int i;
	int uzunluk,sayac=0;
	uzunluk=strlen(cumle);
	
    	for(i=0;i<uzunluk;i++){
		if(cumle[i]==' ')
			sayac++;
	}
	
	return (sayac+1);
}
