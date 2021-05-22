#include <stdio.h>

/*
 *7. Napisz program, który kopiując podany plik (parametr programu) do innego pliku (drugi
 * parametr programu), każde zdanie zaczyna od nowej linii i dużej litery. Zakładamy, że zdanie kończy
 * się znakiem kropki ‘.’ i spacji. , a na dużą literę zamieniamy tylko małe litery po kropce (inne znaki tj.
 * cyfry, kropki itp. kopiowane są bez zmian).
 */

// program.exe ./input.txt ./output.txt
int main(int argc, char *argv[]) {

    // Otwieramy pliczki
    FILE *input = fopen(argv[1], "r");
    FILE *output = fopen(argv[2], "w");

    // Przechowujemy aktualny znak, oraz poprzednio zczytany
    char previousChar = 0;
    char currentChar = 0;
    // Nieskończona pętla, bo w środku sprawdzam koniec pliku
    while (1) {
        // Zczytujemy jeden znaczek
        currentChar = (char)fgetc(input);
        if (currentChar == EOF) {
            break;
        }

        // Pomijamy nowe linie (sami je wstawiamy)
        if (currentChar == '\n') {
            continue;
        }

        // Jeżeli sekwencja ". " oznacza nową linie, więc ją wstawiamy
        // Zapisujemy poprzedni znak jako nową linie, żeby wiedzieć że trzeba sprawdzić, kolejny warunek
        if (previousChar == '.' && currentChar == ' ') {
            fprintf(output, "\n");
            previousChar = '\n';
            continue;
        }

        // Jeżeli poprzedni znak był nową linią, trzeba sprawdzić i ew. podmienić małą litere na dużą
        if (previousChar == '\n' && currentChar >= 'a' && currentChar <= 'z') {
            // 32 to różnica w tabeli ASCII między małymi literami a dużymi
            currentChar -= 32;
        }

        // Kopiujemy do output
        fprintf(output, "%c", currentChar);

        previousChar = currentChar;
    }

    // Zamykamy pliki
    fclose(input);
    fclose(output);
}