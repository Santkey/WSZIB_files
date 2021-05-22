#include <stdio.h>

/*
 *2. Napisz program, który wyświetla na monitorze liczbę wystąpień cyfr i małych liter
 * (każdej osobno) w podanym pliku (parametr programu).
 */

// program.exe ./input.txt
int main(int argc, char *argv[]) {

    // Otwieramy pliczek
    FILE *input = fopen(argv[1], "r");

    int numberCount[10];
    for (int i = 0; i < 10; i++) {
        numberCount[i] = 0;
    }

    int smallCharsCount[30];
    for (int i = 0; i < 30; i++) {
        smallCharsCount[i] = 0;
    }

    // Tutaj sprawdzam znak po znaku plik
    char singleChar = 0;
    do
    {
        // Pobieram jeden znak
        singleChar = (char)fgetc(input);

        // Jeżeli cyfra, zwieksz o jeden
        if (singleChar >= '0' && singleChar <= '9') {
            // Zapisz w odpowiednim indeksie
            int index = singleChar - '0';
            numberCount[index]++;
        }

        // Jeżeli cyfra, zwieksz o jeden
        if (singleChar >= 'a' && singleChar <= 'z') {
            // Zapisz w odpowiednim indeksie
            int index = singleChar - 'a';
            smallCharsCount[index]++;
        }

        // Powtarzaj do końca pliku
    } while(singleChar != EOF);

    // Wypisz ponownie
    printf("Cyfry:\n");
    for (int i = 0; i < 10; i++) {
        // Ale tylko jeżeli wystąpił
        if (numberCount[i] > 0) {
            // Tam odejmowaliśmy, tu dodajemy żeby wrócić do tego samego znaku
            char numberChar = '0' + i;
            printf("%c: %d\n", numberChar, numberCount[i]);
        }
    }

    // Wypisz ponownie
    printf("Male litery:\n");
    for (int i = 0; i < 30; i++) {
        // Ale tylko jeżeli wystąpił
        if (smallCharsCount[i] > 0) {
            char smallChar = 'a' + i;
            // Tam odejmowaliśmy, tu dodajemy żeby wrócić do tego samego znaku
            printf("%c: %d\n", smallChar, smallCharsCount[i]);
        }
    }

    // Zamykamy plik
    fclose(input);
}