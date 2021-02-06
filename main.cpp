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
    bool draw;

    do {
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                cout << "|" << board[i][j] << "|";
            }
            cout << endl;
        }

        cout << "Ход Крестика" << endl;
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
        board[row][col] = 'X';
        if ((board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X') ||
            (board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X') ||
            (board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X') ||
            (board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X') ||
            (board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X') ||
            (board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X') ||
            (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') ||
            (board[2][0] == 'X' && board[1][1] == 'X' && board[0][2] == 'X')) {
            cout << "Выиграл Крестик" << endl;
            break;
        }
        draw = true;
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                if (board[i][j] == ' ') {
                    draw = false;
                }
            }
        }
        if (draw) {
            cout << "Ничья!" << endl;
            break;
        }


        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                cout << "|" << board[i][j] << "|";
            }
            cout << endl;
        }

        cout << "Ход Нолика" << endl;
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
        board[row][col] = 'O';
        if ((board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O') ||
            (board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O') ||
            (board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O') ||
            (board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O') ||
            (board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O') ||
            (board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O') ||
            (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') ||
            (board[2][0] == 'O' && board[1][1] == 'O' && board[0][2] == 'O')) {
            cout << "Выиграл Нолик" << endl;
            break;
        }
        draw = true;
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                if (board[i][j] == ' ') {
                    draw = false;
                }
            }
        }
        if (draw) {
            cout << "Ничья!" << endl;
            break;
        }

    } while (true);
}
