#pragma once
#include <iostream>
#include "FunBoard.h"

using namespace std;

int points = 0, pointsX = 0, pointsO = 0;
int answear = 0;

// подсчет очков для игроков
int Scoring(char player, int points) {
    if (player == 'Х') {
        pointsX += points;
        return pointsX;
    }
    else {
        pointsO += points;
        return pointsO;
    }
}

void Play(char player) {
    bool chek = true;
    do {
        FreeCells();
        cout << "Выберите клетку (от 1 до 9) - "; cin >> answear;
        char ia = answear + '0';
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ia) {
                    board[i][j] = player;
                    !chek;
                    points = 1;
                    Scoring(player, points);
                    points = 0;
                    return;
                }
                else
                    chek = true;
            }
        }

    } while (answear < 1 || answear > 10 || chek);
}
