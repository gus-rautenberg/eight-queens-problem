#include "breadth_first.h"
#include <iostream>
#include <queue>
#include <vector>
#include "board.h"
#include <time.h>
#include <fstream>

using namespace std;

void breath_first() {
    queue<Board> q;
    Board board;
    fstream out;

    q.push(board);

    out.open("BF.json", ios::out);
    board.writeOnFile(out);

    int col;
    while(!q.empty()) {
        Board current = q.front();
        q.pop();

        current.addQueen();
        int col = current.getQueensQuantity() -1;
        for (int i = 0; i < 8; i++) {
            current.moveQueen(col, i, col);

            out << ",";
            current.writeOnFile(out);
        
            if(current.isAttacking(col) == 0) {
                Board newBoard = current;
                q.push(newBoard);
            }
        }
    }
    out.close();
}

float breath_first_Time_First_Solution() {
    queue<Board> q;
    Board board;
    time_t start, finish;

    q.push(board);

    int col = 0, flag = 0;
    start = clock();
    while(!q.empty()) {
        Board current = q.front();
        q.pop();

        // current.printBoard();
        // cout << "Before moving" << endl << endl;

        current.addQueen();
        int col = current.getQueensQuantity() -1;
        for (int i=0; i < 8; i++) {
            current.moveQueen(col, i, col);

            // current.printBoard();
            // cout << "After moving to " << i << " " << col << endl << endl;
        
            if(current.isAttacking(col) == 0) {
                
                Board newBoard = current;
                // newBoard.printBoard();
                if (current.getQueensQuantity() == 8)
                {
                    finish = clock();
                    return((float)(((finish - start) + 0.0) / CLOCKS_PER_SEC));
                }
                // newBoard.printPos();
                // cout << "First" << endl << endl;
                q.push(newBoard);
            }
        }
    }

    return (0);
}

float breath_first_Time_All_Solutions() {
    queue<Board> q;
    Board board;
    time_t start, finish;

    q.push(board);

    int col = 0;    
    start = clock();
    while(!q.empty()) {
        Board current = q.front();
        q.pop();

        // current.printBoard();
        // cout << "Before moving" << endl << endl;

        current.addQueen();
        int col = current.getQueensQuantity() -1;
        for (int i=0; i < 8; i++) {
            current.moveQueen(col, i, col);

            // current.printBoard();
            // cout << "After moving to " << i << " " << col << endl << endl;
        
            if(current.isAttacking(col) == 0) {
                Board newBoard = current;
                // newBoard.printBoard();
                // newBoard.printPos();
                // cout << "All" << endl << endl;
                q.push(newBoard);
            }
        }
    }
    finish = clock();
    
    return((float)(((finish - start) + 0.0) / CLOCKS_PER_SEC));
}