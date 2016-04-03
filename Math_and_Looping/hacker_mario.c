#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // initialize pyramid_height
    int pHeight;
    // start main loop
    do
    {
        printf("Please enter a height for the pyramid: ");
        pHeight = GetInt();	
        if (pHeight == 0)
        {
            return 0;
		}
    }while((pHeight < 0) || (pHeight > 23));

    // start inner loop
    for (int cHeight=0; cHeight <= (pHeight - 1); cHeight++)
    {
        int counter = 0;
        int total_spaces=(pHeight - cHeight) - 1l;
        while (counter < total_spaces)
        {
            printf(" ");
            counter++;
        }
        counter = 0;
        int total_blocks = cHeight + 2;
        // start inner-inner loop
        while (counter < total_blocks)
        {
            printf("#");
            counter++;
        }
        if (counter == total_blocks)
        {
            printf ("  ");
        }
        counter = 0;
        total_spaces=(pHeight - cHeight) - 1l;
        while (counter < total_blocks)
        {
            printf("#");
            counter++;
        }
        printf("\n");	
    }
    

    return 0;
}
