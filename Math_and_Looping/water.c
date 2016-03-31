#include <stdlib.h>
#include <string.h>
#include <cs50.h>
#include <stdio.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    printf("Enter time in minutes spent in the shower: ");
    int usrTime = GetInt();
    int minOz = (usrTime*192);
    int usrBottle = (minOz/16);
    printf("\nMinutes: %i\nBottles: %i\n", usrTime, usrBottle);
    return 0;
}

