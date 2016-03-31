#include <stdlib.h>
#include <string.h>
#include <cs50.h>
#include <stdio.h>
#include <ctype.h>

int main(int argc, string argv[])
    {
    //=========== Initialize Variables ==========// 
    int placeHolder, n = 10, values[10] = { 4, 5, 1, 9, 2, 4, 3 , 10, 7, 6 };

    //============ Sort Values ================//
    for(int j=0; j < (n-1); j++) //Outer loop, complete for n times, n=array size
    {
        for(int i=0; i < (n-1); i++) //Inner loop, check each number and swap if needed for n time
            if (values[i]>values[i+1])
            {
                 placeHolder = values[i+1];
                 values[i+1]=values[i];
                 values[i]=placeHolder;
            }
    }
    //========== Print Values ===========//
    for (int k=0; k < n; k++)
        printf("%i\n", values[k]);
    return 0;
}

