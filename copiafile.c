#include<stdio.h>

int main()
{
    FILE* fc;
    FILE* fm;
    fc= fopen("File.txt", "r");// devo leggere il primo per questo uso r, e quidni cosi devo controllare con if == NULL
    fm= fopen("file22", "w");// il secondo mi si viene creato automaticamente siccome uso w, quindi non uso if == NULL

    if(fc == NULL)
    {
        printf("non si apre il file \n");
        return 1;
    }

    int ca;
    while((ca = fgetc(fc)) != EOF)
    {
        fputc(ca, fm);// metto prima il coso dal quale devo copiare , poi il puntatore del file dove voglio trasformare
    }

    fclose(fc);
    fclose(fm);

    return 0; 
}
