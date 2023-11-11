#ifndef SA_H
#define SA_H

using namespace std;

class Sa{
public:
    Sa();
    void mainSa(Board board, Board auxBoard, int t);
    void drawNeighbor(Board& auxBoard);
    void swapBoard(Board& auxBoard, int neighborX,int  newNeighborX, int neighborY, int newNeighborY);

    // variaveis
    double temperature = 4000;
    double cooling = 0.99;
private:
    
};

#endif // BOARD_H
