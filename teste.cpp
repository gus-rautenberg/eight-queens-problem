#include <iostream>
#include <fstream>
#include <algorithm>
#include <random>

using namespace std;

int main() {
    const string outputFileName = "output.json";
    int posX[8] = {0, 1, 2, 3, 4, 5, 6, 7};
    int posY[8] = {7, 6, 5, 4, 3, 2, 1, 0};
    // Obtém um gerador de números aleatórios
    random_device rd;
    mt19937 g(rd());
    ofstream outputFile(outputFileName);
    outputFile << "{";
    int total = 100000;
    for (int a = 0; a < total; a++) {
        // Embaralha os arrays
        shuffle(begin(posX), end(posX), g);
        shuffle(begin(posY), end(posY), g);

        if (outputFile.is_open()) {
            outputFile << " \"queens" << a << "\": [";

            for (int i = 0; i < 8; ++i) {
                outputFile << "{ \"x\": " << posX[i] << ", \"y\": " << posY[i] << "}";
                if (i < 7) {
                    outputFile << ",";
                }
            }

            outputFile << "]";
            if(a < total-1){
                outputFile << ", ";
            }
            

            
        } 
    }
    outputFile << "} ";
    outputFile.close();
        
    return 0;
}
