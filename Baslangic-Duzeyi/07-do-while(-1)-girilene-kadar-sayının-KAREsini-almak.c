#include <stdio.h>

int main(){
	int sayi;
	
	do{
		printf("Sayi giriniz : "); scanf("%d", &sayi);
		printf("Girdiginiz sayinin karesi : %d\n\n", sayi*sayi);
	}while(sayi!=-1);
	
	printf("Girdiginiz sayi '-1' .. Program sonlandi !!\a\a");
	return 0;
}
