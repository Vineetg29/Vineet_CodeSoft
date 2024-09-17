#include <iostream>
using namespace std;

char board[3][3]; // 3x3 grid for the game board
char currentPlayer; // Tracks the current player ('X' or 'O')

// Function to initialize the board with empty cells
void initializeBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = '1' + (i * 3 + j); // Initialize with numbers 1-9
        }
    }
}

// Function to display the current board
void displayBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        if (i < 2) cout << "\n---------\n";
    }
    cout << "\n";
}

// Function to switch between players 'X' and 'O'
void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

// Function to make a move on the board
bool makeMove(int cell) {
    int row = (cell - 1) / 3;
    int col = (cell - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentPlayer;
        return true;
    } else {
        cout << "Cell already taken, try again.\n";
        return false;
    }
}

// Function to check if the current player has won
bool checkWin() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
            (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
        (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)) {
        return true;
    }

    return false;
}

// Function to check if the game is a draw
bool checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false; // If any cell is not filled, it's not a draw
            }
        }
    }
    return true;
}

// Main game loop
void playGame() {
    int move;
    bool gameWon = false;
    bool gameDraw = false;
    currentPlayer = 'X'; // X always starts the game

    while (!gameWon && !gameDraw) {
        displayBoard();
        cout << "Player " << currentPlayer << ", enter the number of the cell where you want to place your move: ";
        cin >> move;

        // Validate move and update board
        if (move >= 1 && move <= 9 && makeMove(move)) {
            gameWon = checkWin();
            gameDraw = checkDraw();

            if (!gameWon && !gameDraw) {
                switchPlayer();
            }
        } else {
            cout << "Invalid move. Try again.\n";
        }
    }

    displayBoard();
    if (gameWon) {
        cout << "Player " << currentPlayer << " wins the game!\n";
    } else if (gameDraw) {
        cout << "It's a draw!\n";
    }
}

// Main function to manage the game and replay option
int main() {
    char playAgain;

    do {
        initializeBoard();
        playGame();

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing!\n";
    return 0;
}

