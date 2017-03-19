/*      Eger A sayisinin carpanlari toplami B sayisina ve
	B sayisinin carpanlari toplami A sayisina esit ise bu sayilara
	arkadas sayi diyoruz.
	
	Ornegin 220 ve 284..
	
	220 ==> 1 + 2 + 4 + 5 + 10 + 11 + 20 + 22 + 44 + 55 + 110 = 284
	284 ==> 1 + 2 + 4 + 71 + 142 = 220 
	
	Buna gore ikisi de 1000000'dan kucuk arkadas sayi ciftleri nelerdir?   */

#include <stdio.h>
#define MAX 1000000
int carpimlar_toplami(int*);

int main(){
	int a,b;
	
	for(a=2;a<MAX;a++){
		b = carpimlar_toplami(&a);
		if(b<a && carpimlar_toplami(&b)==a){    // b<a ifadesini tekrarlara dusmemek icin yazdik..
  			printf("Bu cift arkadas sayilardir : %6d    %10d \n",a,b);	
		}
	}
	return 0;
	
}

int carpimlar_toplami(int *x){
	int i,result=1;
	
	for(i=2;i<=*x/2;i++){
		if(*x%i==0){
			result+=i;
		}
	}	
	return result;
}
