#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct
{
    char *name;
    float *x;
    float *y;
    float *r;
}Okrag;

Okrag* dodaj_okrag()
{
    Okrag* tmp;
    char nbufor[10];
    char *name;
    float *x, *y, *r;
    printf("Podaj nazwê okrêgu: \n");
    getchar();
    if(gets(nbufor) != NULL)
    {
        name = (char*)malloc(strlen(nbufor)*sizeof(char));
        strcpy(name, nbufor);
    }
    printf("Podaj wspó³rzêdn¹ x œrodka okrêgu: \n");
    x = (float*)malloc(sizeof(float));
    scanf("%f", x);
    printf("Podaj wspó³rzêdn¹ y œrodka okrêgu: \n");
    y = (float*)malloc(sizeof(float));
    scanf("%f", y);
    printf("Podaj promieñ r okrêgu: \n");
    r = (float*)malloc(sizeof(float));
    scanf("%f", r);
    tmp = (Okrag*)malloc(sizeof(Okrag));
    tmp->name = name;
    tmp->x = x;
    tmp->y = y;
    tmp->r = r;
    return tmp;
}
void wczytaj(Okrag **okrag,int n){

    int i;

    for(i = 0; i < n; i++)
    {
        okrag[i] = dodaj_okrag();
        //printf("Okr¹g numer %d: %s %f %f %f \n", i+1, okrag[i]->name, *(okrag[i]->x), *(okrag[i]->y), *(okrag[i]->r));
    }
}
void spr(Okrag **okrag, int n, int **dane){
    int i,j;
    float Sx,Sy,D,RR;


    for(j=0;j<n-1;j++)
    {
        for(i = 0; i < n; i++)
        {
            if(i > j)
            {
            Sx=*(okrag[j]->x)-*(okrag[i]->x);
            Sy=*(okrag[j]->y)-*(okrag[i]->y);
            D=sqrt(Sx*Sx+Sy*Sy);
            RR=*(okrag[j]->r)+*(okrag[i]->r);
            if(D<=RR)
            {
                dane[j][i-j-1]=1;
                printf("%f <= %f \n", D, RR);
            }
            else
            {
                dane[j][i-j-1]=0;
                printf("%f > %f \n", D, RR);
            }
            }
        }
    }
}
int main()
{
    int n, i, j;
    Okrag **okrag;
    int **dane;

    system("clear");
    printf("WprowadŸ liczbê okrêgów: \n");
    scanf("%d", &n);
    okrag = (Okrag**)malloc(n*sizeof(Okrag*));
    dane = (int**)malloc((n-1)*sizeof(int*));
    for(i = 0; i < n-1; i++)
    {
        dane[i] = (int*) malloc((n-i-1)*sizeof(int));
    }
    for(i = 0; i < n-1; i++)
    {
        for(j = 0; j < n-i-1; j++)
        {
            dane[i][j] = 2;
        }
    }
    wczytaj(okrag,n);
    spr(okrag,n,dane);
    for(i = 0; i < n; i++)
    {

       printf("Okr¹g numer %d: %s %f %f %f \n", i+1, okrag[i]->name, *(okrag[i]->x), *(okrag[i]->y), *(okrag[i]->r));
    }

    for(i = 0; i < n-1; i++)
    {
        for(j = 0; j < n-i-1; j++)
        {
            printf("%s-%s: %d \n", okrag[i]->name, okrag[j+i+1]->name, dane[i][j]);
        }
    }

    return 0;
}
