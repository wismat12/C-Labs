#include<stdio.h>
#include<string.h>

int main(){

 char c1[300],c2[300];
 int f1[255], f2[255], i, d1, d2, a1, a2, licz1, licz2;


 printf("Podaj pierwszy ciag znakow: \n");
 scanf("%s", c1);
 printf("Podaj drugi ciag znakow: \n");
 scanf("%s", c2);
 d1 = strlen(c1);
 d2 = strlen(c2);
 a1 = c1[0];
 a2 = c2[0];
 for(i = 0;i < 255;i++){
	f1[i] = 0;
	f2[i] = 0;
 }
 for(i = 0;i < d1;i++){
 	f1[((int) c1[i])] += 1;
 }
 for(i = 0;i < d2;i++){
	f2[((int) c2[i])] += 1;
 }

 printf("\nZnak pierwszy z pierwszego ciagu to ''%c'',- wystapil on %d razy w ciagu pierwszym i %d razy w ciagu drugim, razem %d", a1, f1[a1], f2[a1], f1[a1] + f2[a1]);
 printf("\nZnak pierwszy z drugiego ciagu to ''%c'',- wystapil on %d razy w ciagu pierwszym i %d razy w ciagu drugim, razem %d\n", a2, f1[a2], f2[a2], f1[a2] + f2[a2]);

return 0;
}
