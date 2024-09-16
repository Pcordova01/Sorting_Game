# Sorting_Visualizer
This program recieves data as input from the user and utilizes 5 different sorting algorithms to sort it. Afterwards, the user is instructed to guess the order to which each specific algorithm has been sorted. The user receives 1 point for each guess they enter correctly, and get to play as many rounds as they choose. Each time they score more points than any previous attempt, they are awarded with a new high score. When I first play-tested this program, I faced a dilemma in which each data set i entered was sorted by all 5 algorithms almost instantaneously; as such, I added a functionality in which the user's inputed data is duplicated 100 times in order to create a larger dataset that takes more time to sort. 

## Takeaways
Building this program helped me to better understand how to utilize file I/O in C, namely how to read, write, and overwrite information in a text document. I also learned how to use the 'clock()' function to measure the periods of time it took for each sorting algorithm to commence. Additionally, I learned the process of sorting information with various algorithms, including Bubble Sort, Quick Sort, Merge Sort, Selection Sort, and Insertion Sort. The major challenge for me was assigning effective memory allocation, as I have always struggled with this concept; however, completing this project has helped me to develop a better understanding of how to handle memory in c. 

## Features
- Five sorting algorithms: Bubble Sort, Quick Sort, Merge Sort, Selection Sort, and Insertion Sort
- Random number generator
- High score saving utilizing file I/O
- Game instructions and rules

## Example Gameplay
Welcome to the sorting algorithm game!
1. Start game
2. Algorithm descriptions
3. Game rules
4. Exit
High Score: 10
Enter your choice: 1

Starting the game...<br>
--- Round 1 ---<br>
Enter your data (numbers separated by spaces, max 1000 numbers): 5 2 8 1 9 3 7 4 6<br>

Loading...<br>

Guess the order of the algorithms from fastest to slowest (1-5):<br>
Bubble Sort: 5<br>
Quick Sort: 1<br>
Merge Sort: 2<br>
Selection Sort: 4<br>
Insertion Sort: 3<br>

Actual order from fastest to slowest:<br>
1. Quick Sort: 0.000123 seconds<br>
2. Merge Sort: 0.000156 seconds<br>
3. Insertion Sort: 0.000189 seconds<br>
4. Selection Sort: 0.000234 seconds<br>
5. Bubble Sort: 0.000312 seconds<br>

Your score this round: 5 out of 5

Total score after 1 round(s): 5<br>
Do you want to play another round? (y/n): n<br>

Game over! Your final score: 5<br>
Congratulations! You have a new high score!<br>
