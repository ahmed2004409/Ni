// conta differenza giorni 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct data{
    int giorno;
    int mese;
}typedef data; 

const int giorni_mese[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};//const indica che i valori dentro l'array non possono
// essere modificati 
int valida(Data d) {
    if (d.mese < 1 || d.mese > 12) {
        return 0; // mese non valido
    }
    if (d.giorno < 1 || d.giorno > giorni_mese[d.mese - 1]) {
        return 0; // giorno non valido
    }
    return 1; // data valida
}

int diff_date(data a, data b)
{
    if(!valid(a) || !valid(b))
    {
        return -1;
    }

    if((a.mese > b.mese) || (a.mese == b.mese && a.giorno > b.giorno))
    {
        return -1; 
    }

    int giorni = 0;
    // Calcola il numero di giorni tra le due date
    for (int i = a.mese - 1; i < b.mese - 1; i++) {// parto da a.mese-1 il che assomiglia a dire i = 0, solo che a.mese il suo
    //primo elemento sarà 1 e quindi devo fare a.mese-1 per essere nella posizione 0.
    // con la scritta i < b.mese - 1 cosi io continuo il ciclo fino a b.mese 
        giorni += giorni_mese[i];
    }
    giorni += b.giorno - a.giorno;
    return giorni;
}



int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Errore: specificare il nome del file\n");
        return 1;
    }
    
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Errore nell'aprire il file\n");
        return 1;
    }

    int g1, m1, g2, m2;
    int total_days = 0, count = 0;

    while (fscanf(file, "%d %d %d %d", &g1, &m1, &g2, &m2) == 4) {// sotto poi creiamo 2 date 
        Data d1 = {g1, m1};// data di ingresso 
        Data d2 = {g2, m2};// data di uscita 
        
        int diff = diff_date(d1, d2);// viene richiamata la funzione dif date che abbiamo costruito sopra cosi passiamo le 2 date e ci li calcola 
        if (diff >= 0) {// verifichiamo se la differenza dei giorni è valida ovvero se è uguale o maggiore di 0
            total_days += diff;//Si aggiunge la differenza di giorni calcolata a una variabile total_days che tiene il totale dei giorni validi.
            count++;//Si incrementa il contatore count che tiene traccia di quante coppie di date valide sono state lette.

        }
    }

    fclose(file);

    if (count > 0) {
        printf("Durata media dei soggiorni: %.2f giorni\n", (float) total_days / count);
    } else {
        printf("Nessun soggiorno valido trovato\n");
    }

    return 0;
}
    
    


