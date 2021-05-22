/* 8.Napisz program, który porównuje pierwsze znaki w kolejnych liniach dwóch plików
(parametry programu) i wypisuje na monitorze numery linii, które zaczyna³y siê od tego
samego znaku oraz powtarzaj¹cy siê w nich pierwszy znak.(Je¿eli pliki maj¹ ró¿n¹ liczbê
wierszy, to "nadmiarowe" wiersze d³u¿szego pliku nie s¹ analizowane).*/


#include <stdio.h>
#include <stdlib.h>


int main(){
    char znak1, znak2; // stworzenie dwoch zmiennych typu char do ktorej przypisywane beda znaki
    int wiersz = 1; // stworzenie zmiennej typu int ktora posluzy do wypisywania wiersza w ktorym znaki powtorzyly sie
    FILE *plik, *plik2; // wskazniki do pliku

    // jesli nie da sie otworzyc to zamknij
    if( (plik = fopen("test1.txt","r")) == NULL){
        printf("Nie mozna otworzyc pliku"); // jesli nie mozna otworzyc to zakoncz
        exit(1);
    }
    if( (plik2 = fopen("test2.txt","r")) == NULL){
        printf("Nie mozna otworzyc pliku"); // jesli nie mozna otworzyc to zakoncz
        exit(1);
    }

    while(!( (znak1 = getc(plik)) == EOF || (znak2 = getc(plik2)) == EOF) ){ // Pobieraj znaki z plików dopóki któryœ z plików siê nie skoñczy
        if(znak1 == znak2) {   //Jeœli pierwsze znaki w liniach s¹ równe
            printf("Wiersz: %d, Znak: %c\n", wiersz, znak1); // wypisz w ktorym wierszu i jaki znak jest taki sam
        }
        ++wiersz;  // zwieksz zmienna wiersz
        while((znak1 = getc(plik)) != '\n' || znak1 != EOF)); // dwie petle while majace na celu przeskoczenie kolejnych znakow az do natrafienia na nowa linie
        while((znak2 = getc(plik2)) != '\n' || znak2 != EOF)); // lub na koniec pliku
    }
    fclose(plik); // zamknij oba pliki
    fclose(plik2);

}
