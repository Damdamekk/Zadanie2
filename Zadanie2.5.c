#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100

// Struktura przechowująca dane kontaktu
struct Contact {
    char imie[50];
    char nazwisko[50];
    char numerTelefonu[20];
};

// Tablica przechowująca kontakty
struct Contact ksiazkaAdresowa[MAX_CONTACTS];
int liczbaKontaktow = 0;

// Funkcja dodająca nowy kontakt do książki adresowej
void dodajKontakt(char imie[], char nazwisko[], char numerTelefonu[]) {
    if (liczbaKontaktow < MAX_CONTACTS) {
        strcpy(ksiazkaAdresowa[liczbaKontaktow].imie, imie);
        strcpy(ksiazkaAdresowa[liczbaKontaktow].nazwisko, nazwisko);
        strcpy(ksiazkaAdresowa[liczbaKontaktow].numerTelefonu, numerTelefonu);
        liczbaKontaktow++;
        printf("Kontakt został dodany do książki adresowej.\n");
    } else {
        printf("Książka adresowa jest pełna. Nie można dodać nowego kontaktu.\n");
    }
}

// Funkcja wyszukująca kontakt po nazwisku
void znajdzKontakt(char nazwisko[]) {
    int znaleziono = 0;
    for (int i = 0; i < liczbaKontaktow; i++) {
        if (strcmp(ksiazkaAdresowa[i].nazwisko, nazwisko) == 0) {
            printf("Znaleziono kontakt:\n");
            printf("Imię: %s\n", ksiazkaAdresowa[i].imie);
            printf("Nazwisko: %s\n", ksiazkaAdresowa[i].nazwisko);
            printf("Numer telefonu: %s\n", ksiazkaAdresowa[i].numerTelefonu);
            znaleziono = 1;
        }
    }
    if (!znaleziono) {
        printf("Kontakt o nazwisku '%s' nie został znaleziony.\n", nazwisko);
    }
}

// Funkcja usuwająca kontakt po nazwisku
void usunKontakt(char nazwisko[]) {
    int indeksUsunietego = -1;
    for (int i = 0; i < liczbaKontaktow; i++) {
        if (strcmp(ksiazkaAdresowa[i].nazwisko, nazwisko) == 0) {
            indeksUsunietego = i;
            break;
        }
    }
    if (indeksUsunietego != -1) {
        for (int i = indeksUsunietego; i < liczbaKontaktow - 1; i++) {
            ksiazkaAdresowa[i] = ksiazkaAdresowa[i + 1];
        }
        liczbaKontaktow--;
        printf("Kontakt o nazwisku '%s' został usunięty z książki adresowej.\n", nazwisko);
    } else {
        printf("Kontakt o nazwisku '%s' nie istnieje w książce adresowej.\n", nazwisko);
    }
}

// Funkcja wypisująca wszystkie kontakty w książce adresowej
void wypiszKsiazkeAdresowa() {
    printf("Książka adresowa:\n");
    for (int i = 0; i < liczbaKontaktow; i++) {
        printf("Kontakt %d:\n", i + 1);
        printf("Imię: %s\n", ksiazkaAdresowa[i].imie);
        printf("Nazwisko: %s\n", ksiazkaAdresowa[i].nazwisko);
        printf("Numer telefonu: %s\n", ksiazkaAdresowa[i].numerTelefonu);
    }
}

int main() {
    int wybor;
    char imie[50];
    char nazwisko[50];
    char numerTelefonu[20];

    while (1) {
        printf("\nCo chcesz zrobić?\n");
        printf("1. Dodaj nowy kontakt\n");
        printf("2. Znajdź kontakt po nazwisku\n");
        printf("3. Usuń kontakt po nazwisku\n");
        printf("4. Wyświetl wszystkie kontakty\n");
        printf("5. Wyjdź\n");
        printf("Wybierz opcję: ");
        scanf("%d", &wybor);

        switch (wybor) {
            case 1:
                printf("Podaj imię: ");
                scanf("%s", imie);
                printf("Podaj nazwisko: ");
                scanf("%s", nazwisko);
                printf("Podaj numer telefonu: ");
                scanf("%s", numerTelefonu);
                dodajKontakt(imie, nazwisko, numerTelefonu);
                break;
            case 2:
                printf("Podaj nazwisko do wyszukania: ");
                scanf("%s", nazwisko);
                znajdzKontakt(nazwisko);
                break;
            case 3:
                printf("Podaj nazwisko do usunięcia: ");
                scanf("%s", nazwisko);
                usunKontakt(nazwisko);
                break;
            case 4:
                wypiszKsiazkeAdresowa();
                break;
            case 5:
                printf("Dziękujemy. Do widzenia!\n");
                return 0;
            default:
                printf("Nieprawidłowy wybór. Wybierz opcję od 1 do 5.\n");
        }
    }

    return 0;
}
