#include <stdio.h>

/*
 * 3. Napisz program, który zlicza zapisane linijki w istniejącym pliku (parametr
 * programu) i zapisuje ich liczbę do innego pliku (drugi parametr programu).
 */

// program.exe ./input.txt ./output.txt
int main(int argc, char *argv[]) {

    // Otwieramy pliczki
    FILE *input = fopen(argv[1], "r");
    FILE *output = fopen(argv[2], "w");

    // Tutaj przechowujemy ile jest linijek (przyjmuje że brak znaków = jedna linijka | tak jak w notepad.exe)
    int lineCount = 1;

    // Tutaj sprawdzam znak po znaku plik
    char singleChar = 0;
    do
    {
        // Pobieram jeden znak
        singleChar = (char)fgetc(input);
        // Jeżeli nowa linia, to policz jom
        if (singleChar == '\n') {
            lineCount++;
        }

        // Powtarzaj do końca pliku
    } while(singleChar != EOF);

    // Zapisz do output
    fprintf(output, "%d", lineCount);
    
    fclose(input);
    fclose(output);
}