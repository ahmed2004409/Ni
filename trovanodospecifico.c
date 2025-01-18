// come esempio proviamo a trovare un nodo pari

#include <stdio.h>
#include <stdlib.h>

struct nodo {
    int data;
    struct nodo* link;
} typedef nodo;

// Funzione per trovare il primo nodo con un valore pari
nodo* TrovaNodoPari(nodo* inserito) {
    if (!inserito) return NULL;  // Se la lista è vuota, restituisci NULL
    nodo* nodotrovato = NULL;  // Nodo da restituire, inizialmente NULL

    while (inserito) {
        if (inserito->data % 2 == 0) {  // Se il valore del nodo è pari
            nodotrovato = inserito;  // Memorizza il nodo trovato
            break;  // Esci dal ciclo dopo aver trovato il primo nodo pari
        }
        inserito = inserito->link;  // Passa al nodo successivo
    }

    return nodotrovato;  // Restituisce il nodo trovato, o NULL se non trovato
}

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
    // come il solito 

    printf("Lista:\n");
    printList(head);

    nodo* nodoPari = TrovaNodoPari(head);
    if (nodoPari != NULL) {
        printf("Il primo nodo con un valore pari è: %d\n", nodoPari->data);
    } else {
        printf("Nessun nodo con un valore pari trovato.\n");
    }

    return 0; 
}