#include <iostream>
#include "FunBoard.h"
#include "FunChek.h"
#include "FunPlayer.h"
#include "FunPlay.h"

using namespace std;

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
    player = PlayerChoice(choice);
    do
    {
        PrintBoard(); cout << endl;
        cout << "Ход " << player << endl;
        Play(player);

        if (ChekWinDiagonal(player, SIZE) || ChekWinLanes(player, SIZE)) {
            PrintBoard();
            cout << "Выиграл " << player << " за " << Scoring(player, points) << " хода(ов)!!!" << endl;
            break;
        }
        player = PlayerSelect(player);

        if (ChekDraw()) {
            PrintBoard();
            cout << "Ничья!" << endl;
        }
    } while (!ChekDraw());
}
