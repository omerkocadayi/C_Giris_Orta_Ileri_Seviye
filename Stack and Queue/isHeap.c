#include <stdio.h>

int isHeap(int [], int);

int main(){
	int i, cnt=1, result, key, a[20];
	
	printf("Diziyi giriniz !! '-1' girince dur !!\n");
	for(i=1; i<20; i++){   // **HEAP YAPISINDA 0. ÝNDÝSÝ KULLANMIYORDUK. O YUZDEN Ý DEGÝSKENÝNÝ 1'DEN BASLATTIM.
		printf("\n%d. elemani gir : ", i); scanf("%d", &key);
		if(key != -1){
			a[i] = key;
			cnt++;
		}
		else
			break;
	}
	
	result = isHeap(a, cnt);
	
	if(result == 0)
		printf("\n\nBu dizi Binary Heap dizisidir.");
	else
		printf("\n\nBu dizi Binary Heap dizisi degildir.");
	
	return 0;
}

int isHeap(int a[], int boyut){
	int i, control=0;
	
	for(i=1; i<boyut/2; i++){
		if(a[i] > a[2*i] || a[i] > a[(2*i)+1]){
			control++;
		}
	}
	return control;
}
