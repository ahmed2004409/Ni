#include<stdio.h>
#include<stdlib.h>

struct nodo{
    int data;
    struct nodo* link;
}typedef nodo;

nodo* inverti_lista(nodo* head) {
    nodo* prev = NULL;
    nodo* current = head;
    nodo* next = NULL;

    while (current != NULL) {
        next = current->link;  // Salva il prossimo nodo
        current->link = prev;  // Inverte il collegamento
        prev = current;  // Sposta 'prev' e 'current'
        current = next;
    }

    return prev;  // 'prev' sarà la nuova testa della lista
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
    nodo* head = malloc(sizeof(nodo));
    head->data = 44;
    head->link = malloc(sizeof(nodo));
    head->link->data = 33;
    head->link->link = malloc(sizeof(nodo));
    head->link->link->data = 3;
    head->link->link->link = NULL; 

    printf("Lista prima dell'inversione:\n");
    printList(head);

    head = inverti_lista(head);

    printf("Lista dopo l'inversione:\n");
    printList(head);

    return 0; 

}
