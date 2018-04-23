#include<stdio.h>
#include<string.h>

int main(){


	int i, w1[2], w2[2], w[2] ;
	
 printf("Podaj wspolrzedne wektora 1\n");
 scanf("%d%d",&w1[0],&w1[1]);
 printf("Podaj wspolrzedne wektora 2\n");
 scanf("%d%d",&w2[0],&w2[1]);

 for(i=0;i<2;i++){

 	w[i] = w1[i] + w2[i];
 }

 printf("Wspolrzedne sumy wektorow 1 i 2 to (%d,%d)\n",w[0],w[1]);

return 0;
}
