#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void funkcja(char **tw);
int main(){
	char **tw;
    tw = (char**) malloc(3*sizeof(char*));
   funkcja(tw);

printf("%s",tw[2]);

free(tw);

return 0;
}
void funkcja(char **tw){
int i, length, n;
char bufor[201];

	for(i = 0;i < 3; i++){

		fgets(bufor,201,stdin);

		length = strlen(bufor);

		tw[i] = (char*) malloc((length+1)*sizeof(char));

		if( tw[i]  == NULL){

			printf("Blad przydzialu pamieci\n");
			exit(-1);
		}


		strcpy(tw[i]  ,bufor);


	}
}
