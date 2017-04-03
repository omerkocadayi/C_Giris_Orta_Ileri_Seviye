#include <stdio.h>

int binary_search(int[], int, int, int);
void selection_sort(int[], int);

int main(){
	int i,k,aranan,sonuc,sayilar[10];
	
	for(i=0; i<10; i++){
		printf("%d. elemani gir : ",i+1); scanf("%d",&sayilar[i]);
	}
	
	printf("\nhangi sayi aranacak : "); scanf("%d",&aranan);
	
	selection_sort(sayilar,i);

	printf("\nDizinin sirali hali \n");
	
	for(k=0; k<i; k++){
		printf("%d\t",sayilar[k]);
	}

	sonuc = binary_search(sayilar,0,i,aranan);
	
	if (sonuc == -1){
		printf("Aranan deger bulunamadi");
	}
	else{
		printf("\n\n%d sayisi %d. indiste bulundu",aranan,sonuc);
	}
	
	return 0;
}

int binary_search(int a[], int sol, int sag, int aranan){
	int orta;
	
	while(sol<=sag){
		orta = (sol+sag)/2;
		
		if(aranan == a[orta]){
			return orta;
		}
		
		else if(aranan > a[orta]){
			sol = orta+1;
		}
		
		else
			sag = orta-1;
	}
	return -1;
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
