//9. Napisz program, który przy kopiowaniu jednego pliku do drugiego (parametry programu)
//zmienia w pierwszej kolumnie ma³e litery na du¿e, bez u¿ycia funkcji zamieniaj¹cej ma³e
//litery na du¿e dostêpnej w bibliotece C(pozosta³e znaki kopiuje bez zmian).

#include <stdio.h>
#include <stdlib.h>

int main() {
    char znak;
    FILE *plik, *plik2;

    plik=fopen("test1.txt","r");
    plik2=fopen("test2.txt","w");

    znak=fgetc(plik);
    if(znak>=97 && znak<=122)
        znak-=32;
    fprintf(plik2,"%c",znak);
    while(1){
        znak=fgetc(plik);
        if(znak==EOF)
            break;
        if(znak=='\n'){
            fprintf(plik2,"%c",znak);
            znak=fgetc(plik);
            if(znak>=97 && znak<=122)
            znak-=32;
        }
        fprintf(plik2,"%c",znak);
    }

    fclose(plik);
    fclose(plik2);
}