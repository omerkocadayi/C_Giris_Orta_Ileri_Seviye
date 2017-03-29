#include <stdio.h>

void selection_sort(int [], int);

int main(){
	int i,k,sayilar[10];
	
	for(i=0;i<10;i++){
		
		printf("%d. elemani gir : ",i+1); scanf("%d",&sayilar[i]);
	}
	
	selection_sort(sayilar,i);
	
	printf("\nDizinin sirali hali \n");
	
	for(k=0; k<i; k++){
		printf("%d\t",sayilar[k]);
	}
	
	return 0;
}


void selection_sort(int a[],int n){
	int min,indis,i,k;
	
	for(i=0; i<n-1; i++){
		min = a[n-1];
		indis = n-1;
		
		for(k=i; k<n-1; k++){
			if(a[k] < min){
				min = a[k];
				indis = k;				
			}
		}
		
		a[indis] = a[i];
		a[i] = min;
	}
	
}





