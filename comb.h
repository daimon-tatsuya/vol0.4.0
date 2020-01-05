#pragma once
#include "all.h"

class Comb : public UI
{
    void move(OBJ2D*);
};

EXTERN Comb comb;

class CombErase : EraseAlg
{
public:
    void  erase(OBJ2D*);
};

EXTERN CombErase combErase;

class CombManager : public OBJ2DManager
{

};

EXTERN CombManager CombManager_;
