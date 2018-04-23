#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char ID;
    double a,b,c;
}pudlo;

pudlo *dodaj();
void spr(pudlo **pudelko,int L_P, char **dane);
int main()
{
    int i,j;
    int L_P;
    pudlo **pudelko;
    char **dane;

    printf("Podaj liczbe prostop: \n");
    scanf("%d",&L_P);
    getchar();
    dane = (char**)malloc(L_P*sizeof(char*));
    for(i=0;i<L_P-1;i++){
        dane[i] = (char*) malloc((L_P-i-1)*sizeof(char));
    }
    pudelko = (pudlo**)malloc(L_P*sizeof(pudlo*));
    for(i=0;i<L_P;i++){
        pudelko[i] = dodaj();
    }
    spr(pudelko,L_P,dane);

    for(j=0;j<L_P-1;j++)
        {
            for(i = 0; i < L_P-1-j; i++)
            {

            printf("Prostopadloscian %c  %c  od %c\n",pudelko[j]->ID,dane[j][i],pudelko[i+1+j]->ID);

            }
        }
     for(j=0;j<L_P-1;j++)
            for(i = 0; i < L_P-1-j; i++) free(dane[j][i]);
            free(dane);
     for(i=0;i<L_P;i++)
       free(pudelko[i]);
     free(pudelko);




    return 0;
}
pudlo *dodaj(){

    char ID;
    double a,b,c;
    pudlo *tmp;
    printf("Podaj ID: ");
    scanf("%c",&ID);
    printf("Podaj wymiary a b c : ");
    scanf("%lf%lf%lf",&a,&b,&c);
    getchar();
    tmp = (pudlo*)malloc(sizeof(pudlo));
    tmp->ID=ID;
    tmp->a=a;
    tmp->b=b;
    tmp->c=c;
    return tmp;
}

void spr(pudlo **pudelko,int L_P, char **dane){
    int i,j;


    for(j=0;j<L_P-1;j++)
    {
        for(i = 0; i < L_P-1-j; i++)
        {

            if((pudelko[j]->a)<(pudelko[i+1+j]->a)&&(pudelko[j]->b)<(pudelko[i+1+j]->b)&&(pudelko[j]->c)<(pudelko[i+1+j]->c))
            {
                dane[j][i]='<';
            }
            else
            {
                dane[j][i]='>';

            }
        }
    }
}



