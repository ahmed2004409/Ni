#include <stdio.h>
#include <stdlib.h>

struct nodo {
    int data;
    struct nodo* link;
} typedef nodo;

void printList(nodo* head);

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

int main()
{
    nodo* head = malloc(sizeof(nodo));
    head->data = 44;
    head->link = malloc(sizeof(nodo));
    head->link->data = 33;
    head->link->link = malloc(sizeof(nodo));
    head->link->link->data = 3;
    head->link->link->link = NULL; 

    printList(head); 
    return 0;
}    