#include<stdio.h>

void carica(int* a);
int triangolo(int a, int b);
void stampa_trinagolo(int a);

int main()
{
    int n;

    carica(&n);

    printf("il trinagolo desiderato è cosi : \n");
    
    stampa_trinagolo(n);// non ho fatto la chiamata della funzione ricorsiva nel main perchè è stata già chiamata nella funz
    // stampa e quindi ogni volta in cui viene fatta la chiamata ricorsiva nella funz stampa viene stampato ogni singolo valore
    return 0;// del triangolo di tartaglia.

}

void carica(int* a)
{
    printf("inserisci fino a dove vuoi ottnere il trinagolo di tartaglia \n");
    scanf("%d", a);
}

int triangolo(int a, int b)
{
    if(b == 0 || b == a)
    {
        return 1;
    }// la forma usato qui sotto per calcolare gli elementi e una formula del triangolo t(n,k) = t(n-1. k-1) + t(n-1,k)
    
    return triangolo(a - 1, b - 1) + triangolo(a - 1, b);// io devo calcoare ogni volta 2 valori se facesssi una sola chiamata ricorsiva
}// riesco di perdere uno di questi valori
    // una chiamata ricorsiva calcola un singolo valore e non tutti i valori in ordine 
    //e quindi in un caso del genere io ho biosgna di una funzione con ciclo
    // per poter stamapre ogni singolo valore 
void stampa_trinagolo(int a)
{
    for(int i = 0; i < a ; i++)// ciclo delle righe
    {
        for(int j = 0; j <= i; j++)// ciclo delle colonne 
        {
            printf("%d ", triangolo(i, j));// faccio la chiamata ricorsiva per calcolare un valore alla volta partendo dalla riga
        }// i e poi andando a calcoare tutti i valori nelle colonne della prima secodna terza ecc riga 
        printf("\n");
    }
}
