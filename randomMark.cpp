#include "all.h"

void RandomMark::move(OBJ2D* obj)
{
    randoMark(obj);
}

void RandoMErase::erase(OBJ2D* obj)
{
    obj->mvAlg = nullptr;
}