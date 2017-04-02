#include <stdio.h>

int main(){
	int h;
	printf("piramit icin yukseklik gir : "); scanf("%d",&h);
	
	for(int i=1;i<=h;i++){
		
		for(int j=1;j<=h-i;j++)
			printf(" ");
		for(int k=1;k<i*2;k++)
			printf("*");
		
		printf("\n");
	}
	return 0;
}
