#include <stdio.h>
#include <stdlib.h>

struct nodo {
    int data;
    struct nodo* link;
} typedef nodo;

// Funzione per ordinare la lista in modo crescente usando Bubble Sort
nodo* sorting(nodo* head) {
    if (!head) return NULL;  // Se la lista è vuota, restituisci NULL

    nodo* current;
    nodo* next;
    int temp;

    // Loop per attraversare l'intera lista e ordinare i nodi
    for (current = head; current != NULL; current = current->link) {
        for (next = current->link; next != NULL; next = next->link) {
            // Confronta i valori dei nodi e scambia se necessario
            if (current->data > next->data) {
                // Scambio dei valori
                temp = current->data;
                current->data = next->data;
                next->data = temp;
            }
        }
    }

    return head;  // Restituisce la lista ordinata
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