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

bool ChekWin(char player) {
    int counter = 0;
    if (player == 'Х') {
        counter = counterX;
    }
    else {
        counter = counterO;
    }
    if ((board[0][0] == player && board[0][1] == player && board[0][2] == player) ||
        (board[1][0] == player && board[1][1] == player && board[1][2] == player) ||
        (board[2][0] == player && board[2][1] == player && board[2][2] == player) ||
        (board[0][0] == player && board[1][0] == player && board[2][0] == player) ||
        (board[0][1] == player && board[1][1] == player && board[2][1] == player) ||
        (board[0][2] == player && board[1][2] == player && board[2][2] == player) ||
        (board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[2][0] == player && board[1][1] == player && board[0][2] == player)) {
        PrintBoard();
        cout << "Выиграл " << player << " за " << counter << " хода(ов)!!!" << endl;
        return true;
    }
    else
        return false;
}

bool ChekDraw(char player) {
    bool draw = true;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] != 'Х' && board[i][j] != 'О') {
                draw = false;
            }
        }
    }
    if (draw) {
        PrintBoard();
        cout << "Ничья!" << endl;
        return true;
    }
    return false;
}

char PlayerChoice(char player) {
    if (player == 'Х')
        return 'О';
    else
        return 'Х';
}

int main()
{
    setlocale(LC_ALL, "Rus");

    int choice = 0;
    char player;

    cout << "TicTacToe versia 1.0" << endl << endl;

    do
    {
        cout << "Выберите кто ходит первым: 1 - 'Х'; 2 - 'О' " << endl;
        cin >> choice; cout << endl;
    } while (choice < 0 || choice > 2);

    if (choice == 1) {
        player = 'Х';
    }
    else {
        player = 'О';
    }

    do
    {
        if (ChekDraw(player)) {
            break;
        }
        else {
            PrintBoard(); cout << endl;
            cout << "Ход " << player << endl;
            Play(player);
            if (ChekWin(player)) {
                break;
            }
            player = PlayerChoice(player);
        }
    } while (!ChekDraw(player));



}
