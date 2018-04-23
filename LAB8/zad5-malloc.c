#include<stdio.h>
#include<string.h>
#include <stdlib.h>

void sortb(char *tab[], int n);

int main(){

const int N = 2;
const int M = 5;

char **tab = (char**) malloc(N*sizeof(char*));
int i;
for(i = 0; i < N; i++)
{
    tab[i] = (char*) malloc(M*sizeof(char));
}

for(i = 0; i < N; i++)
{
    fgets(tab[i], M, stdin);
}

    //sortb(tab, N);

//for(i = 0; i < N; i++)
//{
    printf("%c", tab[1][2]);
//}








// zwolnienie pamieci
for(i = 0; i < 10; i++);
    free(tab[i]);
free(tab);


return 0;
}



void sortb(char *tab[], int N){

	char *wie;
    int i, j;

	for(i=0; i<N-1 ;i++)
		for(j=0; j < N-i-1 ;j++)
    		if(((int) tab[j][0]) > ((int) tab[j+1][0]))
            {
	            wie = tab[j];
	            tab[j] = tab[j+1];
	            tab[j+1] = wie;
	        }
}


