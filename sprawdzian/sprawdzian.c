#include <stdio.h>
#include <stdlib.h>
#include <string.h>         /*Wiśniewski Mateusz 51 wtorek 8:00  wersja C*/

typedef struct PUDELKO pudelko;     /*definiuję strukturę struct PUDELKO jako typ pudelko*/
struct PUDELKO{

    char ID;
    double a;
    double b;
    double c;
    pudelko *next;
};

void wczytaj_dane(pudelko **poczatek, int *Liczba_Pudelek, int *zatrzymaj);
void sprawdz(pudelko *poczatek, int Liczba_Pudelek, char **dane);
int main()
{
    pudelko *poczatek = NULL;
    int i,j;                                        /*iteratory*/
    int zatrzymaj = 1;
    int Liczba_Pudelek = 0;
    pudelko *tmp;                                  /*Zmienne tmp do wyszukania odpowiedniej  pozycji w liście*/
    pudelko *tmp22;
    char **dane;                                    /*Tablica wskaźników do wskaźników na informację o relacji międzi pudełkami*/

    while( zatrzymaj == 1){

        wczytaj_dane(&poczatek,&Liczba_Pudelek,&zatrzymaj);

    }

    dane = (char**) malloc(Liczba_Pudelek*sizeof(char*));       /*Przydział pamięci do tablicy z informacjami o relacji miedzy pudełkami*/
    for(i = 0; i < Liczba_Pudelek - 1 ; i++){

        dane[i] = (char*) malloc((Liczba_Pudelek - 1 - i)*sizeof(char));
    }

    sprawdz(poczatek,Liczba_Pudelek,dane);


    tmp = poczatek;
    for(i = 0; i < Liczba_Pudelek - 1; i++){            /*tmp sa przypisywane tak samo jak przy sprawdzaniu relacji, tylko teraz wypisuję dane*/

        for(j = 0; j < Liczba_Pudelek - 1 - i; j++){

            if(j == 0){

                tmp22 = tmp->next;
            }
                if(dane[i][j]=='='){
                    printf("Prostopadloscian %c o wymiarach %1.1f x %1.1f x %1.1f vs \nProstopadloscian",tmp->ID,tmp->a,tmp->b,tmp->c);
                    printf(" %c o wymiarach %1.1f x %1.1f x %1.1f - nie zmiesci sie!\n",tmp22->ID,tmp22->a,tmp22->b,tmp22->c);
                    printf("--------------------\n");
                } else if (dane[i][j]=='<'){
                    printf("Prostopadloscian %c o wymiarach %1.1f x %1.1f x %1.1f vs \nProstopadloscian",tmp->ID,tmp->a,tmp->b,tmp->c);
                    printf(" %c o wymiarach %1.1f x %1.1f x %1.1f - zmiesci sie!\n",tmp22->ID,tmp22->a,tmp22->b,tmp22->c);
                    printf("--------------------\n");
                } else if (dane[i][j]=='>'){
                    printf("Prostopadloscian %c o wymiarach %1.1f x %1.1f x %1.1f vs \nProstopadloscian",tmp->ID,tmp->a,tmp->b,tmp->c);
                    printf(" %c o wymiarach %1.1f x %1.1f x %1.1f - nie zmiesci sie!\n",tmp22->ID,tmp22->a,tmp22->b,tmp22->c);
                    printf("--------------------\n");
                }

            tmp22 = tmp22->next;
            }

        tmp=tmp->next;
        }


                                        /*Zwolnienie pamięci z listy i tablicy z danymi o polożeniu*/
    while(poczatek!=NULL){

        tmp = poczatek;
        poczatek = poczatek->next;
        if(tmp) free(tmp);
    }
    for(i = 0; i<Liczba_Pudelek-1 ;i++){

        free(dane[i]);
    }
    free (dane);

    return 0;
}
void wczytaj_dane(pudelko **poczatek, int *Liczba_Pudelek, int *zatrzymaj){

    char ID;
    double a;
    double b;
    double c;
    pudelko *tmp;                                  /*Zmienna tmp do przypisania nowego węzła, tmp22 do wyszukania ostatniej pozycji w liście*/
    pudelko *tmp22;

    printf("Podaj ID nowego pudelka (Znak x zatrzymuje wprowadzanie): ");

    scanf("%c",&ID);
    if(ID == 'x')
            *zatrzymaj = 0;
        else{
            getchar();

            (*Liczba_Pudelek)++;
            printf("Podaj wymiar a: ");
            scanf("%lf",&a);
            printf("Podaj wymiar b: ");
            scanf("%lf",&b);
            printf("Podaj wymiar c: ");
            scanf("%lf",&c);
            getchar();

            tmp = (pudelko*) malloc(sizeof(pudelko));    /*Alokacja pamięci pod zmienną tymczasową tmp*/
            tmp->ID=ID;
            tmp->a=a;
            tmp->b=b;
            tmp->c=c;
            tmp->next=NULL;

            if (*poczatek != NULL){                     /*Przypisanie tmp na koniec listy lub na poczatek jesli *poczatek=null*/

                tmp22=*poczatek;

                while(tmp22->next!=NULL){
                    tmp22=tmp22->next;
                }

                tmp22->next = tmp;

            }else{
                *poczatek=tmp;
            }
    }
}
void sprawdz(pudelko *poczatek, int Liczba_Pudelek, char **dane){

    int i,j;
    pudelko *tmp;
    pudelko *tmp22;

    tmp = poczatek;

    for(i = 0; i < Liczba_Pudelek - 1; i++){

        for(j = 0; j < Liczba_Pudelek - 1 - i; j++){            //gdy i=0 i j=0 -Sprawdzam relacje dla pierwszego i drugiego pudełka, itd

            if(j == 0){

                tmp22 = tmp->next;
            }
            if ((tmp->a == tmp22->a)&&(tmp->b == tmp22->b)&&(tmp->c == tmp22->c)){

                dane[i][j] = '=';

            } else if((tmp->a < tmp22->a)&&(tmp->b < tmp22->b)&&(tmp->c < tmp22->c)){

                dane[i][j] = '<';

            } else{

                dane[i][j] = '>';
            }
            tmp22 = tmp22->next;
        }
        tmp=tmp->next;
    }
}
