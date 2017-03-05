/* n -->  n/2 (çift)
   n -->  3n+1 (tek)
   Yukaridaki kurali uygulayarak ve 13'ten baslayarak asagidaki diziyi uretiriz..
   13 - 40 - 20 - 10 - 5 - 16 - 8 - 4 - 2 - 1
   13'ten baslayip 1'de sonlanan bu dizi 10 terinden olusmaktadir.
   Henuz kanitlanmamis olsa da (Collatz Problemi), butun baslangic sayilarinin 1'de sonuclanacagi sanilmaktadir.
*/

#include <stdio.h>

int main(){
	int sayi,gecici,sayac=1;
	printf("Hangi sayinin Collatz Zincirini gormek istiyorsun : "); scanf("%d",&sayi);
	gecici=sayi;
	
	while(gecici!=1){
		
		if(gecici%2==0){
			gecici= gecici/2;
			printf("%d   ",gecici);
		}
		else{
			gecici= (3*gecici)+1;
			printf("%d   ",gecici);
		}
		sayac++;
	}
	
	printf("\n\n%d sayisinin zinciri %d terimden olusmaktadir.",sayi,sayac);
	return 0;
}
