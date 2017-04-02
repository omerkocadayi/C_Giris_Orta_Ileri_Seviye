#include <stdio.h>
#include <string.h>

int main(){
	int uzunluk;
	char gecici,cumle[100];
	printf("cumleni gir :"); gets(cumle);
	
	uzunluk=strlen(cumle);
	
     for(int i=0;i<uzunluk;i++){
	
     for(int j=0;j<uzunluk;j++){
			
      if(cumle[i]<cumle[j]){
	    gecici=cumle[j];
				cumle[j]=cumle[i];
				cumle[i]=gecici;
			}
		}
	}
	
	puts(cumle);	
	return 0;
}
