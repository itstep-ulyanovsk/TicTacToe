#include <iostream>

using namespace std;

int main()
{
    system("chcp 65001");

    const int SIZE = 3;
    char board[SIZE][SIZE] = {{' ', ' ', ' '},
                              {' ', ' ', ' '},
                              {' ', ' ', ' '}};

    int row, col;

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << "|" << board[i][j] << "|";
        }
        cout << endl;
    }

    do {
        do {
            cout << "Введите номер строки (от  0 до 2) - ";
            cin >> row;
        } while (row < 0 || row > 2);

        do {
            cout << "Введите номер столбца (от  0 до 2) - ";
            cin >> col;
        } while (col < 0 || col > 2);
    } while (board[row][col] != ' ');
}
