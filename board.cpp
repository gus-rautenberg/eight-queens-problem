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
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (posX[i] == posX[j] || posY[i] == posY[j] || abs(posX[i] - posX[j]) == abs(posY[i] - posY[j])) {
                ++cost;
            }
        }
    }
    return cost;
}

void Board::initialRandomBoard() {
    vector<int> indices(size);
    for (int i = 0; i < size; i++) {
        indices[i] = i;
    }

    // Embaralha aleatoriamente os índices
    random_shuffle(indices.begin(), indices.end());

    for (int i = 0; i < size; i++) {
        posX[i] = indices[i];
    }

    // Embaralha aleatoriamente os índices novamente
    random_shuffle(indices.begin(), indices.end());

    for (int i = 0; i < size; i++) {
        posY[i] = indices[i];
    }
}

Board::Board(const Board &board) {
    size = board.size;
    posX = board.posX;
    posY = board.posY;
}


void Board::randomMove() {
    int randomQueen = rand() % size;
    int randomPositionX = rand() % size;
    int randomPositionY = rand() % size;

    
    while (!isPositionFree(randomPositionX, randomPositionY)) {
        randomPositionX = rand() % size;
        randomPositionY = rand() % size;
    }

    moveQueen(randomQueen, randomPositionX, randomPositionY);
}

bool Board::isPositionFree(int x, int y) const {
    // Verifica se a posição está livre
    for (int i = 0; i < size; i++) {
        if (posX[i] == x && posY[i] == y) {
            return false;
        }
    }
    return true;
}

void Board::moveQueen(int queenIndex, int newPositionX, int newPositionY) {
    posX[queenIndex] = newPositionX;
    posY[queenIndex] = newPositionY;
}