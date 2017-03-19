#include <string.h>
#include <stdio.h>

int main(){
	int sifre[20],uzunluk,a=0;
	int *ptr_sifre;
	char kelime[20];
	char dizi[3][3]={'A','B','C','D','E','F','G','H','I'};
	char *ptr_kelime;
	ptr_sifre=sifre;
	ptr_kelime=kelime;
	
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			printf(" %c |",dizi[i][j]);
			if(j==2){
				printf("\n------------\n");
			}
		}
	}
	
	printf("\n\nMatriste bulunan harflerden kendinize bir sifre olusturun : "); gets(kelime);
	uzunluk=strlen(kelime);
	
	for(int i=0;i<uzunluk;i++){
		for(int j=0;j<3;j++){
			for(int k=0;k<3;k++){
				if (*(ptr_kelime+i)==dizi[j][k]){
					sifre[a]=((j+1)*10)+k+1;
					a++;
				}
			}
		}
	}
	
	printf("\n\nSifrenizin sifrelenmis hali :");
	
	for(int i=0;i<20;i++){
		if(*(ptr_sifre+i)==0){
			break;
		}
		printf("%d ",*(ptr_sifre+i));	
	}
	return 0;
}
