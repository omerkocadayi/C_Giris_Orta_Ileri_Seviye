#include <stdio.h>

int main(){
	int a=5;
	double b=5.5;
	char c='m';
	void *p;
	
	p=&a;
	printf("a = %d\n", *(int*)p);
	*(int*)p=10;
	printf("a = %d\n\n", a);
	
	
   	p=&b;
	printf("b = %.2f\n", *(double*)p);
	*(double*)p = 8.5;
	printf("b = %.2f\n\n", b);
	
	
	p=&c;
	printf("c = %c\n", *(char*)p);
	*(char*)p = 'i';
	printf("c = %c\n\n", c);
	
	
	return 0;
}
