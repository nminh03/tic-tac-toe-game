// Main function
#include "game.h"

// Function to set the terminal text color
void SetTerminalStyle(const char* color) {
    printf("%s", color);
}

// Function to display the game menu
void menu() {
    printf("--------------\n");
    printf("*** 1: Play ***\n");
    printf("*** 0: Exit ***\n");
    printf("--------------\n");
}

// Function to start the game
void game() {
    char ret = 0;

    char board[ROW][COL] = { 0 }; // Initialize the board array
    // Initialize the game board
    InitBoard(board, ROW, COL);

    // Print the game board
    DisplayBoard(board, ROW, COL);

    // Game loop
    while (1) {
        PlayerMove(board, ROW, COL); // Player makes a move
        ret = IsWin(board, ROW, COL); // Check for win
        if (ret != 'C') { // 'C' stands for continue
            break;
        }
        DisplayBoard(board, ROW, COL); // Print the updated board

        ComputerMove(board, ROW, COL); // Computer makes a move
        ret = IsWin(board, ROW, COL); // Check for win
        if (ret != 'C') {
            break;
        }
        DisplayBoard(board, ROW, COL); // Print the updated board
    }
    DisplayBoard(board, ROW, COL);
    // Determine the winner or if it's a draw
    if (ret == '*') {
        printf("Player wins!\n");
    } else if (ret == '#') {
        printf("Computer wins!\n");
    } else {
        printf("It's a draw!\n");
    }
}

// The main entry point of the program
int main() {
    SetTerminalStyle(COLOR_BLUE); // Set the terminal color to blue
    srand((unsigned int)time(NULL)); // Seed the random number generator

    int input;
    do {
        menu(); // Display the menu
        printf("Please select: ");
        scanf("%d", &input); // Read user input
        switch (input) {
            case 1:
                game(); // Start the game
                break;
            case 0:
                printf("Exiting the game\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (input != 0); // Loop until the user chooses to exit

    return 0; // Return statement for the main function
}
