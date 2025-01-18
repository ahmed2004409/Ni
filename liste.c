#include<stdio.h>
#include<stdlib.h>
struct nodo{
    int data;
    struct nodo* link;
}typedef nodo;
int main()
{
    nodo* head = malloc(sizeof(nodo));
    head->data = 44;
    head->link = malloc(sizeof(nodo));
    head->link->data = 33;
    head->link->link = malloc(sizeof(nodo));
    head->link->link->data = 3;
    head->link->link->link = NULL; 

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

    current = head; 
    while(current != NULL)
    {
        nodo* temp = current;
        current = current->link;

        free(temp);
    }

}