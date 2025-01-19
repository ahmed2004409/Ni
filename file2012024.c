//codice lista della spesa
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PR 100// rappresenta il numero massimo di prodotti che possiamo gestire.

typedef struct {
    char nome[21];  // nome del prodotto (max 20 caratteri + terminatore di stringa '\0')
    int quantita;   // quantità acquistata
} Prodotto;
    // fin da dove leggiamo la lista della spesa , fout dove scriviamo la lista combatta 
void ripulisci(FILE *fin, FILE *fout) {
    Prodotto prodotti[MAX_PR];// array che po memorizzare fino a 100 prodotti . 
    int numProdotti = 0;// una variabile per tenere traccia di quanti prodotti sono stati letti dal file.
    int i, j;

    // fscanf serve a leggere gli elementi del file, quindi questa legge il nome e il numero del prodotto == 2 serve a verificare 
    // se entrambi i valori nome e quantità siano stati letti correttamente, se è cosi numprodotti aumenta per memorizzare il
    // prossimo prodotto nel vettore.
    while (fscanf(fin, "%s %d", prodotti[numProdotti].nome, &prodotti[numProdotti].quantita) == 2) {
        numProdotti++;
    }
    // il secondo ciclo è inizializzato con j=i+1, cosi il ciclo non parte dal prodotto stesso, ma parte dal successivo
    // Elimina i duplicati!!!
    for (i = 0; i < numProdotti; i++) {// il ciclo che esplora ogni prodotto
        for (j = i + 1; j < numProdotti; j++) {// confronta l'elemnto il prodotto i con tutti quelli che seguono 
            if (strcmp(prodotti[i].nome, prodotti[j].nome) == 0) {// se i 2 prodotti sono ugauli oppure dublicati
                prodotti[i].quantita += prodotti[j].quantita;// sommiamo le loro quantità
                // Sposta gli elementi successivi per "rimuovere" l'elemento duplicato
                // ciclo che serve per eliminare i prodotti dublicati
                for (int k = j; k < numProdotti - 1; k++){// inizializzo k con j pk j è l'indice del prodotto duplicato e che
                //quindi da eliminare, // numprodotti-1 serve per spostare il prodotto dublicato a sinistra cosi il prodotto duplicato viene
                //sostituito dal prossimo.
                    prodotti[k] = prodotti[k + 1];// quindi il ciclo scorre gli elementi da j fino a num...-1 e per ogni indice k sposta
                }// il prodotto :prodotti[k+1] nella posizione prodotti[k], cosi si effettua uno spostamento a sinistra dei prodotti dopo quello dublicato 
                numProdotti--;//Dopo aver rimosso un prodotto (spostando gli altri), dobbiamo aggiornare il numero di prodotti (numProdotti),
                // perché ora il vettore contiene un prodotto in meno.Decrementiamo numProdotti per riflettere che abbiamo rimosso un duplicato.
                j--; // Decrementa per riesaminare la posizione corrente
                //Questo perché, dopo aver spostato gli elementi, il prodotto che si trova ora nella posizione j deve essere riesaminato.
                // Se non decrementiamo j, salteremmo la riga appena spostata (che potrebbe essere un altro duplicato).
            }
        }
    }

    // Scrivi i prodotti unificati nel file di output
    for (i = 0; i < numProdotti; i++) {
        fprintf(fout, "%s %d\n", prodotti[i].nome, prodotti[i].quantita);
    }
}
