// eliminare un nodo in base alla relazione con il nodo successivo.in questo caso il il uno è minore o uguale a uno dei successivi
#include<stdio.h>
#include<stdlib.h>

typedef struct nd{// questo rappresenta un nodo della lista 
    int val;// il valore del nodo 
    struct nd* next;// il puntatore al nodo successivo 
}Nodo; 

typedef  Nodo * List;

void smdtis(List *lis) {
    List current = *lis;
    
    while (current != NULL && current->next != NULL) {
        // Se il valore corrente è minore o uguale al valore del nodo successivo
        if (current->val <= current->next->val) {
            List temp = current->next;
            current->next = temp->next;  // Sgancia il nodo successivo
            free(temp);  // Dealloca il nodo
        } else {
            current = current->next;  // Passa al nodo successivo
        }
    }
}
