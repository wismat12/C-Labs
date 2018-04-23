#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define pi 3,1415

int wp(long int al);
int main(){

	int j,i,x,p,dlugosc_hasla,rozmiar_odp,g,y;
	long int al;
	char losowyzly[30], haslo[30], odp[30];

	FILE *plik;
		plik = fopen("polski.txt", "r");

		if (plik==NULL){
		printf("Nie mozna otworzyc pliku\n");
		return 1;}
	srand( time( NULL ) );

	fseek(plik,0,SEEK_END);
	al=ftell(plik);
	printf("\n%ld\n",al);

	p = los(al);
	fseek(plik, p, 0);
	fscanf(plik,"%s", losowyzly);
	x = strlen(losowyzly);
	fseek(plik, p+x, 0);
	fscanf(plik,"%s", haslo);
	dlugosc_hasla = strlen(haslo);
	printf("Haslo to %s, a jego dlugosc jest rowna %d\n",haslo,dlugosc_hasla);

	for (i=0;i<dlugosc_hasla;i++){
		//printf("%d",i+1);
		do{
		g = los(al);
		fseek(plik, g, 0);
		fscanf(plik,"%s", losowyzly);
		y = strlen(losowyzly);
		fseek(plik, y+g, 0);
		fscanf(plik,"%s", odp);
		rozmiar_odp = strlen(odp);

		}while((haslo[i]!=odp[0])||(rozmiar_odp<3));

		for(j=0;j<rozmiar_odp;j++){
		printf("|%c|",odp[j]);}
		printf("\n");
	}


return 0;
}

int los(long int al){
if (al>10) return (rand() % (al - 10));
	else return (rand() % al);
}


