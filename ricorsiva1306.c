// hai una stringa la devi dividere in una stringa che contiene le lettere minuscole, una per le lettere minuscole e 
// contare quanti caratteri strani sono rimasti nella stringa d'origine 
#include<stdio.h>
#include<ctype.h>

int distingui(char s[], char up[], char low[]) {
    static int i = 0;  // Utilizzo un indice statico per mantenere il valore tra le chiamate ricorsive
    int j = 0;  // Una variabile per contare i caratteri non alfabetici
    static int j_up = 0, j_low = 0;  //j_up tiene traccia della posizione corrente nella stringa up[], mentre j_low tiene traccia 
    //della posizione corrente nella stringa low[].

    if(s[i] == '\0') {  // Caso base: quando raggiungiamo la fine della stringa
        up[j_up] = '\0';  // Aggiungiamo il terminatore per le stringhe
        low[j_low] = '\0'; // Aggiungiamo il terminatore per le stringhe
        return 0;
    }

    if(islower(s[i])) {  // Se il carattere è minuscolo
        low[j_low] = s[i]; // Aggiungi alla stringa low
        up[j_up] = '\0';   // Lascia vuoto l'array up
        j_low++;           // Incrementa l'indice per low[]
    }
    else if(isupper(s[i])) {  // Se il carattere è maiuscolo
        up[j_up] = s[i];  // Aggiungi alla stringa up
        low[j_low] = '\0'; // Lascia vuoto l'array low
        j_up++;            // Incrementa l'indice per up[]
    }
    else {  // Se il carattere non è né maiuscolo né minuscolo
        up[j_up] = '\0';  // Lascia vuoto l'array up
        low[j_low] = '\0'; // Lascia vuoto l'array low
        j = 1;             // Incrementiamo j per i caratteri non alfabetici
    }

    i++;  // Passiamo al prossimo carattere

    // Restituisce il numero totale di caratteri non alfabetici
    return j + distingui(s, up, low);
}

int main() {
    char s[] = "2Ew?j7y9TRf$";
    char up[100] = "";  // Stringa vuota per i caratteri maiuscoli
    char low[100] = ""; // Stringa vuota per i caratteri minuscoli

    int num_j = distingui(s, up, low);  // Chiamata ricorsiva iniziale

    // Stampa i risultati
    printf("Maiuscoli: %s\n", up);
    printf("Minuscoli: %s\n", low);
    printf("Numero di caratteri non alfabetici: %d\n", num_j);

    return 0;
}
