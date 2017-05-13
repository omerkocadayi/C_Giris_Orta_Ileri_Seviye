#include <stdio.h>

int main(){
	int yas;
	char ad[20];
	
	FILE *fptr;
	fptr = fopen("01-Sirali-Yazma-Ornegi.txt", "w");
	
	if(fptr == NULL)
		printf("Dosya Olusturulamadi !\n");
		
	else{
		printf("Ad giriniz : "); scanf("%s", ad);
		printf("Yas giriniz : "); scanf("%d", &yas);
		
		fprintf(fptr, "Ad : %s\nYas : %d",ad,yas);
	}
	
	fclose(fptr);
	return 0;	
}
