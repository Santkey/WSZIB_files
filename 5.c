#include <stdio.h>

/*
5. Napisz program, który kopiuje plik tekstowy (pierwszy parametr programu ) do drugiego pliku
(drugi parametr programu) w ten sposób, że przy przepisywaniu likwiduje puste linie w pliku
(ma usuwać również linie, które zawierają same spacje) i na końcu skopiowanego pliku podaje liczbę usuniętych linii.
 */

int main() {

    // Otwieramy pliczki
    FILE *input = fopen("test.txt", "r");
    FILE *output = fopen("test2.txt", "w");


    // Przechowujemy aktualny znak, oraz poprzednio zczytany
    char previousChar = 0;
    char currentChar = 0;
    do {
        // Zczytujemy jeden znaczek
        currentChar = (char)fgetc(input);

        if (previousChar != 0) {

            if (previousChar == '\n' && currentChar == '\n') {
                continue;
            }else if(previousChar == ' ' && currentChar == ' '){
                continue;
            }else if(previousChar == ' ' && currentChar == '\n'){
                continue;
            }else if(previousChar == '\n' && currentChar == ' '){
                continue;
            }
        }

        // Je�eli to nie koniec pliku, to zapisz
        if (currentChar != EOF) {
            fprintf(output, "%c", currentChar);
        }
        // Zapami�taj jaki znak teraz zczytali�my
        previousChar = currentChar;

    } while (currentChar != EOF); // End of file

    // Zamykamy pliki
    fclose(input);
    fclose(output);
}
