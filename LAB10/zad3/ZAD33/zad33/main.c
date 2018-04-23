#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct book{

    char *imie[1];
    char *nazwisko[1];
    char *tytul[1];
    int numer_katalogowy;
    float cena;

}dane_o_ksiazce;

void wczytaj(char *tab[]);
int main()
{
    int i, ilosc_ksiazek;
    struct book **dane_o_ksiazce;

    printf("Podaj ilosc ksiazek do wpisania: ");
    scanf("%d",&ilosc_ksiazek);


    dane_o_ksiazce =(struct book**) malloc(ilosc_ksiazek*sizeof(struct book*));

    for(i = 0;i < ilosc_ksiazek;i++){
        dane_o_ksiazce[i] = (struct book*) malloc(sizeof(struct book));
    }
    for(i = 0;i < ilosc_ksiazek;i++){
        printf("Podaj imie Autora ksiazki\n");
        wczytaj(dane_o_ksiazce[i]->imie);
        printf("Podaj Nazwisko Autora ksiazki\n");
        wczytaj(dane_o_ksiazce[i]->nazwisko);
        printf("Podaj Tytul ksiazki\n");
        wczytaj(dane_o_ksiazce[i]->tytul);
        printf("Podaj jej numer katalogowy\n");
        scanf("%d", &dane_o_ksiazce[i]->numer_katalogowy);
        printf("Podaj jej cene\n");
        scanf("%f", &dane_o_ksiazce[i]->cena);
    }

printf("
       %s", dane_o_ksiazce[1]->imie[0]);
printf("%s", dane_o_ksiazce[1]->nazwisko[0]);
printf("%s", dane_o_ksiazce[0]->tytul[0]);

return 0;
}

void wczytaj(char *tab[]){

    int length;
    char bufor[201];


        fgets(bufor,201,stdin);
        if(bufor[0]=='\n')
        fgets(bufor,201,stdin);
        //if(bufor[0]=='\n') break;
		length = strlen(bufor);
		bufor[length-1] = bufor[length];   //Pozbycie sie znaku '\n'

		tab[0] = (char*) malloc((length+1)*sizeof(char));

		if( tab[0]  == NULL){

			printf("Blad przydzialu pamieci\n");
			exit(-1);
		}
		strcpy(tab[0] ,bufor);
}












