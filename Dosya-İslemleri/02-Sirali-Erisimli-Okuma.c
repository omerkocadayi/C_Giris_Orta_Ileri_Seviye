#include <stdio.h>

int main(){
	int tel_no;
	char ad[20];
	FILE *fptr;

	printf("\tREHBER\n  AD\t\t  TEL\n\n");

	if((fptr = fopen("02-Sirali-Okuma-Ornegi.txt", "r")) != NULL){
		while( !feof(fptr) ){
			fscanf(fptr, "%s", &ad);
			fscanf(fptr, "%d", &tel_no);
			printf(" %s\t\t%d\n", ad, tel_no);
		}
	}
	
	else
		printf("Dosya Acilamadi !!");
	
	fclose(fptr);
	return 0;
/*	
	char kisi[100];
	
	if((fptr = fopen("02-Sirali-Okuma-Ornegi.txt", "r")) != NULL){
		while( !feof(fptr) ){
			fgets(kisi, 99, fptr);  // fgets() fonksiyonu dosyadan satýr satýr veri okur.
			printf("%s", kisi);
		}
	}
	
	else
		printf("Dosya Acilamadi !!");
	
	fclose(fptr);
	return 0;
*/	
}
