#include <stdio.h>
#include <string.h>

int main(){
	int deger;
	char cumle[100];
	printf("Cumlenizi giriniz : "); gets(cumle);

	for(int i=0;i<=strlen(cumle);i++){
		if(cumle[i]>=65 && cumle[i]<=90){
			cumle[i]+=32;
		}
		else if(cumle[i]>=97 && cumle[i]<=122){
			cumle[i]-=32;
		}
	}
	
	printf("\nYeni Cumleniz : %s",cumle);
	return 0;
}
