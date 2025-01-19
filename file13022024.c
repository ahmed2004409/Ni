// codice orario dei lavoratori.
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 90

struct indipendente{
    int ora ;
    int minuti;
    char cd[4];
}typedef indipendente;

int minuti(FILE* fp, char* cd)
{
    indipendente lavoro[N];
    int numlavoratori = 0;

    while(fscanf(fp,"%d %d %s", &lavoro[numlavoratori].ora, &lavoro[numlavoratori].minuti, lavoro[numlavoratori].cd)== 3)
    {
        numlavoratori++;
    }

    int minuti_totale = 0;
    int ingresso_trovato = 0; 

    for(int i = 0 ; i < numlavoratori; i++)
    {
        if(strcmp(lavoro[i].cd,cd) == 0)
        {
            if(!ingresso_trovato)
            {
                int minuti_ingresso = (lavoro[i].ora) * 60 + lavoro[i].minuti;
                ingresso_trovato = 1;

                for(int j = i+1; j < numlavoratori; j++)
                {
                    if(strcmp(lavoro[j].cd,cd) == o)
                    {
                        int minuti_uscita = (lavoro[j].ora) * 60 + lavoro[i].minuti;

                        minuti_totali = minuti_uscita - minuti_ingresso;
                        return minuti_totali;
                    }
                }

                return -1; // se c'è una sola registrazione 
            }
        }
    }

    return 0; //il codice non c'è proprio

   
}

int main(int argc, char *argv[]) {
    if (argc < 2) { // Verifica se il numero di parametri è inferiore a 2
        printf("Errore: Devi fornire almeno il nome del file come parametro.\n");
        return 1;
    }

    // Apertura del file
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Errore nell'aprire il file: %s\n", argv[1]);
        return 2;
    }

    if (argc == 2) {
        // Se c'è solo un parametro (il file), stampa l'intero contenuto del file
        char linea[256];
        while (fgets(linea, sizeof(linea), fp) != NULL) {
            printf("%s", linea);
        }
    } else if (argc == 3) {
        // Se ci sono due parametri (file e codice dipendente), calcola i minuti di permanenza
        int minutiPermanenza = minuti(fp, argv[2]);
        if (minutiPermanenza == 0) {
            printf("Errore: nessuna registrazione per il codice %s.\n", argv[2]);
        } else if (minutiPermanenza == -1) {
            printf("Errore: ci sono problemi con i passaggi del codice %s.\n", argv[2]);
        } else {
            printf("Il totale dei minuti per il codice %s è: %d minuti.\n", argv[2], minutiPermanenza);
        }
    } else {
        printf("Errore: Numero errato di parametri. Utilizzo: <programma> <file> [codice dipendente].\n");
        return 3;
    }

    fclose(fp); // Chiude il file dopo l'elaborazione
    return 0;
}