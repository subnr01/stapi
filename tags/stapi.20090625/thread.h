#ifndef THREAD_H
#define THREAD_H

#include "signal.h"
#include "pthread.h"

class Thread
{
private:
    int error;
    static void * EntryPoint(void * arg);
protected:
    bool Terminated;
    pthread_t threadId;

    virtual void Execute(void)=0;
public:
    Thread(void);
    ~Thread(void);

    void Start(void) throw(int&);
    void Detach(void) throw(int&);
    void Join(void) throw(int&);
    void Cancel(void) throw(int&);
    void Kill(int sig = SIGKILL) throw(int&);
    void Terminate(void);
    bool IsRunning(void);
};

#endif//THREAD_H
