#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 1000  // Numero massimo di righe nel file

// Struttura per memorizzare i dati di un ricercatore
struct ricercatore {
    char nome[20];
    char cognome[20];
    char codice[20];
    int citazioni;
} typedef ricercatore;

// Funzione per calcolare l'H-index
void h_index(FILE *fp, char nome[], char cognome[], int *h_index)
{
    ricercatore ricerca[N];
    int num = 0;

    // Legge i dati dal file
    fscanf(fp, "%s %s", nome, cognome);  // Legge nome e cognome del ricercatore
    while (fscanf(fp, "%s %d", ricerca[num].codice, &ricerca[num].citazioni) == 2) {
        num++;
    }

    // Ordinamento in ordine decrescente delle citazioni
    ricercatore temp;
    for (int i = 0; i < num - 1; i++) {
        for (int j = i + 1; j < num; j++) {
            if (ricerca[i].citazioni < ricerca[j].citazioni) {
                // Scambia le strutture
                temp = ricerca[i];
                ricerca[i] = ricerca[j];
                ricerca[j] = temp;
            }
        }
    }

    // Calcolo dell'H-index
    *h_index = 0;
    for (int i = 0; i < num; i++) {
        if (ricerca[i].citazioni >= i + 1) {
            *h_index = i + 1;  // L'indice h è il numero di articoli che hanno almeno i+1 citazioni
        } else {
            break;  // Esci dal ciclo se non ci sono più articoli con almeno i+1 citazioni
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) { // Verifica che il numero di parametri sia 2 (nome del programma e nome del file)
        printf("Errore: Devi fornire il nome del file come parametro.\n");
        return 1;
    }

    FILE *fp = fopen(argv[1], "r"); // Apre il file in modalità lettura
    if (fp == NULL) {
        printf("Errore nell'apertura del file: %s\n", argv[1]);
        return 2;
    }

    char nome[20], cognome[20];
    int h_index_value = 0;

    // Calcola l'H-index e ottieni il nome e cognome del ricercatore
    h_index(fp, nome, cognome, &h_index_value);

    // Stampa i risultati
    printf("Il ricercatore %s %s ha un H-index di %d\n", nome, cognome, h_index_value);

    fclose(fp); // Chiude il file
    return 0;
}
