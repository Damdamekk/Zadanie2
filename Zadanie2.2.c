#include <stdio.h>


void podwoj(float *ptr) {
    *ptr *= 2;
}

int main() {
    float zmienna = 3.5;

    printf("Wartość zmiennej przed wywołaniem funkcji: %.2f\n", zmienna);


    podwoj(&zmienna);

    printf("Wartość zmiennej po wywołaniu funkcji: %.2f\n", zmienna);

    return 0;
}