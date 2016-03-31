/**
 * fifteen.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
char board[DIM_MAX][DIM_MAX];
int cTileX = 0;
int cTileY = 0;
int nTileX = 0;
int nTileY = 0;


// dimensions
int d;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE* file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("\nTile to move: ");
        int tile = GetInt();
        
        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }
    
    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 **/
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(1000500);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 **/
void init(void)
{
    /**
    * Create local variables
    **/
    int top = d * d;
    int p = top;

    /**
    * assign array to 2D array
    **/
    for (int i = 0; i <= d - 1; i++)
    {
        for (int j = 0; j <= d - 1; j++)
        {
            p--;
            if (i == d - 1 && j == d - 1)
            {
                board[i][j] = 0; 
            }
            else
            {
                board[i][j] = p; 
            }
            
            /*
            * 
            * If board has an even number of tiles swap 1 and 2
            *
            **/

        }
    }
        if ( top % 2 == 0 ) // if # of tiles is even
        {
            int swapInit = 0;
            swapInit = board[ d - 1][ d - 3];
            board[ d - 1 ][ d - 3 ] = board[ d - 1 ][ d - 2];
            board[d - 1][ d - 2] = swapInit;
        }

    
}

/* Prints the board in its current state.
*/
void draw(void)
{
    clear();
    for (int i = 0; i < d; i++)
    {
        printf("\n\n");
        for (int j = 0; j < d; j++)
        {
            ( board[i][j] == 0 ) ? printf("  _ ") : printf(" %2i ",board[i][j]) ;
        }
    }
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int tile)
{
    int swap = 0;
    /**
    * Get Current Tile Location
    **/
    for ( int i = 0; i < d; i++ )
    {
        for ( int j = 0; j < d; j++ )
        {
            if ( board[i][j] == tile )
            {
                nTileX = i;
                nTileY = j;

            }
            else if ( board[i][j] == 0 ) 
            {
                cTileX = i;
                cTileY = j;    
            }
        }

    }
    /**
    * Compare tiles against okay moves
    **/
    if ( 
            ( nTileX == cTileX - 1 && nTileY == cTileY ) || 
            ( nTileX == cTileX && nTileY == cTileY + 1 )  ||
            ( nTileX == cTileX + 1 && nTileY == cTileY ) ||
            ( nTileX == cTileX && nTileY == cTileY - 1)
        )
        {
            //If it is == to an okay tile, swap them
            swap = board[nTileX][nTileY];
            board[nTileX][nTileY] = board[cTileX][cTileY];
            board[cTileX][cTileY] = swap;
            return true;
        }
    return false;
}

/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(void)
{
    /**
    * Check each row that board[n] is less than board [n+1]
    **/
    int winner = 1;
    for ( int i = 0; i < d  - 1 ; i++ )
    {
        for ( int j = 0; j < d - 1 ; j++ )
        {
                if ( board[i][j] > board[i][j + 1] )
                {
                        usleep(5000);
                        winner = 0;
                }
                if ( board[i][j] > board[i + 1][j] )
                {
                    usleep(5000);
                    winner = 0;
                }
        }
    } if ( winner == 1 && board[d-1][d-1] == 0 )
    {
        return true;
    }
    else
        return false;
}
