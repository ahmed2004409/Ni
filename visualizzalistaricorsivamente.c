#include <stdio.h>
#include <stdlib.h>

struct nodo {
    int data;
    struct nodo* link;
} typedef nodo;

// Funzione per visualizzare la lista in modo ricorsivo
void VisualizzaLista(nodo* head) {
    if (head == NULL) {
        printf("Lista nulla\n");  // Caso in cui la lista è vuota
    } else if (head->link == NULL) {
        printf("%d\n", head->data);  // Stampa l'ultimo nodo
    } else {
        printf("%d --> ", head->data);  // Stampa il nodo corrente seguito da " --> "
        VisualizzaLista(head->link);  // Chiamata ricorsiva per il nodo successivo
    }
}

// Funzione per inserire un nodo in coda
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
    head = inserisci_in_coda(head, 40);

    // Visualizza la lista
    printf("Lista:\n");
    VisualizzaLista(head);  // Visualizza la lista intera

    return 0;
}
