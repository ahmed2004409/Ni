#include <stdio.h>
#include <stdlib.h>

struct nodo {
    int data;
    struct nodo* link;
} typedef nodo;

// Funzione per rimuovere un nodo dato un valore
void deleteByValue(nodo** head, int value) {
    if (*head == NULL) return;  // Se la lista è vuota, non fare nulla
    
    nodo* current = *head;
    
    // Caso speciale: rimuovere la testa
    if (current->data == value) {
        *head = current->link;
        free(current);
        return;
    }
    
    // Scorri la lista per trovare il nodo da rimuovere
    while (current->link != NULL && current->link->data != value) {
        current = current->link;
    }
    
    if (current->link != NULL) {
        nodo* temp = current->link;
        current->link = current->link->link;  // Salta il nodo da rimuovere
        free(temp);  // Libera la memoria del nodo rimosso
    }
}

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

int main() {
    nodo* head = malloc(sizeof(nodo));
    head->data = 44;
    head->link = malloc(sizeof(nodo));
    head->link->data = 33;
    head->link->link = malloc(sizeof(nodo));
    head->link->link->data = 3;
    head->link->link->link = NULL;

    // Stampa della lista prima della rimozione
    printf("Lista prima della rimozione:\n");
    printList(head);

    // Rimozione del nodo con valore 33
    deleteByValue(&head, 33);  // Rimuove il nodo con valore 33

    // Stampa della lista dopo la rimozione
    printf("Lista dopo la rimozione di 33:\n");
    printList(head);

    return 0;
}
