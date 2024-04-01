#include <stdio.h>

struct Point {
    float x;
    float y;
};


void zmienWspolrzedne(struct Point *ptr, float newX, float newY) {
    ptr->x = newX;
    ptr->y = newY;
}


struct Rectangle {
    struct Point topleft; // Lewy górny róg
    struct Point bottomright; // Prawy dolny róg
};


float obliczPole(struct Rectangle rect) {
    float szerokosc = rect.bottomright.x - rect.topleft.x;
    float wysokosc = rect.topleft.y - rect.bottomright.y;
    return szerokosc * wysokosc;
}

float obliczObwod(struct Rectangle rect) {
    float szerokosc = rect.bottomright.x - rect.topleft.x;
    float wysokosc = rect.topleft.y - rect.bottomright.y;
    return 2 * (szerokosc + wysokosc);
}

int main() {

    struct Point punkt = {2.5, 3.5};


    zmienWspolrzedne(&punkt, 5.5, 7.7);

    printf("Zmienione współrzędne punktu: (%.2f, %.2f)\n", punkt.x, punkt.y);


    struct Rectangle prostokat = {{1.0, 4.0}, {6.0, 1.0}};


    float pole = obliczPole(prostokat);
    printf("Pole prostokąta: %.2f\n", pole);

    // Obliczanie obwodu prostokąta
    float obwod = obliczObwod(prostokat);
    printf("Obwód prostokąta: %.2f\n", obwod);

    return 0;
}
