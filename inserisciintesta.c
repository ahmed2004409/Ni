#include<stdio.h>
#include<stdlib.h>

struct nodo{
    int data ;
    struct nodo* link;
}typedef nodo;

nodo* inserisci_intesta(nodo* head, int value);

int main()
{
    nodo* head = malloc(sizeof(nodo));
    head->data = 44;
    head->link = malloc(sizeof(nodo));
    head->link->data = 33;
    head->link->link = malloc(sizeof(nodo));
    head->link->link->data = 3;
    head->link->link->link = NULL; 

    
    head = inserisci_intesta(head, 10);
    
    nodo* current;
    current = head;
    while(current != NULL)
    {
        printf("%d", current->data);
        if(current->link != NULL)
        {
            printf("->");
        }
        current = current->link;
    }
    printf("\n");


}


nodo* inserisci_intesta(nodo* head, int value)
{
    nodo* ptr = malloc(sizeof(nodo));// crea il puntatore che punterà nel nodo che sto per creare 

    ptr->data = value; // ppassa il valore del nodo
    ptr->link = head; // passa l'indirizzo 
    return ptr;// riorna quel nodo 


}