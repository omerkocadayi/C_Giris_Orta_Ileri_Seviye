#include <stdio.h>

int main(){
	float mesafe, zaman, hiz;
	printf("Gidilecek uzaklik (Km cinsinden) : "); scanf("%f", &mesafe);
	printf("Ne kadar surede gitmeniz gerekiyor (Dakika cinsinden) : ");scanf("%f", &zaman);
	
	hiz=mesafe/zaman;
	
	printf("Ortalama hiziniz : %.2f Km/Saat olmali" , hiz );
	return 0;
}
