#include<stdio.h>
#include<string.h>
#include<math.h>

int main(){

 float w[7], t, x;
 
 printf("podaj wspolrzedne wektora: ");
 scanf("%f%f",&w[0],&w[1]);
 x = powf(w[0],2) + powf(w[1],2);
 t = sqrtf(x);
 printf("\nDlugosc podanego wektora jest rowna %f\n",t);

return 0;
 
//kompilacja gcc -o cw4 cw4.c -lm


}
