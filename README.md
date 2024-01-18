Program symuluje dzialanie mrówki Langtona. Parametry: -i : liczba iteracji, -m : liczba wierszy, -n : liczba kolumn, -d : początkowy kierunek mrówki (N,S,W,E), -f : nazwa pliku do którego zapisana jest planasza po przejściu mrówki Langtona, -l plik z własną planszą (należy dostosować wiersze oraz kolumny do tych podanych w -m i -n, a znaki do tych użytych w porgramie), -r : losowe wygenerowanie planszy (procent na wylosowanie czarnego pola).

kompilacja: cc main.c mrowka.c
Przykładowe wywołanie programu: ./a.out -m 100 -n 100 -i 11000 -d W -f plansza
