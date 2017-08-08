// Hem palindrom hem asal olan sayilara polindromik asal sayilar denir
// palindromik sayi = duzden ve tersten okunusu ayni olan sayilardir. ornek = 101,202,1551......
// buna gore 1.000.000'dan kucuk palindromik asal sayilar nelerdir ???


#include <stdio.h>
#define MAX 1000000

int asal_mi(int);
int tersini_al(int);

int main(){
	int i,sayac=0;
	
	for(i=2;i<MAX;i++){
		if(i == tersini_al(i) && i == asal_mi(i)){
			sayac++;
			printf("%d. palindromik asal sayi : %d\n",sayac,i);
		}
	}
	
   return 0;	
}

int tersini_al(int sayi){
	int toplam=0,gecici=0;
	
	for(int i=0;;i++){
		if(sayi>0){
			gecici=sayi%10;
	      		toplam=((toplam*10)+gecici);
	      		sayi=sayi/10;			
		}
		else
	    		break;		
	}
	return toplam;
}

int asal_mi(int sayi){
	int gecici=0;
	for(int i=2;i<=sayi/2;i++){
		if(sayi%i == 0)
			return gecici;
	}
	return sayi;
}
