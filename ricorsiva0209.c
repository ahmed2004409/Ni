// in un numero n sostituisci ogni numero con il suo successivo tranne il 9 viene sostituito con 0
#include<stdio.h>

int sost(int n)
{
    int ultimacifra = n % 10;

    if(n == 0)
    {
        return 0; 
    }

    if(ultimacifra == 9)
    {
        ultimacifra = 0; 
    }

    else{
        
        ultimacifra += 1;
    }
    return sost(n / 10) * 10 + ultimacifra; // abbiamo moltiplicato per 10 cosi una che arrivo a questo punto richiamo la funzione 
}// escludendo l'ultima cifra , quando *10 cosi sposto tutto il numero a sinistra e aggiungo poi l'ultima cifra che ho fatto
    // cioè il risultato delle condizooni if
int main()
{
    int n;

    // Leggi il numero da input
    printf("Inserisci un numero: ");
    scanf("%d", &n);

    // Chiamata alla funzione e stampa del risultato
    printf("Il numero modificato è: %d\n", sost(n));

    return 0;
}

// come funzione la chiamata ricorsiva: 
/*Esempio con un numero:
Supponiamo che n = 34979:

Prima chiamata: sost(34979):

ultimacifra = 9, che diventa 0.
Chiamata ricorsiva: sost(3497).
Seconda chiamata: sost(3497):

ultimacifra = 7, che diventa 8.
Chiamata ricorsiva: sost(349).
Terza chiamata: sost(349):

ultimacifra = 9, che diventa 0.
Chiamata ricorsiva: sost(34).
Quarta chiamata: sost(34):

ultimacifra = 4, che diventa 5.
Chiamata ricorsiva: sost(3).
Quinta chiamata: sost(3):

ultimacifra = 3, che diventa 4.
Chiamata ricorsiva: sost(0).
Caso base: sost(0):

Ritorna 0.
Ora risaliamo nella ricorsione:

Quinta chiamata: Restituisce 4 (per sost(3), ultimacifra è 4).

sost(0) * 10 + 4 = 0 * 10 + 4 = 4.
Quarta chiamata: Restituisce 45 (per sost(34), ultimacifra è 5).

4 * 10 + 5 = 45.
Terza chiamata: Restituisce 450 (per sost(349), ultimacifra è 0).

45 * 10 + 0 = 450.
Seconda chiamata: Restituisce 4508 (per sost(3497), ultimacifra è 8).

450 * 10 + 8 = 4508.
Prima chiamata: Restituisce 45080 (per sost(34979), ultimacifra è 0).

4508 * 10 + 0 = 45080.*/