#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

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

void wyswietl(int **plansza, Mrowka *mrowka, int m, int n, FILE *out)
{

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (i == mrowka->y && j == mrowka->x)
			{
				if (plansza[i][j] == 0)
				{
					switch (mrowka->kierunek)
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
				}
				else
				{
					switch (mrowka->kierunek)
					{
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

			else if (plansza[i][j] == 1)
			{
				fprintf(out, "■");
			}
			else
			{
				fprintf(out, "□");
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

	int opt, r = 0;
	int m, n, i;
	char *s = "";
	char *d;
	char *l = "";

	while ((opt = getopt(argc, argv, "m:n:i:f:d:l:r:")) != -1)
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
		case 'l':
			l = optarg;
			break;
		case 'r':
			r = atoi(optarg);
			break;
		case '?':
			printf("Nieznana opcja:: %c\n", optopt);
			break;
		}
	}

	FILE *out;
	FILE *in;
	Mrowka mrowka;

	if (s == "")
	{
		out = stdout;
	}
	else
	{

		char nazwa_pliku[BUFFER];
		sprintf(nazwa_pliku, "%s.txt", s);
		out = fopen(nazwa_pliku, "w");
	}

	int **plansza = (int **)malloc(m * sizeof(int *));
	for (int i = 0; i < m; i++)
	{
		plansza[i] = (int *)malloc(n * sizeof(int));
	}
	mrowka.x = m / 2;
	mrowka.y = n / 2;

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

	if (r == 0)
	{
		if (strcmp(l, "") == 0)
		{
			for (int i = 0; i < m; ++i)
			{
				for (int j = 0; j < n; ++j)
				{
					plansza[i][j] = 0;
				}
			}
		}
		else
		{
			in = fopen(l, "r");
			char bufor[4];
			char nowa_linia[2];
			for (int i = 0; i < m; ++i)
			{
				for (int j = 0; j < n; ++j)
				{
					if (fgets(bufor, 4, in) != NULL)
					{

						if (strcmp(bufor, "\n") == 0)
						{
							i--;
							break;
						}

						else if (strcmp(bufor, "□") == 0)
						{
							plansza[i][j] = 0;
						}
						else if (strcmp(bufor, "■") == 0)
						{
							plansza[i][j] = 1;
						}
						else if (strcmp(bufor, "△") == 0)
						{
							plansza[i][j] = 0;
							mrowka.kierunek = N;
							mrowka.x = j;
							mrowka.y = i;
						}
						else if (strcmp(bufor, "▷") == 0)
						{
							plansza[i][j] = 0;
							mrowka.kierunek = E;
							mrowka.x = j;
							mrowka.y = i;
						}
						else if (strcmp(bufor, "▽") == 0)
						{
							plansza[i][j] = 0;
							mrowka.kierunek = S;
							mrowka.x = j;
							mrowka.y = i;
						}
						else if (strcmp(bufor, "◁") == 0)
						{
							plansza[i][j] = 0;
							mrowka.kierunek = W;
							mrowka.x = j;
							mrowka.y = i;
						}
						else if (strcmp(bufor, "▲") == 0)
						{
							plansza[i][j] = 1;
							mrowka.kierunek = N;
							mrowka.x = j;
							mrowka.y = i;
						}
						else if (strcmp(bufor, "▶") == 0)
						{
							plansza[i][j] = 1;
							mrowka.kierunek = E;
							mrowka.x = j;
							mrowka.y = i;
						}
						else if (strcmp(bufor, "▼") == 0)
						{
							plansza[i][j] = 1;
							mrowka.kierunek = S;
							mrowka.x = j;
							mrowka.y = i;
						}
						else if (strcmp(bufor, "◀") == 0)
						{
							plansza[i][j] = 1;
							mrowka.kierunek = W;
							mrowka.x = j;
							mrowka.y = i;
						}
					}
				}
			}
		}
	}
	else
	{
		srand(time(NULL));
		int prawdopodobienstwo = r;
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{

				if (rand() % 100 + 1 <= prawdopodobienstwo)
				{
					plansza[i][j] = 1;
				}
				else
				{
					plansza[i][j] = 0;
				}
			}
		}
	}

	for (int j = 0; j < i; ++j)
	{
		RuchMrowki(&mrowka, plansza, m, n);
	}

	wyswietl(plansza, &mrowka, m, n, out);

	return 0;
}
