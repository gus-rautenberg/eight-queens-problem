#ifndef BREADTH_FIRST_H
#define BREADTH_FIRST_H

#include "board.h" 
#include <pthread.h>
#include <semaphore.h>

using namespace std;

void first_breadth();
void *breath_first(void* arg);

#endif