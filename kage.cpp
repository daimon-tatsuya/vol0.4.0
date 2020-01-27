#include "all.h"

void Kage::move(OBJ2D* obj)
{
    switch (obj->state)
    {
    case 0:

        obj->data = &sprKage;
        obj->color = VECTOR4(1, 1, 1, 0.4f);
        obj->size = VECTOR2(32, 32);
        obj->state++;
        break;

    case 1:

        for ( auto& it : *GarbageManager_.getList() )
        {
            if (rectHitCheck(VECTOR2(obj->position.x - obj->size.x, obj->position.y - (obj->size.y * 2)), obj->size.x, obj->size.y,
                VECTOR2(it.position.x - it.size.x, it.position.y - (it.size.y * 2)), it.size.x, it.size.y) && it.position.x == obj->position.x) { obj->eraseAlg = &kageErase; }
        }

        for (auto& it : *ItemManager_.getList())
        {
            if (rectHitCheck(VECTOR2(obj->position.x - obj->size.x, obj->position.y - (obj->size.y * 2)), obj->size.x, obj->size.y,
                VECTOR2(it.position.x - it.size.x, it.position.y - (it.size.y * 2)), it.size.x, it.size.y) && it.position.x == obj->position.x) {
                obj->eraseAlg = &kageErase;
            }
        }

        break;
    }
}

void KageErase::erase(OBJ2D* obj)
{
    obj->mvAlg = nullptr;
}