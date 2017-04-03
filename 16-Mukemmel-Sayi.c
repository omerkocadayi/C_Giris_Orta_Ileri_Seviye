/* Mukemmel Sayi... sayinin kendisi disinda pozitif tam sayi bolenlerinin toplami,
	sayinin kendisine esit ise bu sayi mukemmel sayidir.
	
	6 ==>  1+2+3 = 6
	Bu durumda 6 mukemmel bir sayidir..
	100.000'e kadar olan mukemmel sayilarin toplami kactir ? */

#include <stdio.h>

int main(){
	int sayi,i,j;
	int sayac=1,toplam=0,mukemmel_toplam=0;
	
	printf("Kaca kadar olan mukemmel sayilari gormek istiyorsun : "); scanf("%d",&sayi);
	
	for(i=1;i<=sayi;i++){
		
		for(j=1;j<i;j++){
			if(i%j==0){
				toplam+=j;
			}
		
			if(toplam==i){
				printf("\n%d. Mukemmel Sayi : %d",sayac,i);
				mukemmel_toplam+=toplam;
				sayac++;
				break;
			}
		}
		toplam=0;
		
	}
	
	printf("\nToplamlari : %d",mukemmel_toplam);
	return 0;
}
