#ifndef CONDITION_H
#define CONDITION_H

#include "mutex.h"

class Condition : public Mutex
{
    protected:
        pthread_cond_t condition;
    public:
        Condition(void);
        ~Condition(void);

        void Wait(void);
        void Signal(void);
        void Broadcast(void);
};

#endif//CONDITION_H
