#pragma once
#include "all.h"

enum COMB
{
    COMB_ANIME,
};


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
public:
    OBJ2D* add(MoveAlg* mvAlg, const VECTOR2& pos, int type); // objListÇ…êVÇΩÇ»OBJ2DÇí«â¡Ç∑ÇÈ
};

EXTERN CombManager CombManager_;
