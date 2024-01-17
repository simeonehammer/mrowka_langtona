#include <stdio.h>
#include <stdlib.h>


enum kierunki
{
        N,
        S,
        W,
        E
};

typedef struct
{
        int x;
        int y;
        enum kierunki kierunek;

} Mrowka;

void wyswietl(int **plansza, Mrowka *mrowka, int m, int n, FILE *out);

void RuchMrowki(Mrowka *mrowka, int **plansza, int m, int n);


