#pragma once
#include <iostream>


using namespace std;
const int SIZE = 3;

char board[SIZE][SIZE] = { {'1', '2', '3'},
                          {'4', '5', '6'},
                          {'7', '8', '9'} };

void PrintBoard()
{
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << "|" << board[i][j] << "|";
        }
        cout << endl;
    }
}

void FreeCells() {
    cout << "Свободные клетки: ";
    for (int i = 0; i < SIZE; ++i) {
        int j = 0;
        for (; j < SIZE; ++j) {
            if (board[i][j] != 'Х' && board[i][j] != 'О')
                cout << board[i][j] << "; ";
        }
    }
    cout << endl;
}
