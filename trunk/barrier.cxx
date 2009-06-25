#include "barrier.h"

Barrier::Barrier(unsigned int count)
{
    pthread_barrier_init(&barrier, NULL, count);
}

Barrier::~Barrier(void)
{
    pthread_barrier_destroy(&barrier);
}

void Barrier::Wait(void)
{
    pthread_barrier_wait(&barrier);
}

