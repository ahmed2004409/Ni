#include<stdio.h>

int main()
{
    FILE* fc;

    fc= fopen("file22", "r");

    if(fc == NULL)
    {
        printf("non si apre il file \n");
        return 1; 
    }
    
    fclose(fc);// bisogna chiudere il file prima di eliminarlo .

    if(remove("file22") == 0)
    {
        printf("file eliminato con successo \n");
    }
    else{
        printf("impossibile eliminare il file \n");
    }

    return 0; 
}
