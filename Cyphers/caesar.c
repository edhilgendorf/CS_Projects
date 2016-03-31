#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc < 2)
    {
        printf("shit");
        return 1;
    }
    char input = argv[1][0];
    if (isdigit(input))
    {
        int theCsr = atoi(argv[1]);
        int alph = 0;
        // Get the string to be encrypted
        string plainStr = GetString();
        for (int i = 0; i < strlen(plainStr); i++)
        {
            int num = plainStr[i];

            if (!isalpha(plainStr[i]))
            {
                printf("%c", plainStr[i]);
            }
            else
            {
                if (islower(plainStr[i]))
                    alph = 97;
                if (isupper(plainStr[i]))
                    alph = 65;
                num = num - alph;
                int c = (num + theCsr) % 26;
                c = c + alph;
                printf("%c", c);
            }
        }
    }
    else
        return 1;
    printf("\n");
    return 0;
}
