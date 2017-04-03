#include <stdio.h>

int tersini_al(int);

int main(){
	int sayi,tersi;
	printf("Sayinizi giriniz : "); scanf("%d",&sayi);
	tersi=tersini_al(sayi);
	
	printf("Sayinizin tersi : %d ",tersi);
	
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
