#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	char cumle[100],deger;
	char sesliharfler[5]={'a','e','i','o','u'};
	int sesliharfsayisi=0;
	
	printf("Girmek istediginiz cumle : "); gets(cumle);
	
	int uzunluk=strlen(cumle);
	
	for(int i=0;i<uzunluk;i++){
		for(int j=0;j<5;j++){
			if(cumle[i]==sesliharfler[j]){
				sesliharfsayisi++;
				break;
			}
		}
	}
	
	printf("\nGirdiginiz cumle : %s",cumle);
	printf("\nCumlenizdeki sesli harf sayisi : %d", sesliharfsayisi);
	return 0;
}
