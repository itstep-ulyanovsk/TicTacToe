#pragma once
#include <iostream>
#include "FunBoard.h"

using namespace std;

// �������� �� ������� ����������
bool ChekWinDiagonal(char player, int size) {
    bool DiagonalRight = true;
    bool DiagonalLeft = true;
    for (int i = 0; i < size; i++) {
        DiagonalRight = DiagonalRight && (board[i][i] == player);
        DiagonalLeft = DiagonalLeft && (board[size - i - 1][i] == player);
    }

    if (DiagonalRight || DiagonalLeft) {
        return true;
    }
    return false;
}
// �������� �� ������� ����� � ��������
bool ChekWinLanes(char player, int size) {
    for (int i = 0; i < size; i++) {
        bool cols = true;
        bool rows = true;
        for (int j = 0; j < size; j++) {
            cols = cols && (board[i][j] == player);
            rows = rows && (board[j][i] == player);
        }

        if (cols || rows) return true;
    }
    return false;
}
// �������� �� "�����"
bool ChekDraw() {
    bool draw = true;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] != '�' && board[i][j] != '�') {
                draw = false;
            }
        }
    }
    if (draw) {
        return true;
    }
    return false;
}
