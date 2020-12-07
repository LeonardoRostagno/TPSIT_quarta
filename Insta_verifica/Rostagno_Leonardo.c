#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

typedef struct tipo {
    char mese[MAX];
    int giorno;
    int ID_post;
    int like;
} Insta;

void spazia () {
    for (size_t a = 0; a < 50; a++) {
        printf("-");
    }
    printf("\n\n");
}

int leggi (FILE *ptr_file, Insta *insta); // funzione per leggere il file

int main () {
    FILE *ptr_file;
    Insta *insta;

    char cicla[MAX]; // array usato per la malloc
    int c = 0; // contatore usato per la malloc

    char nome_mese[MAX]; // nome del mese, lo diamo in imput
    int num_post = 0; // numero dei post
    int num_like = 0; // numero dei like

    ptr_file = fopen("instagram.csv", "rt");

    if (ptr_file) {
        printf("FILE OK...\n");
    }
    else {
        printf("Errore FILE...\n");
    }
    spazia();

    // ciclo che conta il numero di righe del file, usato per la malloc di insta
    while (fgets(cicla, MAX, ptr_file)) {
        c++;
    } 
    insta = (Insta*) malloc ((c - 1) * sizeof(Insta)); // allocamento dinamico in memoria di insta

    ptr_file = fopen("instagram.csv", "rt"); // riapro il file perchè nel ciclo per la malloc il puntatore era arrivato al fondo

    int cont = leggi (ptr_file, insta);
    spazia();

    printf("Inserire il nome di un mese: ");
    scanf("%s", nome_mese);

    // scorro tutto il file
    for (size_t a = 0; a < cont; a++) {
        if (strcmp((insta + a)->mese, nome_mese) == 0) { // controllo se il mese contenuto in (insta + a)->mese sia uguale al mese dato in input
            num_post ++; // aggiorno il numero di post
            num_like += (insta + a)->like; //aggiorno il numero di like
        }
    }
    printf("Nel mese di %s hai postato %d post e hanno ricevuto %d like totali\n", nome_mese, num_post, num_like);

    free(insta);
    fclose(ptr_file);
    return 0;
}

int leggi (FILE *ptr_file, Insta *insta) {
    int cont = 0;

    char riga[MAX]; // array usato per strtok
    char *token; // usato per strtok
    char first[MAX]; // array usato per contenere la prima riga

    fgets(first, MAX, ptr_file); // inserisco in first la prima riga del file

    while (fgets(riga, MAX, ptr_file)) {
        token = strtok(riga, ",");
        strcpy ((insta + cont)->mese, token); // inserisco il valore letto dalla riga precedente in (insta + cont)->mese

        token = strtok(NULL, ",");
        (insta + cont )->giorno = atoi(token); // inserisco il valore letto dalla riga precedente in (insta + cont)->giorno

        token = strtok(NULL, ",");
        (insta + cont )->ID_post = atoi(token); // inserisco il valore letto dalla riga precedente in (insta + cont)->ID_post

        token = strtok(NULL, ",");
        (insta + cont )->like = atoi(token); // inserisco il valore letto dalla riga precedente in (insta + cont)->like

        cont++; // aggiorno di 1 il contatore
    }

    printf("\nLettura FILE completata...\n");

    return cont;
}
