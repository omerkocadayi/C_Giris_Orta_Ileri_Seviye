#include <stdio.h>
int buyuk_bul(int*,int*);

int main(){
	int birinci,ikinci=0;
	int sayilar[10];
	int *ptr=&sayilar[0];
	
	for(int i=0;i<10;i++){
		printf("%d. elamani giriniz : ",i+1); scanf("%d",&sayilar[i]);
	}
	
	birinci=buyuk_bul(ptr,&ikinci);
	
	printf("\n En buyuk sayiniz : %d",birinci);
	printf("\n Ikinci buyuk sayiniz : %d",ikinci);
	return 0;
}

int buyuk_bul(int *ptr,int *max2){
	int max=0;
	
	for(int i=0;i<10;i++){
		if(*(ptr+i)>max){
			max=*(ptr+i);
		}
	}
	
	for(int i=0;i<10;i++){
		if(*(ptr+i)>*max2 && *(ptr+i)!=max){
		   *max2=*(ptr+i);
	        }
	}
	return max;
}
