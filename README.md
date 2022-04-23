# Hangman
This is a repository dedicated to my final project for C. There are three versions, all having different requirements. EX: the first is not allowed to use strings, but future ones may be allowed too. This is just to show some of my progress with C.

# Hangman III Setup
Hangman III attempts to use files. You need to install these files to let it work. In the repository is wordlist.txt and scoreboard.txt; these files are used for their respective names. Scoreboard can be empty, as it'll automatically detect whether the file is empty and ask you to create a user. Wordlist must have words inside to work (50). You'll also need to update the pointer for the file pointers. These two files can be found in the definitions WORDLISTLOCATION and SCOREBOARDLOCATION. Just write out the location to the strings, and it'll work.

Issue with the program: There is only one issue with the program. If you have a score <0, your place on the scoreboard where x = (your position) is x = x-1. Otherwise the program has no issues, but is insecure. I should probably be using fgets and allowing more users and players, but I've completed the class. I'll have more projects in the future though.
