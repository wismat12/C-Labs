#include <stdio.h>
#include <stdlib.h>
float f1(float x);
float funkcja(float (*f)(float), float a, float b, float blad,float *tm);

int main()
{
    float w,l;

    l = funkcja(f1,0,6,0.1,&w);


printf("%f   %f",w,l);

return 0;
}


float funkcja(float (*f)(float), float a, float b, float blad,float *tm){

    float s;

    if((f(a)*f(b))<0){
       s = (a+b)/2;

       if((b-a)<=blad) {*tm =s; return s;}

       if (f(s) == 0 ) return s;

       if((f(a)*f(s)) < 0 ){ return funkcja(f, a, s, blad,tm);}
       if((f(s)*f(b)) < 0 ){ return funkcja(f, s, b, blad,tm);}

    }
}

float f1(float x){

    float y;

    y = x - 4;

    return y;
}


