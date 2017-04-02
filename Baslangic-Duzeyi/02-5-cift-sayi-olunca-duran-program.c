#include <stdio.h> // 5 tane ?ift say? girilince duracak !

int main(){
	int sayi[999],sayac=0;
	for(int i=0;;i++){
		printf("Sayi giriniz : "); scanf("%d",&sayi[i]);
		if(sayi[i]%2==0){
			sayac++;
		}
		if(sayac==5){
			break;
		}
	}
	printf("Dizinizde toplam 5 adet cift sayi olmustur.");	
	
	return 0;
}
