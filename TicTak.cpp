#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 3;

// Function to print the board
void printBoard(const vector<vector<char>>& board) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << board[i][j];
            if (j < SIZE - 1) cout << " | ";
        }
        cout << endl;
        if (i < SIZE - 1) cout << "---------" << endl;
    }
}

// Function to check for a win
bool checkWin(const vector<vector<char>>& board, char player) {
    // Check rows and columns
    for (int i = 0; i < SIZE; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }

    return false;
}

// Function to check for a draw
bool checkDraw(const vector<vector<char>>& board) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

// Function to handle player moves
bool makeMove(vector<vector<char>>& board, int row, int col, char player) {
    if (row < 0 || row >= SIZE || col < 0 || col >= SIZE || board[row][col] != ' ') {
        return false;
    }
    board[row][col] = player;
    return true;
}

int main() {
    vector<vector<char>> board(SIZE, vector<char>(SIZE, ' '));
    char currentPlayer = 'X';
    int row, col;
    bool validMove;

    cout << "Welcome to Tic-Tac-Toe!" << endl;

    while (true) {
        printBoard(board);
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        validMove = makeMove(board, row - 1, col - 1, currentPlayer);

        if (!validMove) {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        if (checkWin(board, currentPlayer)) {
            printBoard(board);
            cout << "Player " << currentPlayer << " wins!" << endl;
            break;
        }

        if (checkDraw(board)) {
            printBoard(board);
            cout << "The game is a draw!" << endl;
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}
