// sommare i primi 3 numeri nel nodo poi sostituire il primo ccon il risultato e eliminare gli altri 2 nodi
#include<stdio.h>
#include<stdlib.h>

typedef  struct  nd
{   int val;    
    struct nd * next; 
}  Nodo;           
typedef  Nodo * List;  

void somma_triplette( List *lis )  
{
    list current = *lis // cosi ho creato una variabile temporanea che contiene il valore della testa per poter lavorare 
    //sui valori nella lista senza modificare direttamente il valore che c'è nella testa 
    while(current != NULL && current->next != NULL && current->next->next != NULL)
    {
        int somma = (current->val + current->next->val + current->next->next->val); 
        current->val = somma ; 
    }

    list temp = current->next; // assegno a temp il valore del secondo nodo
    list temp2 = current->next->next;// assegno a temp2 il valore del 3 nodo
    current->next = current->next->next->next;  // Salta i due nodi assegnando al secondo nodo l'indirizzo del 4 cosi diventa il 2
    free(temp);  // Libera il secondo nodo , elimino 
    free(temp2);  // Libera il terzo nodo, elimino 

    current = current->next; // il primo nodo cosi diventa il nodo successivo pk io devo lavorare dal nodo successivo in poi 

}