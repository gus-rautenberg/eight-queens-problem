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
    // cout << "Apos sair da troca no Draw" << endl;
    // auxBoard.printBoard();
}


void Sa::mainSaFullRandom(Board board, Board auxBoard){
    double delta;
    board.initialRandomBoard();
    Board best;
    best.copyBoard(board);
    double t = temperature;
    //auxBoard.printBoard();
    int boardCost = board.calculateCost();
    int testBoardCost, testBestCost;
    
    //cout << "Custo inicial do board: "<< boardCost << endl;
    while(t > 0){

        cout << "temperatura: " << t << endl;
        t *= cooling;
    //    cout << "Aux" << endl;
        auxBoard.copyBoard(board);
    //    cout << "Pos copia" << endl;
    //    cout <<"Custo board : " << board.calculateCost() << endl;
    //    cout <<"Custo aux : " << auxBoard.calculateCost() << endl;
    //    auxBoard.printBoard();
        drawNeighbor(auxBoard);
    //    cout << "Pos drawNeighbor" << endl;
    //    cout <<"Custo board : " << board.calculateCost() << endl;
    //   cout <<"Custo aux : " << auxBoard.calculateCost() << endl;
    //    auxBoard.printBoard();
        delta = auxBoard.calculateCost() - board.calculateCost();
    //    cout << "delta: " << delta << endl;
        if(delta < 0){
    //        cout << "Entrou no if delta < 0" << endl;
            board.copyBoard(auxBoard);
            boardCost = board.calculateCost();
    //        cout <<"Custo board : " << boardCost<< endl;
    //        cout <<"Custo aux : " << auxBoard.calculateCost() << endl;
        }
        else{
            double prob = exp(-delta/t);
            if (random() /double(RAND_MAX) < prob){
    //            cout << "Entrou no random/double(rand_max)/prob" << endl;
                //auxBoard.copyBoard(board);
                board.copyBoard(auxBoard);
                boardCost = board.calculateCost();
    //            cout <<"Custo board : " << boardCost << endl;
    //            cout <<"Custo aux : " << auxBoard.calculateCost() << endl;
            }
        }
        // cout << "antes best" << endl;
        testBoardCost = board.calculateCost();
        testBestCost = best.calculateCost();
        //cout << testBoardCost << endl;
        //cout << testBestCost << endl;
        if(testBoardCost < testBestCost){
            best.copyBoard(board);
        }
        // cout << "depois best" << endl;

        if(board.calculateCost() == 0){
    //        cout << "Achou o tal do Zero" << endl;
    //       cout << "Board principal :" << endl
    //       cout << "Board auxiliar :" << endl;
    //       auxBoard.printBoard();

            break;
        }
    }
    best.printBoard();
    best.printPos();
    cout << best.calculateCost() << endl;
}

void Sa::mainSaOptimized(Board board, Board auxBoard){
    
    double delta;
    board.initialRandomBoardOptimized();
    board.printBoard();
    auxBoard.initialRandomBoardOptimized();
    Board best = board;
    best.copyBoard(board);
    int boardCost = board.calculateCost();
    int testBoardCost, testBestCost;
    double t = temperature;
    cout << "Custo inicial do board: "<< boardCost << endl;
    while(t > 0){
        cout << "temperatura: " << t << endl;
        t *= cooling;
    //    cout << "Aux" << endl;
        auxBoard.copyBoard(board);
    //    cout << "Pos copia" << endl;
    //    cout <<"Custo board : " << board.calculateCost() << endl;
    //    cout <<"Custo aux : " << auxBoard.calculateCost() << endl;
    //    auxBoard.printBoard();
        drawNeighbor(auxBoard);
    //    cout << "Pos drawNeighbor" << endl;
    //    cout <<"Custo board : " << board.calculateCost() << endl;
    //    cout <<"Custo aux : " << auxBoard.calculateCost() << endl;
        delta = auxBoard.calculateCost() - board.calculateCost();
    //    cout << "delta: " << delta << endl;
        if(delta < 0){
    //        cout << "Entrou no if delta < 0" << endl;
            board.copyBoard(auxBoard);
            boardCost = board.calculateCost();
    //        cout <<"Custo board : " << boardCost<< endl;
    //        cout <<"Custo aux : " << auxBoard.calculateCost() << endl;
        }
        else{
            double prob = exp(-delta/t);
            if (random() /double(RAND_MAX) < prob){
    //            cout << "Entrou no random/double(rand_max)/prob" << endl;
                //auxBoard.copyBoard(board);
                board.copyBoard(auxBoard);
                boardCost = board.calculateCost();
    //            cout <<"Custo board : " << boardCost << endl;
    //            cout <<"Custo aux : " << auxBoard.calculateCost() << endl;
            }
        }
        // cout << "antes best" << endl;
        testBoardCost = board.calculateCost();
        testBestCost = best.calculateCost();
        //cout << testBoardCost << endl;
        //cout << testBestCost << endl;
        if(testBoardCost < testBestCost){
            best.copyBoard(board);
        }
        // cout << "depois best" << endl;
       
       
        if(board.calculateCost() == 0){
    //        cout << "Achou o tal do Zero" << endl;
    //       cout << "Board principal :" << endl;
    //       board.printBoard();
    //       cout << "Board auxiliar :" << endl;
    //       auxBoard.printBoard();

            break;
        }
    }

    best.printBoard();
    best.printPos();
    cout << best.calculateCost() << endl;


}

