//      100 Ögrenciye random not veriyoruz. en düşük, en büyük ve ortalama buluyoruz.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int max_hesap(int notlar[]);
int min_hesap(int notlar[]);
int ort_hesap(int notlar[]);

int main(){
	int ogr_not[100],max,min;
	float ort;
	srand(time(NULL));
	
	for(int i=0;i<100;i++){
		ogr_not[i]=rand()%100+1;
	}
	
	max=max_hesap(ogr_not);
	min=min_hesap(ogr_not);
	ort=ort_hesap(ogr_not);
	
	printf("En yuksek not : %d\n",max);
	printf("En dusuk not : %d\n",min);
	printf("Not ortalamasi : %.2f\n",ort);
	
	return 0;
}

int max_hesap(int notlar[100]){
	int max_not=0;
	for(int i=0;i<100;i++){
		if(notlar[i]>max_not){
			max_not=notlar[i];
		}
	}
	return max_not;
}

int min_hesap(int notlar[100]){
	int min_not=100;
	for(int i=0;i<100;i++){
		if(notlar[i]<min_not){
			min_not=notlar[i];
		}
	}
	return min_not;
}

int ort_hesap(int notlar[100]){
	int toplam=0;
        float ort;
	for(int i=0;i<100;i++){
		toplam+=notlar[i];
	}
	ort=toplam/100;
	return ort;
}
