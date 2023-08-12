#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <vector>
using namespace std;

const char MINE = '*';
const char EMPTY = '0';

class MineSweeper {

public:
    MineSweeper(int n,int x,int y);
    void updateAdjacentCells(int row , int col );
    void reveal(int row,int col);
    bool isGameOver();
    bool isGameWon();
    void displayBoard();
    void playGame();
private:
    int size;
    int totalMines;
    vector<vector<char>> board;
    vector<vector<bool>> revealed;
    bool gameOver;

};

