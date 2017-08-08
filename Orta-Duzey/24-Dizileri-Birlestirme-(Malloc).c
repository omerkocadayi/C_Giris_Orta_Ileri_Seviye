//  2 Diziyi Birlestirme

#include <stdio.h>
#include <stdlib.h>

int *birlestir(int[], int, int[], int);

int main(){
	int dizi1[5]={1,3,5,7,9};
	int dizi2[4]={2,4,6,8};
	int *sonuc;
	
	printf("Dizi1 icin\nAdres\t\tDeger\n");
	for(int i=0;i<5;i++)
		printf("%x\t\t%d\n",&dizi1[i],dizi1[i]);
	
	printf("\n\nDizi2 icin\nAdres\t\tDeger\n");
	for(int i=0;i<4;i++)
		printf("%x\t\t%d\n",&dizi2[i],dizi2[i]);
	
	sonuc=birlestir(dizi1, 5, dizi2, 4);
	
	printf("\n\n\nDinamik Alan\nAdres\t\tDeger\n");
	for(int i=0;i<9;i++)
		printf("%x\t\t%d\n",sonuc+i,*(sonuc+i));
	
	return 0;
}


int *birlestir(int a[], int n1, int b[], int n2){
	int *p,i,j;
	p=(int *) malloc((n1+n2)*sizeof(int));
	
	for(i=0;i<n1;i++)
		*(p+i)=a[i];	
	for(j=0;j<n2;j++,i++)
		*(p+i)=b[j];
	
	return p;	
}
