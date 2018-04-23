#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct OSOBA osoba;
struct OSOBA{
    char *nazwisko;
    int rok_ur;
    int licz_d;
    osoba *dziecko_next;
};
osoba add_rodzic();
void dziecko(osoba *rodzic);
void dane(osoba *rodzic, int numer_osoby);
void spr(osoba *rodzic,int *dziecko_max, int *dziecko_no);
int main()
{   int i,numer_osoby=0;
    osoba rodzic[4];
    int dziecko_max=-1,dziecko_no=0;
    for(i=0;i<4;i++) rodzic[i] = add_rodzic();

    dziecko(rodzic);

    dane(rodzic,numer_osoby);

    spr(rodzic,&dziecko_max,&dziecko_no);

    printf("Osoba o nazwisku %s ma najwiecej dzieci (%d)\nCzy istnieje osoba bezdzietna? - ",rodzic[dziecko_max].nazwisko,rodzic[dziecko_max].licz_d);
    if(dziecko_no)printf("tak");
    else printf("nie");

return 0;
}
void spr(osoba *rodzic,int *dziecko_max, int *dziecko_no){
int i;
int t_dziecko_max=-1,licznik;
    for(i=0;i<4;i++){
        if(rodzic[i].licz_d==0) *dziecko_no=1;

            if(rodzic[i].licz_d>t_dziecko_max){
                t_dziecko_max=rodzic[i].licz_d;
                licznik=i;

            }
    }
    *dziecko_max=licznik;
}


void dane(osoba *rodzic, int numer_osoby){
int i,j;
osoba *tmp;
    if(numer_osoby<4){
            i=numer_osoby;
            printf("Nazwisko:%s || Rok urodzenia:%d || Liczba dzieci:%d || Dzieci:\n",rodzic[i].nazwisko,rodzic[i].rok_ur,rodzic[i].licz_d);

            tmp=rodzic[i].dziecko_next;
            for(j=0;j<rodzic[i].licz_d;j++){
                printf("Nazwisko:%s || Rok urodzenia:%d\n",tmp->nazwisko,tmp->rok_ur);
                tmp=tmp->dziecko_next;
            }printf("-------\n");

    dane(rodzic,numer_osoby+1);
    }
}

void dziecko(osoba *rodzic){
    int i,j;
    osoba *tmp;
    osoba *danedotmp;
    for(i=0;i<4;i++){
            tmp=rodzic[i].dziecko_next;
            for(j=0;j<rodzic[i].licz_d;j++){
                tmp->nazwisko=rodzic[i].nazwisko;
                tmp->licz_d=0;
                tmp->dziecko_next=NULL;

                printf("Podaj rok urodzenia dziecka %d (%s): ",j+1,rodzic[i].nazwisko);

                scanf("%d",&tmp->rok_ur);

                tmp = tmp->dziecko_next;
            }
    }
}

osoba add_rodzic(){

    osoba tmp;
    char *nazwisko;
    char bufor[40];
    int rok_ur;
    int licz_d,i;

    osoba *dzieckotmp;

    printf("Podaj nazwisko rodzica: ");
    if(gets(bufor)!=NULL){
        nazwisko =(char*)malloc(strlen(bufor)*sizeof(char));
        strcpy(nazwisko,bufor);
    }
    printf("Podaj rok urodzenia rodzica: ");
    scanf("%d",&rok_ur);
    printf("Podaj liczbe jego dzieci: ");
    scanf("%d",&licz_d);

    tmp.dziecko_next=NULL;

    tmp.nazwisko=nazwisko;
    tmp.rok_ur=rok_ur;
    tmp.licz_d=licz_d;

    for(i=0;i<licz_d;i++){
            dzieckotmp = (osoba*)malloc(sizeof(osoba));
            dzieckotmp->dziecko_next = NULL;
            tmp.dziecko_next = dzieckotmp;
            tmp.dziecko_next = tmp.dziecko_next->dziecko_next;
    }
  //  dziecko = (osoba*)malloc(licz_d*sizeof(osoba));
    getchar();
   // for(i=0;i<licz_d;i++){
   //    dziecko[i] = (osoba*)malloc(sizeof(osoba));
   // }



    //tmp.dziecko=dziecko;

    return tmp;
}

