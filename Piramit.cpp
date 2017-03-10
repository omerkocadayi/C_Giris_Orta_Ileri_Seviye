#include <stdio.h>
#include <string.h>

int main(){
	int h,u;
	printf("piramit icin yukseklik gir : "); scanf("%d",&u);
	
	for(int i=1;i<=u;i++){
		
		for(int j=1;j<=u-i;j++)
			printf(" ");
		for(int k=1;k<i*2;k++)
			printf("*");
		
		printf("\n");
	}
	return 0;
}
