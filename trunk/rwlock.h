#ifndef RWLOCK_H
#define RWLOCK_H

#include "pthread.h"

class RWLock
{
    protected:
        pthread_rwlock_t rwlock;
    public:
        RWLock(void);
        ~RWLock(void);

        void TryReadLock(void) throw(int&);
        void ReadLock(void);
        void TryWriteLock(void) throw(int&);
        void WriteLock(void);
        void Unlock(void) throw(int&);
};

#endif//RWLOCK_H
