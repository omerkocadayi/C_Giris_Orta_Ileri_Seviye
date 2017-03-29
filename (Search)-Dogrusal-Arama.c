#include <stdio.h>

int dogrusal_arama(int [],int,int);

int main(){
	int i,aranan,sonuc,sayilar[10];
	
	for(i=0; i<10; i++){
		printf("%d. elemani gir : ",i+1); scanf("%d",&sayilar[i]);
	}
	
	printf("\nhangi sayi aranacak : "); scanf("%d",&aranan);
	
	sonuc = dogrusal_arama(sayilar,i,aranan);
	
	if(sonuc == 0){
		printf("Sayi bulunamadi");
	}
	else{
		printf("%d sayisi %d. indiste bulundu", aranan,sonuc);
	}
	
	return 0;
}

int dogrusal_arama(int a[],int n,int aranan){
	int i;
	
	for(i=0; i<n; i++){
		if(a[i] == aranan){
			return i;
		}
	}
	
	return -1;
}
