#include <stdio.h>
#include <stdlib.h>

int main () {
    int vet[5] = {11, 22, 33, 44, 55};
    int *pi = vet;
    int offset = 3;

    vet[offset] = 88;
    /* *(vet + offset) = 88;
    pi[offset] = 88;
    *(pi + offset) = 88; */ //sono tutte uguali

    /* VIETATO USARE PARENTESI QUADRE */
    for (size_t a = 0; a < 5; a++) {
        printf("Valore %d del vettore --> %d\n", a, *(vet + a));
    }

    /* stampa altermativa del ciclo for di sopra */ 
    for (size_t b = pi; pi < b + 5; pi++) {
        printf("Valore %d del vettore --> %d\n", b, *pi);

    }

    return 0;
}