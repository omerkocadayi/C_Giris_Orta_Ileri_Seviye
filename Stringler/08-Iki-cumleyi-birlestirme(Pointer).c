#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *birlestir(char*,char*);
char *sonuc;

int main(){
	char cumle1[100],cumle2[100];
	char *p_cumle1=&cumle1[0];
	char *p_cumle2=&cumle2[0];
	
	printf("Birinci cumlenizi giriniz : "); gets(cumle1);
	printf("Ikinci cumlenizi giriniz : "); gets(cumle2);
	
	printf("Birlesmis cumleniz : %s",birlestir(p_cumle1,p_cumle2));
	
	return 0;
}

char *birlestir(char *p_cml1,char *p_cml2){
	int i,j;
	sonuc=(char *)malloc((strlen(p_cml1)+strlen(p_cml2)+2)*sizeof(char));
	
	for(i=0;i<strlen(p_cml1);i++){
		sonuc[i]=*(p_cml1+i);
	}
	
	for(j=0;j<strlen(p_cml2);j++){
		sonuc[i]=*(p_cml2+j);
		i++;
	}

	return sonuc;
}
