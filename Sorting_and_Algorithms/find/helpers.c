/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
   
    for (int i = 0; i < n; i++)
    {
        if (values[i] == value)
            return true; 
    }
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    int placeHolder; 
    for(int i=0; i<n-1; i++)
        if (values[i]>values[i+1])
        {
            placeHolder = values[i+1];
           values[i+1]=values[i];
            values[i]=placeHolder;
        }
}
