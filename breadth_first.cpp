#include "breadth_first.h"
#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

using namespace std;

sem_t semaphore;

void first_breadth() {
    Board board[5];
    pthread_t new_thread[5];

    sem_init(&semaphore, 0, 1);

    for (int i = 0; i < 5; i++)
    {
        board[i].initialRandomBoard();
        pthread_create(&new_thread[i], NULL, breath_first, &board[i]);
    }
    
    for (int i = 0; i < 5; i++)
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
    sem_wait(&semaphore);
    board->printBoard();
    sem_post(&semaphore);
    return NULL;
}