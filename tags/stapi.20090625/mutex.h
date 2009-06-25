#ifndef MUTEX_H
#define MUTEX_H

#include "pthread.h"

class Mutex
{
protected:
    pthread_mutex_t mutex;
public:
    Mutex(void);
    ~Mutex(void);

    void TryLock(void) throw(int&);
    void Lock(void);
    void Unlock(void) throw(int&);
};

#endif//MUTEX_H
