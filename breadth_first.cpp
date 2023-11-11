#include "breadth_first.h"
#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

using namespace std;

sem_t semaphore;

void first_breadth() {
    Board board[8];
    pthread_t new_thread[8];

    sem_init(&semaphore, 0, 1);

    for (int i = 0; i < 8; i++)
    {
        board[i].initialRandomBoard();
        pthread_create(&new_thread[i], NULL, breath_first, &board[i]);
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
    
    Board* board = static_cast<Board*>(arg);
    
    if ()
    {
        /* code */
    }
    

    for (int i = 0; i < 8; i++)
    {
        
    }
    
    sem_wait(&semaphore);
    board->printBoard();
    cout << endl;
    sem_post(&semaphore);
    return NULL;
}