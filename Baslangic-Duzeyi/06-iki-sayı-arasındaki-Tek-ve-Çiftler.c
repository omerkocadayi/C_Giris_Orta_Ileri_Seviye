#include <stdio.h>

int main()0{
	int i,s1,s2,cift=0,tek=0;
	printf("birinci sayiyi giriniz : "); scanf("%d",&s1);
	printf("ikinci sayiyi giriniz : "); scanf("%d",&s2);
	
	if(s1<s2){
		for(i=s1; i<=s2; i++){
			if(i%2==0)
				cift++;		
			else
				tek++;
		
		}
	
	}
	
	else{
		for(i=s1; i>=s2; i--){
			if(i%2==0)
				cift++;
			
			else	
				tek++;
		}
	}
	
	printf("%d adet cift sayi, %d adet tek sayi vardir.",cift,tek);
	return 0;
}
