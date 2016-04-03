#include <stdlib.h>
#include <string.h>
#include <cs50.h>
#include <stdio.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    long long credNum = 0;
    int curNum = 0;
    printf ("\nNumber: ");    
    credNum = GetLongLong();
    curNum = credNum/1000%2;
    printf ("\n Number in fourth position is: %i", curNum);
    return 0;
}

