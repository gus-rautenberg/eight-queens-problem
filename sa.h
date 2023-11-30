#ifndef SA_H
#define SA_H

using namespace std;

class Sa{
public:
    Sa(double initialTemperature, double coolingRate);
    void mainSaFullRandom(Board board, Board auxBoard);
    void mainSaOptimized(Board board, Board auxBoard);
    void drawNeighbor(Board& auxBoard);
    void swapBoard(Board& auxBoard, int neighborX,int  newNeighborX, int newNeighborY);

    int temperature;
    double cooling;
private:
};

#endif 
