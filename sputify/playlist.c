#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define Nsong 1000

typedef struct playlist {
    int numero;
    char titolo[MAX];
    char autore[MAX]; 
}play;

void apri (FILE *ptr_file); //funzione per l'apertura del file
void lettura (FILE *ptr_file); //funzione per la lettura del file.csv

int main () {
    FILE *ptr_file;

    apri (ptr_file);
    lettura (ptr_file);

    fclose (ptr_file);
    return 0;
}

void apri (FILE *ptr_file) {
    ptr_file = fopen("playlist.csv", "rt");

    if (ptr_file) {
        printf("FILE OK!\n");
    }
    else {
        printf("Errore FILE...\n");
    }
}

void lettura (FILE *ptr_file) {
    play playlist[Nsong];

    int counter = 0;

    char riga[MAX];
    char delimitatori[] = ","; //è il delimitatore nel file.csv 
    char *token;

    //stampo a terminale la playlist
    while(!feof(ptr_file)) {
        fgets(riga, MAX, ptr_file); 

        printf("%s", riga); 
    }

    //lettura delle varie righe
    while (fgets(riga, MAX, ptr_file)) {
        if (counter > 1) {
            token = strtok(riga, delimitatori);
            playlist[counter].numero = atoi(token);

            token = strtok(NULL, delimitatori);
            playlist[counter].titolo = strdup(token);

            token = strtok(NULL, delimitatori);
            playlist[counter].autore = strdup(token);
        }
        counter++;
    }
}