#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    int sAlph = 0;
    int pAlph = 0;
    int vigCyph = 0;
    /* Variables to iterate through the password */
    int curX = 0;

    /* Check argc length to make sure there is at least one argument
       provided */
    if (argc < 2 || argc > 3)
    {
        printf("shit");
        return 1;
    }

    /* Get the string word to be used for the cipher from the first
       argument provided, string type */
    string passPhrase = argv[1];
    int totalX = strlen(passPhrase);
    for (int count = 0; count < strlen(passPhrase); count++)
    {
        if (!isalpha(passPhrase[count]))
        {
            printf("shit");
            return 1;
        }
    }

    /* Get the string to be encrypted */
    string plainStr = GetString();
    int x = 1;
    int num = 0;
    int c = 0;
    for (int i = 0; i < strlen(plainStr); i++)
    {
        /* Get the number of the current character as an integer */
       num = plainStr[i];
       if (isalpha(plainStr[i]))
       {
//            printf("\n\nLetter: %c:\n", num);

           
            // apply formula here
            if (islower(passPhrase[curX]))
                pAlph = 97;
            if (isupper(passPhrase[curX]))
                pAlph = 65;
            if (islower(plainStr[i]))
                sAlph = 97;
            if (isupper(plainStr[i]))
                sAlph = 65;


//            printf("vigCyph(%i) = (passPhrase[curX](%i) - palph(%i)\n\n",(passPhrase[curX]-pAlph), passPhrase[curX], pAlph);
            vigCyph = (passPhrase[curX] - pAlph);
            
 //           printf("num(%i) = num(%i) - sAlph(%i)\n\n", (num - sAlph), num, sAlph);
            num = num - sAlph;

  //          printf("c(%i) = (num(%i) + vigCyph(%i) mod 26)\n\n", (num + vigCyph) % 26, num, vigCyph);
            c = (num + vigCyph) % 26;

   //         printf("c(%i) = c(%i) + sAlph(%i)\n\n", c + sAlph, c, sAlph);
            c = c + sAlph;


    //        printf("curX(%i)(%c) = x(%i) mod totalX(%i)\n\n", (x % totalX),passPhrase[curX], x, totalX);
            curX = x % (totalX);

            printf("%c", c);
            x++;
       }
        else
            /* Check if current char is alpha, if not print it out */
            if (!isalpha(plainStr[i]))
                printf("%c", plainStr[i]);
        }
    printf("\n");
    return 0;
}
