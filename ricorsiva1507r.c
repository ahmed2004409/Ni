// cambia matrice sommanda i valori fino a i e fino a j 

/*#include <stdio.h>
#define R 3
#define C 4 

void integrale(int m[][C]);

void integrale(int m[][C])
{
   for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            for(int k = 0; k <= i; k++)
            {
                for(int n = 0; n <= j; n++)
                {
                  if (k != i || n != j) {  // Non aggiungere il valore a se stesso
                        m[i][j] += m[k][n]; 
                    }
                }
            }
            
        }
    }

    
    
}




int main()
{
    int m[R][C] = {
        {1, 3, 8, 2},
        {10, 5, 12, 3},
        {3, 2, 12, 16}
    };
    
    
    printf("la matrice originale è cosi \n");

    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            printf("%d ", m[i][j]);

        }
        printf("\n");
    }

    integrale(m); 

    printf("la nuova matrice è : \n");

    for(int i = 0; i < R; i++)
    {
        for(int j= 0; j < C; j++ )
        {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }

    return 0; 

}*/



