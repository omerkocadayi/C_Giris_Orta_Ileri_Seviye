#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char sesli_bul(char*,char*);
int main(){
	char cumle[100];
	char sesli[5]={'a','e','i','o','u'};
	char *p_cumle=&cumle[0];
	char *p_sesli=&sesli[0];
	int sessiz_adet,uzunluk,bosluk=0;
	
	printf("Cumlenizi giriniz : "); gets(cumle);

	for(int i=0;i<strlen(cumle);i++){
		if(cumle[i]==' '){
			bosluk++;
		}
	}
	
	uzunluk=strlen(cumle)-bosluk;
	sessiz_adet=uzunluk-sesli_bul(p_cumle,p_sesli);
	
	printf("\n\nCumlenizdeki sesli harf sayisi : %d",sesli_bul(p_cumle,p_sesli));
	printf("\n\nCumlenizdeki sessiz harf sayisi : %d",sessiz_adet);
	
	return 0;
}
char sesli_bul(char *ptr_cumle,char *ptr_sesli){
	int sayac=0;
	
	for(int i=0;i<strlen(ptr_cumle);i++){
		for(int j=0;j<5;j++){
			if(*(ptr_cumle+i)==*(ptr_sesli+j)){
				sayac++;
			}
		}
	}
	return sayac;
}
