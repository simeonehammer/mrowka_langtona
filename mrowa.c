#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define BUFFER 50
// LINE_VERTICAL:│
// LINE_HORIZONTAL:─
// LINE_DOWN_RIGHT:┌
// LINE_DOWN_LEFT:┐
// LINE_UP_RIGHT:└
// LINE_UP_LEFT:┘
// SQUARE_WHITE:
// SQUARE_BLACK:█
// ARROW_NORTH_WHITE:△
// ARROW_NORTH_BLACK:▲
// ARROW_EAST_WHITE:▷
// ARROW_EAST_BLACK:▶
// ARROW_SOUTH_WHITE:▽
// ARROW_SOUTH_BLACK:▼
// ARROW_WEST_WHITE:◁
// ARROW_WEST_BLACK:◀

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


void wyswietl(int **plansza,Mrowka *mrowka, int m, int n, FILE *out){
	
	 for (int i = 0; i < m; ++i)
        {
                for (int j = 0; j < n; ++j)
                {
			if ( i == mrowka->y && j == mrowka->x ){
				if(plansza[i][j] == 0){
					switch(mrowka->kierunek)
					{
						case N:
							fprintf(out, "△");
							break;
						case S: 
							fprintf(out, "▽");
							break;
						case W: 
							fprintf(out, "◁");
							break;
						case E: 
							fprintf(out, "▷");
							break;
					}
				} else {
					switch(mrowka->kierunek){
						case N:
                                                        fprintf(out, "▲");
                                                        break;
						case S:
                                                        fprintf(out, "▼");
                                                        break;
						case W:
                                                        fprintf(out, "◀");
                                                        break;
						case E:
                                                        fprintf(out, "▶");
                                                        break;	
					}
				
				} 
			}
                        if(plansza[i][j]==1){
				fprintf(out, "█");
			}else{
				fprintf(out, " ");
			}
                }
                fprintf(out, "\n");
        
	}
}

void RuchMrowki(Mrowka *mrowka, int **plansza, int m, int n)
{
	if (plansza[mrowka->y][mrowka->x] == 0)
	{
		switch (mrowka->kierunek)
		{
		case N:
			mrowka->kierunek = E;
			break;
		case S:
			mrowka->kierunek = W;
			break;
		case W:
			mrowka->kierunek = N;
			break;
		case E:
			mrowka->kierunek = S;
			break;
		default:
			break;
		}
		plansza[mrowka->y][mrowka->x] = 1;
		switch (mrowka->kierunek)
		{
		case N:
			mrowka->y--;
			break;
		case S:
			mrowka->y++;
			break;
		case W:
			mrowka->x--;
			break;
		case E:
			mrowka->x++;
			break;
		}
		if (mrowka->x > n - 1)
		{
			mrowka->x = 0;
		}

		if (mrowka->y > m - 1)
		{
			mrowka->y = 0;
		}

		if (mrowka->x < 0)
		{
			mrowka->x = n - 1;
		}

		if (mrowka->y < 0)
		{
			mrowka->y = m - 1;
		}
	}
	else if (plansza[mrowka->y][mrowka->x])
	{
		switch (mrowka->kierunek)
		{
		case N:
			mrowka->kierunek = W;
			break;
		case S:
			mrowka->kierunek = E;
			break;
		case W:
			mrowka->kierunek = S;
			break;
		case E:
			mrowka->kierunek = N;
			break;
		}
		plansza[mrowka->y][mrowka->x] = 0;
		switch (mrowka->kierunek)
		{
		case N:
			mrowka->y--;
			break;
		case S:
			mrowka->y++;
			break;
		case W:
			mrowka->x--;
			break;
		case E:
			mrowka->x++;
			break;
		}
		if (mrowka->x > n - 1)
		{
			mrowka->x = 0;
		}

		if (mrowka->y > m - 1)
		{
			mrowka->y = 0;
		}

		if (mrowka->x < 0)
		{
			mrowka->x = n - 1;
		}

		if (mrowka->y < 0)
		{
			mrowka->y = m - 1;
		}
	}
}

int main(int argc, char *argv[])
{

	char x = "█";
	int opt;
	int m, n, i;
	char *s = "";
	char *d;

	while ((opt = getopt(argc, argv, "m:n:i:f:d:")) != -1)
	{
		switch (opt)
		{

		case 'm':
			m = atoi(optarg);
			break;
		case 'n':
			n = atoi(optarg);
			break;
		case 'i':
			i = atoi(optarg);
			break;
		case 'd':
			d = optarg;
			break;
		case 'f':
			s = optarg; 
			break;
		case '?':
			printf("Nieznana opcja:: %c\n", optopt);
			break;
		}
	}

	FILE *out;

	if(s == ""){
		out = stdout;
	} else {

		char nazwa_pliku[BUFFER];
		sprintf(nazwa_pliku, "%s.txt", s);
	        out = fopen(nazwa_pliku, "w");	
	}



	Mrowka mrowka = {m / 2, n / 2, 0};

	switch (*d)
	{

	case 'N':
		mrowka.kierunek = N;
		break;
	case 'S':
		mrowka.kierunek = S;
		break;
	case 'W':
		mrowka.kierunek = W;
		break;
	case 'E':
		mrowka.kierunek = E;
		break;
	default:
		printf("BLAD");
		return 1;
	}

	int **plansza = (int **)malloc(m * sizeof(int *));
	for (int i = 0; i < m; i++)
	{
		plansza[i] = (int *)malloc(n * sizeof(int));
	}

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			plansza[i][j] = 0;
		}
	}

	for (int j = 0; j < i; ++j)
	{
		RuchMrowki(&mrowka, plansza, m, n);
	}


	wyswietl(plansza, &mrowka ,m , n, out);


	return 0;
}
