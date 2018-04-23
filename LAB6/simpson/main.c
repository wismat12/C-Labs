#include <stdio.h>
#include <math.h>
/*Program liczy pole pod wykresem dla funkcji y=x^2*/
double simpson(double a, double b, int i, double delta);
double f(double x);                                             //zwraca wartosc funkcji

int main()
{
    double a,b,delta;
    printf("Podaj granice przedzialu:\n");
    scanf("%lf%lf",&a,&b);
    printf("Podaj wartosc bledu:");
    scanf("%lf",&delta);
    printf("\nPole pod wykresem jest rowne %.4lf",simpson(a,b,1,delta));
    return 0;
}

double f(double x){

    double y;

    y = pow(x,2);

return y;
}

double simpson(double a, double b, int i, double delta){

    double S,c,S1,S2,suma;

    S = ((b-a)*(f(a) + 4*f(a/2+b/2) + f(b)))/6;
    c = (a+b)/2;
    S1 = ((c-a)*(f(a) + 4*f(a/2+c/2) + f(c)))/6;
    S2 = ((b-c)*(f(c) + 4*f(c/2+b/2) + f(b)))/6;
    suma = S1+S2;

    if((S - suma)<= (delta/i)) return S;

    return ((simpson(a,c,i+1,delta) + simpson(c,b,i+1,delta)));
}
