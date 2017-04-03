//     SAYI TAHMİN OYUNU    ( 1 ve 1000 arasında random sayı alınacak. Tahminlerle bulmaya calısacagız)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	int n,sayac,tahmin,secim=1;
	
	while(secim==1){
		srand(time(NULL));
		n=rand()%1000+1;
		printf("\n....SAYIYI BULMAK ICIN 10 HAKKIN VAR....\n\n1 ve 1000 arasinda sayi tahmin ediniz : "); scanf("%d",&tahmin);
		
		for(int i=1;;i++){
			if(tahmin<n){
		   		printf("\nDaha buyuk bir sayiyla tekrar tahmin ediniz : "); scanf("%d",&tahmin);
		  		
		   		if(i==9){
		    			printf("\n\nHAKKINIZ DOLDU UZGUNUM :(\a\a");
		    			break;
				}
     			}
     	
     			else if(tahmin>n){
     	   			printf("\nDaha kucuk bir sayiyla tekrar tahmin ediniz : "); scanf("%d",&tahmin);
		   
		   		if(i==9){
		      			printf("\n\nHAKKINIZ DOLDU UZGUNUM :(\a\a");
		      			break;
				}
     			}
     	
     			else if(tahmin==n){
     				printf("\nTebrikler %d. Tahmininiz Dogru !!! ",i);
		   		break;
        		}
		}
		
		printf("\n\nTekrar oynamak ister misin ? (evet=1 , hayir=0) : "); scanf("%d",&secim);
		
		if(secim==0)
			break;
		
		if(secim!=1){
			printf("HATALI GİRİS !!\a\a");
			break;
		}
	}

	return 0;
}
