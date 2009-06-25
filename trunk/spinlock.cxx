#include "spinlock.h"

SpinLock::SpinLock(void)
{
    pthread_spin_init(&spinlock, NULL);
}

SpinLock::~SpinLock(void)
{
    pthread_spin_destroy(&spinlock);
}

void SpinLock::TryLock(void) throw(int&)
{
    int code = pthread_spin_trylock(&spinlock);
    if (0 != code)
    {
        throw code;
    }
}

void SpinLock::Lock(void)
{
    pthread_spin_lock(&spinlock);
}

void SpinLock::Unlock(void) throw(int&)
{
    int code = pthread_spin_unlock(&spinlock);
    if (0 != code)
    {
        throw code;
    }
}

