#include <stdio.h>

/*
 * 4. Napisz program, który kopiuje plik tekstowy (pierwszy parametr programu ) do
 * drugiego pliku (drugi parametr programu) w ten sposób, że każdy ciąg spacji redukuje
 * do jednej i na końcu pliku podaje liczbę usuniętych spacji.
 */

// program.exe ./input.txt ./output.txt
int main(int argc, char *argv[]) {

    // Otwieramy pliczki
    FILE *input = fopen(argv[1], "r");
    FILE *output = fopen(argv[2], "w");


    // Przechowujemy aktualny znak, oraz poprzednio zczytany
    char previousChar = 0;
    char currentChar = 0;
    do {
        // Zczytujemy jeden znaczek
        currentChar = (char)fgetc(input);


        // Jeżeli nie ma poprzedniego znaku (początek pliku) to pomiń
        if (previousChar != 0) {
            // Jeżeli poprzedni to spacja i aktualny to spacja (dwie spacje pod rząd) to pomiń, bo nie chce dwóch 
            // spacji obok siebie. Nie musze zapisywać do previous, bo to te same znaki.
            if (previousChar == ' ' && currentChar == ' ') {
                continue;
            }
        }

        // Jeżeli to nie koniec pliku, to zapisz
        if (currentChar != EOF) {
            fprintf(output, "%c", currentChar);
        }
        // Zapamiętaj jaki znak teraz zczytaliśmy
        previousChar = currentChar;

    } while (currentChar != EOF); // End of file

    // Zamykamy pliki
    fclose(input);
    fclose(output);
}