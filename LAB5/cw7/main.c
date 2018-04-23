#include <stdio.h>
#include <stdlib.h>
#include<strings.h>

int main()
{
    char tab[10];
    int t[10],i,p;
    printf("Wprowadz dane do tablicy:\n");
    scanf("%s", tab);
for(i=0;i<10;i++){
   t[i] = int tab[i]-48;

    printf("%d",t[i]);

}
    return 0;
}
