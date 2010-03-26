#ifndef RUNNABLE_H
#define RUNNABLE_H

class Runnable
{
    public:
        virtual void run(void)=0;
        virtual ~Runnable(void){};
};

#endif//RUNNABLE_H
