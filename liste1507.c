// devo lavorare con dei sottolisti in una lista , devo controllare se ci sono coppie uguali di numeir dispari e pari tipo cosi: 
// 1,2,3,4,5,6 quindi io ho 1,2,3,4,5,6 poi ho 3,4,5,6 poi ho 5,6 
#include<stdio.h>
#include<stdlib.h>

typedef  struct  nd {   
    int val;  
    struct nd * next;  
}  Nodo;          
typedef  Nodo * List;  

 int contaCodeBilanciate ( List lis ) 
 {
    if(lis == NULL)
    {
        return 0; 
    }

    List start = lis;
    int cont = 0; 

    while(start != NULL)
    {
        int pari = 0; // variabile per controllare il pari
        int dispari = 0; // controllare i dispari 
        List temp = start; // un'altra variabile per lavorare con le sotto liste 

        while(temp != NULL)// finchè non è vuota
        {
            if(temp % 2 == 0)//controllo pari
            {
                pari++;// nel caso auemnto 
            }
            else{
                dispari++;//altrimenti è dispari 
            }
            temp = temp->next// vado al nodo successivo 
        }
        if(pari == dispari)// se i 2 nodi sono uno pari e l'altro è dispari e viceversa
            {
                cont++;// aumento il numero delle coppie 
            }

        start= start->next;   
    }

    return cont; 
 }