#include <iostream>
#include <random>
#include <algorithm>
#include <cmath>
#include "board.h"
#include "sa.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>

using namespace std;
Sa::Sa(){}

void Sa::swapBoard(Board& auxBoard, int neighborX,int  newNeighborX, int neighborY, int newNeighborY){
    vector<int> vectorX = auxBoard.getVectorX();
    vector<int> vectorY = auxBoard.getVectorY();
    // cout << "Antes da troca" << endl;
    // auxBoard.printBoard();

    swap(vectorX[neighborX], vectorX[newNeighborX]);
    swap(vectorY[neighborY], vectorY[newNeighborY]);
    auxBoard.setVectorX(vectorX);
    auxBoard.setVectorY(vectorY);
    // cout << "Depois da troca" << endl;
    // auxBoard.printBoard();
}


void Sa::drawNeighbor(Board& auxBoard){
    vector<int> vectorX = auxBoard.getVectorX();
    vector<int> vectorY = auxBoard.getVectorY();

    int neighborX , neighborY, newNeighborX, newNeighborY;
    while(true){
        neighborX = (int)random() % 8;
        neighborY = (int)random() % 8;
        newNeighborX = (int)random() % 8;
        newNeighborY = (int)random() % 8;
        if(vectorX[neighborX] != vectorX[newNeighborX] && vectorY[neighborY] !=  vectorY[newNeighborY]) break;
    }
   swapBoard(auxBoard, neighborX, newNeighborX, neighborY, newNeighborY);
    // cout << "Apos sair da troca no Draw" << endl;
    // auxBoard.printBoard();
}


void Sa::mainSa(Board board, Board auxBoard, int t){
    double delta;
    board.initialRandomBoard();
    auxBoard.initialRandomBoard();
    int boardCost = board.calculateCost();
    //cout << "Custo inicial do board: "<< boardCost << endl;
    while(t > 0){
        //cout << "temperatura: " << t << endl;
        t *= cooling;
        cout << "Aux" << endl;
        board.copyBoard(auxBoard);
        //cout << "Pos copia" << endl;
        //cout <<"Custo board : " << board.calculateCost() << endl;
        cout <<"Custo aux : " << auxBoard.calculateCost() << endl;
        auxBoard.printBoard();
        drawNeighbor(auxBoard);
        //cout << "Pos drawNeighbor" << endl;
        //cout <<"Custo board : " << board.calculateCost() << endl;
        //cout <<"Custo aux : " << auxBoard.calculateCost() << endl;
        delta = auxBoard.calculateCost() - boardCost;
        //cout << "delta: " << delta << endl;
        if(delta < 0){
            cout << "Entrou no if delta < 0" << endl;
            board.copyBoard(auxBoard);
            boardCost = board.calculateCost();
            cout <<"Custo board : " << boardCost<< endl;
            //cout <<"Custo aux : " << auxBoard.calculateCost() << endl;
        }
        else{
            double prob = exp(-delta/t);
            if (random() /double(RAND_MAX) < prob){
                cout << "Entrou no random/double(rand_max)/prob" << endl;
                auxBoard.copyBoard(board);
                boardCost = board.calculateCost();
                cout <<"Custo board : " << boardCost << endl;
                //cout <<"Custo aux : " << auxBoard.calculateCost() << endl;
            }
        }
       
        if(board.calculateCost() == 0){
        //    cout << "Board principal :" << endl;
           board.printBoard();
        //    cout << "Board auxiliar :" << endl;
        //    auxBoard.printBoard();

            break;
        }
    }
}

