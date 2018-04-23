#include <stdio.h>
#include <stdlib.h>

int main()
{
    int s,w,i;
    printf("Podaj liczbe do obliczenia silni\n");
    scanf("%d",&s);
    if((s==0)||(s==1)) w = 1;
    if(s>1){
        w = s;
        for(i = 1;i < s;i++){
           w = w*(s-i);
        }
    }
    printf("wartosc silni jest rowna %d\n",w);
    return 0;
}
