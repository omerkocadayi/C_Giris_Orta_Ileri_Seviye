#include <stdio.h>

int main(){
	int sayi,faktoriyel=1;
	printf("Faktoriyelini bulmak istediginiz sayiyi giriniz : "); scanf("%d", &sayi);
	
	if(sayi>=5 && sayi<=10){
		int i=1;
	    while(i<=sayi){
	    	faktoriyel=faktoriyel*i;
		    i++;
		}
		
		printf("\n%d sayisinin faktoriyeli %d'dir.",sayi,faktoriyel);
	}
	
	else{
		printf("Hatali giris yaptiniz !!\a\a\a");
	}
	
	return 0;
}
