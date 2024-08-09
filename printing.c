#include <stdio.h>

//File containing all printing functions

//Descriptions from wikapedia
void algorithmDescriptions() {
    printf("\nAlgorithm Descriptions:\n");
    printf("1. Bubble Sort: A simple sorting algorithm that repeatedly steps through the list,\n   compares adjacent elements and swaps them if they are in the wrong order.\n");
    printf("2. Quick Sort: An efficient, recursive divide-and-conquer algorithm that partitions\n   the array and sorts the partitions independently.\n");
    printf("3. Merge Sort: A divide-and-conquer algorithm that divides the input array into two\n   halves, recursively sorts them, and then merges the two sorted halves.\n");
    printf("4. Selection Sort: A simple sorting algorithm that repeatedly selects the smallest\n   (or largest) element from the unsorted portion of the list and moves it to the\n   sorted portion of the list.\n");
    printf("5. Insertion Sort: A simple sorting algorithm that builds the final sorted array\n   one item at a time. It is much less efficient on large lists than more advanced\n   algorithms such as quicksort, heapsort, or merge sort.\n");
}

//Describes the rules of the game
void gameRules() {
    printf("\nGame Rules:\n");
    printf("1. Enter a series of numbers and/or letters separated by spaces.\n");
    printf("2. The game will sort these numbers and/or letters using 5 different sorting algorithms.\n");
    printf("3. You will try to guess the order (from fastest to slowest) in which each algorithm sorted your information.\n");
    printf("4. Afterwards, the exact time it took for each algorithm to sort your information will be revealed.\n");
    printf("5. For each guess you get correct, you will recieve a point.\n");
    printf("6. Play as many rounds as you can to beat your highscore.");
}