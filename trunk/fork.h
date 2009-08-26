#ifndef FORK_H
#define FORK_H

#include <unistd.h>
#include <signal.h>
#include <errno.h>

class Fork
{
    private:
        pid_t pid;
        pid_t parent;
        static Fork * instance;

        static void Signal(int sig);
    protected:
        void SignalParent(int sig);

        virtual void Execute(void)=0;
        virtual void OnHangup(void) {};
        virtual void OnInterrupt(void) {};
        virtual void OnTerminate(void) {};
    public:
        Fork(void);
        ~Fork(void);

        void Start(void) throw(int&);
        void Kill(int sig = SIGINT) throw(int&);
        void Detach(void);

        pid_t getChildPid(void);
        pid_t getParentPid(void);
};

#endif//FORK_H
