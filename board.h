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
    vector<int> getVectorX() const;
    vector<int> getVectorY() const;
    void copyBoard(const Board &source);
    void setVectorX(const vector<int>& newVectorX);
    void setVectorY(const vector<int>& newVectorY);
    int getQueensQuantity();
    void setQueensQuantity(int x);
    void placeQueen(int x, int y);

private:
    int size;
    int queensQuantity;
    vector<int> posX; // Vetor para armazenar as posições X das rainhas
    vector<int> posY; // Vetor para armazenar as posições Y das rainhas
    void moveQueen(int queenIndex, int newPositionX, int newPositionY);
};

#endif // BOARD_H
