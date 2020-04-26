#include <stdio.h>
#include <conio.h>

#include <stdio.h>

char StrBilangan[10][10] = { "nol","satu","dua","tiga","empat","lima","enam","tujuh","delapan","sembilan" };

void SaySatuan(char nilai) //0..9
{
	printf("%s",StrBilangan[nilai]);
}

void SayPuluhan(char nilai) // 10..99
{
	if (nilai < 10)
		SaySatuan(nilai);
else
{
		if (nilai == 10)
			printf("sepuluh");
		if (nilai == 11)
			printf("sebelas");
		if (nilai >= 12 && nilai <= 19)
		{
			SaySatuan(nilai % 10);
			printf("belas");
		}
		if (nilai >= 20 && nilai <= 99)
		{
			SaySatuan(nilai / 10);
			printf(" puluh ");
			SaySatuan(nilai % 10);
		}
	}
}

void SayRatusan(int nilai) // 100..999
{
	if (nilai < 100)
		SayPuluhan(nilai);
	else
	{
		if (nilai >= 100 && nilai <= 199)
			printf("seratus ");
		if (nilai >= 200 && nilai <= 999)
		{
			SaySatuan(nilai / 100);
			printf(" ratus ");
		}
		if (nilai % 100 != 0) //untuk menghindari seratus nol
			SayPuluhan(nilai % 100);
	}
}

void SayRibuan(unsigned long nilai) //1000...999999
{
	if (nilai < 1000)
		SayRatusan(nilai);
	else
	{
		if (nilai >= 1000 && nilai <= 1999)
			printf("Seribu ");
		if (nilai >= 2000 && nilai <= 999999)
		{
			SayRatusan(nilai / 1000);
			printf(" ribu ");
		}
		if (nilai % 1000 != 0)
			SayRatusan(nilai % 1000);
	}
}

void SayJuta(unsigned long nilai) //1.000.000 -> 999.999.999
{
	if (nilai < 1000000)
		SayRibuan(nilai);
	else
	{
		SayRatusan(nilai / 1000000);
		printf(" juta ");

		if (nilai % 1000000 != 0)
			SayRibuan(nilai % 1000000);
	}
}

void SayMilyar(unsigned long nilai) // 1.000.000.000 -> 999.999.999.999
{
	if (nilai < 1000000000)
		SayJuta(nilai);
	else
	{
		SayRatusan(nilai / 1000000000);
		printf(" Milyar ");
		if (nilai % 1000000000 != 0)
			SayJuta(nilai % 1000000000);
	}
}

void SayBilangan(unsigned long nilai) // Fungsi pengarah
{
	if (nilai <= 9)
		SaySatuan(nilai);
	if (nilai >= 10 && nilai <= 99)
		SayPuluhan(nilai);
	if (nilai >= 100 && nilai <= 999)
		SayRatusan(nilai);
	if (nilai >= 1000 && nilai <= 999999)
		SayRibuan(nilai);
	if (nilai >= 1000000 && nilai <= 999999999)
		SayJuta(nilai);
	if (nilai >= 1000000000)
		SayMilyar(nilai);
}

void main(void)
{
	
	printf("163 = "); 
	SayBilangan(163); puts("");

	printf("25234 = ");
	SayBilangan(25234); puts("");

	SayBilangan(-1);

	_getch();
}