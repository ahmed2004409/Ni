// conta partecipanti paesi;
#include<stdio.h>
#include<string.h>
#define N 25

struct invitati{
    char nome[N];
    char stato[N];
} typedef invitati;

void provenienze(FILE* fp)
{
    invitati invitati1[N];
    int numinvitati = 0; 

    while(fscanf(fp,"%s %s", invitati1[numinvitati].nome, invitati1[numinvitati].stato ) == 2)
    {
        numinvitati++;
    }

    int cont[100]= {0}; // ho bisogno di più contatori appunto per ogni paese quidni la soluzione giusta sarebbe creare un array
    for(int i = 0; i < numinvitati; i++)// che ci sta per 100 paesi ad esempio e inizializzato a 0
    {
        for(int j = i+1 ; j < numinvitati; j++ )
        {
            if(strcmp(invitati1[i].stato, invitati1[j].stato) == 0)
            {
                cont[j]++; // se trovo la corrispondenza aumento il primo elemento dell'array che sarebbe il numero dei partecipanti
                break;// di quel paese 
            }// e poi quando esco e rientro nel ciclo interno l'indice dellarray cambia e quidni cosi ho il mio nuovo contatore per 
        }// il nuovo paese 

        if(cont[i] == 0)// se non ho aumentato mai il contatore 
        {
            cont[i] = 1;// significa che il paese ha un solo numero 
        }
    } 

    for(int i = 0; i < numinvitati; i++)// stampo
    {
        if(cont[i] > 0)
        {
            printf("%s %d \n", invitati1[i].stato, cont[i]);
        }
        
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) { // Verifica se il numero di parametri è inferiore a 2
        printf("Errore: Devi fornire il nome del file come parametro.\n");
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Errore nell'apertura del file: %s\n", argv[1]);
        return 2;
    }

    
    printf("i partecipanti per ogni paese sono \n");
    provenienze(fp);
    

    fclose(fp); // Chiude il file dopo l'elaborazione
    return 0;
}