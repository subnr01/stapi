#ifndef THREADPOOL_H
#define THREADPOOL_H

#include "signal.h"
#include "pthread.h"
#include "runnable.h"

class ThreadPool
{
    private:
        int error;
        static void * EntryPoint(void * arg);
    public:
        ThreadPool(void);
        pthread_t spawn(Runnable * runnable) throw(int&);
};

#endif//THREADPOOL_H
