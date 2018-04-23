#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
   char tab[10];
 //   char bufor;
   int i,l,mnoz;

    int liczby;

   fgets(tab,10,stdin);
    l = strlen(tab);
    mnoz = 1;
    liczby = 0;
    for(i = 0; i<l; i++)
        if(tab[i]!=' '){ liczby = liczby + ((int)tab[i]);
            mnoz=mnoz*10;}


      printf("%d", liczby);

   for( i = 0; i < 5;i++){

   }
    return 0;
}
