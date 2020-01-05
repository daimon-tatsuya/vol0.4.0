#include "all.h"

void Timer::move(OBJ2D* obj)
{
    timerMove(obj);
}

void TimerErase::erase(OBJ2D* obj)
{    
    obj->mvAlg = nullptr;
}
