#include <iostream>
#include <vector>

using namespace std;


void displayBoard(const vector<char>& board) {
    cout << "-------------" << endl;
    for (int i = 0; i < 9; i += 3) {
        cout << "| " << board[i] << " | " << board[i + 1] << " | " << board[i + 2] << " |" << endl;
        cout << "-------------" << endl;
    }
}


bool checkWin(const vector<char>& board, char player) {
    
    for (int i = 0; i < 9; i += 3) {
        if (board[i] == player && board[i + 1] == player && board[i + 2] == player) {
            return true;
        }
    }
    
    for (int i = 0; i < 3; i++) {
        if (board[i] == player && board[i + 3] == player && board[i + 6] == player) {
            return true;
        }
    }
    
    if (board[0] == player && board[4] == player && board[8] == player) {
        return true;
    }
    if (board[2] == player && board[4] == player && board[6] == player) {
        return true;
    }
    return false;
}


bool checkTie(const vector<char>& board) {
    for (char c : board) {
        if (c == ' ') {
            return false;
        }
    }
    return true;
}


bool playAgain() {
    char choice;
    cout << "Do you want to play again? (y/n): ";
    cin >> choice;
    return (choice == 'y' || choice == 'Y');
}

int main() {
    while (true) {
        vector<char> board(9, ' ');
        char currentPlayer = 'X';

        while (true) {
            displayBoard(board);
            cout << "Player " << currentPlayer << ", enter a number (1-9) to place your mark: ";
            int position;
            cin >> position;

            if (position < 1 || position > 9 || board[position - 1] != ' ') {
                cout << "Invalid move. Try again." << endl;
                continue;
            }

            board[position - 1] = currentPlayer;

            if (checkWin(board, currentPlayer)) {
                displayBoard(board);
                cout << "Player " << currentPlayer << " wins!" << endl;
                break;
            }

            if (checkTie(board)) {
                displayBoard(board);
                cout << "It's a tie!" << endl;
                break;
            }

            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }

        if (!playAgain()) {
            break;
        }
    }

    return 0;
}