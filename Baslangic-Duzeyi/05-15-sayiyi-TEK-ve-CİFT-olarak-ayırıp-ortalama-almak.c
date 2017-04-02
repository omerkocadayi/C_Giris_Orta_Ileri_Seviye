#include <stdio.h>

int main(){
	int i,sayi,ciftort,tekort,cifttoplam=0,ciftsayac=0,tektoplam=0,teksayac=0;
	
	for(i=0;i<=14;i++){
		printf("%d. sayiyi giriniz : ", i+1); scanf("%d",&sayi);
		if(sayi%2==0){
			cifttoplam+=sayi;
			ciftsayac++;
		}
		
		else{
			tektoplam+=sayi;
			teksayac++;
		}
		
	}
	
	ciftort=cifttoplam/ciftsayac;
	tekort=tektoplam/teksayac;
	
	printf("\nCift sayilarinizin ortalamasi : %d\nTek sayilarinizin ortalamasi : %d",ciftort,tekort);
		
	return 0;
}
