#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct CIAG ciag;

struct CIAG{
    int dlugosc;
    double *cg;
    ciag *next;
};
void nowy_ciag(ciag **poczatek,int *check){

    ciag *tmp;
    int dlugosc,i;
    double *cg;

    system("clear");

    printf("dlugosc: ");
    scanf("%d",&dlugosc);
    getchar();

    if(dlugosc==0){
      *check=0;
    }
    else{

    cg = (double*) malloc(dlugosc*sizeof(double));
    printf("Podaj ciag: ");
    for(i=0;i<dlugosc;i++){
        scanf("%lf",&cg[i]);
    }

    tmp = (ciag*) malloc(sizeof(ciag));

    tmp->next = NULL;
    tmp->dlugosc = dlugosc;
    tmp->cg = cg;

    if(*poczatek != NULL) tmp->next = *poczatek;
    *poczatek = tmp;
    }

}
void spr(ciag *poczatek,double *s_min,ciag **wsk_min, double *s_max, ciag **wsk_max){
    ciag *tmp;
    int i,step=0;
    double mintemp=0,maxtemp=0, srednia_max=0, srednia_min=0;
    tmp = poczatek;
    *wsk_min = poczatek;
    *wsk_max = poczatek;
    if(tmp == NULL) printf("Lista jest pusta");
    else{
            while(tmp!=NULL){
                    srednia_min=0;
                    srednia_max=0;
                    for(i=0;i<tmp->dlugosc;i++){
                        srednia_min+=tmp->cg[i];
                        srednia_max+=tmp->cg[i];

                    }
                srednia_min=srednia_min/tmp->dlugosc;
                srednia_max=srednia_max/tmp->dlugosc;
                if(step==0){
                    mintemp=srednia_min;
                    maxtemp=srednia_max;
                    *s_min=srednia_min;
                    *s_max=srednia_max;
                }
                if(srednia_min<mintemp){
                        mintemp=srednia_min;
                        *wsk_min=tmp;
                        *s_min=mintemp;
                }
                if(srednia_max>maxtemp){
                        maxtemp=srednia_max;
                        *wsk_max=tmp;
                        *s_max=maxtemp;
                }
            tmp = tmp->next;
            step++;
            }
    }
}



void usun(ciag **poczatek){

    ciag *tmp;

    while(*poczatek!=NULL){

        tmp = *poczatek;
        *poczatek = (*poczatek)->next;
        if(tmp->dlugosc) free(tmp->dlugosc);
    free(tmp);
    }
}

int main()
{
    ciag *poczatek= NULL;
    ciag *wsk_min, *wsk_max;
    ciag *tmp;
    int check,i;
    double srednia_min, srednia_max;
    do{
        nowy_ciag(&poczatek,&check);
    }while(check!=0);

    spr(poczatek,&srednia_min,&wsk_min,&srednia_max,&wsk_max);

    tmp=poczatek;
    while(tmp!=NULL){
        if (tmp==wsk_min){
            printf("\nSrednia min ma wartosc %lf Sklada sie z %d elementow, z wyrazow: ",srednia_min,tmp->dlugosc);
            for(i=0;i<tmp->dlugosc;i++) printf("%lf ",tmp->cg[i]);
            break;
        }
    tmp = tmp->next;
    }
    tmp=poczatek;
    while(tmp!=NULL){
        if (tmp==wsk_max){
            printf("\nSrednia max ma wartosc %lf Sklada sie z %d elementow, z wyrazow: ",srednia_max,tmp->dlugosc);
            for(i=0;i<tmp->dlugosc;i++) printf("%lf ",tmp->cg[i]);
            break;
        }
    tmp = tmp->next;
    }

    usun(&poczatek);

    return 0;
}
