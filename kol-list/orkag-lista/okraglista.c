#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct KOLO Kolo;
struct KOLO
{
    char *nazwa;
    float *x;
    float *y;
    float *r;
    Kolo* next;
};

Kolo* nowe_kolo()
{
	Kolo* kolo;
    int len;
	char bufor[60];
    char *nazwa;
    float *x;
    float *y;
    float *r;

	system("cls");  //"clear" dla unixa
	printf("Nazwa kola: ");
	if(fgets(bufor, sizeof(bufor), stdin) != NULL)
    {
        len = strlen(bufor);
        if(len > 0 && bufor[len-1] == '\n')
        {
            bufor[len-1] = '\0';
        }
        nazwa = (char*)malloc(1+sizeof(char)*(strlen(bufor)));
	    strcpy(nazwa, bufor);
    }
    x = (float*)malloc(sizeof(float));
    printf("Wspolrzedna x srodka kola: ");
    scanf("%f", x);

    y = (float*)malloc(sizeof(float));
    printf("Wspolrzedna y srodka kola: ");
    scanf("%f", y);

    do{
    r = (float*)malloc(sizeof(float));
    printf("Promien kola: ");
    scanf("%f", r);
    if(*r<=0) printf("Podales bledny promien!");
    }while(*r<=0);

    kolo = (Kolo*)malloc(sizeof(Kolo));
	kolo->next = NULL;
	kolo->x = x;
	kolo->y = y;
	kolo->r = r;
	kolo->nazwa = nazwa;

	return kolo;
}

void dodaj_kolo_do_listy(Kolo **glowa)
{
	Kolo *tmp;

	tmp = *glowa;
    if (tmp==NULL){
        *glowa = nowe_kolo();

    }else{
	while (tmp->next != NULL){
        tmp = tmp->next;
	}
	tmp->next = nowe_kolo();
    }

    getchar();
}

void drukuj_liste(Kolo **glowa)
{
	Kolo *tmp;

	system("cls");
	tmp = *glowa;
	if (tmp == NULL)
		printf("Lista jest pusta");
	else
	{
		while (tmp != NULL)
		{
			printf("Okrag(%s) Wspolrzedne: x = (%2.2f), y = (%2.2f) Promien: r = (%2.2f)\n", tmp->nazwa, *(tmp->x), *(tmp->y), *(tmp->r));
			tmp = tmp->next;
		}
	}

}

void wyczysc_liste(Kolo **glowa)
{
	Kolo *tmp;

	while (*glowa != NULL)
	{
		tmp = *glowa;
		*glowa = (*glowa)->next;
        if (tmp->nazwa)
            free(tmp->nazwa);
        if (tmp->x)
            free(tmp->x);
        if (tmp->y)
            free(tmp->y);
        if (tmp->r)
            free(tmp->r);
        free(tmp);

	}
}

void spr(Kolo **glowa,int L_K, char **dane){
    int i,j;
    Kolo *tmp,*tmp22;
    float Wspol_X_odleg_srodkow,Wspol_Y_odleg_srodkow,Odle_od_S1_do_S2,Suma_Rr;

    tmp=*glowa;
    for(j=0;j<L_K-1;j++)
    {
        for(i = 0; i < L_K-1-j; i++)
        {   if (i==0){
            tmp22=tmp->next;

            }
            Wspol_X_odleg_srodkow=*(tmp->x)-*(tmp22->x);
            Wspol_Y_odleg_srodkow=*(tmp->y)-*(tmp22->y);
            Odle_od_S1_do_S2= sqrt(pow(Wspol_X_odleg_srodkow,2)+pow(Wspol_Y_odleg_srodkow,2));
            Suma_Rr=*(tmp->r)+*(tmp22->r);

            if(Suma_Rr==Odle_od_S1_do_S2)
            {
                dane[j][i]='=';

            } else if(Suma_Rr < Odle_od_S1_do_S2)
            {
                dane[j][i]='n';
            }
            else
            {
                dane[j][i]='t';

            }
            tmp22=tmp22->next;
        }
        tmp=tmp->next;
    }
}
char **menu(Kolo **glowa,int *L_K){
	char i;
    char **dane;

	do
	{
		system("cls");
		printf("1. Dodaj kolo do listy\n");
		printf("2. Drukuj liste\n");

		printf("3. Wyczyscl iste\n");
		printf("4. Zakoncz wprowadzanie kol - sprawdzenie przeciecia\n\n");
		printf("Wybierz opcje (0-5): ");
		i = getchar();
		getchar();
		switch(i){
		case '1':{
                dodaj_kolo_do_listy(glowa);
                (*L_K)++;
                break;
		}
		case '2':{
		    drukuj_liste(glowa);
		    break;}
        case '3':{
            wyczysc_liste(glowa);
            break;}
        }
    }while (i != '4');

    dane = (char**) malloc(((*L_K)-1)*sizeof(char*));
    for(i=0;i<(*L_K)-1;i++){
        dane[i] = (char*) malloc(((*L_K)-i-1)*sizeof(char));
    }
    spr(glowa,(*L_K),dane);

    return dane;
}

int main()
{
    Kolo *glowa = NULL;
    int L_K=0, i, j;
    char **dane;

    Kolo *tmp,*tmp22;

    dane = menu(&glowa,&L_K);

    printf("Twoje okregi zapisane w pamieci: \n");

    drukuj_liste(&glowa);

    tmp=glowa;
    for(j=0;j<L_K-1;j++)
    {
        for(i = 0; i < L_K-1-j; i++)
        {   if (i==0){
            tmp22=tmp->next;

            }

            if(dane[j][i]=='=')
            {
               printf("Okrag %s jest styczny zew. z okregiem %s\n",tmp->nazwa,tmp22->nazwa);

            } else if( dane[j][i]=='n')
            {
                printf("Okrag %s nie przecina sie z okregiem %s\n",tmp->nazwa,tmp22->nazwa);
            }
            else
            {
               printf("Okrag %s przecina sie z okregiem %s\n",tmp->nazwa,tmp22->nazwa);

            }
            tmp22=tmp22->next;
        }
        tmp=tmp->next;
    }
    wyczysc_liste(&glowa);

    return 0;
}
