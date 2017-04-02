#include <stdio.h>

void main()
{
	int A=1,B=1,C, sayac=3, N;
	printf("Sayi gir:");
	scanf("%d", &N);
	printf("%d  %d  ", A, B);


	for(;sayac<=N;sayac++)
	{
		C= A+B;
		A= B;
		B= C;		
		printf("%d  ", C);
	}
	getch();
}
