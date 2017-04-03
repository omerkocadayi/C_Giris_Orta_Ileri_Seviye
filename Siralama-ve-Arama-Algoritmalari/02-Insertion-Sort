#include <stdio.h>

void insertion_sort(int [],int);

int main(){
	int i,k,sayilar[10];
	
	for(i=0;i<10;i++){
		
		printf("%d. elemani gir : ",i+1); scanf("%d",&sayilar[i]);
	}
	
	insertion_sort(sayilar,i);
	
	printf("\nDizinin sirali hali \n");
	
	for(k=0; k<i; k++){
		printf("%d\t",sayilar[k]);
	}
	
	return 0;
}
	

void insertion_sort(int a[],int n){
	int ekle,i,k;
	
	for(i=1; i<n; i++){
		ekle = a[i];
		
		for(k=i-1; k>=0 && ekle <= a[k]; k--){
			a[k+1] = a[k];
		}
		
		a[k+1] = ekle;
	}
}
