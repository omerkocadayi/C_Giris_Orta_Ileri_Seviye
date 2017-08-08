//       kullanıcıdan metin alıyoruz. hangi harften kaç tane olduğunu buluyoruz. pointer kullanarak

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	char cumle[100];
	int harf_sayisi[255]={0};
	char *p_cumle;
	int *p_harf;
	
	p_cumle=cumle;
	p_harf=harf_sayisi;
	
	printf("Cumlenizi giriniz : "); gets(cumle);

	for(int i=0;i<strlen(cumle);i++){
		int k=*(p_cumle+i);  // karakterin ascıı kodunu k'ya atadık.
		*(p_harf+k)=*(p_harf+k)+1;  // harf sayısını bir artırıyoruz.
	}
	
	for(int i=0;i<255;i++){
  		if(*(p_harf+i)>0 && i!=32)
			printf("\n %c   karakterinden %d tane var",i,*(p_harf+i));
	}
  	return 0;
}
