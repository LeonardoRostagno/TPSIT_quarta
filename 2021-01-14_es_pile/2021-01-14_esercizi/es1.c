#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo {
    char val;
    struct nodo* next;
} Nodo;

/* funzione per vedere se la pila è piena */
int is_empty(Nodo *head) { 
    if (head == NULL) {
        return 1;
    }
    else {
        return 0;
    }
} 

void push (Nodo **head, Nodo *elemento); // funzione push
Nodo* pop (Nodo **head); // funzione pop

int main () {
    Nodo *pila = (Nodo*) malloc (sizeof (Nodo)); // pila 
    Nodo *elemento = (Nodo*) malloc (sizeof (Nodo)); // elemento

    int dim; // dimensione dell'array

    do {
        printf("Inserire un numero maggiore di 10: ");
        scanf("%d", &dim);
    } while (dim <= 10);

    char arr[dim];

    for (size_t a = 0; a < dim; a++) {
        printf("Inserire elemento alla posizione %d: \n", a);
        fscanf(stdin, "%s", arr);

        elemento->val = *(arr + a);
        
        push(&pila, elemento);
    }

    for (size_t b = 0; b < dim; b++) {
        printf("Posizione -> %d \tElemento -> %c\n", b, pop(&pila)->val);
    }

    return 0;
}

/* funzione push */
void push (Nodo **head, Nodo* elemento) {
    if (is_empty(*head)) {
        printf("\tLa pila e' piena...\n");
    }
    else {
        elemento->next = *head;
        *head = elemento;
    }
}

/* funzione pop */
Nodo* pop (Nodo **head) {
    Nodo* app = *head; // variabile di appoggio

    if(is_empty(*head)) {
        return NULL;
    }
    else {
        *head = app->next;
    }
    return app;
}