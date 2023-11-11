#include <iostream>
#include <random>
#include <algorithm>
#include <cmath>
#include "board.h"
#include "sa.h"
using namespace std;

// arquivo para testes
// g++ -o sa saMain.cpp board.cpp sa.cpp

int main(int argc, char *argv[]){
srand((unsigned int)time(nullptr));
random_device rd;
mt19937 g(rd());

double initialTemperature = 4000; // Valor padrão
double coolingRate = 0.99; // Valor padrão

// Verificar se foram fornecidos argumentos extras
if (argc >= 3) {
    // Converter os argumentos para double
    try {
        initialTemperature = stod(argv[1]);
        coolingRate = stod(argv[2]);
    } catch (const invalid_argument& e) {
        cerr << "Erro ao converter argumentos para double." << endl;
        return 1;
    }
}

Sa sa(initialTemperature, coolingRate);
Board board, auxBoard;
sa.mainSa(board, auxBoard, sa.temperature);
cout << initialTemperature << " " << coolingRate << endl;
sa.getInfo();
    return 0;
}
