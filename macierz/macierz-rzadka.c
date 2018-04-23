#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NIEZEROWY niezerowy;
struct NIEZEROWY{
    double element;
    int x;
    int y;
    niezerowy *next;
};
void rzadka(int x, int y, double element, niezerowy **poczatek);
void wyprowadz(int ilosc_w, int ilosc_k, niezerowy *poczatek);
void minmax(niezerowy **min, niezerowy **max, niezerowy *poczatek);

int main(){
    niezerowy *poczatek;
    int ilosc_w, ilosc_k, i, j;
    double **gesta;
    poczatek=NULL;
    niezerowy *min, *max;

    printf("Podaj ilosc wierszy swojej macierzy gestej: \n");
    scanf("%d",&ilosc_w);
    printf("Podaj ilosc kolumn swojej macierzy gestej: \n");
    scanf("%d",&ilosc_k);

    gesta = (double**) malloc(ilosc_w*sizeof(double*));
    for(i=0;i<ilosc_k;i++){
        gesta[i] = (double*) malloc(ilosc_k*sizeof(double));
    }
    printf("Wprowadz wartosci do swojej macierzy gestej:\n");
    for(i=0;i<ilosc_w;i++){ printf("Dla wiersza o indeksie %d: ",i+1);
        for(j=0;j<ilosc_k;j++){
                printf("Kolumna %d: ",j+1);
                scanf("%lf",&gesta[i][j]);
        }
    }
    for(i=0;i<ilosc_w;i++){
        for(j=0;j<ilosc_k;j++){
                if(gesta[i][j]!=0){
                    rzadka(i,j,gesta[i][j],&poczatek);
                }
        }
    }
    wyprowadz(ilosc_w,ilosc_k, poczatek);
    minmax(&min,&max, poczatek);

    printf("Najmniejszy element to %1.1f o wspolrzednych x-%d i y-%d\n",min->element,min->x+1,min->y+1);
    printf("Najwiekszy element to %1.1f o wspolrzednych x-%d i y-%d\n",max->element,max->x+1,max->y+1);



return 0;
}
void rzadka(int x, int y, double element, niezerowy **poczatek){
    niezerowy *tmp,*tmp22;

    tmp = (niezerowy*) malloc(sizeof(niezerowy));
    tmp->x=x;
    tmp->y=y;
    tmp->element=element;
    tmp->next=NULL;
    if( *poczatek!=NULL){
        tmp22=*poczatek;
        while(tmp22->next!=NULL){
            tmp22=tmp22->next;
        }
        tmp22->next = tmp;
    } else
    {
    *poczatek=tmp;
    }
}
void wyprowadz(int ilosc_w, int ilosc_k, niezerowy *poczatek){

    int i,j;
    niezerowy *tmp;

    tmp = poczatek;
    for(i=0;i<ilosc_w;i++){

        for(j=0;j<ilosc_k;j++){

            if(( i == tmp->x)&&( j == tmp->y)){
                printf("%1.1f   ",tmp->element);
                tmp = tmp->next;
            }else
            {
                printf("%1.1f   ",0.0);
            }
        }
        printf("\n");
    }
}
void minmax(niezerowy **min, niezerowy **max, niezerowy *poczatek){
    niezerowy *tmp;
    if(poczatek!=NULL){

        tmp = poczatek;
        *min = tmp;
        *max = *min;
        while(tmp->next!=NULL){
            tmp=tmp->next;
            if((*min)->element>tmp->element) *min = tmp;
            if((*max)->element<tmp->element) *max = tmp;
        }
    }
}
