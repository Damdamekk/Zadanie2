#include <stdio.h>

int main() {

    int liczba = 10;

    int *wskaznik = &liczba;
    *wskaznik = 20;


    printf("Wartość zmiennej: %d\n", liczba);

    printf("Wartość zmiennej przez wskaźnik: %d\n", *wskaznik);

    return 0;
}