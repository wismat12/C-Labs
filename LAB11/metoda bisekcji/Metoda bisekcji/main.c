#include <stdio.h>
#include <stdlib.h>
float f1(float x);
float funkcja(float (*f)(float), float a, float b, float blad);

int main()
{
    int w;

    w = funkcja(f1,0,6,0.1);


printf("%d",w);

return 0;
}


float funkcja(float (*f)(float), float a, float b, float blad){

    float S;

    if((f(a)*f(b)) < 0){


       S = (a+b)/2;
       if((b-a)<=blad) return S;

       if (f(S) == 0 ) return 5;

       if((f(a)*f(S)) < 0 ){ funkcja(f, a, S, blad);}
       if((f(S)*f(b)) < 0 ){ funkcja(f, S, b, blad);}

    }
}

float f1(float x){

    float y;

    y = x - 4;

    return y;
}


