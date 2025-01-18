#include<stdio.h>

int main()
{
    FILE* fc;

    fc = fopen("File.txt", "r");

    if(fc == NULL)
    {
        printf("non si apre il file \n");
        return 1; 
    }

    if(rename("File.txt", "file.22") == 0 )
    {
        printf("file rinominato con succeso \n");
    }
    else{
        printf("il file non si è rinomianto con successo \n");
    }

    fclose(fc);
    return 0; 
}
