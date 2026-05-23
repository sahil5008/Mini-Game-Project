#include <iostream>

using namespace std;

char board[3][3];
char currentPlayer;

// Initialize Board
void initializeBoard() {
    char ch = '1';

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ch++;
        }
    }

    currentPlayer = 'X';
}

// Display Board
void displayBoard() {

    cout << "\n";

    for (int i = 0; i < 3; i++) {

        cout << " ";

        for (int j = 0; j < 3; j++) {

            cout << board[i][j];

            if (j < 2)
                cout << " | ";
        }

        cout << endl;

        if (i < 2)
            cout << "---|---|---" << endl;
    }

    cout << "\n";
}

// Check Winner
bool checkWinner() {

    // Rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] &&
            board[i][1] == board[i][2])
            return true;
    }

    // Columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] &&
            board[1][i] == board[2][i])
            return true;
    }

    // Diagonals
    if (board[0][0] == board[1][1] &&
        board[1][1] == board[2][2])
        return true;

    if (board[0][2] == board[1][1] &&
        board[1][1] == board[2][0])
        return true;

    return false;
}

// Check Draw
bool checkDraw() {

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {

            if (board[i][j] != 'X' &&
                board[i][j] != 'O')
                return false;
        }
    }

    return true;
}

// Player Move
void playerMove() {

    int choice;
    int row, col;

    while (true) {

        cout << "Player " << currentPlayer
             << ", enter position (1-9): ";

        cin >> choice;

        if (choice < 1 || choice > 9) {
            cout << "Invalid position! Try again.\n";
            continue;
        }

        row = (choice - 1) / 3;
        col = (choice - 1) % 3;

        // Check if already occupied
        if (board[row][col] == 'X' ||
            board[row][col] == 'O') {

            cout << "Position already taken!\n";
        }
        else {
            board[row][col] = currentPlayer;
            break;
        }
    }
}

// Switch Player
void switchPlayer() {

    if (currentPlayer == 'X')
        currentPlayer = 'O';
    else
        currentPlayer = 'X';
}

// Main Game
void playGame() {

    initializeBoard();

    while (true) {

        displayBoard();

        playerMove();

        if (checkWinner()) {

            displayBoard();

            cout << "🎉 Player "
                 << currentPlayer
                 << " Wins!\n";

            break;
        }

        if (checkDraw()) {

            displayBoard();

            cout << "🤝 Match Draw!\n";

            break;
        }

        switchPlayer();
    }
}

// Main Function
int main() {

    char replay;

    do {

        cout << "\n====== TIC TAC TOE ======\n";

        playGame();

        cout << "\nDo you want to play again? (y/n): ";
        cin >> replay;

    } while (replay == 'y' || replay == 'Y');

    cout << "Thanks for Playing!\n";

    return 0;
}