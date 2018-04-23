#include <stdio.h>
#include <stdlib.h>

int main()
{
    char bufor[200];
    int l;
    fgets(bufor,20,stdin);
    l = strlen(bufor);
    printf("%d",l);
}
