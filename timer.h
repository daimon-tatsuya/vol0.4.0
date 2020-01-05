#pragma once
#include "all.h"

class Timer : public UI
{
public:

    void move(OBJ2D*);
};

EXTERN Timer timer;

class TimerErase : public EraseAlg
{
public:
    void erase(OBJ2D*);
};

EXTERN TimerErase timerErase;

class TimerManager : public OBJ2DManager
{

};

EXTERN TimerManager TimerManager_;