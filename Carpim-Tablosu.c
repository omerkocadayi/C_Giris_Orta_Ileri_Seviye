#include <stdio.h>

int main(){
	int i=1;
	while(i<=10){
		printf("1 x %2d = %2d\t",i,i*1);
		printf("2 x %2d = %2d\t",i,i*2);
	        printf("3 x %2d = %2d\t",i,i*3);
	        printf("4 x %2d = %2d\t",i,i*4);
		printf("5 x %2d = %2d\n",i,i*5);
		i++;	
	}
        printf("\n\n");
	i=1;
	
	while(i<=10){
	    	printf("6 x %2d = %2d\t",i,i*6);
		printf("7 x %2d = %2d\t",i,i*7);
		printf("8 x %2d = %2d\t",i,i*8);
		printf("9 x %2d = %2d\t",i,i*9);
		printf("10 x %2d = %2d\n",i,i*10);
		i++;
        }
		
	return 0;
}
