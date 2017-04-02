#include <stdio.h>

int main(){
	
	int finalnotu;
	printf("Final notu giriniz:");
	scanf("%d", &finalnotu);

    if(finalnotu>=90)
		printf("Gecti : Notun A \n");

	else if(finalnotu >=80)
		printf("Gecti : Notun B \n");

	else if(finalnotu>=70)
		printf("Gecti : Notun C \n");

	else if(finalnotu>=60)
		printf("Gecti : Notun D \n");

	else
		printf("Bu dersten KALDIN !");
	
	return 0;
	
}
