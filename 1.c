#include <stdio.h>

/*
 * 1. Napisz program, który wpisuje do pliku (parametr programu) 40 znaków w wierszach
 * 5-cio znakowych. Przy czytaniu ignoruje znak ‘*’ i ‘.’ (one nie są wliczane do 40 znaków)
 */

int main(int argc, char *argv[]) {

    // Otwieram plik argv[1] (parametr uruchomienia programu) w trybie (w)rite
    FILE *file = fopen(argv[1], "w");

    // Pętla się wykonuje dopuki wpisane bedzie 40 znaków
    int count = 1;
    while (count <= 40)
    {
        // Wczytuje znak
        char znak = 0;
        printf("\nPodaj znak:");
        scanf(" %c", &znak);

        // Jeżeli * lub . to pomiń
        if (znak == '*' || znak == '.') {
            continue;
        }

        // Wpisuje znak do pliku
        fprintf(file, "%c", znak);

        // Co 5 znaków wpisz nową linie ("w wierszach 5-cio znakowych")
        if (count % 5 == 0) {
            fprintf(file, "\n");
        }

        count++;
    }

    // Zamknięcie pliku (ważne!)
    fclose(file);
}