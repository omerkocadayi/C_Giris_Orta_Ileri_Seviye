#include <stdio.h>

int main(){
	int enb,ikincienb,dizi[10];
	enb=dizi[0];
	ikincienb=dizi[1];
	
	for(int i=0;i<10;i++){
		printf("%d. degeri giriniz : ",i+1); scanf("%d", &dizi[i]);
	}
	
	for(int i=0;i<10;i++){
		if(dizi[i]>enb){
			enb=dizi[i];
		}
	}
	
	for(int i=0;i<10;i++){
		if(dizi[i]>ikincienb && dizi[i]!=enb){
			ikincienb=dizi[i];
		}
	}
	
	printf("\nEn buyuk degeriniz : %d",enb);
	printf("\nEn buyuk ikinci degeriniz : %d",ikincienb);
	
	return 0;	
}
