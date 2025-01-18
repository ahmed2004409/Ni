#include <stdio.h>
#include <stdlib.h>

struct nodo {
    int data;
    struct nodo* link;
} typedef nodo;

nodo* inserisci_in_coda(nodo* head, int value);

int main() {
    nodo* head = malloc(sizeof(nodo));  // Allocazione del primo nodo
    head->data = 44;
    head->link = malloc(sizeof(nodo));  // Allocazione del secondo nodo
    head->link->data = 33;
    head->link->link = malloc(sizeof(nodo));  // Allocazione del terzo nodo
    head->link->link->data = 3;
    head->link->link->link = NULL;  // Ultimo nodo con link a NULL

    // Inserimento in coda
    head = inserisci_in_coda(head, 10);  // La funzione restituisce la nuova testa

    // Stampa della lista
    nodo* current = head;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->link != NULL) {
            printf("->");
        }
        current = current->link;
    }
    printf("\n");

    return 0;
}

// Funzione per inserire in coda
nodo* inserisci_in_coda(nodo* head, int value) {
    nodo* nuovoNodo = malloc(sizeof(nodo));  // Crea il nuovo nodo
    nuovoNodo->data = value;  // Imposta il valore del nuovo nodo
    nuovoNodo->link = NULL;   // Il nuovo nodo deve puntare a NULL (fine della lista)

    if (head == NULL) {
        // Se la lista è vuota, il nuovo nodo diventa la testa
        return nuovoNodo;
    }

    nodo* current = head;
    while (current->link != NULL) {
        current = current->link;  // Trova l'ultimo nodo
    }

    current->link = nuovoNodo;  // Collega il nuovo nodo alla fine della lista
    return head;
}
