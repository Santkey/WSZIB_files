#include <stdio.h>

/*
 * 6. Napisz program, który kopiuje podany plik (parametr programu) do innego pliku
 * (drugi parametr programu) w wierszach zawierających po 20 znaków i na końcu
 * każdego z tych wierszy dopisuje znak ‘*’.(Mamy otrzymać równą kolumnę o szerokości
 * 20 + '*').
 */

// program.exe ./input.txt ./output.txt
int main(int argc, char *argv[]) {

    // Otwieramy pliczki
    FILE *input = fopen(argv[1], "r");
    FILE *output = fopen(argv[2], "w");

    int charsCountBuffer = 1;

    // Przechowujemy aktualny znak, oraz poprzednio zczytany
    char currentChar = 0;
    // Nieskończona pętla, bo w środku sprawdzam koniec pliku
    while (1) {
        // Zczytujemy jeden znaczek
        currentChar = (char)fgetc(input);
        if (currentChar == EOF) {
            break;
        }

        // Jeżeli nowa linia, pomiń (sam je wstawiam)
        if (currentChar == '\n') {
            continue;
        }

        // Kopiujemy tekst do drugiego pliku
        fprintf(output, "%c", currentChar);

        // Jeżeli naliczyliśmy 20 znaków, wstaw *, nową linie oraz wyzeruj buFort.
        if (charsCountBuffer == 20) {
            fprintf(output, "*\n");
            charsCountBuffer = 0;
        }

        charsCountBuffer++;
    }

    // Zamykamy pliki
    fclose(input);
    fclose(output);
}