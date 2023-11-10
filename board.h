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

private:
    int size;
    vector<int> board;
};

#endif // BOARD_H
