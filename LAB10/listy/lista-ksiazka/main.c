#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct KSIAZKA ksiazka;

struct KSIAZKA{
    char *imie;
    char *nazwisko;
    char *tytul;
    int nrkat;
    float cena;
    ksiazka *next;
};
ksiazka* nowa_ksiazka(){

    ksiazka *tmp;
    int nrkat;
    float cena;
    char bufor[60];
    char *imie, *nazwisko, *tytul;
    system("cls");
    printf("imie: ");
    if(gets(bufor)!=NULL){
        imie = (char*) malloc(sizeof(char)*(strlen(bufor)));
        strcpy(imie,bufor);
    }
    printf("nazwisko: ");
    if(gets(bufor)!=NULL){
        nazwisko = (char*) malloc(sizeof(char)*(strlen(bufor)));
        strcpy(nazwisko,bufor);
    }
    printf("tytul: ");
    if(gets(bufor)!=NULL){
        tytul = (char*) malloc(sizeof(char)*(strlen(bufor)));
        strcpy(tytul,bufor);
    }
    printf("Podaj Nr Kat i cene: ");
    scanf("%d %f",&nrkat,&cena);

    tmp = (ksiazka*) malloc(sizeof(ksiazka));
    tmp->next = NULL;
    tmp->imie = imie;
    tmp->nazwisko = nazwisko;
    tmp->tytul = tytul;
    tmp->nrkat = nrkat;
    tmp->cena = cena;
    return tmp;
}

void dodaj_ksiazke(ksiazka **poczatek){

    ksiazka *tmp = nowa_ksiazka();

    if(*poczatek != NULL) tmp->next = *poczatek;
    *poczatek = tmp;
}

void drukuj(ksiazka *poczatek){

    ksiazka *tmp;
    system("cls");
    tmp = poczatek;

    if(tmp == NULL) printf("Lista jest pusta");
    else{
            while(tmp!=NULL){

                printf("Autor:%s %s Tytu³:%s Numer Katalogowy:%d Cena: %f\n",tmp->imie,tmp->nazwisko,tmp->tytul,tmp->nrkat,tmp->cena);
                tmp = tmp->next;
            }
    }
    getchar();
}

void usun(ksiazka **poczatek){

    ksiazka *tmp;

    while(*poczatek!=NULL){

        tmp = *poczatek;
        *poczatek = (*poczatek)->next;
        if(tmp->imie) free(tmp->imie);
        if(tmp->nazwisko) free(tmp->nazwisko);
        if(tmp->tytul) free(tmp->tytul);
    free(tmp);
    }
}

void drukuj_menu(ksiazka *poczatek){

    char wybor;
    int i;
    i=1;
    do
    {
        system("cls");
        printf("Menu wyswietlono %d razy\n",i); i++;
        printf("Aby dodac ksiazke, wcisnij 1\n");
        printf("Aby wyswietlic liste ksiazek, wcisnij 2\n");
        printf("Aby usunac liste, wcisnij 3\n");
        printf("Aby wyjsc z programu, wcisnij 4\n");
        scanf("%d",&wybor);
        getchar();
        switch(wybor){
        case 1:{
            dodaj_ksiazke(&poczatek);
            break;}
        case 2:{
            drukuj(poczatek);
            break;}
        case 3:{
            usun(&poczatek);
            break;}}
    }while(wybor!=4);
}


int main()
{
    ksiazka *poczatek = NULL;

    drukuj_menu(poczatek);

    usun(&poczatek);

    return 0;
}
