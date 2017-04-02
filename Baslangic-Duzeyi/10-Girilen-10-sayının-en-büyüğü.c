#include <stdio.h>

int main()

{
	int i,sayi,max=0;
	for (i=1;i<=10;i++)
	{
		printf("\n%d. sayiyi giriniz :",i); scanf("%d",&sayi);
		if (sayi>max)
		{
			max=sayi;
		}
		}	
	
	printf("\n\tEn buyuk sayiniz : %d", max);
	return 0;
}
