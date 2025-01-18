 #include <stdio.h>
int main() 
{
    FILE* file1 = fopen("File.txt", "r");
    if (file1 == NULL) 
    {
        perror("Errore durante l'apertura del file");
        return 1;
    }

    char ca; 
    while ((ca = fgetc(file1)) != EOF)// il programma legge il contenuto del file e lo assegna al contenitore ca 
    {
        putchar(ca);// questa cosa qui mi lo stampa a video
    }
    printf("\n");
    fclose(file1);

    return 0;
}


/*#include<stdio.h>

int main()
{
    FILE* fc; 

    fc = fopen("File.txt", "r");

    char f[1000];
    if(fc != NULL)
    {
        while(fgets(f, 1000 , fc))
        {
            printf("%s", f);
        }
    }
    else{
        printf("file non si apre \n");
    }
     printf("\n");

    fclose(fc);

    return 0; 
}
*/
