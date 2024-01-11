#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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

enum kierunki{
	GORA,
	DOL,
	PRAWO,
	LEWO
};

typedef struct {
	int x;
	int y;
	enum kierunki kierunek;

} Mrowka;


int main(int argc, char *argv[]){

	char x = "█";
	int opt;
	int m, n, i;
	char *s;

    	while ((opt = getopt(argc, argv, "m:n:i:f:d:")) != -1) {
        	switch (opt) {

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
			d 
            	case 'f':
                	s = optarg;
			break;
            	case '?':
			printf("Nieznana opcja:: %c\n", optopt);
                	break;
        	}
    	}

	Mrowka mrowka = {m/2, n/2, 0};

	
	switch(d){
	
		case "GORA": 
			mrowka.kierunek = GORA;
			break;
		case "DOL":
			mrowka.kierunek = DOL;
			break;
		case "LEWO":
			mrowka.kierunek = LEWO;
			break;
		case "PRAWO"
			mrowka.kierunek = PRAWO;
			break;
		default
			printf("BLAD");
			return 1;
	}


    	int **plansza = (int**)malloc(m * sizeof(int *));
	for(int i = 0; i < m; i++) {
		plansza[i] = (int *)malloc(n * sizeof(int));
	}

	for (int i = 0; i < m; ++i) {
        	for (int j = 0; j < n; ++j) {
            		plansza[i][j] = 0;
        	}
    	}

	

	





    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d", plansza[i][j]);
        }
	printf("\n");
    }

    return 0;
}








