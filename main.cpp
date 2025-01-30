#include <iostream>
#include <string>

using namespace std;

int main()
{
    // representing a tic-tac-toe board using a 2d array of characters

    char board[3][3] = // 3 rows and 3 colomns
        {
            {' ', ' ', ' '}, // empty tile
            {' ', ' ', ' '}, // empty tile
            {' ', ' ', ' '}  // empty tile
        };
    // we need two players:
    const char player_x = 'x';
    const char player_0 = 'o';
    // keeps track of the current player
    char current_player = player_x; // by default, player_x will start first
    // default values to keep track of the rows and columns

    int row = -1;    // player has not made a decision yet
    int column = -1; // player has not made a decision yet
    char winner = ' ';

    // iterating through the 9 boards
    for (int i = 0; i < 9; i++)
    {
        // print game board
        cout << "   |   |   " << endl;
        cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
        cout << "___|___|___" << endl;
        cout << "   |   |   " << endl;
        cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
        cout << "___|___|___" << endl;
        cout << "   |   |   " << endl;
        cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
        cout << "   |   |   " << endl;

        // if there is a winner, we are not going to ask for the input
        if (winner != ' ')
        {
            break;
        }

        // get player input
        cout << "The current player is : " << current_player << endl;
        while (true)
        {
            cout << "Please Enter two numbers from 0-2 for row and column: " << endl;
            cin >> row >> column;
            // checking if values are within the ranges of 0 and 2
            if (row < 0 || row > 2 || column < 0 || column > 2)
            {
                cout << "invalid input, please try again, values must be between 0 and 2" << endl;
            }
            // checking if there is no empty space
            else if (board[row][column] != ' ')
            {
                cout << "tile is full, please try again!" << endl;
            }
            else
            {
                break;
            }
            // reset the board
            row = -1;
            column = -1;
            cin.clear(); // clear the error flags
            // discard the values from the input stream and skip to the new line upto 10 000 characters already in input stream
            cin.ignore(10000, '\n');
        }

        board[row][column] = current_player;
        // if current player is equal to player_x, then we set the current_player to player_o, otherwise to player_x
        current_player = (current_player == player_x) ? player_0 : player_x;

        // check for winners:
        //  checking all the rows/horizontal:
        for (int j = 0; j < 3; j++)
        {
            if (board[j][0] != ' ' && board[j][0] == board[j][1] && board[j][1] == board[j][2])
            {
                winner = board[j][0];
                break;
            }
        }
        // checking the columns/verticals
        for (int k = 0; k < 3; k++)
        {
            if (board[0][k] != ' ' && board[0][k] == board[1][k] && board[1][k] == board[2][k])
            {
                winner = board[k][0];
                break;
            }
        }

        // checking the diagonals
        if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
        {
            winner = board[0][0];
        }
       else if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0])
        {
            winner = board[0][2];
        }
    }
    if (winner != ' ')
    {
        cout << "The winner is player: "<<winner << endl;
    }
    else
    {
        cout << "Its a Tie" << endl;
    }
}