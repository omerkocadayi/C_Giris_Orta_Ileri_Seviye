#include <stdio.h>

void bubble_sort(int [], int);

int main(){
	int i,k,sayilar[10];
	
	for(i=0;i<10;i++){
		
		printf("%d. elemani gir : ",i+1); scanf("%d",&sayilar[i]);
	}
	
	bubble_sort(sayilar,i);
	
	printf("\nDizinin sirali hali \n");
	
	for(k=0; k<i; k++){
		printf("%d\t",sayilar[k]);
	}
	
	return 0;
}

void bubble_sort(int a[],int n){
	
	int temp,i,k;

	for(i=0; i<n; i++){
	
		for(k=0; k<n-i-1; k++){
			
			if(a[k] > a[k+1]){
				temp = a[k];
				a[k] = a[k+1];
				a[k+1] = temp;
			}
		}
	}
}
