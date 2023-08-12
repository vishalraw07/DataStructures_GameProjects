
#include "MineSweeper.h"
using namespace std;



MineSweeper::MineSweeper(int n, int x, int y) : size(n), totalMines(n), gameOver(false) {
        board.assign(size, vector<char>(size, EMPTY));
        revealed.assign(size, vector<bool>(size, false));

        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(0, size - 1);

        // Place mines randomly
        for (int i = 0; i < totalMines; ++i) {
            int row, col;
            do {
                row = dis(gen);
                col = dis(gen);
            } while (row == x && col == y); // Ensure the first input cell is not a mine
            board[row][col] = MINE;
            updateAdjacentCells(row, col);
        }
}


void MineSweeper::updateAdjacentCells(int row, int col) {

        for (int i = row - 1; i <= row + 1; ++i) {
            for (int j = col - 1; j <= col + 1; ++j) {
                if (i >= 0 && i < size && j >= 0 && j < size && board[i][j] != '*') {
                    board[i][j]++;
                }
            }
        }
    }

void MineSweeper::reveal(int row, int col) {
        if (row < 0 || row >= size || col < 0 || col >= size || revealed[row][col] || gameOver) {
            return;
        }

        revealed[row][col] = true;

        if (board[row][col] == '*') {
            gameOver = true;
            return;
        }

        if (board[row][col] == '0') {
            for (int i = row - 1; i <= row + 1; ++i) {
                for (int j = col - 1; j <= col + 1; ++j) {
                    reveal(i, j);
                }
            }
        }
    }


bool MineSweeper::isGameWon() {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (board[i][j] != '*' && !revealed[i][j]) {
                    return false;
                }
            }
        }
        return true;
}

bool MineSweeper::isGameOver() {
        return gameOver;
    }

void MineSweeper::displayBoard() {
        cout << "Current Board Status:" << endl;
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (revealed[i][j]) {
                    cout << board[i][j] << " ";
                } else {
                    cout << "- ";
                }
            }
            cout << endl;
        }
}

void MineSweeper::playGame() {
        int row, col;

        while (!isGameOver() && !isGameWon()) {
            displayBoard();

            cout << "Enter the next cell to click (row and column): ";
            cin >> row >> col;

            reveal(row, col);
        }

        displayBoard();

        if (isGameWon()) {
            cout << "Congratulations! You've won!" << endl;
        } else {
            cout << "Game over! You've hit a mine!" << endl;
        }
    }












