// board.cpp
#include "board.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>

#include <unordered_set>

using namespace std;

Board::Board() {
    this->setQueensQuantity(0);
    size = 8; // Tamanho padrão do xadrez
    posX.resize(size, 0);
    posY.resize(size, 0);
}


void Board::printBoard() const{
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            bool temRainha = false;

            for (int k = 0; k < size; k++) {
                if (posX[k] == i && posY[k] == j) {
                    temRainha = true;
                    break;
                }
            }
            if (temRainha) {

                cout << "Q ";
            } else {
                cout << ". ";
            }
        }

        cout << "\n";
    }
}



int Board::calculateCost() const {
    int cost = 0;
    for (int i = 0; i < queensQuantity; i++) {
        for (int j = i + 1; j < queensQuantity; j++) {
            if (posX[i] == posX[j] || posY[i] == posY[j] || abs(posX[i] - posX[j]) == abs(posY[i] - posY[j])) {

                cost++;                                     

            }
        }
    }
    return cost;
}



void Board::initialRandomBoard() {

    posX.resize(size, 0);
    posY.resize(size, 0);

    setQueensQuantity(size);

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


// Função para obter o vetor posX
vector<int> Board::getVectorX() const{
    return posX;
}

// Função para obter o vetor posY
vector<int> Board::getVectorY() const{
    return posY;
}

void Board::setVectorX(const vector<int>& newVectorX) {
    posX = newVectorX;
}

// Função para definir o vetor posY
void Board::setVectorY(const vector<int>& newVectorY) {
    posY = newVectorY;
}

void Board::copyBoard(const Board &source) {
    // Copia o tamanho do tabuleiro
    size = source.size;

    // Copia as posições X e Y das rainhas diretamente usando =
    posX = source.posX;
    posY = source.posY;
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

int Board::getQueensQuantity() {
   return queensQuantity; 
}


void Board::setQueensQuantity(int x) {
   queensQuantity = x;
}

void Board::placeQueen(int queenIndex, int x, int y){
    int newQueenQuantity = getQueensQuantity() + 1;
    
    setQueensQuantity(newQueenQuantity);
    
    posX.resize(newQueenQuantity);
    posY.resize(newQueenQuantity);
    
    posX[queenIndex] = x;
    posY[queenIndex] = y;

}

void Board::printBoardBF() const{
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            bool temRainha = false;

            for (int k = 0; k < queensQuantity; k++) {
                if (posX[k] == i && posY[k] == j) {
                    temRainha = true;
                    break;
                }
            }
            if (temRainha) {

                cout << "Q ";
            } else {
                cout << ". ";
            }
        }

        cout << "\n";
    }
}

void Board::printPos() {
    for (int i = 0; i < posX.size(); i++)
    {
        cout << posX[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < posY.size(); i++)
    {
        cout << posY[i] << " ";
    }
    cout << endl;
}