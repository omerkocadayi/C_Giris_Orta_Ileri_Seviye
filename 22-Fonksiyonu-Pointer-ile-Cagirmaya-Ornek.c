#include <stdio.h>

int alan(int,int);
int cevre(int,int);

int main(){
	int secim,a,b;
	int (*p)(int,int);
	
	printf("Kenarlari giriniz :"); scanf("%d%d",&a,&b);
	printf("islem sec (alan=1 , cevre=2) : "); scanf("%d",&secim);
	
	if(secim==1){
		p=alan;
	}
	
	else if(secim==2){
		p=cevre;
	}
	
	else {
		printf("HATALI GIRIS YAPTINIZ !!!!");
		return 0;
	}
	
	printf("Sonuc : %d", p(a,b));
	return 0;
}

int alan(int a,int b){
	return a*b;
}

int cevre(int a,int b){
	return 2*(a+b);
}
