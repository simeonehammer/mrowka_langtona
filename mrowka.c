#include "mrowka.h"



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


