// board.h
#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <fstream>

using namespace std;

class Board {
public:
    Board();
    void printBoard() const;
    void writeOnFile(fstream& out, int i);
    int calculateCost() const;
    void initialRandomBoard();
    void initialRandomBoardOptimized();
    Board(const Board &board);
    void randomMove();
    bool isPositionFree(int x, int y) const;
    vector<int> getVectorX() const;
    vector<int> getVectorY() const;
    int getSize();
    void copyBoard(const Board &source);
    void setVectorX(const vector<int>& newVectorX);
    void setVectorY(const vector<int>& newVectorY);
    int getQueensQuantity();
    void addQueen();
    void placeQueen(int queenIndex, int x, int y);
    int isAttacking(int newestQueen = 8);
    void moveQueen(int queenIndex, int newPositionX, int newPositionY);

    void printPos();

private:
    int size;
    int queensQuantity;
    vector<int> posX; // Vetor para armazenar as posições X das rainhas
    vector<int> posY; // Vetor para armazenar as posições Y das rainhas
};

#endif // BOARD_H
