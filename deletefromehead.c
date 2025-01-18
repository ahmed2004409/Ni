#include <stdio.h>
#include <stdlib.h>

struct nodo {
    int data;
    struct nodo* link;
} typedef nodo;

// Funzione per rimuovere dal primo nodo
nodo* rimuovi_da_testa(nodo* head);

// Funzione per inserire in coda
nodo* inserisci_in_coda(nodo* head, int value);

int main() {
    nodo* head = NULL;

    // Creazione di una lista
    head = inserisci_in_coda(head, 10);
    head = inserisci_in_coda(head, 20);
    head = inserisci_in_coda(head, 30);

    // Rimozione dalla testa
    head = rimuovi_da_testa(head);

    // Stampa della lista
    nodo* current = head;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->link != NULL) {
            printf(" -> ");
        }
        current = current->link;
    }
    printf("\n");

    return 0;
}

// Funzione per rimuovere il primo nodo
nodo* rimuovi_da_testa(nodo* head) {
    if (head == NULL) {
        return NULL;  // La lista è vuota
    }

    nodo* temp = head;  // Salva il nodo da rimuovere
    head = head->link;  // Sposta la testa al secondo nodo
    free(temp);  // Libera la memoria del nodo rimosso
    return head;
}

// Funzione per inserire in coda
nodo* inserisci_in_coda(nodo* head, int value) {
    nodo* nuovoNodo = malloc(sizeof(nodo));  // Crea il nuovo nodo
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
