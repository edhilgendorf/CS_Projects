
#include <stdlib.h>
#include <string.h>
#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <time.h>


int main(int argc, string argv[])
{
/**
* Random Test
**/
/**
    srand(time(NULL));
    int a=rand()%9+1;
    printf("%i", a);


    * char as num via ascii
    char letterOne='B';
    char letterTwo='A';
    if (letterTwo>=letterOne)
    {
        printf("B is greater than A, test success!");
    }
    else
        printf("Failure.");
**/
    int d = 4;
    int board[d][d];

    for (int i=0; i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
           board[i][j]=i*d+j; 
        }

    }

    for (int i=0; i<4;i++)
    {
        printf("\n");
        for(int j=0;j<4;j++)
        {
            printf("  %i  ", board[i,j]);    
        }

    }

    printf("\n\n Swap 0, 0 and 0, 1\n\n");
    


    return 0;
}

