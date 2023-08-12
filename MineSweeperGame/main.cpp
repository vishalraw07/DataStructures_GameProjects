#include "MineSweeper.h"
#include <iostream>

using namespace std;

void introMessage()
{
    cout<<"\t------------------------------------------------------------------------\n";
    cout<<"\t|                                                                      |\n";
    cout<<"\t|                     WELCOME TO MINESWEEPER GAME                      |\n";
    cout<<"\t|                                                                      |\n";
    cout<<"\t------------------------------------------------------------------------\n";
    cout<<endl;

    cout<<"RULES:\n";
    cout<<"1.The board is divided into cells, with mines randomly distributed.\n2.To win, you need to open all the cells.\n3.The number on a cell shows the number of mines adjacent to it. Using this information,\n  you can determine cells that are safe, and cells that contain mines.\n4.Interact, evolve and enjoy!";
    cout<<endl;

    cout<<"\nHow to play:\n";
    cout<<"1.user will input x & y (coordinates where they want to click)\n2.In each step check for win or lose case.\n";
    cout<<endl;
}

int main() {

    introMessage();

    int n, x, y;
    cout << "Enter the size of the board (n >= 9): ";
    cin >> n;

    cout << "Enter the first cell to click (row and column): ";
    cin >> x >> y;

    MineSweeper game(n, x, y);
    game.playGame();

    return 0;
}
