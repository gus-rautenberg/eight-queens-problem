#include "breadth_first.h"
#include <iostream>
#include <pthread.h>
#include <semaphore.h>

using namespace std;



void first_breadth() {
    Board board;

    pthread_t new_thread;
    int result = pthread_create(&new_thread, NULL, breath_first, &board);
    pthread_join(new_thread, NULL);
}

void* breath_first(void* arg) {
    
    Board* board = static_cast<Board*>(arg);

    cout << "1" << endl;
    return NULL;
}