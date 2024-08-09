//Toolbox for functionalities
#include <stdio.h>

//Function to read highscore.txt document
int readHighScore() {
    // Open the file in read mode
    FILE *file = fopen("highscore.txt", "r");

    //Variable storing high score value 
    int highScore;

    //Scans the file and assignes the number it finds to 'highScore'
    fscanf(file, "%d", &highScore);

    //Close the file
    fclose(file);

    //Returns whatever number the high score is at the time
    return highScore;
}

//Function to write highsore.txt document
void writeHighScore(int highScore) {
    //Open the file in writting mode 
    FILE *file = fopen("highscore.txt", "w");
    
    //Writes the value of 'highScore' into the text file (overwritting the old value)
    fprintf(file, "%d", highScore);

    //Closes the file
    fclose(file);
    
}