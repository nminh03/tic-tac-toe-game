// Include the game.h header file, which presumably contains necessary declarations and macros
#include "game.h"

// Initialize the game board with empty spaces
void InitBoard(char board[ROW][COL], int row, int col) {
    int i = 0, j = 0;
    for (i = 0; i < ROW; i++) { // Loop through each row
        for (j = 0; j < COL; j++) { // Loop through each column
            board[i][j] = ' '; // Set each cell to an empty space ' '
        }
    }
}

// Display the game board to the console
void DisplayBoard(char board[ROW][COL], int row, int col) {
    int i = 0;
    for (i = 0; i < ROW; i++) { // Loop through each row
        int j = 0;
        for (j = 0; j < COL; j++) { // Loop through each column
            printf(" %c ", board[i][j]); // Print the cell character
            if (j < COL - 1) { // If not the last column, print a vertical line
                printf("|");
            }
        }
        printf("\n"); // New line after each row
        if (i < ROW - 1) { // If not the last row, print a horizontal line
            for (j = 0; j < COL; j++) {
                printf("---"); // Print a line for each column
                if (j < COL - 1) {
                    printf("|");
                }
            }
            printf("\n");
        }
    }
}

// Handle the player's move on the game board
void PlayerMove(char board[ROW][COL], int row, int col) {
    int x = 0;
    int y = 0;
    printf("Player's move:\n");
    while (1) { // Infinite loop until a valid move is made
        printf("Enter coordinates (format: x y): ");
        scanf("%d %d", &x, &y); // Read the player's input
        if (x >= 1 && x <= row && y >= 1 && y <= col) { // Check if the coordinates are within the board
            if (board[x - 1][y - 1] == ' ') { // Check if the cell is empty
                board[x - 1][y - 1] = '*'; // Place the player's mark '*'
                break; // Exit the loop
            } else {
                printf("Coordinates are already occupied, please make another move!\n");
            }
        } else {
            printf("Invalid input, please enter again!\n");
        }
    }
}

// Handle the computer's move on the game board
void ComputerMove(char board[ROW][COL], int row, int col) {
    printf("Computer's move:\n");
    while (1) { // Infinite loop until an empty cell is found
    	int x = rand() % ROW; // Random row
    	int y = rand() % COL; // Random column
        if (board[x][y] == ' ') { // Check if the cell is empty
            board[x][y] = '#'; // Place the computer's mark '#'
            break; // Exit the loop
        }
    }
}

// Check if the game board is full
int IsFull(char board[ROW][COL], int row, int col) {
    int i = 0, j = 0;
    for (i = 0; i < row; i++) { // Loop through each row
        for (j = 0; j < col; j++) { // Loop through each column
            if (board[i][j] == ' ') { // If an empty cell is found
                return 0; // Board is not full
            }
        }
    }
    return 1; // Board is full
}

// Check for a win condition on the game board
char IsWin(char board[ROW][COL], int row, int col) {
    // Check rows for a win
    int i = 0;
    for (i = 0; i < row; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ') {
            return board[i][1]; // Return the winning mark
        }
    }
    // Check columns for a win
    int j = 0;
    for (j = 0; j < col; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[1][j] != ' ') {
            return board[1][j]; // Return the winning mark
        }
    }
    // Check diagonals for a win
    for (i = 0, j = 1; i < row; i++, j++) {
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ') {
            return board[1][1]; // Return the winning mark
        }
        if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ') {
            return board[1][1]; // Return the winning mark
        }
    }
    // Check for a draw (board full)
    if (IsFull(board, ROW, COL)) {
        return 'Q'; // Return 'Q' for draw
    }
    return 'C'; // Return 'C' for continue playing
}
