// Toplam eleman sayýsýný kullanýcýdan al. bu sayý kadar bellekten calloc ile yer al. elemanlarý gir. bu degerler icinde en buyuk olaný yazdýr.
// (pointer kullanarak)

#include <stdio.h>
#include <stdlib.h>

int buyuk_bul(int*,int);

int main(){
	int n;
	int *ptr;
	printf("diziniz kac elemanli olacak : "); scanf("%d",&n);
	ptr=(int *)calloc(n,sizeof(int));
	
	for(int i=0;i<n;i++){
		printf("Dizinizin %d. elemanini giriniz : ",i+1); scanf("%d",ptr+i);
	}
	
	printf("Dizinin en buyuk degeri : %d",buyuk_bul(ptr,n));
	return 0;
}

int buyuk_bul(int *p,int boyut){
	int max=*p;
	for(int i=0;i<boyut;i++){
		if(*(p+i)>max){
			max=*(p+i);
		}
	}
	return max;
}
