
#include<stdio.h>

int main()
{
    FILE* fc;

    fc = fopen("File.txt", "w");

    if(fc == NULL)
    {
        printf("file non si apre \n");
        return 1; 
    }

    fputs("ahmed is a baba yaga \n", fc);// stamp semplicemente una frase in un file :(
    fputs("motherfuckers hope you alla fucken die \n", fc);
    fputs("a7a men hena lbokra \n", fc);
    fputs("bla bla bla bla bla \n", fc);

    fclose(fc);
    return 0; 
}
