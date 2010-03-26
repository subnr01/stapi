#include "threadpool.h"

void * ThreadPool::EntryPoint(void * arg)
{
    Runnable * runnable = (Runnable *) arg;
    runnable->run();
    delete runnable;
}

ThreadPool::ThreadPool(void)
    : error(0)
{
}

pthread_t ThreadPool::spawn(Runnable * runnable) throw(int&)
{
    pthread_t threadId;
    error = pthread_create(&threadId, NULL, ThreadPool::EntryPoint, runnable);
    if (0 != error) throw error;
    return threadId;
}
