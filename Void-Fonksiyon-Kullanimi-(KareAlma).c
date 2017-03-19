//   bi sayi gir. girilen sayının karesini void fonksiyonda al ve aynı adrese ata. 
//   void fonksiyon geri dönüş değeri olmayan fonksiyonlardır.

#include <stdio.h>

void KareAl(int *);

int main(){
	int x;
	printf("Sayi giriniz : "); scanf("%d",&x);
	printf("\nMain'de %d'nin adresi : %x",x,&x);
	KareAl(&x);
}

void KareAl(int *y){
	printf("\n\nFonksiyonda %d'nin adresi : %x",*y,&y);
	*y=(*y)*(*y);
	printf("\n\nSonuc = %d'nin adresi : %x",*y,&y);
}
