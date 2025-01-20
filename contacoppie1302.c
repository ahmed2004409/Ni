// conta coppie di un numero 
#include<stdio.h>

int conta_coppie(int n )
{
    int ultimacifra= n % 10;
    int penultimacifra = (n / 10) % 10; 
    int cont = 0; 

    if(n < 10)
    {
        return 0;
    }

    if( ultimacifra != penultimacifra)
    {
        return conta_coppie(n / 10);;
    }
    else{
        return 1+ conta_coppie(n / 10);
         

    }

}       

/*int main() {
    // Test con alcuni numeri
    printf("%d -> %d coppie\n", 7752211, conta_coppie(7752211)); // 3 coppie
    printf("%d -> %d coppie\n", 2344, conta_coppie(2344)); // 1 coppia
    printf("%d -> %d coppie\n", 3648, conta_coppie(3648)); // 0 coppie
    printf("%d -> %d coppie\n", 1888, conta_coppie(1888)); // 2 coppie
    printf("%d -> %d coppie\n", 2, conta_coppie(2)); // 0 coppie
    printf("%d -> %d coppie\n", 3333, conta_coppie(3333)); // 3 coppie

    return 0;
}   
*/ 