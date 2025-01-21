//partendo da una lista originale bisogna creare 2 liste separate, una per contenere i numeri positivi e una per i numeri negativi
// è utile in generale se voglio aggiungere dei valori da una lista a un'altra lista che viene creata al momento
#include <stdio.h>
#include <stdlib.h>

typedef struct nd {
    int valore;
    struct nd* next;
} Nodo;

typedef Nodo* List;

void sdoppia(List lis, List *pPos, List *pNeg) {
    // Inizializzazione delle liste vuote
    *pPos = NULL;
    *pNeg = NULL;

    // Scorrimento della lista originale
    while (lis != NULL) {
        // Creazione del nuovo nodo
        List nuovoNodo = malloc(sizeof(Nodo));
        nuovoNodo->valore = lis->valore;
        nuovoNodo->next = NULL;

        // Se il valore è positivo, aggiungiamo il nodo a pPos
        if (lis->valore > 0) {
            if (*pPos == NULL) {
                *pPos = nuovoNodo;  // primo nodo della lista positiva
            } else {
                List tmp = *pPos;
                while (tmp->next != NULL) {
                    tmp = tmp->next;
                }
                tmp->next = nuovoNodo;  // aggiungiamo alla fine
            }
        } 
        // Se il valore è negativo, aggiungiamo il nodo a pNeg
        else if (lis->valore < 0) {
            if (*pNeg == NULL) {
                *pNeg = nuovoNodo;  // primo nodo della lista negativa
            } else {
                List tmp = *pNeg;
                while (tmp->next != NULL) {
                    tmp = tmp->next;
                }
                tmp->next = nuovoNodo;  // aggiungiamo alla fine
            }
        }

        // Passiamo al nodo successivo nella lista originale
        lis = lis->next;
    }
}

void stampaLista(List l) {
    while (l != NULL) {
        printf("%d ", l->valore);
        l = l->next;
    }
    printf("\n");
}

int main() {
    // Esempio di lista: 1 -> -2 -> 3 -> -4 -> 5
    List lis = malloc(sizeof(Nodo));
    lis->valore = 1;
    lis->next = malloc(sizeof(Nodo));
    lis->next->valore = -2;
    lis->next->next = malloc(sizeof(Nodo));
    lis->next->next->valore = -3;
    lis->next->next->next = malloc(sizeof(Nodo));
    lis->next->next->next->valore = 4;
    lis->next->next->next->next = malloc(sizeof(Nodo));
    lis->next->next->next->next->valore = 5;
    lis->next->next->next->next->next = NULL;

    List pos = NULL, neg = NULL;

    // Chiamata alla funzione sdoppia
    sdoppia(lis, &pos, &neg);

    // Stampa delle due liste separate
    printf("Lista positiva: ");
    stampaLista(pos);
    printf("Lista negativa: ");
    stampaLista(neg);

    // Liberiamo la memoria
    free(lis);
    free(pos);
    free(neg);

    return 0;
}
