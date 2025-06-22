#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int game(char you, char computer){
    if (you == computer){
        return -1;
    }

    if ((you == 'r' && computer == 's')||(you == 'p' && computer == 'r')||(you == 's' && computer == 'p')){
        return 1;
    }else{
        return 0;
    }
}





int main(){
    int n;
    
    char you, computer, result;
    
    srand(time(NULL));
    
    
    
    
    
    
    while (1){
    
        n = rand() % 3;
        
        if (n == 0){
            computer = 'r';
        }else if(n == 1){
            computer = 'p';
        }else{
            computer = 's';
        }
    
    
    
        system("@cls||clear");
        printf("\n\n");
        
        
        
        //ASCII FROM LINE 55-67  You don't have to use it because it's just my ASCII with the game name and my nickname
        printf("                      __   __________                             _________      .__                            \n"
            "_______  ____   ____ |  | _\\______   \\_____  ______   ___________/   _____/ ____ |__|__________________________ \n"
            "\\_  __ \\/  _ \\_/ ___\\|  |/ /|     ___/\\__  \\ \\____ \\_/ __ \\_  __ \\_____  \\_/ ___\\|  \\___   /\\___   /  _ \\_  __ \\\n"
            " |  | \\(  <_> )  \\___|    < |    |     / __ \\|  |_> >  ___/|  | \\/        \\  \\___|  |/    /  /    (  <_> )  | \\/\n"
            " |__|   \\____/ \\___  >__|_ \\|____|    (____  /   __/ \\___  >__| /_______  /\\___  >__/_____ \\/_____ \\____/|__|   \n"
            "                   \\/     \\/               \\/|__|        \\/             \\/     \\/         \\/      \\/            \n"
            "          ____  ___       .__            .___ _____  _______      _____                                         \n"
            "          \\   \\/  / _____ |__| ____    __| _//  |  | \\   _  \\    /  |  |                                        \n"
            "  ______   \\     / /     \\|  |/    \\  / __ |/   |  |_/  /_\\  \\  /   |  |_                                       \n"
        " /_____/   /     \\|  Y Y  \\  |   |  \\/ /_/ /    ^   /\\  \\_/   \\/    ^   /                                       \n"
        "          /___/\\  \\__|_|  /__|___|  /\\____ \\____   |  \\_____  /\\____   |                                        \n"
        "                \\_/     \\/        \\/      \\/    |__|        \\/      |__|                                        \n"
        );
        
        printf("\n\n");
        
        
        
        printf("---====<>-Welcome in Rock Paper Scissor Game-<>====---\n\n\n");
        printf("Enter your option under bellow(r / p / s) or 'q' to leave:\nshell> ");
        
        scanf(" %c", &you);
        
        if (you != 'r' && you != 'p' && you != 's' && you != 'q'){
            printf("Invalid input! Try r /p /s or 'q' to leave");
            continue;
        }
        
        if(you == 'q'){
            break;
        }
        
        result = game(you, computer);
        
        printf("\n\n");
        


        if (result == 1){
            printf("YOU WIN!!!");
        }else if (result == 0){
            printf("COMPUTER WIN!!!");
        }else if(result == -1){
            printf("DRAW!!!");
        }
    };
    printf("Leaving.");
    
    return 0;   
}
// Crafted in C by Xmind404 - no libraries, just logic
