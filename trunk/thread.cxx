#include "thread.h"
#include "signal.h"

void * Thread::EntryPoint(void * instance)
{
    Thread * thread = (Thread *) instance;
    thread->Execute();
    thread->Terminated = true;
}

Thread::Thread(void) : Terminated(false)
{
}

Thread::~Thread(void)
{
    if (!Terminated)
    {
        Cancel();
    }
}

void Thread::Start(void) throw(int&)
{
    error = pthread_create(&threadId, NULL, EntryPoint, this);
    if (0 != error) throw error;
}

void Thread::Join(void) throw(int&)
{
    error = pthread_join(threadId, NULL);
    if (0 != error) throw error;
}

void Thread::Detach(void) throw(int&)
{
    error = pthread_detach(threadId);
    if (0 != error) throw error;
}

void Thread::Cancel(void) throw(int&)
{
    error = pthread_cancel(threadId);
    if (0 != error) throw error;
}

void Thread::Kill(int sig) throw(int&)
{
    error = pthread_kill(threadId, sig);
    if (0 != error) throw error;
}

bool Thread::IsRunning(void)
{
    return !Terminated;
}

void Thread::Terminate(void)
{
    Terminated = true;
}

