// board.cpp
// sudo apt-get install nlohmann-json3-dev
#include "board.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <fstream>
// #include<iostream> 
// #include <nlohmann/json.hpp>


#include <unordered_set>

using namespace std;
// using json = nlohmann::json; 

Board::Board() {
    size = 8; // Tamanho padrão do xadrez
    
    vector<int> newBoard(size, -1);

    queensQuantity = 0;
    posX = newBoard; //setting all queens X position to -1 so if they not in the board they won't show anywere
    posY = newBoard; //setting all queens Y position to -1 so if they not in the board they won't show anywere
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

        cout << "<br>" << endl;
    }
    cout << "<br>" << "<br>" << endl << endl;
}

void Board::writeOnFile(fstream& out){
    if (out.is_open()) {
        out << "{ \"queens\": [";

        for (int i = 0; i < 8; ++i) {
            out << "{ \"x\": " << posX[i] << ", \"y\": " << posY[i] << "}";
            if (i < 7) {
                out << ",";
            }
        }
        out << "]";
    }
}


int Board::calculateCost() const {
    int cost = 0;
    for (int i = 0; i < 7; i++) {
        for (int j = i + 1; j < 8; j++) {
            
            if (i != j && posX[i] == posX[j] || posY[i] == posY[j] || abs(posX[i] - posX[j]) == abs(posY[i] - posY[j])) {
                cost++;                                     
            }
        }
    }
    return cost;
}



void Board::initialRandomBoard() {

    posX.resize(size, 0);
    posY.resize(size, 0);

    queensQuantity = 8;

    for (int i = 0; i < 8; i++)
    {
        int rx, ry;
        do
        {
            rx = rand()%8;
            ry = rand()%8;
        } while (!isPositionFree(rx, ry));
        posX[i] = rx;
        posY[i] = ry;
    }

}

void Board::initialRandomBoardOptimized() {

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

int Board::getSize() {
    return size;    
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
    queensQuantity = source.queensQuantity;
}

Board::Board(const Board &board) {
    size = board.size;
    posX = board.posX;
    posY = board.posY;
    queensQuantity = board.queensQuantity;
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


void Board::addQueen() {
   queensQuantity += 1;
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

int Board::isAttacking(int newestQueen){
    int count=0;
    for (int j = newestQueen-1; j >= 0; j--) {
        if (posX[newestQueen] == posX[j] || posY[newestQueen] == posY[j] || abs(posX[newestQueen] - posX[j]) == abs(posY[newestQueen] - posY[j])){
            // cout << "true" << endl << endl;
            count++;
        }
    }

    // cout << "false" << endl << endl;
    return count;
}