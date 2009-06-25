#include "condition.h"

Condition::Condition(void)
{
    pthread_cond_init(&condition, NULL);
}

Condition::~Condition(void)
{
    pthread_cond_destroy(&condition);
}

void Condition::Wait(void)
{
    pthread_cond_wait(&condition, &mutex);
}

void Condition::Signal(void)
{
    pthread_cond_signal(&condition);
}

void Condition::Broadcast(void)
{
    pthread_cond_broadcast(&condition);
}

