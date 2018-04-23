#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct DIAMENT lux;

struct DIAMENT{
    char *id;
    int cena;
};

int **przetwarzanie(lux **diament, int liczba_diam);
lux **gromadzenie(int *liczba_diam);
void obsluga(lux **diament,int **dane, int liczba_diam);
int main()
{
    lux **diament;
    int **dane;
    int liczba_diam;


    diament = gromadzenie(&liczba_diam);
    dane = przetwarzanie(diament, liczba_diam);

    obsluga(diament,dane,liczba_diam);

return 0;
}
void obsluga(lux **diament,int **dane, int liczba_diam){
    int i,ch1,ch2;
    printf("Sposrod diamentow: \n");
    for(i=0;i<liczba_diam;i++)
        printf("Nr: %d ID: %s  Cena: %d\n",i+1,diament[i]->id,diament[i]->cena);
    printf("Wybierz DWA numery: ");
    scanf("%d%d",&ch1,&ch2);

    printf("Cena Twojej konfiguracji to: %d",dane[ch1-1][ch2-2-ch1+1]);
}

int **przetwarzanie(lux **diament, int liczba_diam){

    int **tmp,i,j;

    tmp =(int**) malloc((liczba_diam-1)*sizeof(int*));
    for(i=0;i<liczba_diam-1;i++){

        tmp[i] =(int*) malloc((liczba_diam-i-1)*sizeof(int));
    }

    for(i=0;i<liczba_diam-1;i++){

            for(j=0;j<liczba_diam-1-i;j++)
                tmp[i][j] = diament[i]->cena + diament[j+1+i]->cena;
    }
return tmp;
}

lux **gromadzenie(int *liczba_diam){

    int i;
    lux **tmp;
    char *id;
    int length,cena;
    char bufor[60];
    int len;

    printf("Podaj liczbe diamentow\n");
    scanf("%d",liczba_diam);
    getchar();
    tmp =(lux**) malloc(*liczba_diam*sizeof(lux*));


    for(i=0;i<(*liczba_diam);i++){

        tmp[i] = (lux*) malloc(sizeof(lux));
    }
    for(i=0;i<(*liczba_diam);i++){

        printf("Podaj id diamentu nr %d\n",i+1);

        if(fgets(bufor, sizeof(bufor), stdin) != NULL){
        len = strlen(bufor);
        if(len > 0 && bufor[len-1] == '\n')
        {
            bufor[len-1] = '\0';
        }
        id = (char*)malloc(1+sizeof(char)*(strlen(bufor)));
	    strcpy(id, bufor);
        }else{
             id=NULL;
             exit(-1);
        }
        printf("Podaj cene diamentu nr %d\n",i+1);
        scanf("%d", &cena);
        getchar();


        tmp[i]->id = id;
        tmp[i]->cena=cena;
    }printf("------------------------\n");
return tmp;
}





