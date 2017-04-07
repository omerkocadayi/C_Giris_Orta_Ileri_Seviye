#include <stdio.h>

int main(){
	int i, n, r, x=1, y=1;
	
	printf("* C(n,r) - Kombinasyon\n");
	printf("* n ve r degerlerini giriniz\n\n");
	printf("n : "); scanf("%d",&n);
	printf("r : "); scanf("%d",&r);
	
	for(i=n; i>=(n-r+1); i--){
		x *= i;
	}
	
	for(i=1; i<=r; i++){
		y *= i;
	}
		
	printf("\nC(%d,%d) -> Sonuc :  =  %d",n,r,x/y);
	return 0;
}
