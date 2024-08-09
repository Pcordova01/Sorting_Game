// Toolbox for functionalities
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


// Structure to store the name and execution time of each sorting algorithm
typedef struct {
    // Name of the sorting algorithm
    char name[20];

    // Execution time of sorting algorithm
    double time;
} AlgorithmTime;

// Function for round
int playRound() {

    // Array for input
    int user_data[1000];

    // Buffer for user's input
    char input[10000];

    // Integer for counting how many inputs the user enters
    int size = 0;

    // Pointer for tokenizing the input
    char *token;

    // Integer storing score of the player 
    int score = 0;

    //Storing the player's guess
    int guesses[5];

    // Prompt user to enter their data
    printf("Enter your data (numbers separated by spaces, max 1000 numbers): ");

    // Consume newline from the previous input
    getchar();

    // Reads the data from the user
    fgets(input, sizeof(input), stdin);

    // Searches user input and separates strings with spaces and newlines
    token = strtok(input, " \n");

    // While loop that iterates throughout the rest of the tokens
    while (token != NULL && size < 1000) {

        // Array of user's input with index of each integer of the user input is converted to integer
        user_data[size] = atoi(token);

        // Size is incremented
        size++;

        // Continue separating strings with spaces and newlines
        token = strtok(NULL, " \n");
    }

    // Display loading screen
    printf("Loading...\n");

    // If user's data set isn't multiplied by 100 all sorting time is essentially instant

    // Multiplies user input by 100 so that sorting takes more time
    int total_size = size * 100;

    // Memory allocation for the multiplied data set
    int *data = malloc(total_size * sizeof(int));

    // Loop iterates through data to multiply it 100 times
    for (int i = 0; i < 100; i++) {

        // Takes the user's input and copies it into the data array, i represents loop index and size represents number of elements
        memcpy(data + i * size, user_data, size * sizeof(int));
    }

    // Allocating memory for algorithms
    int *data_bubble = malloc(total_size * sizeof(int));
    int *data_quick = malloc(total_size * sizeof(int));
    int *data_merge = malloc(total_size * sizeof(int));
    int *data_selection = malloc(total_size * sizeof(int));
    int *data_insertion = malloc(total_size * sizeof(int));

    // Array for algorithm times
    AlgorithmTime times[5];

    // Variables for timing sorting algorithms
    clock_t start;
    clock_t end;

    // Begin execution time for bubblesort
    start = clock();
    for (int i = 0; i < 1000; i++) {

        // Copying data
        memcpy(data_bubble, data, total_size * sizeof(int));

        // Calling bubblesort
        bubbleSort(data_bubble, total_size);
    }
    // Ends execution time for bubblesort
    end = clock();

    // Calculate time for bubblesort
    times[0].time = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Storing name for bubble sort
    strcpy(times[0].name, "Bubble Sort");

    // Quick Sort
    start = clock();
    for (int i = 0; i < 1000; i++) {

        // Copying data
        memcpy(data_quick, data, total_size * sizeof(int));

        // Calling quickSort
        quickSort(data_quick, 0, total_size - 1);
    }
    // Ends execution time for quickSort
    end = clock();

    // Calculate time for quickSort
    times[1].time = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Storing name for quick sort
    strcpy(times[1].name, "Quick Sort");

    // Merge Sort
    start = clock();
    for (int i = 0; i < 1000; i++) {

        // Copying data
        memcpy(data_merge, data, total_size * sizeof(int));

        // Calling mergeSort
        mergeSort(data_merge, 0, total_size - 1);
    }
    // Ends execution time for mergeSort
    end = clock();

    // Calculate time for mergeSort
    times[2].time = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Storing name for merge sort
    strcpy(times[2].name, "Merge Sort");

    // Selection Sort
    start = clock();
    for (int i = 0; i < 1000; i++) {

        // Copying data
        memcpy(data_selection, data, total_size * sizeof(int));

        // Calling selectionSort
        selectionSort(data_selection, total_size);
    }
    // Ends execution time for selectionSort
    end = clock();

    // Calculate time for selectionSort
    times[3].time = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Storing name for selection sort
    strcpy(times[3].name, "Selection Sort");

    // Insertion Sort
    start = clock();
    for (int i = 0; i < 1000; i++) {

        // Copying data
        memcpy(data_insertion, data, total_size * sizeof(int));

        // Calling insertionSort
        insertionSort(data_insertion, total_size);
    }
    // Ends execution time for insertionSort
    end = clock();

    // Calculate time for insertionSort
    times[4].time = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Storing name for insertion sort
    strcpy(times[4].name, "Insertion Sort");

    // Free allocated memory
    free(data);
    free(data_bubble);
    free(data_quick);
    free(data_merge);
    free(data_selection);
    free(data_insertion);

    // Sort the times array by time
    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (times[i].time > times[j].time) {
                AlgorithmTime temp = times[i];
                times[i] = times[j];
                times[j] = temp;
            }
        }
    }

    // Prompt the user to guess the order
    printf("Guess the order of the algorithms from fastest to slowest (1-5):\n");

    // Iterates through the user;s guesses 
    for (int i = 0; i < 5; i++) {

        //Displays the algorithm name
        printf("%s: ", times[i].name);

        //Scan the user's guess
        scanf("%d", &guesses[i]);
    }

    // Calculating the score
    for (int i = 0; i < 5; i++) { 

        //If the player's guess is correct, score is incremented
        if (guesses[i] == i + 1) {
            score++;
        }
    }

    // Reveal the actual order and times
    printf("\nActual order from fastest to slowest:\n");

    // Cycle through each sorting algorithm and their times
    for (int i = 0; i < 5; i++) {
        printf("%d. %s: %f seconds\n", i + 1, times[i].name, times[i].time);
    }

    // Reveal the score
    printf("\nYour score this round: %d out of 5\n", score);

    // Returns points earned by player
    return score;
}

// Function for game
void game() {

    // Integer storing points across all rounds
    int totalScore = 0;

    // Integer storing number of rounds
    int roundNumber = 0;

    // User's choice to play the game again
    char playAgain = 'y'; // Initialized char to 'y' to ensure the loop starts

    // While loop to continue playing rounds as long as the user wants
    while (playAgain == 'y' || playAgain == 'Y') {

        // Increment round by 1
        roundNumber++;

        // Display round number
        printf("\n--- Round %d ---\n", roundNumber);

        // After round is played, the points from the round are added to total score
        totalScore += playRound();

        // Display the current score at the current round
        printf("\nTotal score after %d round(s): %d\n", roundNumber, totalScore);

        // Prompt user to play again
        printf("Do you want to play another round? (y/n): ");

        // Scan user's input
        scanf(" %c", &playAgain);
    }

    // Tell player the game is over and what their final score is
    printf("\nGame over! Your final score: %d\n", totalScore);

    // Reads current high score from text document
    int highScore = readHighScore();

    // Check if the final score is a new high score
    if (totalScore > highScore) {

        // Congratulate the player
        printf("Congratulations! You have a new high score!\n");

        // Calls the writing function to replace old high score
        writeHighScore(totalScore);
    }
}
