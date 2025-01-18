#include <stdio.h>
#include <stdlib.h>

struct nodo {
    int data;
    struct nodo* link;
} typedef nodo;

// Funzione per ordinare la lista in modo crescente usando Bubble Sort
void ordinaLista(nodo* head) {
    if (head == NULL) return;  // Se la lista è vuota, non fare nulla

    int swapped;
    nodo* current;
    nodo* prev = NULL;

    // Ripetere finché non ci sono più scambi da fare
    do {
        swapped = 0;
        current = head;

        // Scorrere la lista
        while (current != NULL && current->link != NULL) {
            // Se il valore del nodo corrente è maggiore del valore del nodo successivo
            if (current->data > current->link->data) {
                // Scambia i dati dei due nodi
                int temp = current->data;
                current->data = current->link->data;
                current->link->data = temp;

                swapped = 1;  // Segna che uno scambio è stato fatto
            }
            current = current->link;  // Passa al nodo successivo
        }
    } while (swapped);  // Continua finché ci sono stati scambi
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


int main()
{
    nodo* head = malloc(sizeof(nodo));
    head->data = 44;
    head->link = malloc(sizeof(nodo));
    head->link->data = 33;
    head->link->link = malloc(sizeof(nodo));
    head->link->link->data = 3;
    head->link->link->link = NULL; 

    printf("Lista prima dell'ordinamento:\n");
    printList(head);

    ordinaLista(head);

    printf("Lista dopo l'ordinamento:\n");
    printList(head);

    return 0;
}