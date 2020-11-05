#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX 100

typedef struct playlist {
    int numero;
    char titolo[MAX];
    char autore[MAX]; 
    bool riproduci;        //false --> non riprodotta  true --> riprodotta
}play;

int main () {
    FILE *ptr_file;

    ptr_file = fopen("playlist.csv", "rt");

    if (ptr_file) {
        printf("FILE OK!\n\n");
    }
    else {
        printf("Errore FILE...\n\n");
    }

    play playlist[MAX];

    int counter = 0;

    char riga[MAX];
    char delimitatori[] = ","; //è il delimitatore nel file.csv 
    char *token;

    //lettura delle varie righe
    while (fgets(riga, MAX, ptr_file)) {

        token = strtok(riga, delimitatori);
        playlist[counter].numero = atoi(token);

        token = strtok(NULL, delimitatori);
        strcpy (playlist[counter].titolo, token);

        token = strtok(NULL, delimitatori);
        strcpy (playlist[counter].autore, token);

        counter++;
    }

    //stampo la playlist
    for (int b = 0; b < counter; b++) {
        printf("%d - %s - %s\n", playlist[b].numero, playlist[b].titolo, playlist[b].autore);
    } 
    printf("\n");

    int casuale;
    int continua = 0;

   do {
       // ciclo di ripristino di tutte le canzoni
       for (size_t a = 0; a < counter; a++) {
           playlist[a].riproduci = false;
       }
       
        // ciclo per la generazione di un numero casuale e successiva verifica se disponibile
       for (size_t c = 0; c < counter; c++) {
            casuale = rand() % 11;

            for (size_t b = 0; b < counter; b++) { 

                if (casuale == playlist[b].numero && playlist[b].riproduci == false) {
                    printf("Canzone --> %s\nAutore --> %s\n", playlist[b].titolo, playlist[b].autore);

                    playlist[b].riproduci = true;
                }
            }
       }
        
        printf("Riprodurre la playlist?\n\t1 --> riproduci\n\t0 --> termina\n");
        scanf("%d", &continua);

   } while (continua == 1);

    fclose (ptr_file);
    return 0;
}
