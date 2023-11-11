#include <iostream>
#include <random>
#include <algorithm>
#include <cmath>
#include "board.h"
#include "sa.h"
using namespace std;

// arquivo para testes
// g++ -o sa saMain.cpp board.cpp sa.cpp

int main(){
srand((unsigned int)time(nullptr));
random_device rd;
mt19937 g(rd());
 Sa sa;
 Board board, auxBoard;
 sa.mainSa(board, auxBoard, sa.temperature);

    return 0;
}
