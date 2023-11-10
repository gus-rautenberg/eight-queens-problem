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
    Board(const Board &board);
    void randomMove();
    bool isPositionFree(int x, int y) const;
    


private:
    int size;
    vector<int> posX; // Vetor para armazenar as posições X das rainhas
    vector<int> posY; // Vetor para armazenar as posições Y das rainhas
    void moveQueen(int queenIndex, int newPositionX, int newPositionY);
};

#endif // BOARD_H
