#include "breadth_first.h"
#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

using namespace std;

sem_t semaphore;

void first_breadth() {
    Board board;
    pthread_t new_thread[8];

    sem_init(&semaphore, 0, 1);

    for (int i = 0; i < 8; i++)
    {
        board.placeQueen(0, i, 0);

        pthread_create(&new_thread[i], NULL, breath_first, &board);

        sem_wait(&semaphore);
        cout << i << " " << board.getQueensQuantity() << endl;
        board.printBoard();
        cout << endl;
        sem_post(&semaphore);
    }
    
    for (int i = 0; i < 8; i++)
    {
        pthread_join(new_thread[i], NULL);   
    }

    
    sem_wait(&semaphore);
    cout << "return" << endl;
    sem_post(&semaphore);

    sem_destroy(&semaphore);
    return;
}

void* breath_first(void* arg) {
    
    // Board* board = static_cast<Board*>(arg);
    // int queenQuantity;

    // queenQuantity = board->getQueensQuantity();
    
    // if (queenQuantity >= 8)
    // {
    //     sem_wait(&semaphore);
    //     board->printBoard();
    //     cout << endl;
    //     sem_post(&semaphore);
    //     return NULL;
    // }
    
    // Board newBoard[8];
    
    // for (int i = 0; i < 8; i++)
    // {
    //     newBoard->copyBoard(*board);
    //     newBoard[i].placeQueen(queenQuantity, i, queenQuantity);
    //     // if (newBoard->calculateCost() > 0)
    //     // {
    //     sem_wait(&semaphore);
    //     cout << newBoard[i].calculateCost() << endl;
    //     board->printBoard();
    //     cout << endl;
    //     sem_post(&semaphore);
    //     return NULL;
    //     // }   
    // }

    return NULL;
}