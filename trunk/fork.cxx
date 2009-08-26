#include "fork.h"

Fork * Fork::instance(NULL);

void Fork::Signal(int sig)
{
    switch (sig)
    {
        case SIGHUP:
            instance->OnHangup();
            break;
        case SIGINT:
            instance->OnInterrupt();
            break;
        case SIGTERM:
            instance->OnTerminate();
            break;
    }
}

void Fork::SignalParent(int sig)
{
    kill(parent, sig);
}

Fork::Fork(void)
    : pid(0), parent(0)
{
    parent = getpid();
}

Fork::~Fork(void)
{
    Kill(pid);
}

void Fork::Start(void) throw(int&)
{
    pid = fork();

    switch (pid)
    {
        case -1: throw errno;
        case 0:
            instance = this;
            sigset(SIGINT, Fork::Signal);
            sigset(SIGHUP, Fork::Signal);
            sigset(SIGTERM, Fork::Signal);
            Execute();
            break;
    }
}

void Fork::Kill(int sig) throw(int&)
{
    if (0 < pid)
    {
        if (-1 == kill(pid, sig))
        {
            throw errno;
        }
    }
}

void Fork::Detach(void)
{
    pid = 0;
}

pid_t Fork::getChildPid(void)
{
    return pid;
}

pid_t Fork::getParentPid(void)
{
    return parent;
}
