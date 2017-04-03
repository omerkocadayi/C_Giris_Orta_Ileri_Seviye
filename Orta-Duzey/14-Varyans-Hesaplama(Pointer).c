#include <stdio.h>
float varyans_hesabi(int *,float);

int main(){
	int dizi[15];
	float ort,toplam=0,varyans;
	int *ptr_dizi;
	ptr_dizi=&dizi[0];
	
	for(int i=0;i<15;i++){
		printf("Dizinizin %d. sayisini giriniz : ",i+1); scanf("%d",(ptr_dizi+i));
		toplam+=*(ptr_dizi+i);
	}
	ort=toplam/15;
	
	printf("\n\nSayilarin toplami : %.2f",toplam);
	printf("\n\nSayilarin ortalamasi : %.2f",ort);
	
	varyans= varyans_hesabi(ptr_dizi,ort);
	printf("\n\nVaryans : %.2f",varyans);
	
	return 0;
}

float varyans_hesabi(int *ptr,float ort){
	float tplm=0,vryns;
	
	for(int i=0;i<15;i++){
		tplm+=(ort-(*(ptr+i)))*(ort-(*(ptr+i)));
	}
	
	vryns=tplm/15;
	return vryns;
}
