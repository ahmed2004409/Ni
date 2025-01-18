#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* link;
}typedef node;
int main()
{
    node* head = malloc(sizeof(node));
    head->data = 44;
    head->link = malloc(sizeof(node));
    head->link->data = 33;
    head->link->link = malloc(sizeof(node));
    head->link->link->data = 3;
    head->link->link->link = NULL; 

    node* current; 
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
        node* temp = current;
        current = current->link;

        free(temp);
    }

}