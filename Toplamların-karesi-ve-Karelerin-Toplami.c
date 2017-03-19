/* ilk 10 sayının kareleri toplamı
   f(10) = 1^2 + 2^2 + ....... + 10^2 = 385
   
   toplamlarının karesi ise
   p(10) = (1 + 2 + ....... + 10)^2 ise = 3025
   
   bunlar arasındaki fark
   p(10) - f(10) = 3025 - 385 = 2640
   
   Öyleyse p(100) - f(100) = ?   */
   
   
#include <stdio.h>

int bul_kare_top(int);
int bul_top_kare(int);

int main(){
	int kareler_toplami , toplamlar_karesi;
	int x,sonuc;
	
	printf("' P(x) - F(x) ' isleminde x'in hangi degeri icin sonucu bulmak istersin : "); scanf("%d",&x);
	
		
	toplamlar_karesi= bul_top_kare(x);    // p(x)
	printf("\nToplamlarin karesi : %d",toplamlar_karesi);
	
	kareler_toplami= bul_kare_top(x);    // f(x)
	printf("\nKarelerin toplami : %d",kareler_toplami);

	
	sonuc= toplamlar_karesi - kareler_toplami;    // p(x) - f(x)

	printf("\nP(%d) - F(%d) = %d",x,x,sonuc);
	return 0;
}

int bul_kare_top(int x){
	int sonuc=0;
	
	for(int i=0;i<(x+1);i++){
		sonuc+=i*i;
	}
	
	return sonuc;
}

int bul_top_kare(int x){
	int sonuc=0;
	sonuc= (x*(x+1))/2;      //  (x*(x+1))/2  ===> 0'dan  x'e kadar olan tamsayıların toplam formülü
   
   return sonuc*sonuc;
}
