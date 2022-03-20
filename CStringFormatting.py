#this just formats strings into caracter arrays
#note, you have to edit it to fix the added comma
#made this because the first revision doesn't allow me to declare the words as strings :(
#I initially declared them this way and made this to re-add all 50 words to guess in hangman
def main():

    inputs = '1'

    while inputs != '0':

        print("Note: entering 0 will end it")
        inputs = input("Please enter a word to enter : ")
        
        print('{', end ="")
        for i in inputs:
            print("\'" + i + "\', ", end="")
        print('},', end ="")
        print()

main()
