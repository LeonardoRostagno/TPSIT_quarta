#include <stdio.h>
#include <stdlib.h>

// struttura autoreferenziale
typedef struct nodo {
    int val;
    struct nodo * next;
} Nodo;

void push (Nodo *head, int valore) {
    //aggiunge un elemento in fondo alla lista  contenente il valore
    Nodo * appoggio = head;

    while (appoggio->next != NULL) {
        appoggio = appoggio->next;
    }
    // siamo arrivati all'ultimo elemento della lista
    appoggio->next = (Nodo*) malloc (sizeof(Nodo));
    appoggio->next->val = valore; 
    appoggio->next->next = NULL;
}

int main () {
    Nodo *first_element;

    first_element = (Nodo*) malloc (sizeof(Nodo));

    first_element->val = 1;
    first_element->next = NULL;

    push(first_element, 2);
    push(first_element, 3);

    /* fanno la stessa cosa 
    Nodo *second_element;
    Nodo *third_element;

    second_element = (Nodo*) malloc (sizeof(Nodo));
    third_element = (Nodo*) malloc (sizeof(Nodo));

    first_element->next = second_element;
    second_element->val = 2;
    second_element->next = third_element;
    third_element->val = 3;
    */

    Nodo *appoggio;
    appoggio = first_element;

    while (appoggio != NULL) { // perchè cicla anche per l'ultimo valore, altrementi esce e non stamperebbe third_element
        printf("Il valore e' %d\n", appoggio->val);

        appoggio = appoggio->next;
    }
    
    free();
    return 0;
}