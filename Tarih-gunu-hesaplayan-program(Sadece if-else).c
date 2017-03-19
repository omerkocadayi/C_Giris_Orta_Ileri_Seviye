#include <stdio.h>

int main(){
	int gun,ay,yil,toplam=0,artik=0;
	long gt;
	printf("\n(Rakamsal olarak) Gun giriniz : "); scanf("%d", &gun);
	printf("\n(Rakamsal olarak) Ay giriniz : "); scanf("%d", &ay);
	printf("\n(Rakamsal olarak) Yil giriniz : "); scanf("%d", &yil);
	
	if (gun>31 || ay>12){
		printf("\n\t\tHATALI GIRIS YAPTINIZ !!\n");
		return 0;
	}
	
	if (yil%4==0 && ay>2){
		toplam=((yil-1)*365)+(yil/4);
	}
        else (yil%4==0 && ay<=2);
	        toplam=((yil-1)*365)+((yil-1)/4);
	        
	if (yil%4!=0){
	    toplam=((yil-1)*365)+(yil/4)-1;
        }
	
	if (gun<=31 || ay<=12){
	
	if (ay==1)
	    toplam=toplam+gun;
	else if (ay==2)
	    toplam=toplam+gun+31;
	else if (ay==3)
	    toplam=toplam+gun+31+28;
	else if (ay==4)
	    toplam=toplam+gun+31+28+31;
	else if (ay==5)
	    toplam=toplam+gun+31+28+31+30;
	else if (ay==6)
	    toplam=toplam+gun+31+28+31+30+31;
	else if (ay==7)
	    toplam=toplam+gun+31+28+31+30+31+30;
	else if (ay==8)
	    toplam=toplam+gun+31+28+31+30+31+30+31;
	else if (ay==9)
	    toplam=toplam+gun+31+28+31+30+31+30+31+31;
	else if (ay==10)
	    toplam=toplam+gun+31+28+31+30+31+30+31+31+30;
	else if (ay==11)
	    toplam=toplam+gun+31+28+31+30+31+30+31+31+30+31;
	else if (ay==12)
	    toplam=toplam+gun+31+28+31+30+31+30+31+31+30+31+30;
	
	    
	    
    toplam=toplam%7;
    if (toplam==1){
    	printf("\n\tBu tarih Pazartesi gunune denk gelir.");
    }
    else if (toplam==2)
	printf("\n\tBu tarih Sali gunune denk gelir.");
    else if (toplam==3)
	printf("\n\tBu tarih Carsamba gunune denk gelir.");
    else if (toplam==4)
	printf("\n\tBu tarih Persembe gunune denk gelir.");
    else if (toplam==5)
	printf("\n\tBu tarih Cuma gunune denk gelir.");
    else if (toplam==6)
	printf("\n\tBu tarih Cumartesi gunune denk gelir.");
    else
	printf("\n\tBu tarih Pazar gunune denk gelir.");
		
	}
	
	
	return 0;
}
