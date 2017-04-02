#include <stdio.h>
#include <string.h>

int main(){
	char cumle[100];
	printf("Cumlenizi giriniz : "); gets(cumle);
	
	for(int i=0;i<=strlen(cumle);i++){
                if(cumle[i]>=65 && cumle[i]<=90){
		        printf("%c",cumle[i]);
		}
	}

	printf("\n\n");
	
	for(int i=0;i<=strlen(cumle);i++){
		if(cumle[i]>=97 && cumle[i]<=122){
		        printf("%c",cumle[i]);
		}
	}
	
	return 0;
}
