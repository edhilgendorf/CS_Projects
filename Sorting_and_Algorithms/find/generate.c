/**
 * generate.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Generates pseudorandom numbers in [0,LIMIT), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 */
 
#define _XOPEN_SOURCE

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// constant
#define LIMIT 65536

int main(int argc, string argv[])
{
    // if arguments provided is not two or three then print error message
    if (argc != 2 && argc != 3)
    {
        printf("Usage: generate n [s]\n");
        return 1;
    }

    // Cast the first argument as integer n
    int n = atoi(argv[1]);

    // if there are two arguments pass the first argument into srand
    if (argc == 3)
    {
        srand48((long int) atoi(argv[2]));
    }
    else //if there are more or less then pass in the time
    {
        srand48((long int) time(NULL));
    }

    // iterate through i until it hits n, which is the first argument supplied
    for (int i = 0; i < n; i++)
    {
        //for each iteration print drand48 multiplied by the constant 65536 defined as LIMIT
        printf("%i\n", (int) (drand48() * LIMIT));
    }

    // success
    return 0;
}
