#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void przydzial(char ***tabliczka,int d);
void wczytaj(char **tabliczka,int d);
void wypisz(char **tabliczka, int d);
void sort(char **tab, int N);

int main()
{
    char **pointer;
    int liczba_wyrazow;


    printf("Podaj Liczbe wyrazow: ");
    scanf("%d",&liczba_wyrazow);

    getchar();

    przydzial(&pointer,liczba_wyrazow);

    wczytaj(pointer,liczba_wyrazow);

    sort(pointer,liczba_wyrazow);

    wypisz(pointer,liczba_wyrazow);

    printf("\nCiag pierwszy %s\nCiag ostatni %s",pointer[0],pointer[liczba_wyrazow-1]);

    return 0;
}

void sort(char **tab, int N){
    char *wie;
    int i, j,pierwszy, drugi;

	for(i=0; i<N-1 ;i++){
		for(j=0; j < N-i-1 ;j++){
    		if(strcmp(tab[j], tab[j+1]) > 0)
            {
	            wie = tab[j];
	            tab[j] = tab[j+1];
	            tab[j+1] = wie;
	        }
		}
	}
}

void wypisz(char **tabliczka, int d){
int i;
    for(i=0;i<d;i++) printf("%s\n",tabliczka[i]);
}

void wczytaj(char **tabliczka,int d){
    int i;
    char bufor[200];
    int length;

  for(i=0;i<d;i++){
            printf("Podaj ciag wyrazow\n");
        if(gets(bufor)!=NULL){
            length = strlen(bufor);
            tabliczka[i] = (char*) malloc(length*sizeof(char));
            strcpy(tabliczka[i],bufor);
        }
    }
}


void przydzial(char ***tabliczka,int d){
    *tabliczka=(char**) malloc(d*sizeof(char*));
}
