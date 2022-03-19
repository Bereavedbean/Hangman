//This is the first revision of the hangman project (same as the morbid childhood game)
//

//libraries
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

//global constants
const int TOTALARRAYLENGTH = 30;
const int LIFELIMIT = 10;


int main(void)
{
    //for the menu and misc configurations/stats
    int menuInput;
    menuInput = 0;
    int totalpoints = 0;
    int totalWins = 0;
    int totalGuesses = 0;
    int totalIncorrect = 0;
    int totalQuits = 0;
    int totalLosses = 0;

    //for the actual game
    char hangArray [2] [30];
    int i, j, randNum, counter, lives;
    char guessInput;
    bool notFinished = true;
        //used for loop within game
        char quit;

    //for functions
    //char wordgrabber(void);

    //random number seed
    srand((unsigned) time(NULL));

    do {

    switch (menuInput)
    {
        //displays menu
        case 0:
        initialmenu();
        break;

        //play a round
        case 1:

        //fills the array with the word
        ///////////////////////////

        for (i = 0; i < TOTALARRAYLENGTH; i++)
            {
            hangArray[1][i] = '_';
            }

        //Add in some words to the wordlist
        char wordList[50] [30] ={
        "pen",
        "pencil",
        "drone",
        "user",
        "computer",
        "mouse",
        "keyboard",
        "ethernet",
        "windows",
        "mac",
        "linux",
        "trackpad",
        "processor",
        "laptop",
        "desktop",
        "playdoh",
        "glasses",
        "water",
        "bottle",
        "rocket",
        "paper",
        "poster",
        "router",
        "competition",
        "university",
        "steel",
        "steal",
        "think",
        "center",
        "intellignt",
        "faith",
        "piety",
        "sin",
        "place",
        "pace",
        "pandemic",
        "cross",
        "cost",
        "power",
        "wrath",
        "drunk",
        "drink",
        "stink",
        "apple",
        "orange",
        "black",
        "green",
        "white",
        "red",
        "chick"
        };

        //generate random number for selection

        randNum = rand() % 50;

        //Sets up Word finally
        for (i = 0; i < 30; i++)
            {
                if (wordList[randNum] [i] != '\0')
                {
                hangArray [0] [i] = wordList [randNum] [i];
                }
                else {
                hangArray [0] [i] = '_';
                }
            }
        ///////////////////////////
        //begins the game that needs to be looped
    lives = 0;
    do {
    printf("\nCurrent score : %d", totalpoints);
    printf("\nCurrent lives : %d", LIFELIMIT - lives);

    printf("\nCurrent word: ");
    for (i = 0;i < TOTALARRAYLENGTH; i++)
        {
        if ((hangArray [0] [i] == hangArray [1] [i]) && (hangArray [0] [i] != '_'))
            {
            printf("%c ", hangArray [0] [i]);
            }

        if ((hangArray [0] [i] != hangArray [1] [i]) && (hangArray [0] [i] != '_'))
            {
            printf("_ ");
            }
        }

    //receives input for game
    printf("\nPlease enter a letter to guess : ");
    scanf(" %c", &guessInput);
    guessInput = tolower(guessInput);
    totalGuesses += 1;
    //checks for right answers
    counter = 0;
    for (i = 0; i < TOTALARRAYLENGTH; i++)
        {
        if ((hangArray [0] [i] == guessInput ) && (guessInput != hangArray [1] [i]))
            {
            hangArray [1] [i] = guessInput;
            counter++;
            }
        }
    totalpoints += counter * 10;
    if (counter == 0)
        {
        printf("\nSorry, that wasn't correct");
        totalpoints -= 2;
        lives += 1;
        totalIncorrect += 1;
        //checks if the person wants to quit
        printf("\nWould you like to give up? y/n : ");
        scanf(" %c", &quit);
        quit = tolower(quit);
        //checks if you ran out of lives
        if (lives == LIFELIMIT)
            {
            totalpoints -= 40;
            }
        }

    //check if the game is solved
    counter = 0;
    notFinished = false;
    for (i = 0; i < TOTALARRAYLENGTH; i++)
        {
        if (hangArray [0] [i] != hangArray [1] [i])
        notFinished = true;
        }


        } while ((quit != 'y') && (lives != LIFELIMIT) && notFinished);

        //resets stuff for future
        if (!notFinished)
            {
            totalpoints += 100;
            totalWins += 1;
            }
        else
            {
            totalLosses +=1;
            }

        lives = 0;

        //shows the word you missed
        printf("\nThe word was : ");
        for (i = 0; i < TOTALARRAYLENGTH; i++)
            {
            if (hangArray[0] [i] != '_')
                printf("%c", hangArray [0] [i]);
            }
        break;

        //Display the stats
        case 2:

        printf("\nYour total points are : %d", totalpoints);
        printf("\nYour total wins are : %d", totalWins);
        printf("\nYour total guesses : %d", totalGuesses);
        printf("\nYour total incorrect guesses : %d", totalIncorrect);
        printf("\nYour total losses : %d", totalLosses);

        break;

        //ends game/loop and acks as a void statement
        case 3:
        //add stuff
        break;

        default:
        printf("\nPlease enter a valid number");
    }
    printf("\n\nPlease enter an integer : ");
    scanf(" %d", &menuInput);
    }   while (menuInput != 3);

    printf("Program Ending");

    return 0;
}

//prints the initial menu
int initialmenu(void)
{
    printf("\nWelcome to hangman!\n");
    printf("Enter 0 to play a round\n");
    printf("Enter 1 to play a round\n");
    printf("Enter 2 to view stats\n");
    printf("Enter 3 to exit the game\n");
}
/*
int hangDisplay (char array [2] [30])
{
    int i;
    printf("Current word: ");
    for (i = 0;i < TOTALARRAYLENGTH; i++)
        {
        if ((array [0] [i] == array [1] [i]) && (array [0] [i] != "_"))
            {
            printf("%c ", array [0] [i]);
            }
        if ((array [0] [i] != array [1] [i]) && (array [0] [i] != "_"))
            {
            printf("_ ");
            }

        }
}
*/

/*
//grabs the word for the game from a wordlist
char wordgrabber(void)
{
    int i, j;
    char word[2] [30];
    //fills it with underscores
    for (i = 0; i < TOTALARRAYLENGTH; i++)
        {
        word[1][i] = '_';
        }

    //Add in some words to the wordlist
    char wordList[10] [30] ={

    "user",
    "computer",
    "mouse",
    "keyboard",
    "ethernet",
    "windows",
    "mac",
    "linux",
    "trackpad",
    "processor"
    };

    //generate random number for selection
    int randNum;

    randNum = rand() % 10;

    //Sets up Word finally
    for (i = 0; i < 30; i++)
        {
        if (wordList[randNum] [i] != "")
            {
            word [0] [i] = wordList [randNum] [i];
            } else {
            word [0] [i] = "_";
            }
        }

    for ( i = 0; i < 30; i++)
        {
        printf("%d, %c %c, \n", i, word[0] [i], word[1] [i]);
        }

    return word;
}
*/

//These are functions I decided not to use or didn't work


//fills an array entirely with one character
/*
char characterfiller30_02(char array[30][2], int l, int w, char character)
{
    int i, j;
    for (i = 0; i < l; i++)
        {
        for (j = 0; j < w; j++)
            {
            array[l] [w] = character;
            }
        }
    return array[30][2];
}
*/
