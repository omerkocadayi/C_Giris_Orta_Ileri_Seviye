#include <stdio.h>  //DÝZÝNÝN EN BÜYÜK ÇÝFT SAYISI VE DÝZÝNÝN EN KÜÇÜK TEK SAYISI

int main(){
	int dizi[10],enb,enk;
	
	for(int i=0;i<10;i++){
		printf("Dizinin %d. elamanini giriniz : ",i+1); scanf("%d",&dizi[i]);
	}	
	
	for(int i=0;i<10;i++){
		if(dizi[i]%2==0){
			enb=dizi[i];
			break;
		}
	}
	
	for(int i=0;i<10;i++){
		if(dizi[i]%2!=0){
			enk=dizi[i];
			break;
		}
	}	
	
	for(int i=0;i<10;i++){
		if(dizi[i]>enb && dizi[i]%2==0)
			enb=dizi[i];
	}
	
	for(int i=0;i<10;i++){
		if(dizi[i]<enk && dizi[i]%2==1)	
			enk=dizi[i];
	}
	
	printf("\n\n En kucuk tek sayiniz : %d \n En buyuk cift sayiniz : %d",enk,enb);
	return 0;
}
