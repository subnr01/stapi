#ifndef SPINLOCK_H
#define SPINLOCK_H

#include "pthread.h"

class SpinLock
{
protected:
    pthread_spinlock_t spinlock;
public:
    SpinLock(void);
    ~SpinLock(void);

    void TryLock(void) throw(int&);
    void Lock(void);
    void Unlock(void) throw(int&);
};

#endif//SPINLOCK_H
