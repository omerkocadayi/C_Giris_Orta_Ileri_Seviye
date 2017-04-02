#include <stdio.h>
#include <string.h>

char *sirala(char*);

int main(){
	char cumle[100];
	char *p_cumle=&cumle[0];
	printf("Cumlenizi giriniz : "); gets(cumle);
	
	printf("\n\n Alfabetik dizilmis hali : %s",sirala(p_cumle));
	
	return 0;
}

char *sirala(char *ptr){
	char gecici;
	
  for(int i=0;i<strlen(ptr);i++){
		
    for(int j=0;j<strlen(ptr);j++){
		
    if(*(ptr+i)<*(ptr+j)){
				gecici=*(ptr+j);
				*(ptr+j)=*(ptr+i);
				*(ptr+i)=gecici;
			}
		}
	}
	return ptr;
}
