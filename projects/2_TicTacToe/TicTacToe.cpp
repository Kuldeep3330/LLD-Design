// components
// GameBoard: A 3*3 matrix to represent the game state
// Players: Two players, Typically 'X' and 'O'
//  Game Flow Alternating turns between players until there is a win or a draw
// win / Draw Logic: checking rows, columns and diagonals for a win or a full board for a draw
//  Class: TicTacToe
//  Attributes:

// char board[3][3]: 3x3 array representing the game board.
// char currentPlayer: Tracks the current player ('X' or 'O').
// Methods:

// void displayBoard(): Prints the current state of the board.
// bool makeMove(int row, int col): Allows the current player to make a move if the position is valid.
// bool checkWin(): Checks if the current player has won.
// bool checkDraw(): Checks if the game has ended in a draw.
// void switchPlayer(): Switches the current player after a valid move.
// void playGame(): Main method to control game flow.

#include <bits/stdc++.h>
using namespace std;

#define BOARD_SIZE 3
const char EMPTY = ' ';
const char PLAYER_X = 'X';
const char PLAYER_O = 'O';

class TicTacToe
{
private:
    // char board[3][3];
    char board[BOARD_SIZE][BOARD_SIZE];
    char currentPlayer;

    // Initialize the board with empty spaces
    void initializeBoard()
    {
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                // board[i][j] = ' ';
                board[i][j] = EMPTY;
    }

    // Display the current board state
    void displayBoard()
    {
        cout << "  0 1 2\n";
        for (int i = 0; i < 3; ++i)
        {
            cout << i << " ";
            for (int j = 0; j < 3; ++j)
            {
                cout << board[i][j];
                if (j < 2)
                    cout << "|";
            }
            cout << endl;
            if (i < 2)
                cout << "  -----\n";
        }
    }

    // Check if the current player has won
    bool checkWin()
    {
        // Check rows and columns
        for (int i = 0; i < 3; ++i)
        {
            if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
                (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer))
                return true;
        }

        // Check diagonals
        if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
            (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer))
            return true;

        return false;
    }

    // Check if the board is full (draw)
    bool checkDraw()
    {
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                if (board[i][j] == ' ')
                    return false;
        return true;
    }

    // Switch to the next player
    void switchPlayer()
    {
        // currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        currentPlayer = (currentPlayer == PLAYER_X) ? PLAYER_O : PLAYER_X;
    }

public:
    // Constructor
    TicTacToe()
    {
        initializeBoard();
        currentPlayer = 'X';
    }

    // Play the game
    void playGame()
    {
        int row, col;
        bool gameRunning = true;

        while (gameRunning)
        {
            displayBoard();
            cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            cin >> row >> col;

            if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ')
            {
                board[row][col] = currentPlayer;

                if (checkWin())
                {
                    displayBoard();
                    cout << "Player " << currentPlayer << " wins!\n";
                    gameRunning = false;
                }
                else if (checkDraw())
                {
                    displayBoard();
                    cout << "It's a draw!\n";
                    gameRunning = false;
                }
                else
                {
                    switchPlayer();
                }
            }
            else
            {
                cout << "Invalid move. Try again.\n";
            }
        }
    }
};
// void initializeBoard(char board[3][3])
// {
//     for (int i = 0; i < 3; ++i)
//         for (int j = 0; j < 3; ++j)
//             board[i][j] = ' ';
// }
// void displayBoard(char board[3][3])
// {
//     initializeBoard(board);

//     cout << " 0 1 2\n";
//     for (int i = 0; i < 3; i++)
//     {
//         cout << i << " ";
//         for (int j = 0; j < 3; j++)
//         {
//             cout << board[i][j];
//             if (j < 2)
//                 cout << "|";
//         }
//         cout << endl;
//         if (i < 2)
//             cout << " ------\n";
//     }
// }
int main()
{
    TicTacToe game;
    game.playGame();
    // char board[3][3];

    // displayBoard(board);
    return 0;
}