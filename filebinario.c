#include<stdio.h>

int main()
{
    FILE* fc;

    fc = fopen("file.txt", "wb");

    for(int i = 1; i <= 10; i++)
    {
        fwrite(&i, sizeof(int), 1, fc);
    }

    fclose(fc);
    printf("i numeri sono stati scritti nel file binario \n");

    return 0; 
}


