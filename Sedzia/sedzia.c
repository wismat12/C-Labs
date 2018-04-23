#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct DANE_SEDZIA dane_sedzia;
typedef struct LISTA lista;

struct DANE_SEDZIA{
    char *nazwisko;
    int *ID;
};

struct LISTA{
    dane_sedzia *sedzia;
    lista *next;
};


void dodaj_nowy_wezel(lista **poczatek){

     lista *tmp;

     tmp =(lista*)malloc(sizeof(lista));
     tmp->next=NULL;

     if(*poczatek!=NULL) tmp->next = *poczatek;
     *poczatek = tmp;
}
dane_sedzia *czytajdane(int *liczba_sedziow){


     dane_sedzia *dtmp;
     char *nazwisko;
     int *ID,len;
     char bufor[60];

     printf("PPodaj ID sedziego [1-50] : \n");

     ID = (int*)malloc(sizeof(int));
     scanf("%d",ID);
     if (*ID == 0 ){
        return NULL;
     }
     (*liczba_sedziow)++;
     getchar();
     printf("Podaj nazwisko sedziego o ID  (%d): \n",*ID);

     if(fgets(bufor,sizeof(bufor),stdin)!=NULL){
        len = strlen(bufor);
        if(len>0 && bufor[len-1]=='\n') bufor[len-1] = '\0';
     nazwisko =(char*) malloc((1+strlen(bufor))*sizeof(char));
     strcpy(nazwisko,bufor);
     }

     dtmp =(dane_sedzia*)malloc(sizeof(dane_sedzia));
     dtmp->nazwisko = nazwisko;
     dtmp->ID = ID;

     return dtmp;
}
int **przydziel_sedziego(lista *poczatek, int sedziowie, int nd){

    int **tmp;
    lista *tmplisty;
    int losoweID;

    int i,j,g;



    tmp =(int**) malloc((nd-1)*sizeof(int*));
    for(i=0;i<nd-1;i++){

        tmp[i] =(int*) malloc((nd-i-1)*sizeof(int));
    }


    for(i=0;i< nd-1 ;i++){

            for(j=0;j< nd-1-i ;j++){

                        losoweID = (rand() % sedziowie);
                        tmplisty = poczatek;



                        for(g=0;g<losoweID;g++) tmplisty=tmplisty->next;


            tmp[i][j] = *(tmplisty->sedzia->ID);
            }
    }


return tmp;

}
void info(lista *poczatek, int **obszar, int nd){

    lista *tmplisty;
    int ID_doszukania;

    int i,j;

    srand( time( NULL ) );


    for(i=0;i< nd-1 ;i++){

            for(j=0;j< nd-1-i ;j++){
            tmplisty = poczatek;
            ID_doszukania = obszar[i][j];
                        while((tmplisty!=NULL)&&((*tmplisty->sedzia->ID)!=ID_doszukania)){
                        tmplisty=tmplisty->next;
                        }
            printf("Druzyna %d zagra z druzyna %d - Sedzia to %s o ID (%d))\n",i+1,j+2+i, tmplisty->sedzia->nazwisko,(*tmplisty->sedzia->ID));

            }
    }




}

int main()
{
    lista *poczatek=NULL;
    lista *tmp;
    int nd;
    int **obszar;
    int liczba_sedziow=0;
    int i;


    dane_sedzia *pomocniczy=NULL;
    printf("Podaj liczbe druzyn: "); scanf("%d",&nd);
    while(1){

      pomocniczy = czytajdane(&liczba_sedziow);
      if (pomocniczy==NULL) break;
        else{
            dodaj_nowy_wezel(&poczatek);
            poczatek->sedzia = pomocniczy;
        }
    }

    obszar = przydziel_sedziego(poczatek,liczba_sedziow,nd);

    info(poczatek,obszar,nd);





    for(i=0;i<nd-1;i++){

        free(obszar[i]);
    }
    free (obszar);

    while (poczatek != NULL)
	{
		tmp = poczatek;
		poczatek = poczatek->next;
        //if (tmp->sedzia->nazwisko)
            free(tmp->sedzia->nazwisko);
        //if (tmp->sedzia->ID)
            free(tmp->sedzia->ID);
        //if (tmp->sedzia)
            free(tmp->sedzia);
        //if (tmp)
            free(tmp);
	}




return 0;
}
