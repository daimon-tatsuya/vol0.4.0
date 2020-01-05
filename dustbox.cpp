#include "all.h"


void DustBox::move(OBJ2D* obj)
{
    switch (obj->state)
    {
    case 0:

        obj->data = &sprDustBox;
        obj->color = VECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
        break;
    }
}

void DustBoxErase::erase(OBJ2D* obj)
{
    obj->mvAlg = nullptr;
}