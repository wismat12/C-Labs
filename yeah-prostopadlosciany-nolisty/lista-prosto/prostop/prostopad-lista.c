#include <stdio.h>
#include <stdlib.h>
typedef struct PUDLO pudlo;

 struct PUDLO{
    char ID;
    double a,b,c;
    pudlo *next;
};

void dodaj(pudlo **poczatek, int *L_P, int *check);
void spr(pudlo *poczatek,int L_P, char **dane);
int main()
{
    int i,j;
    int L_P=0;
    int check=1;

    pudlo *tmp,*tmp22;

    char **dane;
    pudlo *poczatek=NULL;

    while(check!=0){

            dodaj(&poczatek,&L_P, &check);
    }


    dane = (char**)malloc((L_P-1)*sizeof(char*));
    for(i=0;i<L_P-1;i++){
        dane[i] = (char*) malloc((L_P-i-1)*sizeof(char));
    }

    spr(poczatek,L_P,dane);

    tmp=poczatek;

     for(j=0;j<L_P-1;j++)
    {
        for(i = 0; i < L_P-1-j; i++)
        {    if (i==0){
            tmp22=tmp->next;

            }
            printf("Prostopadloscian %c  %c  %c\n",tmp->ID,dane[j][i],tmp22->ID);


            tmp22=tmp22->next;
        }
        tmp=tmp->next;
    }




    while(poczatek!=NULL){

        tmp = poczatek;
        poczatek = poczatek->next;
        if(tmp) free(tmp);
    }
    for(i=0;i<L_P-1;i++){

        free(dane[i]);
    }
    free (dane);



    return 0;
}
void dodaj(pudlo **poczatek, int *L_P, int *check){

    char ID;
    double a,b,c;
    pudlo *tmp,*tmp22;

    printf("Podaj ID stop wpisujac x: ");
    scanf("%c",&ID);
    if(ID=='x') *check = 0;
        else{
    getchar();
    (*L_P)++;
    printf("Podaj wymiary a b c : ");
    scanf("%lf%lf%lf",&a,&b,&c);
    getchar();

    tmp = (pudlo*) malloc(sizeof(pudlo));
    tmp->ID=ID;
    tmp->a=a;
    tmp->b=b;
    tmp->c=c;
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
}

void spr(pudlo *poczatek,int L_P, char **dane){
    int i,j;
    pudlo *tmp,*tmp22;

    tmp=poczatek;


    for(j=0;j<L_P-1;j++)
    {
        for(i = 0; i < L_P-1-j; i++)
        {   if (i==0){
            tmp22=tmp->next;
            //for (g=0;g<j+1;g++) tmp22 = tmp22->next;
            }
            if((tmp->a)==(tmp22->a)&&(tmp->b)==(tmp22->b)&&(tmp->c)==(tmp22->c))
            {
                dane[j][i]='=';

            } else if((tmp->a)<(tmp22->a)&&(tmp->b)<(tmp22->b)&&(tmp->c)<(tmp22->c))
            {
                dane[j][i]='<';
            }
            else
            {
                dane[j][i]='>';

            }
            tmp22=tmp22->next;
        }
        tmp=tmp->next;
    }
}



