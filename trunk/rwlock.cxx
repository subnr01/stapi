#include "rwlock.h"

RWLock::RWLock(void)
{
    pthread_rwlock_init(&rwlock, NULL);
}

RWLock::~RWLock(void)
{
    pthread_rwlock_destroy(&rwlock);
}

void RWLock::TryReadLock(void) throw(int&)
{
    int code = pthread_rwlock_tryrdlock(&rwlock);
    if (0 != code)
    {
        throw code;
    }
}

void RWLock::ReadLock(void)
{
    pthread_rwlock_rdlock(&rwlock);
}

void RWLock::TryWriteLock(void) throw(int&)
{
    int code = pthread_rwlock_trywrlock(&rwlock);
    if (0 != code)
    {
        throw code;
    }
}

void RWLock::WriteLock(void)
{
    pthread_rwlock_wrlock(&rwlock);
}

void RWLock::Unlock(void) throw(int&)
{
    int code = pthread_rwlock_unlock(&rwlock);
    if (0 != code)
    {
        throw code;
    }
}

