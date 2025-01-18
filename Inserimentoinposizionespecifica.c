#include <stdio.h>
#include <stdlib.h>

struct nodo {
    int data;
    struct nodo* link;
} typedef nodo;

// Funzione per inserire in posizione specifica
nodo* inserisci_in_posizione(nodo* head, int value, int posizione);

int main() {
    nodo* head = NULL;  // Lista vuota

    // Inserimento in posizione
    head = inserisci_in_posizione(head, 10, 0);  // Inseriamo 10 in posizione 0
    head = inserisci_in_posizione(head, 20, 1);  // Inseriamo 20 in posizione 1

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

// Funzione per inserire in posizione specifica
nodo* inserisci_in_posizione(nodo* head, int value, int posizione) {
    nodo* nuovoNodo = malloc(sizeof(nodo));  // Crea il nuovo nodo
    nuovoNodo->data = value;  // Imposta il valore
    if (posizione == 0) {
        nuovoNodo->link = head;  // Collega il nuovo nodo alla testa attuale
        return nuovoNodo;  // Restituisce la nuova testa
    }

    nodo* current = head;
    for (int i = 0; i < posizione - 1 && current != NULL; i++) {
        current = current->link;  // Trova il nodo precedente alla posizione
    }

    if (current == NULL) {
        // Se la posizione è fuori dai limiti, aggiungi in coda
        nuovoNodo->link = NULL;
        return head;
    }

    nuovoNodo->link = current->link;  // Collega il nuovo nodo
    current->link = nuovoNodo;  // Collega il nodo precedente al nuovo nodo
    return head;
}
