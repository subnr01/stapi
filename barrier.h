#ifndef BARRIER_H
#define BARRIER_H

#include "pthread.h"

class Barrier
{
protected:
    pthread_barrier_t barrier;
public:
    Barrier(unsigned int count);
    ~Barrier(void);

    void Wait(void);
};

#endif//BARRIER_H
