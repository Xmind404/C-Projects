#include <stdio.h>
#include <float.h>
#include <math.h>
#include <stdlib.h>


int main(){
    char op;
    double a, b, res;
        
    system("@cls||clear");
    printf("\n\n");


    //ASCII FROM LINE 16-23  You don't have to use it because it's just my ASCII with the game name and my nickname
    printf(
        "       .__               .__         _________        .__               .__          __                           ____  ___       .__            .___ _____  _______      _____  \n"
        "  _____|__| _____ ______ |  |   ____ \\_   ___ \\_____  |  |   ____  __ __|  | _____ _/  |_  ___________            \\   \\w/  / _____ |__| ____    __| _//  |  | \\   _  \\    /  |  | \n"
        " /  ___/  |/     \\\\____ \\|  | _/ __ \\/    \\  \\/\\__  \\ |  | _/ ___\\|  |  \\  | \\__  \\\\   __\\/  _ \\_  __ \\   ______   \\     / /     \\|  |/    \\  / __ |/   |  |_/  /_\\  \\  /   |  |_ \n"
        " \\___ \\|  |  Y Y  \\  |_> >  |_\\  ___/\\     \\____/ __ \\|  |_\\  \\___|  |  /  |__/ __ \\|  | (  <_> )  | \\/  /_____/   /     \\|  Y Y  \\  |   |  \\/ /_/ /    ^   /\\  \\_/   \\/    ^   / \n"
        "/____  >__|__|_|  /   __/|____/\\___  >\\______  (____  /____/\\___  >____/|____(____  /__|  \\____/|__|              /___/\\  \\__|_|  /__|___|  /\\____ \\____   |  \\_____  /\\____   | \n"
        "     \\/         \\/|__|             \\/        \\/     \\/          \\/                \\/                                    \\_/     \\/        \\/      \\/    |__|        \\/      |__| \n"
    );
    


    printf("\n\n");

    printf("---====<>-Welcome in Simple Calculator-<>====---\n\n\n");
    
    printf("Enter an operator(+, -, *, /) down bellow: \nshell> ");
    scanf(" %c", &op);

    printf("Enter two operands: \nshell> ");
    scanf("%lf %lf", &a, &b);

    switch(op){
        case '+':
            res = a + b;
            break;
        case '-':
            res = a - b;
            break;
        case '*':
            res = a * b;
            break;
        case '/':
            res = a / b;
            break;
        default:
            printf("Error! Incorrect Operator Value\n");
            res = -DBL_MAX;
    }

    if(!isnan(res)){
        printf("Result: %.2lf\n", res);
    }
    
    return 0;
}

// Crafted in C by Xmind404 – no libraries, just logic