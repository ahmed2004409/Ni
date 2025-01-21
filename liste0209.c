// modificare una lista cercando quale è il piu grande tra il nodo in posizone pari e quello in poszione dispari e poi eliminare il più piccolo
#include<stdio.h>
#include<stdlib.h>

typedef  struct  nd {   
    int val;  
    struct nd * next;  
    }  Nodo;      

    typedef  Nodo * List;  

    void filtra(List lis)
    {
        List temp = lis;

        while(temp != NULL && temp->next != NULL)
        {
            if(temp->val > temp->next->val)
            {
                List current = tem->next;
                temp->next = temp->next->next;
                free(curreent;
            }
            else{
                List current = temp;
                temp = temp->next;
                free(current1);
            }
            
            if(temp->val == temp->next->val)
            {
                temp = temp->next; // passo al nodo successivo mantenendo il valore di entrambi .
            }


            

            temp = temp->next; 
        } 

    }