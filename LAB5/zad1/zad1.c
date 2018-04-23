#include<stdio.h>
#include<string.h>

int main()
{

	char t[300];
	int f[255], i, imax, fmax, dlugosc;

	for(i = 0;i < 255;i++){
		
		f[i] = 0;

	}
	
	printf("Podaj ciag znaków: ");
	scanf("%s", t);
	dlugosc =  strlen(t);

	for(i = 0; i < dlugosc;i++){
	
		f[((int) t[i])] += 1;
	}
	imax = 0;
	fmax = 0;

	for(i = 0;i < 255;i++){
	
		if( f[i]!=0){
		
			if( f[i] > fmax){
			
				imax = i;
				fmax = f[i];
			}
			
			printf("\n Znak %c wystapil %d razy",i,f[i]);
		}
	}
	
	printf("\nZnak powtarzajacy sie najczesciej to %c\nWystapil on %d razy\n",imax,fmax);
return 0;

}
