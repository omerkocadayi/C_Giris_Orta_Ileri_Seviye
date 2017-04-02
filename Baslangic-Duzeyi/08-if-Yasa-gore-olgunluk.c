#include <stdio.h>

int main(){
	int yas;
	printf("Bir yas giriniz:");
	scanf("%d", &yas);
	
	if(yas<=7)
		printf("Bu kisi bir cocuktur.");
	
	else if(yas<12)
		printf("Bu kisi bir genctir.");
	
	else if(yas<18)
		printf("Bu kisi bir ergendir.");
	
	else if(yas<50)
		printf("Bu kisi bir olgundur.");
	
	else if(50<yas)
		printf("Bu kisi yaslidir.");
	
	else
		printf("yanlis giris yaptiniz.");
	
	return 0;
}
