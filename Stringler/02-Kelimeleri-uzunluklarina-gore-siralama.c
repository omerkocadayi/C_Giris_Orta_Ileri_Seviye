#include <stdio.h>
#include <string.h>

int main(){
	int uzunluk1,uzunluk2,uzunluk3;
	char kelime1[20],kelime2[20],kelime3[20];
	printf("Birinci kelimeyi giriniz : "); gets(kelime1);
	printf("Ikinci kelimeyi giriniz : "); gets(kelime2);
	printf("Ucuncu kelimeyi giriniz : "); gets(kelime3);
	
	uzunluk1=strlen(kelime1);
	uzunluk2=strlen(kelime2);
	uzunluk3=strlen(kelime3);
	
	if(uzunluk1<uzunluk2 && uzunluk1<uzunluk3){
		if(uzunluk2<uzunluk3)
			printf("\nKelimelerinizin uzunluklara gore siralamasi : \n %s , %s , %s",kelime3,kelime2,kelime1);
		else
			printf("\nKelimelerinizin uzunluklara gore siralamasi : \n %s , %s , %s",kelime2,kelime3,kelime1);	
	}
	
	else if(uzunluk2<uzunluk1 && uzunluk2<uzunluk3){
		if(uzunluk1<uzunluk3)
			printf("\nKelimelerinizin uzunluklara gore siralamasi : \n %s , %s , %s",kelime3,kelime1,kelime2);
		else
			printf("\nKelimelerinizin uzunluklara gore siralamasi : \n %s , %s , %s",kelime1,kelime3,kelime2);
	}
	else{
		if(uzunluk1<uzunluk2)
			printf("\nKelimelerinizin uzunluklara gore siralamasi : \n %s , %s , %s",kelime2,kelime1,kelime3);
		else
			printf("\nKelimelerinizin uzunluklara gore siralamasi : \n %s , %s , %s",kelime1,kelime2,kelime3);
	}
	return 0;
}
