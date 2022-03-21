
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
    int i, j, randNum, counter, lives, localGuesses;
    char guessInput;
    bool notFinished = true, doubleGuess;
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
        {'p', 'e', 'n'},
        {'p', 'e', 'n', 'c', 'i', 'l'},
        {'d', 'r', 'o', 'n', 'e'},
        {'u', 's', 'e', 'r'},
        {'c', 'o', 'm', 'p', 'u', 't', 'e', 'r'},
        {'m', 'o', 'u', 's', 'e'},
        {'k', 'e', 'y', 'b', 'o', 'a', 'r', 'd'},
        {'e', 't', 'h', 'e', 'r', 'n', 'e', 't'},
        {'w', 'i', 'n', 'd', 'o', 'w', 's'},
        {'m', 'a', 'c'},
        {'l', 'i', 'n', 'u', 'x'},
        {'t', 'r', 'a', 'c', 'k', 'p', 'a', 'd'},
        {'p', 'r', 'o', 'c', 'e', 's', 's', 'o', 'r'},
        {'l', 'a', 'p', 't', 'o', 'p'},
        {'d', 'e', 's', 'k', 't', 'o', 'p'},
        {'p', 'l', 'a', 'y', 'd', 'o', 'h'},
        {'g', 'l', 'a', 's', 's', 'e', 's'},
        {'w', 'a', 't', 'e', 'r'},
        {'b', 'o', 't', 't', 'l', 'e'},
        {'r', 'o', 'c', 'k', 'e', 't'},
        {'p', 'a', 'p', 'e', 'r'},
        {'p', 'o', 's', 't', 'e', 'r'},
        {'r', 'o', 'u', 't', 'e', 'r'},
        {'c', 'o', 'm', 'p', 'e', 't', 'i', 't', 'i', 'o', 'n'},
        {'u', 'n', 'i', 'v', 'e', 'r', 's', 'i', 't', 'y'},
        {'s', 't', 'e', 'e', 'l'},
        {'s', 't', 'e', 'a', 'l'},
        {'t', 'h', 'i', 'n', 'k'},
        {'c', 'e', 'n', 't', 'e', 'r'},
        {'i', 'n', 't', 'e', 'l', 'i', 'g', 'e', 'n', 't'},
        {'f', 'a', 'i', 't', 'h'},
        {'p', 'i', 'e', 't', 'y'},
        {'s', 'i', 'n'},
        {'p', 'l', 'a', 'c', 'e'},
        {'p', 'a', 'c', 'e'},
        {'p', 'a', 'n', 'd', 'e', 'm', 'i', 'c'},
        {'c', 'r', 'o', 's', 's'},
        {'c', 'o', 's', 't'},
        {'p', 'o', 'w', 'e', 'r'},
        {'w', 'r', 'a', 't', 'h'},
        {'d', 'r', 'u', 'n', 'k'},
        {'d', 'r', 'i', 'n', 'k'},
        {'s', 't', 'i', 'n', 'g'},
        {'o', 'r', 'a', 'n', 'g', 'e'},
        {'a', 'p', 'p', 'l', 'e'},
        {'b', 'l', 'a', 'c', 'k'},
        {'g', 'r', 'e', 'e', 'n'},
        {'w', 'h', 'i', 't', 'e'},
        {'r', 'e', 'd'},
        {'c', 'h', 'i', 'c', 'k', 'e', 'n'},
        {'w', 'i', 'r', 'e', 'l', 'e', 's', 's'}
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
    localGuesses = 0;
    char stringChecker[30] = {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'};
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

    //receives input for game and checks for duplicates
    do {
    doubleGuess = false;
    printf("\nPlease enter a letter to guess : ");
    scanf(" %c", &guessInput);
    guessInput = tolower(guessInput);

    for (i = 0; i < 30; i++)
        {
        //printf("Testing %c : %c : %d", guessInput, stringChecker[i], i);
         if (guessInput == stringChecker[i])
                {
                doubleGuess = true;
                //printf("It worked%c", guessInput);
                }
        }

    if (doubleGuess)
        printf("Please enter a valid guess (No double guessing)");
    } while (doubleGuess);
    stringChecker [localGuesses] = guessInput;
    localGuesses += 1;
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
            printf("\nCongrats on getting it right!!");
            }
        else
            {
            totalLosses +=1;
            printf("\nSorry, you didn't get it");
            }

        lives = 0;

        //shows the word you missed
        printf("\nThe word was : ");
        for (i = 0; i < TOTALARRAYLENGTH; i++)
            {
            if (hangArray[0] [i] != '_')
                printf("%c", hangArray [0] [i]);
            }
        printf("\n");
        initialmenu();
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
    printf("Enter 0 to show the initial menu\n");
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
