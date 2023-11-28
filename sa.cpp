#include <iostream>
#include <random>
#include <algorithm>
#include <cmath>
#include "board.h"
#include "sa.h"
#include <cmath>
#include <cstdlib>
#include <vector>
#include <time.h>
#include <fstream>

using namespace std;
//Sa::Sa(){}
Sa::Sa(double initialTemperature, double coolingRate) : temperature(initialTemperature), cooling(coolingRate) {}


void Sa::swapBoard(Board& auxBoard, int neighborX,int  newNeighborX, int newNeighborY){
    vector<int> vectorX = auxBoard.getVectorX();
    vector<int> vectorY = auxBoard.getVectorY();
    // cout << "Antes da troca" << endl;
    // auxBoard.printBoard();

    vectorX[neighborX] = newNeighborX;
    vectorY[neighborX] = newNeighborY;
    auxBoard.setVectorX(vectorX);
    auxBoard.setVectorY(vectorY);
    // cout << "Depois da troca" << endl;
    // auxBoard.printBoard();
}


void Sa::drawNeighbor(Board& auxBoard){
    vector<int> vectorX = auxBoard.getVectorX();
    vector<int> vectorY = auxBoard.getVectorY();

    int neighbor , newPositionX, newPositionY;
        neighbor = (int)random() % 8;

    do{
        newPositionX = (int)random() % 8;
        newPositionY = (int)random() % 8;
    }while(!auxBoard.isPositionFree(newPositionX, newPositionY));
    swapBoard(auxBoard, neighbor, newPositionX, newPositionY);
}


void Sa::mainSaFullRandom(Board board, Board auxBoard){
    int counter = 1;
    double delta;
    board.initialRandomBoard();
    Board best;
    best.copyBoard(board);
    double t = temperature;
    int boardCost = board.calculateCost();
    int testBoardCost, testBestCost;
    fstream out, time;
    out << "{ ";
    out.open("output.json", ios::out);
    board.writeOnFile(out, counter++);
    for(int k = 0; k < 1000; k++){
        t *= cooling;
        auxBoard.copyBoard(board);
        drawNeighbor(auxBoard);
        out << ", ";
        auxBoard.writeOnFile(out, counter++);
        delta = auxBoard.calculateCost() - board.calculateCost();
        if(delta < 0){
            board.copyBoard(auxBoard);
            boardCost = board.calculateCost();
        }
        else{
            double prob = exp(-delta/t);
            if (random() /double(RAND_MAX) < prob){
                board.copyBoard(auxBoard);
                boardCost = board.calculateCost();
            }
        }
        testBoardCost = board.calculateCost();
        testBestCost = best.calculateCost();
        if(testBoardCost < testBestCost){
            best.copyBoard(board);
        }
        out << ", ";
        board.writeOnFile(out, counter++);
        if(board.calculateCost() == 0){
            break;
        }
    }
    out << "}";
    out.close();
}

void Sa::mainSaOptimized(Board board, Board auxBoard){
    int counter = 1;
    double delta;
    board.initialRandomBoardOptimized();
    board.printBoard();
    auxBoard.initialRandomBoardOptimized();
    Board best = board;
    best.copyBoard(board);
    int boardCost = board.calculateCost();
    int testBoardCost, testBestCost;
    double t = temperature;
    fstream out;
    out << "{ ";
    out.open("output.json", ios::out);
    board.writeOnFile(out, counter++);
    for(int k = 0; k < 1; k++){    
        t *= cooling;
        auxBoard.copyBoard(board);
        drawNeighbor(auxBoard);
        out << ", ";
        auxBoard.writeOnFile(out, counter++);
        delta = auxBoard.calculateCost() - board.calculateCost();
        if(delta < 0){
            board.copyBoard(auxBoard);
            boardCost = board.calculateCost();
        }
        else{
            double prob = exp(-delta/t);
            if (random() /double(RAND_MAX) < prob){
                board.copyBoard(auxBoard);
                boardCost = board.calculateCost();
            }
        }
        testBoardCost = board.calculateCost();
        testBestCost = best.calculateCost();
        if(testBoardCost < testBestCost){
            best.copyBoard(board);
        }
        out << ", ";
        board.writeOnFile(out, counter++);
        if(board.calculateCost() == 0){
            break;
        }
    }
    out << "}";
    out.close();
}

