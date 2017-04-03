/*
Pisagor Uclusu a<b<c ve  a^2 + b^2 = c^2 olarak tanimlanabilir.
Ornegin ==>  3^2 + 4^2 = 9+16 = 25 = 5^2
a+b+c = 1000 sonucunu veren, yukaridaki kurala uyan yalnizca 1 adet pisagor uclusu vardir.
Bu uclu için a*b*c kactir ?
*/

#include <stdio.h>

int main(){
	int a,b,c;
	
	for(a=1; a<1000; a++){
		for(b=1; b<1000; b++){
			c = 1000-a-b;
			
			if(a*a + b*b == c*c){
				printf("Bu uclu ==> a = %d , b = %d , c = %d",a,b,c);
				printf("\nCarpimlari = %d",a*b*c);
				return 0;
			}
		}
	}
}
