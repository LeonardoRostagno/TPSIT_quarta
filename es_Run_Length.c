#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

void Encoding();
void Decoding();

int main () {
    int scelta;  

    printf ("Scegliere modalita' d'uso: \n\t1-->Encoding \n\t2-->Decoding\n");
    scanf ("%d", scelta);

    /* switch creato per la scelta (encoding o decoding) */
    switch (scelta)
    {
    case 1:
        Encoding();
        break;
    case 2:
        Decoding();
        break;
    }

    return 0;
}

void Encoding() {
    char string[MAX];
    int length;
    int cont;
    int a, b;

    printf ("Inserire la stringa per eseguire il Run Length Encoding: ");
    printf ("-- Esempio: WWWWBWWWAACDD --");
    gets (string);

    /* controllo di quanti elementi è composto l'array */
    for (a = 0; string[a] != '\0'; a++) {
        length = a;
    }

    printf ("\n\tOperazione di Encoding in corso...\n");

    /* controllo ogni singola cella dell'array */
    for (b = 0; b <= length; b++) {

        /* se la lettera alla posizione b dell'array è uguale 
        alla lettera alla posizione successiva dello stesso array */
        if (string[b] == string[b+1]) {
            cont++;     //incremento il contatore delle uguaglianze delle lettere di uno 
        }

        /* se le lettere alla posizione attuale e alla posizione successiva sono diverse,
        stampa quante volte la lettera alla posizione attuale è stata trovata */
        else if (string[b] != string[b+1]) {
            printf("%d%c", cont, string[b]);
        }
    }
    printf ("\n\tProgramma terminato...\n");
}

void Decoding() {
    char string[MAX];
    int length;
    int a, b, c, d;
    int cont;
    char num[] = "1,2,3,4,5,6,7,8,9";

    printf ("Inserire la stringa per eseguire il Run Length Decoding: ");
    printf ("-- Esempio: 4W1B3W2A1C2D --");
    gets (string);

    /* controllo di quanti elementi è composto l'array */
    for (a = 0; string[a] != '\0'; a++) {
        length = a;
    }

    printf ("\n\tOperazione di Decoding in corso...\n");

    /* controllo il numero di volte da stampare la lettera*/
    for (b = 0; b <= length; b++) {

        /* ciclo che si ripete per 9 volte, perchè devo scorrere ogni volta l'array num di 9 elementi */
        for (c = 0; c < 9; c++) {

            /* se ho individuato un numero */
            if (string[b] == num[c]) {
                cont = num[c];      //lo salvo in cont
            }

            /* e poi lo inserisco in un ciclo for che mi stampa cont volte la lettera string[b+1]*/
            for (d = 0; d < cont; d++) {
                printf("%c", string[b+1]);
            }
        }
    }

    printf ("\n\tProgramma terminato...\n");
}