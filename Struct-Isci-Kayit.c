#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct isci_bilgileri {
	char isim[30];
	char soyisim[30];
	char memleket[30];
	char mezuniyet[30];
	int sicil_no;
	unsigned long long int kimlik_no;
	unsigned long long int  tel_no;

	struct dogum_bilgileri {
		int gun, ay, yil;
	}dogum;
};

typedef struct isci_bilgileri isci;
isci *ptr;
int kayitsayisi = 0;

void yeni_kayit();
void kayit_listele();
void kayit_guncelle();

int main() {
	int secim;

	while (1) {
		system("cls");
		
		if (kayitsayisi > 0)
			printf("\n*** ISLEM TAMAMLANDI ***\n\n");

		printf("Yeni isci kaydi icin           ==> 1'e bas\nKayitlari listelemek icin      ==> 2'ye bas\n");
		printf("Kayit guncellemek icin         ==> 3'e bas\nCikmak icin                    ==> 4'e bas");
		printf("\n\nSecimini Yap : "); scanf("%d", &secim);

		switch (secim) {
		case 1:
			yeni_kayit();
			break;
		case 2:
			kayit_listele();
			break;
		case 3:
			kayit_guncelle();
			break;
		case 4:
			printf("\n*** CIKIS YAPILDI ***");
			free(ptr);
			return 0;
		default:
			printf("\n*** HATALI GIRIS YAPILDI ***\n");
			printf("\n(devam icin herhangi bir tusa bas)");
			printf("\n\nBir tusa basana kadar ekranda kalacaktir..");
			getch();
		}
	}
}


void yeni_kayit() {
	system("cls");
	isci isci1;

	if (kayitsayisi == 0)
		ptr = (isci *)malloc(sizeof(isci));
	else
		ptr = (isci *)realloc(ptr, (kayitsayisi+1) * sizeof(isci));

	if (ptr != NULL) {
		printf("Ad giriniz : "); scanf("%s", isci1.isim);
		printf("Soyad giriniz : "); scanf("%s", isci1.soyisim);
		printf("Memleket giriniz : "); scanf("%s", isci1.memleket);
		printf("Mezuniyet bilgisi giriniz : "); scanf("%s", isci1.mezuniyet);
		printf("Kimlik numarasi giriniz : "); scanf("%llu", &isci1.kimlik_no);
		printf("Sicil numarasi giriniz : "); scanf("%d", &isci1.sicil_no);
		printf("Telefon numarasi giriniz : "); scanf("%llu", &isci1.tel_no);
		printf("Dogum gunu giriniz (gun/ay/yil) : "); scanf("%d %d %d", &isci1.dogum.gun, &isci1.dogum.ay, &isci1.dogum.yil);
		*(ptr+kayitsayisi) = isci1;
		kayitsayisi++;
	}
	else
		printf("\n*** Yeterli Hafiza Bulunamadi ***\n");
		
	

}


void kayit_listele() {
	int i,no,secim,bulundu=0;
	isci isci1;
	system("cls");
	printf("Tumunu Listele ==> 1'e bas\nSicile Göre Listele ==> 2'ye bas\n");
	printf("\nSecimini yap : "); scanf("%d", &secim);
	system("cls");

	if (secim == 1) {
		for (i = 0; i < kayitsayisi; i++) {
			isci1 = *(ptr + i);
			printf("\n\n\nAd soyad  : %s %s", isci1.isim, isci1.soyisim);
			printf("\nMemleket  : %s \t\t\t\t Mezuniyet : %s", isci1.memleket, isci1.mezuniyet);
			printf("\nKimlik no : %llu \t\t\t Sicil no  : %d", isci1.kimlik_no, isci1.sicil_no);
			printf("\nDogum     : %d/%d/%d \t\t\t\t Iletisim  : %llu", isci1.dogum.gun, isci1.dogum.ay, isci1.dogum.yil, isci1.tel_no);
		}
	}

	else if (secim == 2) {
		printf("Sicil no gir : "); scanf("%d", &no);

		for (i = 0; i < kayitsayisi; i++) {
			isci1 = *(ptr + i);
			if (no == isci1.sicil_no) {
				bulundu++;
				printf("\n\n\nAd soyad  : %s %s", isci1.isim, isci1.soyisim);
				printf("\nMemleket  : %s \t\t\t\t Mezuniyet : %s", isci1.memleket, isci1.mezuniyet);
				printf("\nKimlik no : %llu \t\t\t Sicil no  : %d", isci1.kimlik_no, isci1.sicil_no);
				printf("\nDogum     : %d/%d/%d \t\t\t\t Iletisim  : %llu", isci1.dogum.gun, isci1.dogum.ay, isci1.dogum.yil, isci1.tel_no);

			}
		}

		if (bulundu == 0)
			printf("\n*** Sicil no bulunamadi ***");

	}

	else
		printf("\n*** HATALI GIRIS ***");


	printf("\n\nBir tusa basana kadar ekranda kalacaktir..");
	getch();
}


void kayit_guncelle() {
	int i, no, bulundu = 0;;
	isci isci1;

	system("cls");
	printf("Bilgilerini guncellemek istediginiz iscinin sicil numarasi : "); scanf("%d", &no);

	for (i = 0; i < kayitsayisi; i++) {
		isci1 = *(ptr + i);

		if (isci1.sicil_no == no) {
			bulundu++;

			printf("Yeni ad giriniz : "); scanf("%s", isci1.isim);
			printf("Yeni soyad giriniz : "); scanf("%s", isci1.soyisim);
			printf("Yeni memleket giriniz : "); scanf("%s", isci1.memleket);
			printf("Yeni mezuniyet bilgisi giriniz : "); scanf("%s", isci1.mezuniyet);
			printf("Yeni kimlik numarasi giriniz : "); scanf("%llu", &isci1.kimlik_no);
			printf("Yeni sicil numarasi giriniz : "); scanf("%d", &isci1.sicil_no);
			printf("Yeni telefon numarasi giriniz : "); scanf("%llu", &isci1.tel_no);
			printf("Yeni dogum gunu giriniz (gun/ay/yil) : "); scanf("%d%d%d", &isci1.dogum.gun, &isci1.dogum.ay, &isci1.dogum.yil);
			
			*(ptr+i) = isci1;
		}
	}

	if (bulundu == 0)
		printf("\n*** Sicil no bulunamadi ***");

	printf("\n\nBir tusa basana kadar ekranda kalacaktir..");
	getch();
}
