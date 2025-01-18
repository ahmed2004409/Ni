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
        printf("%d", current->data);
        if (current->link != NULL) {
            printf(" -> ");
        }
        current = current->link;
    }
    printf(" -> NULL\n");  // Indica la fine della lista
}

// Funzione per distruggere la lista (liberare la memoria)
void destroyList(nodo** head) {
    nodo* current = *head;
    nodo* next = NULL;

    while (current != NULL) {
        next = current->link;  // Salva il prossimo nodo
        free(current);  // Libera il nodo corrente
        current = next;  // Passa al prossimo nodo
    }

    *head = NULL;  // Imposta la testa a NULL per evitare l'accesso a memoria già liberata
}

int main() {
    nodo* head = NULL;

    // Creazione della lista con alcuni nodi
    head = malloc(sizeof(nodo));
    head->data = 10;
    head->link = malloc(sizeof(nodo));
    head->link->data = 20;
    head->link->link = malloc(sizeof(nodo));
    head->link->link->data = 30;
    head->link->link->link = NULL;

    // Stampa della lista prima di distruggerla
    printf("Lista prima di distruggerla:\n");
    printList(head);

    // Distrugge la lista e libera la memoria
    destroyList(&head);

    // Dopo la distruzione, la lista dovrebbe essere vuota
    printf("Lista dopo la distruzione:\n");
    printList(head);  // Non dovrebbe stampare nulla, poiché la lista è vuota

    return 0;
}
