#include <iostream>

using namespace std;

int counterX = 0, counterO = 0;
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

void Play(char player) {
    int row = 0, col = 0;
    int answear;
    do
    {
        do {
            cout << "Выберите клетку (от 1 до 9) - "; cin >> answear;
            switch (answear)
            {
            case 1:
                row = 0;
                col = 0;
                break;
            case 2:
                row = 0;
                col = 1;
                break;
            case 3:
                row = 0;
                col = 2;
                break;
            case 4:
                row = 1;
                col = 0;
                break;
            case 5:
                row = 1;
                col = 1;
                break;
            case 6:
                row = 1;
                col = 2;
                break;
            case 7:
                row = 2;
                col = 0;
                break;
            case 8:
                row = 2;
                col = 1;
                break;
            case 9:
                row = 2;
                col = 2;
                break;
            }
        } while (answear < 0 || answear > 10 || board[row][col] == 'Х' || board[row][col] == 'О');
        board[row][col] = player;
        if (player == 'Х') {
            counterX++;
        }
        else {
            counterO++;
        }
    } while (board[row][col] != 'Х' && board[row][col] != 'О');
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


        PrintBoard();
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
