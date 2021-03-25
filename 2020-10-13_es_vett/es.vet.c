#include <stdio.h>
#include <stdlib.h>

int main () {
    int vet[10];
    int a, b;

    int length = sizeof(vet);

    printf("Riempi l'array di valori\n");

    for (a = 0; a <= length; a++) {
        scanf("%d", vet + a);
    }

    printf("Stampo array in corso...\n");

    for (b = 0; b <= length; b++) {
        printf("%d", *(vet + b));
    }

    return 0;
}