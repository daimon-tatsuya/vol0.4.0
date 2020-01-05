#include "all.h "

void Comb::move(OBJ2D* obj)
{
    combMove(obj);
}

void CombErase::erase(OBJ2D* obj)
{
    obj->mvAlg = nullptr;
}