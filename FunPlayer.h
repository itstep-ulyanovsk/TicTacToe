#pragma once
#include <iostream>

using namespace std;
// выбор игрока
char PlayerChoice(char choice) {
    if (choice == 1) {
        return 'Х';
    }
    else {
        return 'О';
    }
}
// смена игрока
char PlayerSelect(char player) {
    if (player == 'Х')
        return 'О';
    else
        return 'Х';
}

