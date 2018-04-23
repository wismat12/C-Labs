#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct DIAMENT lux;
struct DIAMENT{

    char *id;
    int cena;


};

void gromadzenie(lux ***diam,int *liczba_diam);
int main()
{
    lux **diament;
    int liczba_diam;

    gromadzenie(&diament,&liczba_diam);



return 0;
}
void gromadzenie(lux ***diament,int *liczba_diam){
    int i;
    lux *tmp;
    char *id;
    int length,cena;
    char bufor[60];
    printf("Podaj liczbe diamentow\n");
    scanf("%d", liczba_diam);
    getchar();
    *diament =(lux**) malloc((*liczba_diam)*sizeof(lux*));


    for(i=0;i<(*liczba_diam);i++){

        diament[i] = (lux*) malloc(sizeof(lux));
    }
    for(i=0;i<(*liczba_diam);i++){



        printf("Podaj id diamentu nr %d\n",i+1);
        if(gets(bufor)!=NULL){
            length = strlen(bufor);
            id =(char*) malloc(length*sizeof(char));
            strcpy(id,bufor);
        }
        printf("Podaj cene diamentu nr %d\n",i+1);
        scanf("%d", &cena);
        getchar();


        *diament[i]->id = id;
        *diament[i]->cena=cena;
    }


}





