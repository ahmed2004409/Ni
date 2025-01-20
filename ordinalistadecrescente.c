#include <stdio.h>
#include <stdlib.h>

struct nodo {
    int data;
    struct nodo* link;
} typedef nodo;


// Funzione per ordinare la lista in modo decrescente usando Bubble Sort
nodo* sortingDecrescente(nodo* head) {
    if (!head) return NULL;  // Se la lista è vuota, restituisci NULL

    nodo* current;
    nodo* next;
    int temp;

    // Loop per attraversare l'intera lista e ordinare i nodi
    for (current = head; current != NULL; current = current->link) {
        for (next = current->link; next != NULL; next = next->link) {
            // Confronta i valori dei nodi e scambia se necessario (per ordinare in ordine decrescente)
            if (current->data < next->data) {
                // Scambio dei valori
                temp = current->data;
                current->data = next->data;
                next->data = temp;
            }
        }
    }

    return head;  // Restituisce la lista ordinata in modo decrescente
}