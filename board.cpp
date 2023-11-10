// board.cpp
#include "board.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>

using namespace std;

Board::Board() {
    size = 8; // Tamanho padrão do xadrez
    posX.resize(size, 0);
    posY.resize(size, 0);
}

void Board::printBoard() const {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (posX[i] == j) {
                cout << "Q ";
            } else {
                cout << ". ";
            }
        }
        cout << "\n";
    }
    cout << "\n";
}

int Board::calculateCost() const {
    int cost = 0;
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (posX[i] == posX[j] || abs(posX[i] - posX[j]) == abs(posY[i] - posY[j])) {
                ++cost;
            }
        }
    }
    return cost;
}

void Board::initialRandomBoard() {
    for (int i = 0; i < size; ++i) {
        posX[i] = i;
        posY[i] = i;
    }

    // Embaralha aleatoriamente os vetores
    random_shuffle(posX.begin(), posX.end());
    random_shuffle(posY.begin(), posY.end());
}

