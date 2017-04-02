#include <stdio.h>

int main()
{
	int secim;
	printf("\tBURC YORUMLARI");
	printf("\n\nYay burcu icin : 1");
	printf("\nKoc burcu icin : 2");
	printf("\nOglak burcu icin : 3");
	printf("\nAkrep burcu icin : 4");
	printf("\nIkizler burcu icin : 5");
	printf("\nBalik burcu icin : 6");
	printf("\nYengec burcu icin : 7");
	printf("\nTerazi burcu icin : 8");
	printf("\nKova burcu icin : 9");
	buraya : printf("\n\n\t1-9 arasinda secim yapiniz :"); scanf("%d",&secim);
	
	if(secim>=1 && secim<=9)
	{
		switch(secim)
		{
		case 1: printf("\n\tMasallahin var bu aralar ;)"); break;
		case 2: printf("\n\tIs hayatinizda olumlu gelismeler olacak gibi hissediyorum :)"); break;
		case 3: printf("\n\t3 mu desem 5 mi desem :) Bayagi kismetin var :d"); break;
		case 4: printf("\n\tKardesim bos islerle ugrasma, otur derslerine calis, HAYATIN SALLANTIDA GORUNUYOR !!"); break;
		case 5: printf("\n\tSana iyi seyler yazmak gelmiyo icimden.. Sagligin kotu durumda.. Bi ayagin cukurda gibi.."); break;
		case 6: printf("\n\tAt kendini discolara :d"); break;
		case 7: printf("\n\tBu aralar yengec burclari cok karizmatik.."); break;
		case 8: printf("\n\tSana iyi para gelcek kardesim. Guzel yerlere harcamani temenni ederim.."); break;
		case 9: printf("\n\tAga sen Fornezzi misin aq KOVA BURCU NE DEMEK asdkjfnasdkjf"); break;
		
		}
		return 0;
		
  
	}
	else
		printf("\nYanlis giris yaptiniz. Tekrar deneyin..\a"); goto buraya;
	
	
	return 0;
}
