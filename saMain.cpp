#include <iostream>
#include <random>
#include <algorithm>
#include <cmath>
#include "board.h"
#include "sa.h"
#include <fstream>
using namespace std;



// arquivo para testes
// g++ -o sa saMain.cpp board.cpp sa.cpp

int main(){
time_t start, finish;
float count;
fstream out;

srand((unsigned int)time(nullptr));
random_device rd;
mt19937 g(rd());
 Sa sa;
 Board board, auxBoard;
 start = clock();
 sa.mainSa(board, auxBoard, sa.temperature);
 finish = clock();
 count = ((float)(((finish - start) + 0.0) / CLOCKS_PER_SEC));

// abrindo arquivo
    out.open("sa.out", ios::app);
    out << count << endl;



    return 0;
}
