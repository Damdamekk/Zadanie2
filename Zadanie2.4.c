#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STUDENTS 100

// Struktura przechowująca dane studenta
struct Student {
    char imie[50];
    float ocenaKoncowa;
};

// Funkcja sortująca studentów malejąco według oceny końcowej
void sortujStudentow(struct Student *tablica, int rozmiar) {
    for (int i = 0; i < rozmiar - 1; i++) {
        for (int j = 0; j < rozmiar - i - 1; j++) {
            if (tablica[j].ocenaKoncowa < tablica[j + 1].ocenaKoncowa) {
                // Zamiana miejscami
                struct Student temp = tablica[j];
                tablica[j] = tablica[j + 1];
                tablica[j + 1] = temp;
            }
        }
    }
}

int main() {
    // Inicjalizacja generatora liczb pseudolosowych
    srand(time(NULL));

    // Utworzenie tablicy struktur Student i zainicjowanie przykładowymi danymi
    struct Student studenci[MAX_STUDENTS];
    for (int i = 0; i < MAX_STUDENTS; i++) {
        sprintf(studenci[i].imie, "Student%d", i + 1); // Generowanie imienia
        studenci[i].ocenaKoncowa = (float)(rand() % 101) / 10.0; // Losowanie oceny końcowej z zakresu 0.0 - 10.0
    }

    // Wywołanie funkcji sortującej
    sortujStudentow(studenci, MAX_STUDENTS);

    // Wyświetlenie posortowanej listy studentów wraz z ich ocenami
    printf("Posortowana lista studentów:\n");
    for (int i = 0; i < MAX_STUDENTS; i++) {
        printf("Student %d: Imię: %s, Ocena końcowa: %.1f\n", i + 1, studenci[i].imie, studenci[i].ocenaKoncowa);
    }

    return 0;
}
