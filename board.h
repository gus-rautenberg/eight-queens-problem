// board.h
#ifndef BOARD_H
#define BOARD_H

#include <vector>

using namespace std;

class Board {
public:
    Board();
    void printBoard() const;
    int calculateCost() const;
    void initialRandomBoard();

private:
    int size;
    vector<int> posX; // Vetor para armazenar as posições X das rainhas
    vector<int> posY; // Vetor para armazenar as posições Y das rainhas
};

#endif // BOARD_H
