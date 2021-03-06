//This is the third revision of the hangman project (same as the morbid childhood game)
//

//libraries
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//definitions for Hansen and other people
//I ran this on my personal linux box, so you will need to change these to make it work
#define WORDLISTLOCATION "###FileLocation###"
#define SCOREBOARDLOCATION "###FileLocation"

//definitions
#define TOTALARRAYLENGTH 30
#define ALPHABETLENGTH 26
#define LIFELIMIT 10
#define NAMELENGTH 50
#define TOTALPLAYERS 50
#define MAXWORDS 50

//Structs
/*
struct Players {
    char


};
*/
struct WordHolder {
    char wordArray[TOTALARRAYLENGTH];
    char displayWord[TOTALARRAYLENGTH];
};

//global constants
const char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int main(void)
{
    //for the menu and misc configurations/stats
    int menuInput;
    int totalSessionPoints = 0;
    int totalSessionWins = 0;
    int totalSessionGuesses = 0;
    int totalSessionIncorrect = 0;
    int totalSessionLosses = 0;

    //for the actual game
    struct WordHolder word;
    int i, j, z, randNum, counter, lives, localGuesses, fullWordCycle;
    char guessInput[TOTALARRAYLENGTH], grabWord[TOTALARRAYLENGTH];
    bool notFinishedGame = true, doubleGuess, letterCheck, doubleWord;
    bool doubleWordList[50];
    for (i = 0; i < 50; i++)
    {
    doubleWordList[i] = true;
    }

        //used for loop within game
        char quit;

    //for the player stuff and scoreboard
    char tempName [50] = {0};
    char playerName[50][50] = {0};
    int playerScore[50] = {0};
    int currentPlayer = 0;
    int playerAmmount = 0;
    int playerCounter = 0;
    //scoreboard sorting stuff
    char tempDisplayNames [50] [50] = {0};
    int tempTotalScore[50] = {0};
    int intTemp = 0;
    char charTemp[50] = {0};
    //random number seed
    srand((unsigned) time(NULL));

    //used for working with files
    char singleBuffer;

    //-----------------------------------------------------------------------------
    //function to get words
    FILE *wordPTR;
    //checks if available
    if (wordPTR = fopen(WORDLISTLOCATION, "r") == NULL)
        {
        printf("ERROR, Can't find wordlist file");
        //exit program
        exit(1);
        }
    wordPTR = fopen(WORDLISTLOCATION, "r");
        //Add in some words to the wordlist
    char wordList[50] [TOTALARRAYLENGTH];
    int error = 1;
    char buffer [TOTALARRAYLENGTH];
    i = 0;
    while (error != -1)
    {
        //printf("Hello");
        error = fscanf(wordPTR, "%s\n", &buffer);
        for (j = 0; j < TOTALARRAYLENGTH; j++)
            {
            wordList [i] [j] = buffer[j];
            }
        memset(buffer, 0, strlen(buffer));
        i++;
    }
    fclose(wordPTR);



    //-----------------------------------------------------------------------------
    //this checks if the file is empty and available
    FILE *statPTR;
    if (statPTR = fopen(SCOREBOARDLOCATION, "r") == NULL)
        {
        printf("ERROR, Can't find the scoreboard file");
        //exit program
        exit(1);
        }
    statPTR = fopen(SCOREBOARDLOCATION, "r");
    int size;
    if (statPTR != NULL) {
        fseek(statPTR, 0, SEEK_END);
        size = ftell(statPTR);

        if (size == 0)
            {
            printf("Congratulations, you're the first player!\n");
            menuInput = 4;
            }
        else
            {
            menuInput = -1;
            while ((menuInput !=3) && (menuInput != 4))
                {
                printf("Enter 3 to login to an already created user\nEnter 4 to create a new user account\nEnter here : ");
                scanf("%d", &menuInput);
                getchar();
                }
            }
    }
    fclose(statPTR);
    //gets the first players name and adds it to the array
    /*
    printf("Please enter your player name : ");
    gets(tempName);
    for (i = 0; i < NAMELENGTH; i++)
    {
        playerName[currentPlayer] [i] = tempName[i];
    }
    */
    //this is where the loop for the entire game is
    do {

    switch (menuInput)
    {
        //displays menu
        case 0:
        initialmenu();
        break;

        //play a round
        case 1:

        //fills the array with the
        ///////////////////////////

        for (i = 0; i < TOTALARRAYLENGTH; i++)
            {
            word.displayWord[i] = '_';
            }

        //checks to see if all words have been looped through
        fullWordCycle = 0;
        for (i = 0; i < 50; i++)
            {
            if (doubleWordList[i] == true)
                {
                //printf("\nfound one word true and set worcycle +1 %d", i);
                fullWordCycle++;
                }
            }
            //checks and resets it back to false
        if (fullWordCycle == 0)
            {
            //printf("\nAll false");
            for (i = 0; i < 50; i++)
                {
                doubleWordList[i] = true;
                }
            }
        //checks to see if the same word has been repeated and then loops back until a word that hasn't is selected
        doubleWord = true;
        while (doubleWord)
        {
            //generate random number for selection
            randNum = rand() % MAXWORDS;
            if (!doubleWordList[randNum])
                {
                //printf("\nIm going to be looping around doubleword again");
                doubleWord = true;
                }
            else
                {
                printf("\nWord Successfully found");
                doubleWord = false;
                }
        }
        //printf("\nDoubleWordList %d is false", randNum);
        doubleWordList[randNum] = false;
        // sets up word for word guess
        for (i = 0; i < TOTALARRAYLENGTH; i++)
        {
            grabWord[i] = wordList [randNum] [i];
        }

        //Sets up Word finally
        for (i = 0; i < TOTALARRAYLENGTH; i++)
            {
                if (wordList[randNum] [i] != '\0')
                {
                word.wordArray [i] = wordList [randNum] [i];
                }
                else {
                word.wordArray [i] = '_';
                }
            }
        ///////////////////////////
        //begins the game that needs to be looped
    localGuesses = 0;
    char stringChecker[30] = {'\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0'};
    bool letterCheckArray[26] = {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false};
    lives = 0;
    do {

    printf("\nLetters guessed : ");
    //prints all the characters that have been guessed in the session
    for (i = 0; i < ALPHABETLENGTH; i++)
    {
    letterCheck = false;
    for (j = 0; j < TOTALARRAYLENGTH; j++)
        {
            if (alphabet[i] == stringChecker[j])
            {
                //printf("True");
                letterCheck = true;
            }
        }
    //testing
    //printf("\n%c, %c", alphabet[i], stringChecker[i]);
    //end of testing
    if (letterCheck == true)
        {
        //printf("True");
        printf("%c", alphabet[i]);
        letterCheckArray[i] = true;
        }
    }
    printf("\nLetters available : ");
    //prints all the letters that haven't been guessed
    for ( i = 0; i < ALPHABETLENGTH; i++)
    {
        if (!letterCheckArray[i])
        {
            printf("%c", alphabet[i]);
        }
    }
    printf("\nCurrent total score : %d", playerScore[currentPlayer]);
    printf("\nCurrent session score : %d", totalSessionPoints);
    printf("\nCurrent lives : %d", LIFELIMIT - lives);

    printf("\nCurrent word: ");
    for (i = 0;i < TOTALARRAYLENGTH; i++)
        {
        if ((word.wordArray [i] == word.displayWord [i]) && (word.wordArray [i] != '_'))
            {
            printf("%c ", word.wordArray [i]);
            }

        if ((word.wordArray [i] != word.displayWord [i]) && (word.wordArray [i] != '_'))
            {
            printf("_ ");
            }
        }

    //testing
    //printf("Point of failure");
    //receives input for game and checks for duplicates
    do {
    doubleGuess = false;

    printf("\nPlease enter a letter or word to guess : ");
    //actually gets the input
    gets(guessInput);
    //sets it to lowercase
    for (i = 0; i < TOTALARRAYLENGTH; i++)
    {
        guessInput[i] = tolower(guessInput[i]);
    }

    if (guessInput[1] == '\0')
    {
        for (i = 0; i < 30; i++)
            {
            //printf("Testing %c : %c : %d", guessInput, stringChecker[i], i);
            if (guessInput[0] == stringChecker[i])
                    {
                    doubleGuess = true;
                    //printf("It worked%c", guessInput);
                    }
            }
        if (doubleGuess)
            printf("Please enter a valid guess (No double guessing)");
    }
    } while (doubleGuess);

    localGuesses += 1;
    totalSessionGuesses += 1;

        if (guessInput[1] == '\0')
    {
        //checks for right answers
        stringChecker [localGuesses] = guessInput[0];
        counter = 0;
        for (i = 0; i < TOTALARRAYLENGTH; i++)
            {
            if ((word.wordArray [i] == guessInput[0] ) && (guessInput[0] != word.displayWord [i]))
                {
                word.displayWord [i] = guessInput[0];
                counter++;
                }
            }
         playerScore[currentPlayer] += counter * 10;
        totalSessionPoints += counter * 10;
        if (counter == 0)
            {
            printf("\nSorry, that letter wasn't correct");
             playerScore[currentPlayer] -= 2;
            totalSessionPoints -= 2;
            lives += 1;
            totalSessionIncorrect += 1;
            //checks if the person wants to quit
            printf("\nWould you like to give up? y/n : ");
            scanf(" %c", &quit);
            getchar();
            quit = tolower(quit);
            //checks if you ran out of lives
            if (lives == LIFELIMIT)
                {
                playerScore[currentPlayer] -= 40;
                totalSessionPoints -= 40;
                }
            }

        //check if the game is solved
        counter = 0;
        notFinishedGame = false;
        for (i = 0; i < TOTALARRAYLENGTH; i++)
            {
            if (word.wordArray [i] != word.displayWord [i])
            notFinishedGame = true;
            }

    }
    else
    {

        //compares the strings (I did this weird)
        notFinishedGame = true;
        if (strcmp(grabWord, guessInput) == 0)
        {
            printf("That\'s the word!");
            notFinishedGame = false;
            if (localGuesses == 1)
            {
                playerScore[currentPlayer] += 200;
                totalSessionPoints += 200;
            }
        }
        else
        {
            printf("\nSorry, that wasn't the right word");
             playerScore[currentPlayer] -= 40;
            totalSessionPoints -= 40;
            lives += 1;
            totalSessionIncorrect += 1;
        }


    }

        } while ((quit != 'y') && (lives != LIFELIMIT) && notFinishedGame);

        //resets stuff for future
        if (!notFinishedGame)
            {
            playerScore[currentPlayer] += 100;
            totalSessionPoints += 100;
            totalSessionWins += 1;
            printf("\nCongrats on getting it right!!");
            }
        else
            {
            totalSessionLosses +=1;
            printf("\nSorry, you didn't get it");
            }

        lives = 0;

        //shows the word you missed
        printf("\nThe word was : ");
        for (i = 0; i < TOTALARRAYLENGTH; i++)
            {
            if (word.wordArray [i] != '_')
                printf("%c", word.wordArray [i]);
            }
        printf("\n");
        initialmenu();
        break;

        //Display the stats
        case 2:
        printf("\nTop scores\n");
        //makes the temporary name list the same as the player namelist
        for (i = 0; i < TOTALPLAYERS; i++)
        {
            for (j = 0; j < TOTALPLAYERS; j++)
            {
                tempDisplayNames[i] [j] = playerName[i] [j];
            }
        }

        //testing to see if it worked
        /*
        for (i = 0; i < TOTALPLAYERS; i++)
        {
            for (j = 0; j < TOTALPLAYERS; j++)
            {
                printf("%c", tempDisplayNames[i] [j]);
            }
        }
        */

        //makes the temporary score list same as the players score list
        for (i = 0; i < TOTALPLAYERS; i++)
        {
            tempTotalScore[i] = playerScore[i];
        }

        //sorts the lists using bubblesort
        for (i = 0; i < (playerAmmount); i++)
        {
            for (j = 0; j < playerAmmount - i; j++)
            {
                if (tempTotalScore[j] > tempTotalScore[j+1])
                {
                    intTemp = tempTotalScore[j];

                    for (z = 0; z < TOTALPLAYERS; z++)
                    {
                        charTemp[z] = tempDisplayNames[j][z];
                    }

                    tempTotalScore[j] = tempTotalScore[j+1];

                    for (z = 0; z < TOTALPLAYERS; z++)
                    {
                        tempDisplayNames[j] [z] = tempDisplayNames[j+1] [z];
                    }

                    tempTotalScore[j+1] = intTemp;

                    for (z = 0; z < TOTALPLAYERS; z++)
                    {
                        tempDisplayNames[j+1] [z] = charTemp[z];
                    }

                }
            }
        }
        //testiing
        /*
        for (i = 0; i < TOTALPLAYERS; i++)
        {
            for (j = 0; j < TOTALPLAYERS; j++)
            {
                printf("%c", tempDisplayNames[i] [j]);
            }
        }
        */
        //the z is to correct an issue I'm having when displaying the bubble sort. I don't know why it's happening and I just want it gone at this point
        //printing the scoreboard
        for (i = TOTALPLAYERS-1; i > 0-1; i--)
        {
            z = 0;
            if (tempDisplayNames[i] [0] != '\0')
            {
            if (tempTotalScore[i] == '\0')
                z++;
            printf("\nPosition : %d : Score : %d : name : ", ((playerAmmount - i)+1)-z, tempTotalScore[i]);
                for (j = 0; j < TOTALPLAYERS; j++)
                {
                printf("%c", tempDisplayNames[i] [j]);
                }
            }
        }
        //testing
        //printf("\nWeird variable : ")
        //for (j = 0; j < )
        //testing
        //displays the session information
        printf("\n\nSession Information is below");
        printf("\nYour total session points are : %d", totalSessionPoints);
        printf("\nYour total session wins are : %d", totalSessionWins);
        printf("\nYour total session guesses : %d", totalSessionGuesses);
        printf("\nYour total session incorrect guesses : %d", totalSessionIncorrect);
        printf("\nYour total session losses : %d\n", totalSessionLosses);
        initialmenu();
        break;

        //Used for changing the player
        case 3:
        //gets characters from file
        //matches the playerName variables to the file
        //reads from the file to memory
        if (statPTR = fopen(SCOREBOARDLOCATION, "r") == NULL)
            {
            printf("ERROR, Can't find the scoreboard file");
            //exit program
            exit(1);
            }
        //printf("Got to decleration of statement\n");
        statPTR = fopen(SCOREBOARDLOCATION, "r");
        i = 0;
        error = 1;
        while (error != -1)
            {
            error = fscanf(statPTR, "%d|%s\n", &playerScore[i], &buffer);
            //printf("%s | %d\n", buffer, playerScore[i]);
            for (j = 0; j < TOTALARRAYLENGTH; j++)
                {
                playerName [i] [j] = buffer[j];
                }
            memset(buffer, 0, strlen(buffer));
            i++;
            }
        fclose(statPTR);

        //displays all the characters
        for (i = 0; i < TOTALPLAYERS; i++)
        {
        if (playerName[i][0] != '\0')
            {
                printf("\nPlayer %d is : ", i+1);
                for (j = 0; j < NAMELENGTH; j++)
                {
                        printf("%c", playerName[i] [j]);
                }
           }
        }

        printf("\nEnter the number of the player you\'d like to become : ");
        scanf(" %d", &currentPlayer);
        getchar();
        currentPlayer -= 1;
        printf("\nA new session begun");
        //sets the local stuff back to zero
        totalSessionPoints = 0;
        totalSessionWins = 0;
        totalSessionGuesses = 0;
        totalSessionIncorrect = 0;
        totalSessionLosses = 0;
        initialmenu();

        //counts how many players through the amount of lines in the file
        playerAmmount = totalThePlayers();
        break;
        //adds players
        case 4:

        playerAmmount = totalThePlayers();

        //Copies from Disk to ram user information
        //matches the playerName variables to the file
        //reads from the file to memory
        if (statPTR = fopen(SCOREBOARDLOCATION, "r") == NULL)
            {
            printf("ERROR, Can't find the scoreboard file");
            //exit program
            exit(1);
            }
        //printf("Got to decleration of statement\n");
        statPTR = fopen(SCOREBOARDLOCATION, "r");
        i = 0;
        error = 1;
        while (error != -1)
            {
            error = fscanf(statPTR, "%d|%s\n", &playerScore[i], &buffer);
            //printf("%s | %d\n", buffer, playerScore[i]);
            for (j = 0; j < TOTALARRAYLENGTH; j++)
                {
                playerName [i] [j] = buffer[j];
                }
            memset(buffer, 0, strlen(buffer));
            i++;
            }
        fclose(statPTR);
        //gets input from user
        for ( i = 0; i < TOTALPLAYERS; i++)
        {
            tempName[i] = '\0';
        }
        printf("Please enter player %d\'s name : ", totalThePlayers()+1);
        gets(tempName);
        for (i = 0; i < NAMELENGTH; i++)
        {
            playerName[playerAmmount] [i] = tempName[i];
        }

        //appends the player to file
        if (statPTR = fopen(SCOREBOARDLOCATION, "r") == NULL)
            {
            printf("ERROR, Can't find the scoreboard file");
            exit(1);
            }

        statPTR = fopen(SCOREBOARDLOCATION, "a");
        fprintf(statPTR, "%d|%s\n", 0, tempName);
        printf("%d|%s\n", 0, tempName);
        fclose(statPTR);

        //sets the user to the new player
        currentPlayer = totalThePlayers()-1;

        //Copies from Disk to ram user information
        //matches the playerName variables to the file
        //reads from the file to memory
        if (statPTR = fopen(SCOREBOARDLOCATION, "r") == NULL)
            {
            printf("ERROR, Can't find the scoreboard file");
            //exit program
            exit(1);
            }
        //printf("Got to decleration of statement\n");
        statPTR = fopen(SCOREBOARDLOCATION, "r");
        i = 0;
        error = 1;
        while (i < totalThePlayers())
            {
            fscanf(statPTR, "%d|%s\n", &playerScore[i], &buffer);
            //printf("%s | %dl1\n", buffer, playerScore[i]);
            for (j = 0; j < TOTALARRAYLENGTH; j++)
                {
                playerName [i] [j] = buffer[j];
                }
            memset(buffer, 0, strlen(buffer));
            i++;
            }
        fclose(statPTR);
            //-------------------------------------
    //writes memory to the file
        if (statPTR = fopen(SCOREBOARDLOCATION, "r") == NULL)
            {
            printf("ERROR, Can't find the scoreboard file");
            //exit program
            exit(1);
            }
        playerAmmount = totalThePlayers();
        statPTR = fopen(SCOREBOARDLOCATION, "w");
        i = 0;
        while (i < playerAmmount)
            {
            //printf("round %d :\n", i);
            for (j = 0; j < TOTALARRAYLENGTH; j++)
                {
                buffer[j] = playerName[i] [j];
                //printf("Buffer : %c :\n", buffer);
                }

            fprintf(statPTR, "%d|%s\n", playerScore[i], buffer);
            //printf("%d | %sl2\n", playerScore[i], buffer);
            memset(buffer, 0, strlen(buffer));
            i++;
            }
        fclose(statPTR);


        initialmenu();
        break;

        //Used to exit the game
        case 5:
        //literally nothing
        break;

        default:
        printf("\nPlease enter a valid number");
    }
            //-------------------------------------
    //writes memory to the file
        if (statPTR = fopen(SCOREBOARDLOCATION, "r") == NULL)
            {
            printf("ERROR, Can't find the scoreboard file");
            //exit program
            exit(1);
            }
        playerAmmount = totalThePlayers();
        statPTR = fopen(SCOREBOARDLOCATION, "w");
        i = 0;
        //printf("\nCheckNumber %d\n",totalThePlayers()+1);
        while (i < playerAmmount)
            {
            //printf("round %d :\n", i);
            for (j = 0; j < TOTALARRAYLENGTH; j++)
                {
                buffer[j] = playerName[i] [j];
                //printf("Buffer : %c :\n", buffer);
                }

            fprintf(statPTR, "%d|%s\n", playerScore[i], buffer);
            //printf("%d | %sl3\n", playerScore[i], buffer);
            memset(buffer, 0, strlen(buffer));
            i++;
            }
        fclose(statPTR);

    //----------------------------------------------
    //matches the playerName variables to the file
    //reads from the file to memory
        if (statPTR = fopen(SCOREBOARDLOCATION, "r") == NULL)
            {
            printf("ERROR, Can't find the scoreboard file");
            //exit program
            exit(1);
            }
        //printf("Got to decleration of statement\n");
        playerAmmount = totalThePlayers();
        statPTR = fopen(SCOREBOARDLOCATION, "r");
        i = 0;
        error = 1;
        while (i < playerAmmount)
            {
            fscanf(statPTR, "%d|%s\n", &playerScore[i], &buffer);
            //printf("%s|%d\n", buffer, playerScore[i]);
            for (j = 0; j < TOTALARRAYLENGTH; j++)
                {
                playerName [i] [j] = buffer[j];
                }
            memset(buffer, 0, strlen(buffer));
            i++;
            }
        fclose(statPTR);
    //-------------------------------------

    printf("\n\nPlease enter an integer : ");
    scanf(" %d", &menuInput);
    getchar();

    }   while (menuInput != 5);

    printf("Program Ending");

    return 0;
}

//returns the total amount of lines in STAT
int totalThePlayers(void)
{
        char singleBuffer;
        FILE *statPTR;
        //counts how many players through the amount of lines in the file
        int playerAmmount = 0;
        if (statPTR = fopen(SCOREBOARDLOCATION, "r") == NULL)
            {
            printf("ERROR, Can't find the scoreboard file");
            //exit program
            exit(1);
            }
        statPTR = fopen(SCOREBOARDLOCATION, "r");
        for (singleBuffer = getc(statPTR); singleBuffer != EOF; singleBuffer = getc(statPTR))
            {
            if (singleBuffer == '\n')
                {
                playerAmmount++;
                }
            }
        fclose(statPTR);
        return playerAmmount;
}

//prints the initial menu
int initialmenu(void)
{
    printf("\nWelcome to hangman!\n");
    printf("Enter 0 to show the initial menu\n");
    printf("Enter 1 to play a round\n");
    printf("Enter 2 to view stats\n");
    printf("Enter 3 to change player\n");
    printf("Enter 4 to add a player\n");
    printf("Enter 5 to exit and save the game\n");
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
