#include <iostream>

using namespace std;

const int SIZE = 3;
char board[SIZE][SIZE] = {{' ', ' ', ' '},
                          {' ', ' ', ' '},
                          {' ', ' ', ' '}};

void PrintBoard()
{
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << "|" << board[i][j] << "|";
        }
        cout << endl;
    }
}
int Win(char board [SIZE][SIZE], char symbol) {
    int score;
    if ((board[0][0] == symbol && board[0][1] == symbol && board[0][2] == symbol) ||
        (board[1][0] == symbol && board[1][1] == symbol && board[1][2] == symbol) ||
        (board[2][0] == symbol && board[2][1] == symbol && board[2][2] == symbol) ||
        (board[0][0] == symbol && board[1][0] == symbol && board[2][0] == symbol) ||
        (board[0][1] == symbol && board[1][1] == symbol && board[2][1] == symbol) ||
        (board[0][2] == symbol && board[1][2] == symbol && board[2][2] == symbol) ||
        (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) ||
        (board[2][0] == symbol && board[1][1] == symbol && board[0][2] == symbol)) {
        score = 1;
    }
    else {
        score = 0;
    }
    return score;
    }

int main()
{
    system("chcp 65001");

    int row, col;
    bool draw;

    do {
        PrintBoard();
        cout << "Ход Крестика" << endl;
        do {
            do {
                cout << "Введите номер строки (от  1 до 3) - ";
                cin >> row;
                if (row - 1 < 0 || row - 1 > 2) {
                    cout << "Вы вышли за диапазон, попробуйте еще раз! " << endl;
                }

            } while (row - 1 < 0 || row - 1 > 2);
            
            
            do {
                cout << "Введите номер столбца (от  1 до 3) - ";
                cin >> col;
            } while (col-1 < 0 || col-1 > 2);
            if (col - 1 < 0 || col - 1 > 2) {
                cout << "Вы вышли за диапазон, попробуйте еще раз! " << endl;
            }
        } while (board[row-1][col-1] != ' ');
        board[row-1][col-1] = 'X';

        if (Win(board, 'X')==1){
            cout << "Выиграл Крестик!" << endl;
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


        PrintBoard();
        cout << "Ход Нолика" << endl;
        do {
            do {
                cout << "Введите номер строки (от  1 до 3) - ";
                cin >> row;
                if (row - 1 < 0 || row - 1 > 2) {
                    cout << "Вы вышли за диапазон, попробуйте еще раз! " << endl;
                }
            } while (row-1 < 0 || row-1 > 2);

            do {
                cout << "Введите номер столбца (от  1 до 3) - ";
                cin >> col;
                if (col - 1 < 0 || col - 1 > 2) {
                    cout << "Вы вышли за диапазон, попробуйте еще раз! " << endl;
                }
            } while (col-1 < 0 || col-1 > 2);
        } while (board[row-1][col-1] != ' ');
        board[row-1][col-1] = 'O';

        if (Win(board, 'O') == 1) {
            cout << "Выиграл Нолик!" << endl;
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
