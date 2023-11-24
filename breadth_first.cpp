#include "breadth_first.h"
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void breath_first() {
    queue<Board> q;
    Board board;

    q.push(board);

    int col = 0;
    while(!q.empty()) {
        Board current = q.front();
        q.pop();

        current.printBoard();
        cout << "Before moving" << endl << endl;

        current.addQueen();
        int col = current.getQueensQuantity() -1;
        for (int i=0; i < 8; i++) {
            current.moveQueen(col, i, col);

            // current.printBoard();
            // cout << "After moving to " << i << " " << col << endl << endl;
        
            if(current.isAttacking(col) == 0) {
                Board newBoard = current;
                newBoard.printBoard();
                newBoard.printPos();
                cout << "New" << endl << endl;
                q.push(newBoard);
            }
        }
    }
}