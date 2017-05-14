#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* DOSYADAN OKUMA ISLEMINE GEREK KALMADAN SADECE DIZI UZERINDEN DE BU ISLEMI GERCEKLESTIREBILIRDIK.
AMA PRATIK OLMASI ACISINDAN OKUYARAK BU ISLEMI YAPTIK. */

int main(){
	int yazilan_dizi[20], okunan_dizi[20];
	int i, j;
	int sayac, frekans=0, sayi;
	FILE *fptr;
	
	if((fptr = fopen("04-Sirali-Okuma-ve-Yazma-Ornegi.txt", "w+")) != NULL){
		srand(time(NULL));
		for(i=0; i<20; i++){
			yazilan_dizi[i] = rand()%10+1;
			fprintf(fptr, "%d\n", yazilan_dizi[i]);
		}
		
		rewind(fptr);  // DOSYAYI BASA SARDIK
		printf("Dizi Elemanlari\n");
		i = 0;
		
		while( !feof(fptr) ){
			fscanf(fptr, "%d", &sayi);
			okunan_dizi[i] = sayi;
			printf("%-3d",okunan_dizi[i]);
			i++;
		}

		for(i=0; i<20; i++){
			sayac=0;
			for(j=0; j<20; j++){
				if(okunan_dizi[i] == okunan_dizi[j])
					sayac++;
				if(sayac > frekans){
					frekans = sayac;
					sayi = okunan_dizi[i];
				}
			}
		}
		
		printf("\n\nEn cok tekrar eden sayi : %d",sayi);
		printf("\n%d sayisi %d kez tekrar etti.",sayi,frekans);
	}

	else
		printf("Dosya Acilamadi !!");
		
	fclose(fptr);	
	return 0;
}
