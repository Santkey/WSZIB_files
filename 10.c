/*10. Napisz program, który znajduje w pliku (parametr programu) cyfry, oblicza ich iloczyn i
wypisuje jego wartość na monitorze.*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    char liczba;
    int iloczyn = 1;
    int jd= 0;

    FILE *f1;
    f1 = fopen("pliczek.txt", "r");

    while(1){
      liczba = fgetc(f1);
      if(liczba == EOF)
          break;
      if(liczba >= 48 && liczba <= 57){
         jd= liczba - '0';
        iloczyn *= jd;
        printf("jd");
        }
    }

    printf("iloczyn wynosi %d\n",iloczyn);


    fclose(f1);

    return 0;
}