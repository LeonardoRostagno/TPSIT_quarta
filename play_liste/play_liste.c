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
    struct playlist *next; // nodo 
}Play;

void push (Play *head, char *riga) {
    Play *appoggio = head;
    char *token;

    while (appoggio->next != NULL) {
        appoggio = appoggio->next;
    }

    appoggio->next = (Play*) malloc (sizeof(Play));

    token = strtok(riga, ",");
    appoggio->next->numero = atoi(token);

    token = strtok(NULL, ",");
    strcpy (appoggio->next->titolo, token);

    token = strtok(NULL, ",");
    strcpy (appoggio->next->autore, token);

    appoggio->next->riproduci = false;
    appoggio->next->next = NULL;
}

void canzone_uno (Play *head, char *riga) {
    char *token;

    token = strtok(riga, ",");
    head ->numero = atoi(token);

    token = strtok(NULL, ",");
    strcpy (head ->titolo, token);

    token = strtok(NULL, ",");
    strcpy (head ->autore, token);

    head->next = NULL;
}

int leggi (FILE *ptr_file, Play *first_element) { // leggo il file
    int counter = 0;
    char riga[MAX];
    char *token;

    fgets(riga, MAX, ptr_file);
    canzone_uno (first_element, riga);

    //lettura delle varie righe
    while (fgets(riga, MAX, ptr_file)) {

        push (first_element, riga);

        counter++;
    }

    return counter;
}

void random (Play *first_element, int counter) { // mando a random le canzoni da far partire  
    int casuale;
    Play *appoggio;

    for (size_t c = 0; c < counter; c++) {
        do {
            appoggio = first_element;
            casuale = rand() % counter;

            for (size_t b = 0; b < casuale; b++) {
                appoggio = appoggio->next;
            }
        } while (appoggio->next->riproduci);

        appoggio->next->riproduci = true;

        printf("Canzone --> %s\nAutore --> %s\n", appoggio->next->titolo, appoggio->next->autore);
    }
}

int main () {
    FILE *ptr_file;

    ptr_file = fopen("playlist.csv", "rt");

    // verifica se il file esiste
    if (ptr_file) {
        printf("FILE OK!\n\n");
    }
    else {
        printf("Errore FILE...\n\n");
    }

    Play *first_element; // nodo del primo elemento della lista
    first_element = (Play*) malloc (sizeof(Play));

    int counter = leggi (ptr_file, first_element);

    int continua = 0;

    do {
        random(first_element, counter);

        printf("Riprodurre la playlist?\n\t1 --> riproduci\n\t0 --> termina\n");
        scanf("%d", &continua);

   } while (continua == 1);

    free(first_element);
    fclose (ptr_file);
    return 0;
}
