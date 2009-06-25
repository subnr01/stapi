#include "mutex.h"

Mutex::Mutex(void)
{
    pthread_mutex_init(&mutex, NULL);
}

Mutex::~Mutex(void)
{
    pthread_mutex_destroy(&mutex);
}

void Mutex::TryLock(void) throw(int&)
{
    int code = pthread_mutex_trylock(&mutex);
    if (0 != code)
    {
        throw code;
    }
}

void Mutex::Lock(void)
{
    pthread_mutex_lock(&mutex);
}

void Mutex::Unlock(void) throw(int&)
{
    int code = pthread_mutex_unlock(&mutex);
    if (0 != code)
    {
        throw code;
    }
}

