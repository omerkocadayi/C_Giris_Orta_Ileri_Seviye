// Girilen sayinin basamaklari toplamini ozyinelemeli bir fonksiyon kullanarak bulunuz.

#include <stdio.h>

int topla(int);

int main(){
	int sayi;
	printf("Sayinizi giriniz : "); scanf("%d",&sayi);
	
	printf("\nBasamaklarin toplami ==> %d",topla(sayi));
	
	return 0;
}

int topla(int x){
	if(x==0)
		return 0;
		
	else
		return x%10 + topla(x/10);	
}
