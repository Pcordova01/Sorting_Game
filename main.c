//Toolbox for functionalites
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Includes other required files for program
#include "sorting.c"
#include "printing.c"
#include "highscore.c"
#include "game.c"

//Main function 
int main() {

    //Stores user's choice (1 - 4)
    int choice;

    //Stores the user input data 
    char input[100];

    //Highscore is whatever number is in the "highscore.txt" file
    int highScore = readHighScore();

    //While true - loop runs continuously 
    while(1) {
        
        //Highscore is whatever number is in the "highscore.txt" file
        highScore = readHighScore();

        //Displays main menu 
        printf("Welcome to the sorting algorithm game!\n1. Start game\n2. Algorithm descriptions\n3. Game rules\n4. Exit\nHigh Score: %d\nEnter your choice:", highScore);
        scanf("%d", &choice); //Receives user input

        //Switch statement determining next prompt based on user input 
        switch(choice) {
            case 1://user selects 1

                printf("Starting the game...\n");
                //starts game
                game(); 

                //prompt user to go back to main menu
                printf("Press 'Enter' to return to the main menu...\n");

                getchar(); // Gets rid of newline
                getchar(); // Waits for user to press enter

                break; // Exits switch statement and returns to menu because of while loop
            case 2://user selects 2

                //Takes user to description page 
                algorithmDescriptions();

                //prompt user to go back to main menu
                printf("\nPress 'Enter' to return to the main menu...");

                getchar(); // Gets rid of newline
                getchar(); // Waits for user to press Enter

                break; // Exits switch statement and returns to menu because of while loop
            case 3://user selects 3 
                
                //Takes user to game rules page
                gameRules();

                //prompt user to go back to main menu
                printf("\nPress 'Enter' to return to the main menu...");

                getchar(); // Gets rid of newline
                getchar(); // Waits for user to press Enter

                break; // Exits switch statement and returns to menu because of while loop
            case 4://user selects 4

                // Say goodbye to the player
                printf("Fine then... Goodbye!\n");

                //Terminate the program
                return 0;  
            default://user doesn't select one of the options

                //Tell the player that their exact input is invalid
                printf("\n\"%d\" is not one of the choices!\n", choice);
        }
    }

    return 0;
}