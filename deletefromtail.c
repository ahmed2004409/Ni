#include <stdio.h>
#include <stdlib.h>

struct nodo {
    int data;
    struct nodo* link;
} typedef nodo;

// Funzione per rimuovere dall'ultimo nodo
nodo* rimuovi_da_coda(nodo* head);

// Funzione per inserire in coda
nodo* inserisci_in_coda(nodo* head, int value);

// Funzione per rimuovere l'ultimo nodo
nodo* rimuovi_da_coda(nodo* head) {
    if (head == NULL || head->link == NULL) {
        // Se la lista è vuota o ha un solo nodo, ritorna NULL
        free(head);
        return NULL;
    }

    nodo* current = head;
    while (current->link && current->link->link != NULL) {
        current = current->link;  // Trova il penultimo nodo
    }

    free(current->link);  // Libera l'ultimo nodo
    current->link = NULL;  // Imposta il penultimo nodo come l'ultimo
    return head;
}

// Funzione per inserire in coda
nodo* inserisci_in_coda(nodo* head, int value) {
    nodo* nuovoNodo = malloc(sizeof(nodo));  // Crea un nuovo nodo
    nuovoNodo->data = value;  // Imposta il valore
    nuovoNodo->link = NULL;   // Il nuovo nodo deve puntare a NULL (fine lista)

    if (head == NULL) {
        return nuovoNodo;  // Se la lista è vuota, il nuovo nodo diventa la testa
    }

    nodo* current = head;
    while (current->link != NULL) {
        current = current->link;  // Trova l'ultimo nodo
    }

    current->link = nuovoNodo;  // Collega il nuovo nodo alla fine della lista
    return head;
}
