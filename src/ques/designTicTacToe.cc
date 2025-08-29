/* The given problem describes a tic-tac-toe game which
* is generalized for an n x n board, as opposed to the
* traditional 3 x 3 board. Two players take turns to
* place their mark on the board. The goal for each
* player is to get n of their own marks in a row, either
* horizontally, vertically, or diagonally.
*
* The challenge is to implement a class TicTacToe that can
* process each move made by the players and determine the
* status of the game after each move, specifically:
*
* If the game continues with no winner.
* If player 1 has won.
*If player 2 has won.
*/
#include<iostream>

#include "utils.hpp"

using namespace std;

// return the state of game
typedef enum game_state_s {
    CONTINUE = 0,
    PLAYER_WON = 1,
} game_state_e;


/*
board_state_ is vector of length 2n+2
Its store the state of row, cloumn and diagonals
row = 0 to n-1
cloumn = n to 2n-1
row == cloumn diagonal(clock wise) are in 2n
row+cloumn = n-1 diagonal(anticlock wise) are in 2n+1
for any player if any of these become equal to n then it wins
*/ 
class TicTacToe {
    int n_;
    vector<vector<int>> board_state_;
public:
    TicTacToe(int n) {
        n_=n;
        board_state_ = vector<vector<int>>(2,vector<int>((n*2)+2, 0));
    }

    game_state_e
    move(int row, int col, int player) {
        // update the row covered
        board_state_[player][row]++;
        // update the column covered
        board_state_[player][col+n_]++;
        // update clock wise diagonal
        if(row == col) {
            board_state_[player][2*n_]++;
        }

        // update the anticlock wise diagonal
        if((row+col) == (n_ - 1)) {
            board_state_[player][(2*n_) + 1]++;
        }

        // verify that any one is fulfilled
        // Check the counters for the player to see if they've reached 'size',
        // which would mean they've filled a row, column, or diagonal.
        if (board_state_[player][row] == n_
            || board_state_[player][col + n_] == n_
            || board_state_[player][n_ * 2] == n_
            || board_state_[player][(n_ * 2) + 1] == n_) {
            return PLAYER_WON;  // The player has won the game.
        }
        return CONTINUE;
    }
};

int
main()
{
    int n = 3;
    game_state_e result;
    TicTacToe board = TicTacToe(n);
    result = board.move(1,1,0); // first player move
    result = board.move(0,0,1); // second player move
    result = board.move(2,2,0); // first player move
    result = board.move(0,2,1); // second player move
    result = board.move(1,2,0); // second player move
//    result = board.move(0,1,1); // first player move

    if(result == PLAYER_WON) {
        cout << "player 1 won\n";
    } else {
        cout << "no one won\n";
    }
    return 0;
}
