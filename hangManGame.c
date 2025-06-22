#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LENGTH 50
#define MAX_LIVES 6


struct Word{
    char text[MAX_LENGTH];
    char hint[MAX_LENGTH];
};


void showWord(const char word[], const bool guessed[]);
void showHangman(int lives);


int main(){
    srand(time(NULL));

    struct Word words[] = {
        {"apple", "A fruit"},
        {"computer", "Smart thinking machine"},
        {"zoo", "Place with animals"},
        {"shop","Place where are you buying something"},
        {"school", "Place where you are learning"}
    };


    int totalWords = sizeof(words)/sizeof(words[0]);
    int randomIndex = rand() % totalWords;

    const char* secret = words[randomIndex].text;
    const char* hint = words[randomIndex].hint;

    int length = strlen(secret);
    char progress[MAX_LENGTH] = {0};
    bool guessedLetters[26] = {false};


    for (int i = 0; i < length; i++) {
        progress[i] = '_';
    }
    
    progress[length] =  '\0';

    int mistakes = 0;



    system("@cls||clear");


    //ASCII FROM LINE 59-74  You don't have to use it because it's just my ASCII with the game name and my nickname
printf(
    "\n"
    ".__                             _____                  ________                       \n"
    "|  |__ _____    ____    ____   /     \\ _____    ____  /  _____/_____    _____   ____  \n"
    "|  |  \\\\__  \\  /    \\  / ___\\ /  \\ /  \\\\__  \\  /    \\/   \\  ___\\__  \\  /     \\_/ __ \\ \n"
    "|   Y  \\/ __ \\|   |  \\/ /_/  >    Y    \\/ __ \\|   |  \\    \\_\\  \\/ __ \\|  Y Y  \\  ___/ \n"
    "|___|  (____  /___|  /\\___  /\\____|__  (____  /___|  /\\______  (____  /__|_|  /\\___  >\n"
    "     \\/     \\/     \\//_____/         \\/     \\/     \\/        \\/     \\/      \\/     \\/ \n"
    "         ____  ___       .__            .___ _____  _______      _____                \n"
    "         \\   \\/  / _____ |__| ____    __| _//  |  | \\   _  \\    /  |  |               \n"
    "  ______  \\     / /     \\|  |/    \\  / __ |/   |  |_/  /_\\  \\  /   |  |_              \n"
    " /_____/  /     \\|  Y Y  \\  |   |  \\/ /_/ /    ^   /\\  \\_/   \\/    ^   /              \n"
    "         /___/\\  \\__|_|  /__|___|  /\\____ \\____   |  \\_____  /\\____   |               \n"
    "               \\_/     \\/        \\/      \\/    |__|        \\/      |__|               \n"
    "\n"
);




    printf("\n\n");


    printf("---====<>-Welcome to Hangman Game!-<>====---\n\n\n");
    
    printf("\n\n");
    printf("Hints: %s\n", hint);

    while(mistakes < MAX_LIVES){
        printf("\n");
        showWord(secret, guessedLetters);
        showHangman(mistakes);

        char letter;
        printf("Enter a letter: ");
        scanf(" %c", &letter);
        letter = tolower(letter);

        if(letter < 'a' || letter > 'z'){
            printf("Only letters a-z !\n");
            continue;            
        }

        if(guessedLetters[letter - 'a']){
            printf("You aleready tried that one.\n");
            continue;
        }

        guessedLetters[letter - 'a'] = true;

        bool correct = false;
        for(int i = 0; i < length; i++){
            if(secret[i] == letter){
                progress[i] = letter;
                correct = true;
            }
        }

        if(correct){
            printf("Correct!\n");
        }else{
            printf("Wrong letter!\n");
            mistakes++;
        }

        if(strcmp(secret, progress) == 0){
            printf("\nYou win! The word was: %s\n", secret);
            return 0;
        }
    }
    printf("\nGame over! The word was: %s\n", secret);
    return 0;
}


void showWord(const char word[], const bool guessed[]){
    printf("Word: ");
    for(int i = 0; word[i] != '\0'; i++){
        if(guessed[tolower(word[i])-'a']){
            printf("%c ", word[i]);
        }else{
            printf("_ ");
        }
    }
    printf("\n");
}

void showHangman(int step) {
    const char* parts[] = {
        "  _______",
        "  |     |",
        "  |     O",
        "  |    /|\\",
        "  |    / \\",
        "  |"
    };

    printf("\n");
    for (int i = 0; i <= step && i < MAX_LIVES; i++) {
        printf("%s\n", parts[i]);
    }
}

// Crafted in C by Xmind404 – no libraries, just logic