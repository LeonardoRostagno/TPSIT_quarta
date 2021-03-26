#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct queue_node {
    char val; // valore dei semi
    struct queue_node* next;
} Nodo;

/* funzione per vedere se la coda è piena */
int is_empty(Nodo *head) { 
    if (head == NULL) {
        return 1;
    }
    else {
        return 0;
    }
} 

void enqueue (Nodo **head, Nodo **tail, Nodo *element); // funzione enqueue
Nodo * dequeue(Nodo **head, Nodo **tail); // funzione dequeue

int main () {
    Nodo *head = (Nodo*) malloc (sizeof (Nodo)); // testa 
    Nodo *tail = (Nodo*) malloc (sizeof (Nodo)); // coda 
    Nodo *elemento = (Nodo*) malloc (sizeof (Nodo)); // elemento

    char cuori = 'C'; // carte di cuori
    char picche = 'P'; // carte di picche
    char quadri = 'D'; // carte di quadri
    char fiori = 'F'; // carte di cuori

    int cont = 1; // cont mi serve per la numerazione delle carte
    
    printf("\nInserimento carte...\n"); // avviso

    for (size_t a = 0; a < 4; a++) { // ciclo che mi permette di inserire tutte le carte da gioco
        while (cont < 14) { // ciclo che mi permette di inserire tutti i numeri di un seme
            if (a == 0) { // se a = 0, genero le carte del seme Cuori
                elemento->val = cuori; // assegno a elemento->val i cuori

                enqueue(&head, &tail, elemento); // richiamo la funzione enqueue
            } else if(a == 1) {
                elemento->val = picche; // assegno a elemento->val i picche

                enqueue(&head, &tail, elemento); // richiamo la funzione enqueue
            } else if(a == 2) {
                elemento->val = quadri; // assegno a elemento->val i quadri

                enqueue(&head, &tail, elemento); // richiamo la funzione enqueue
            } else if(a == 3) {
                elemento->val = fiori; // assegno a elemento->val i fiori

                enqueue(&head, &tail, elemento); // richiamo la funzione enqueue
            }
            cont++; // aggiorno cont di 1
        }
        cont = 1; // riporto cont a 1
    }

    printf("\nInserimento carte completato...\n"); // avviso

    printf("\nEstrazione carte...\n\n"); // avviso

    for (size_t b = 0; b < 4; b++) { // ciclo che mi permette di controllare tutte le carte da gioco
        while (cont < 14) { // controllo tutti i semi e tutti i numeri
            if (dequeue(&head, &tail)->val == 'C') { // contollo cuori
                elemento->val = cuori; // assegno a elemento->val i cuori

                enqueue(&head, &tail, elemento); // richiamo la funzione enqueue
            } else if(dequeue(&head, &tail)->val == 'P') { // controllo picche
                printf("Scarto carta...\n"); // segnalo di aver trovato una carta nera
            } else if(dequeue(&head, &tail)->val == 'D') { // controllo quadri
                elemento->val = cuori; // assegno a elemento->val i cuori

                enqueue(&head, &tail, elemento); // richiamo la funzione enqueue
            } else if(dequeue(&head, &tail)->val == 'F') { // controllo fiori
                printf("Scarto carta...\n"); // segnalo di aver trovato una carta nera
            }
            cont++; // aggiorno cont2 di 1
        }
        cont = 1; // riporto cont2 a 1
    }

    printf("\nEstrazione carte completato...\n"); // avviso

    printf("\nStampa carte...\n\n"); // avviso

    for (size_t b = 0; b < 2; b++) { // ciclo con cui scorro la coda
        while (cont < 14) { // stampo ogni carta di ogni seme
            if (dequeue(&head, &tail)->val == 'C') {  // stampo cuori
                printf ("Seme %c -> carta %d\n", dequeue(&head, &tail)->val, cont); // stampo carta
            } else if(dequeue(&head, &tail)->val == 'D') { // stampo quadri
                printf ("Seme %c -> carta %d\n", dequeue(&head, &tail)->val, cont); // stampo carta
            }
            cont++; // aggiorno cont di 1
        }
        cont = 1; // riporto cont a 1
    }

    printf("\nStampa carte completato...\n"); // avviso

    return 0;
}

/* ENQUEUE */
void enqueue (Nodo **head, Nodo **tail, Nodo *element) {
    if(is_empty(*head)) {
        *head = element;
    }
    else {
        (*tail)->next = element;
    }

    *tail = element;
    element->next = NULL;
}

/* DEQUEUE */
Nodo * dequeue(Nodo **head, Nodo **tail) {

    Nodo *ret = *head;

    if (is_empty(*head)) {
        return NULL;
    }
    else {
        *head = ret->next;
    }

    if (*head == NULL) {
        *tail = NULL;
    }
    return ret;
}