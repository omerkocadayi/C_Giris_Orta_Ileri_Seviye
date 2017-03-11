/*
Pisagor Uclusu a<b<c ve  a^2 + b^2 = c^2 olarak tanimlanabilir.
Ornegin ==>  3^2 + 4^2 = 9+16 = 25 = 5^2
a+b+c = 1000 sonucunu veren, yukaridaki kurala uyan yalnizca 1 adet pisagor uclusu vardir.
Bu uclu için a*b*c kactir ?
*/

#include <stdio.h>

int main(){
	int a,a2,b,b2,c,c2;
	printf("........Pisagor Uclusu Teoremi........ (a^2 + b^2 = c^2)");
	
	for(a=1;a<1000;a++){
		a2=a*a;
		
		for(b=1;b<1000;b++){
			b2=b*b;
			
			for(c=1;c<1000;c++){
				c2=c*c;
				
				if(a<b && b<c && (a+b+c)==1000 && c2==a2+b2){
					printf("\n\n   Toplamlari 1000 yapan pisagor uclusu : %d,%d,%d",a,b,c);
				   	printf("\n   a^2 + b^2 = c^2  ==> %d + %d = %d",a2,b2,c2);
					printf("\n   Carpimlari (a*b*c) ==> %d * %d = %d",a,b,(a*b*c));
					return 0;
				}
			}
		}
	}
}
