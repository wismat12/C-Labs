#include <stdio.h>
#include <stdlib.h>

char p[3][3]={{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};

void rysuj(void){

    int i,j;
    for(i=0;i<3;i++){
            if(i==0){
                printf(" _____  _____  _____\n|     ||     ||     |\n");
                    for(j=0;j<3;j++){
                        printf("|  %c  |",p[i][j]);}
                printf("\n|_____||_____||_____|");
            }
            if(i==1){
                printf("\n|     ||     ||     |\n");
                    for(j=0;j<3;j++){
                        printf("|  %c  |",p[i][j]);}
                printf("\n|_____||_____||_____|");
            }
            if(i==2){
                printf("\n|     ||     ||     |\n");
                    for(j=0;j<3;j++){
                        printf("|  %c  |",p[i][j]);}
                printf("\n|_____||_____||_____|\n");
            }
    }
    return;
}

void czyszczenie(void){

    int i,j;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            p[i][j]=' ';}
    }
    return;

}

int rg(char znak){

    int x,y;
    printf("\nPodaj wspolrzedne twojego ruchu: ");
    scanf("%d%d",&x,&y);
        if(x>0&&x<=3&&y>0&&y<=3){
            if(p[x-1][y-1]==' '){
            p[x-1][y-1]=znak;
            return 1;
            }
            else{
            printf("\nPodales zajete wspolrzedne!");
            return 0;}
        }

    else{
            printf("\nPodales zle wspolrzedne!\nOdpowiednie wspolrzedne to 1-3!");
            return 0;}
}

int rgK(char znak){

    int x,y;
    x = (rand() % 3) + 1;
    y = (rand() % 3) + 1;
        if(x>0&&x<=3&&y>0&&y<=3){
            if(p[x-1][y-1]==' '){
            p[x-1][y-1]=znak;
            return 1;
            }
            else return 0;
            
        }
    else return 0;           
}

int spr(){
                if((p[0][0]=='X')&&(p[0][0]==p[0][1])&&(p[0][0]==p[0][2]))return 1;
                if((p[0][0]=='O')&&(p[0][0]==p[0][1])&&(p[0][0]==p[0][2]))return 2;
                if((p[1][0]=='X')&&(p[1][0]==p[1][1])&&(p[1][0]==p[1][2]))return 1;
                if((p[1][0]=='O')&&(p[1][0]==p[1][1])&&(p[1][0]==p[1][2]))return 2;
                if((p[2][0]=='X')&&(p[2][0]==p[2][1])&&(p[2][0]==p[2][2]))return 1;
                if((p[2][0]=='O')&&(p[2][0]==p[2][1])&&(p[2][0]==p[2][2]))return 2;
                if((p[0][0]=='X')&&(p[0][0]==p[1][0])&&(p[0][0]==p[2][0]))return 1;
                if((p[0][0]=='O')&&(p[0][0]==p[1][0])&&(p[0][0]==p[2][0]))return 2;
                if((p[0][1]=='X')&&(p[0][1]==p[1][1])&&(p[0][1]==p[2][1]))return 1;
                if((p[0][1]=='O')&&(p[0][1]==p[1][1])&&(p[0][1]==p[2][1]))return 2;
                if((p[0][2]=='X')&&(p[0][2]==p[1][2])&&(p[0][2]==p[2][2]))return 1;
                if((p[0][2]=='O')&&(p[0][2]==p[1][2])&&(p[0][2]==p[2][2]))return 2;
                if((p[0][0]=='X')&&(p[0][0]==p[1][1])&&(p[0][0]==p[2][2]))return 1;
                if((p[0][0]=='O')&&(p[0][0]==p[1][1])&&(p[0][0]==p[2][2]))return 2;
                if((p[2][0]=='X')&&(p[2][0]==p[1][1])&&(p[2][0]==p[0][2]))return 1;
                if((p[2][0]=='O')&&(p[2][0]==p[1][1])&&(p[2][0]==p[0][2]))return 2;
                 else return 3;
}

int wybor_znaku()
{
    int symbol;
    do
    {
         if(symbol != '\n')
            printf("\nJesli chcesz zagrac jako pierwszy znakiem X, - wpisz 1\nJesli chcesz zagrac jako pierwszy znakiem O, - wpisz 2\n");
        symbol = getchar();
    } while(symbol != '1'  && symbol != '2');
    if(symbol == '1')return 1;
    if(symbol == '2')return 0;
}

int gra(){

    int odp; //OdpowiedŸ z ruchu gracza
    int s;  // OdpowiedŸ z warunku zwyciêstwa
    int r=0; // Numer ruchu
    int a;   // Zmienna do wyboru gracza
    int alfa; // Okresla warunek - komputer - czlowiek
    char x,o; 

	alfa = wybor_gry();
        a = wybor_znaku();
        system("clear");
        if(a==1){
            x='X';
            o='O';}
            else{
                x='O';
                o='X';}
        printf("Jako pierwszy zagrasz %c\n",x);
                    do{
                        do{
                            odp = rg(x);
                        } while(odp==0);
                        system("clear");
                        rysuj();
                        s = spr();
                        if(s==1)break;
                        if(s==2)break;
                        r++;
                            if (r<9){
                                do{
					if(alfa == 1) odp = rg(o);
						else odp = rgK(o);
                                } while(odp==0);
                            system("clear");
                            rysuj();
                            s = spr();
                            if(s==2)break;
                            if(s==1)break;
                            r++;}
                    } while(r<9);
        if(s==1)
        printf("\nGratulacje dla zawodnika  X!\n");
        if(s==2)
        printf("\nGratulacje dla zawodnika O!\n");
        if(s==3)
        printf("\nRemis!!!\n");

return 0;
}

int wybor_gry(){

    int gracz;
    do{
    	if(gracz!='\n')
	printf("\nWitaj w grze kolko i krzyzyk!!!\njesli chcesz zagrac z czlowiekiem - wybierz 1\nJesli chcesz zagrac z komputerem - wybierz 2\n");
    gracz = getchar();
    if(gracz=='1')return 1;
    if(gracz=='2')return 2;
    }while((gracz!='1')&&(gracz!='2'));
}

int gra_ponowna(){

    int w;
        do{
		if(w!='\n')
                printf("\nCzy chcesz zagrac jeszcze raz?\nWycisnij Y lub N\n");
                w=getchar();
            }while((w!='y')&&(w!='n'));

    if(w=='y') return 1;

return 0;
}

int main(void){
  
    do{
        czyszczenie();
	gra();
    }while(gra_ponowna()==1);

return 0;
}


