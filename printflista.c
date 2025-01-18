#include <stdio.h>
#include <stdlib.h>

struct nodo {
    int data;
    struct nodo* link;
} typedef nodo;

// Funzione per stampare la lista
void printList(nodo* head) {
    nodo* current = head;
    while (current != NULL) {
        printf("%d", current->data);  // Stampa il valore del nodo
        if (current->link != NULL) {
            printf(" -> ");  // Aggiungi "->" tra i nodi
        }
        current = current->link;  // Passa al nodo successivo
    }
    printf(" -> NULL\n");  // Indica la fine della lista
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

int main() {
    nodo* head = NULL;

    // Creazione della lista con l'inserimento in coda
    head = inserisci_in_coda(head, 10);
    head = inserisci_in_coda(head, 20);
    head = inserisci_in_coda(head, 30);

    // Stampa della lista
    printList(head);  // Chiama la funzione per stampare la lista

    return 0;
}
