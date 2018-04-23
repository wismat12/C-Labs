#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void wczytaj(char *tab);
int main(){

	int i, length, n;

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
		tab[i] = (char*) malloc((length+1)*sizeof(char));

		if( tab[i] == NULL){

			printf("Blad przydzialu pamieci\n");
			exit(-1);
		}


		strcpy(tab[i],bufor);


	}


	for(i = 0;i < n; i++){

		printf("%s",tab[i]);

		free(tab[i]);
	}

printf("%d\n", n);

}


