#include <stdio.h>
// 10 çift sayý alana kadar sayý giriyoruz. 10 çift sayý tamamlanýnca çiftlerin en büyüðünü buluyoruz. hem en büyüðü hem de sýralamasýný yazdýrýyoruz.
int main(){
	int sayi,enb,cs=0,gecici=0,ciftdizi[10];
	enb=ciftdizi[0]; // cs : cift sayac
	for(int i=0;;i++){
		printf("Sayi giriniz : "); scanf("%d",&sayi);
		if(sayi%2==0){
			ciftdizi[cs]=sayi;
			cs++;			
		}
		if(cs==10){
			break;
		}
	}
	for(int i=1;i<10;i++){
		if(ciftdizi[i]>enb){
			enb=ciftdizi[i];
		}
	}
	printf("\nEn buyuk cift sayiniz : ",enb);
	
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			if(ciftdizi[j]>ciftdizi[j+1]){
				gecici=ciftdizi[j];
				ciftdizi[j]=ciftdizi[j+1];
				ciftdizi[j+1]=gecici;		
			}
		}
	}
	printf("\nCift sayilarinizin siralamasi : ");

	for(int i=0;i<10;i++)	{
		printf("%d\t", ciftdizi[i]);
	}
	return 0;
}
