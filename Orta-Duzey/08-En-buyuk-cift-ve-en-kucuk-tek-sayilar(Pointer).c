#include <stdio.h>
#include <stdlib.h>

int bul(int*,int*);

int main(){
	int sayilar[10],kucuk,buyuk;
	int *p_sayilar=&sayilar[0];
	kucuk=RAND_MAX;
	
	for(int i=0;i<10;i++)
		printf("%d. elemani giriniz : ",i+1); scanf("%d",p_sayilar+i);
	
	buyuk=bul(p_sayilar,&kucuk);
	printf("\nEn buyuk cift sayiniz : %d\nEn kucuk tek sayiniz : %d",buyuk,kucuk);

	return 0;
}

int bul(int *ptr,int *kucuk){
	int max=0;
	for(int i=0;i<10;i++){
		if(*(ptr+i)%2==0 && *(ptr+i)>max)
			max=*(ptr+i);
	}
	
	for(int i=0;i<10;i++){
		if(*(ptr+i) % 2 == 1 && *(ptr+i) < *kucuk)
			*kucuk = *(ptr+i);
	}
	return max;
}
