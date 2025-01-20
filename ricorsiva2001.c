// stampami la lettere più piccola nella parola 
#include<stdio.h>
#include<string.h>
#define N 20

char min_ch(char* s)
{
    if(*s == '\0')// caso base se la stringa è vuota ritorna '\0'
    {
        return '\0';
    }

    char min = min_ch(s+1);// faccio la chiamata ricorsiva per poter prendere e poi esaminare tutti i numeri, quando esaurisco 
    // tutte le lettere arrivo a \0  e la chiamata ricorsiva si ferma 
    if( min == '\0' || *s < min)// poi questa if risale nella funzione ricorsiva facendo il confronto 
    {
        return *s;// se *s è il più piccolo lo restituisce
    }
    else{
        return min; // altrimenti restituisce il più piccolo;
    }
}

/*int main() {
    // Esempi di stringhe
    char str1[] = "MELO";
    char str2[] = "BURRO";
    char str3[] = "ZANGOLA";
    char str4[] = "F";
    char str5[] = "";

    printf("Minimo di '%s': %c\n", str1, min_ch(str1));
    printf("Minimo di '%s': %c\n", str2, min_ch(str2));
    printf("Minimo di '%s': %c\n", str3, min_ch(str3));
    printf("Minimo di '%s': %c\n", str4, min_ch(str4));
    printf("Minimo di '%s': %c\n", str5, min_ch(str5));

    return 0; 
}*/
