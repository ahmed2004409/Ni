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