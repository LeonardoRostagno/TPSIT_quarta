#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

void Encoding(char* string);  //--> funzione per l'Encoding
void Decoding(char* string);  //--> funzione per il Decoding

int main () {
    short scelta;  //variabile per la scelta tra Encoding e Decoding
    char string[MAX];   //stringa

    printf ("Scegliere modalita' d'uso: \n\t 1-->Encoding \n\t 2-->Decoding\n");
    scanf ("%d", &scelta);

    /* switch creato per la scelta (encoding o decoding) */
    switch (scelta)
    {
    case 1:
        Encoding(string);
        break;
    case 2:
        Decoding(string);
        break;
    }

    return 0;
}

void Encoding(char* string) {
    int length;         //lunghezza della stringa
    int cont = 1;       //contatore delle lettere, parte da 1 perchè il num.minimo delle lettere è sempre 1
    size_t a, b;        //variabili dei cicli

    printf ("Inserire la stringa per eseguire il Run Length Encoding: ");
    printf ("\n-- Esempio: WWWWBWWWAACDD --\n");
    scanf ("%s", string);

    /* controllo di quanti elementi è composto l'array */
    for (a = 0; string[a] != '\0'; a++) {
        length = a;
    }

    printf ("\n\tOperazione di Encoding in corso...\n\n");

    /* controllo ogni singola cella dell'array */
    for (b = 0; b <= length; b++) {

        /* se la lettera alla posizione b dell'array è uguale 
        alla lettera alla posizione successiva dello stesso array */
        if (string[b] == string[b+1]) {
            cont++;     //incremento il contatore delle uguaglianze delle lettere di uno 
        }

        /* se le lettere alla posizione attuale e alla posizione successiva sono diverse,
        stampa quante volte la lettera alla posizione attuale è stata trovata */
        else {
            printf("%d%c", cont, string[b]);
            cont = 1;
        }
    }
    printf ("\n\n\tProgramma terminato...\n");
}

void Decoding(char* string) {
    int length;                         // lunghezza della stringa
    int cont = 0;                       // contatore delle lettere, parte da 0 perchè non si sa se sono presenti tutte le lettere
    size_t a, b, c, d;                  // variabili dei cicli

    printf ("Inserire la stringa per eseguire il Run Length Decoding: ");
    printf ("\n-- Esempio: 4W1B3W2A1C2D --\n");
    scanf ("%s", string);

    /* controllo di quanti elementi è composto l'array */
    for (a = 0; string[a] != '\0'; a++) {
        length = a;
    }

    printf ("\n\tOperazione di Decoding in corso...\n\n");

    /* controllo il numero di volte da stampare la lettera*/
    for (b = 0; b <= length; b++) {

        /* se ho individuato un numero */
        if (string[b] <= '1' && string[b] >= '9') {
            cont = string[b] - '0';      //lo salvo in cont
        }
        else {

            /* e poi lo inserisco in un ciclo for che mi stampa cont volte la lettera string[b]*/
            for (d = 0; d < cont; d++) {
                printf("%c", string[b]);
            }

            cont = 0;
        }
    }

    printf ("\n\n\tProgramma terminato...\n");
}