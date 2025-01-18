#include<stdio.h>

int main()
{
    FILE* fm;
    fm = fopen("File.txt", "r");

    if(fm == NULL)
    {
        printf("non si apre sto cazzo \n");
        return 1;
    }

    int cont = 0;
    char ca;
    while((ca = fgetc(fm)) != EOF)
    {
        if(ca == '\n')// appena che trova un \n significa che è la fine della riga e quindi conta 1
        {
            cont++;
        }
        
    }

    printf("sono %d righe \n", cont);

    fclose(fm);

    return 0;
}
