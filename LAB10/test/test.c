#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void czytaj(char *tab);
int main(){

char *g;

czytaj(&g);


printf("%s",g);
return 0;

}


void czytaj(char *tab){
    int length;
    char bufor[201];



        fgets(bufor,201,stdin);

        //if(bufor[0]=='\n') break;
		length = strlen(bufor);

		tab = (char*) malloc((length+1)*sizeof(char));

		if( tab == NULL){

			printf("Blad przydzialu pamieci\n");
			exit(-1);
		}


		strcpy(tab,bufor);



	//	printf("%s",tab);

		free(tab);

}








/*
struct book{

    char *imie;
    char *nazwisko;
    char *tytul;
    int numer_katalogowy;
    float cena;

}test;

int main(){
char bufor[201];
 int i, length, n;

fgets(bufor,201,stdin);
length = strlen(bufor);

test.imie = (char*) malloc((length+1)*sizeof(char));
strcpy(test.imie,bufor);

printf("%s\n", test.imie);



return 0;
}






/*
void wczytaj(char *tab);
int main(){

	int ilosc_ksiazek,i, length, n;
	char *tw;


    wczytaj(tw);



return 0;
}

void wczytaj(char *tab){

    int i, length, n;
    char bufor[201];
    n = 0;
    for(i = 0;i < 1; i++){


		fgets(bufor,201,stdin);

        if(bufor[0]=='\n') break;
		length = strlen(bufor);
        n++;
		tab = (char*) malloc((length+1)*sizeof(char));

		if( tab == NULL){

			printf("Blad przydzialu pamieci\n");
			exit(-1);
		}


		strcpy(tab,bufor);


	}


	//for(i = 0;i < n; i++){

		printf("%s",tab);

		free(tab);
	//}

printf("%d\n", n);

}*/


