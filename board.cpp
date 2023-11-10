// board.cpp
#include "board.h"
#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

Board::Board() {
    size = 8; // Tamanho padrão do xadrez
    board.resize(size, 0);
}

void Board::printBoard() const {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (alguma coisa pra dizer que rainha ta aqui) {
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
            if (board[i] == board[j] || abs(board[i] - board[j]) == j - i) {
                ++cost;
            }
        }
    }
    return cost;
}
