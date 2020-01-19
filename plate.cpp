#include "all.h"

void Plate::move(OBJ2D* obj)
{
    obj->data = &sprPlate1;
    obj->color = VECTOR4(1, 1, 1, 1);
    obj->scale = VECTOR2(1, 1);
}

void PlateErase::erase(OBJ2D* obj)
{
    obj->mvAlg = nullptr;
}