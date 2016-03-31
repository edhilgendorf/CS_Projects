#include <stdio.h>
#include <cs50.h>

// Function to get the floating point number from the user,
// cast it as an integer, then return it to Main
int getChange()
{
    int i; 
    do
    {
        printf("Enter some float: "); 
        float TotalChange = GetFloat();
        i = (int) ((TotalChange * 100) + 0.5);
    }while(i < 0);	
    return i;
}

int main(void)
{
    // ***************************
    // Initialize Static Variables//
    int coins, quarters, dimes, nickels, pennys;
    coins = quarters = dimes = nickels = pennys = 0; 
    int intChange = getChange();
    int cChange = intChange % 100;
    int dollars = ((intChange - cChange) / 100);
    while(cChange >= 25)
    {
        cChange = cChange - 25;
        quarters = quarters + 1;
        coins = coins + 1;
    }
    // Second Loop, see if dimes can be removed.
    while(cChange >= 10)
    {
        cChange = cChange - 10;
        dimes = dimes + 1;
        coins = coins + 1;
    }
    // Third loop, see if nickels can be removed.
    while(cChange >= 5)
    {
        cChange = cChange - 5;
        nickels = nickels + 1;
        coins = coins + 1;
    }
    // Final loop, remove pennys.
    while ((cChange >= 1) && (cChange > 0))
    {
        cChange = cChange - 1;
        pennys = pennys + 1;
        coins = coins + 1;
    }
    int dChange;
    dChange = dollars * 4;
    coins = coins + dChange;
    printf("%i\n", coins);	
    return 0;
}
