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

int main(int argc, char const *argv[]){

 


time_t start, finish;
float count;
fstream out;

srand((unsigned int)time(nullptr));
random_device rd;
mt19937 g(rd());

 

double initialTemperature = 12; // Valor padrão
double coolingRate = 0.99; // Valor padrão

// Verificar se foram fornecidos argumentos extras
if (argc >= 4) {
    // Converter os argumentos para double
    try {
        initialTemperature = stod(argv[2]);
        coolingRate = stod(argv[3]);
    } catch (const invalid_argument& e) {
        cerr << "Erro ao converter argumentos para double." << endl;
        return 1;
    }
}


Sa sa(initialTemperature, coolingRate);
Board board, auxBoard;

switch(argv[1][0])
{
case 'n':
    start = clock();
    sa.mainSaFullRandom(board, auxBoard);
    finish = clock();
    count = ((float)(((finish - start) + 0.0) / CLOCKS_PER_SEC));
    // abrindo arquivo
    out.open("saFullRandom.out", ios::app);
    
    break;
case 'o':
    start = clock();
    sa.mainSaOptimized(board, auxBoard);
    finish = clock();
    count = ((float)(((finish - start) + 0.0) / CLOCKS_PER_SEC));
    out.open("saOptimized.out", ios::app);
    break;
}

    out << count << endl;
 
    out.close();




    return 0;
}
