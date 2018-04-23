#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{

    int dlugosc;
    int *ciag;

}typ_ciag;


void dodajcg(int l_ciagow, int dlugosc_var, typ_ciag **cg){
int i;


    (cg[l_ciagow]->dlugosc)=dlugosc_var;
    cg[l_ciagow]->ciag = (int*) malloc((cg[l_ciagow]->dlugosc)*sizeof(int));
    for(i=0;i<cg[l_ciagow]->dlugosc;i++){
            scanf("%d",&cg[l_ciagow]->ciag[i]);
        }



}
int main()
{   int l_ciagow=0,l=1;
    typ_ciag **cg;
    typ_ciag **tmp;

    cg=NULL;

    //while(l>0){
    //cg =(typ_ciag**)realloc(cg,(l_ciagow+1)*sizeof(typ_ciag*));
    cg = (typ_ciag**) realloc(cg,(l_ciagow+1)*sizeof(typ_ciag*));
    printf("Podaj dlugosc ciagu, Jesli podasz 0 - przerywasz wprowadzanie: ");
    scanf("%d",&l);

   // if(l==0)
   printf("noo");



    dodajcg(l_ciagow,l,cg);
    l_ciagow= l_ciagow+1;
     tmp =(typ_ciag**)realloc(cg,(2)*sizeof(typ_ciag*));
        scanf("%d",&l);
        if (tmp ==NULL) return -1;
        else

    dodajcg(1,2,tmp);
    //}



   // printf("%d",cg[1]->ciag[0]);











return 0;
}
