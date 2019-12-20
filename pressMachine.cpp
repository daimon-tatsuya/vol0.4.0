#include "all.h"

using namespace GameLib;
using namespace system;

void PressMachine::init()
{
    data = &sprPressMachine;

    position = VECTOR2(108, 610);

    timer = 0;

    size = VECTOR2(105, 94);
}

void PressMachine::update()
{
    if (position.y >= 610) { speed.y = -5; }

    else if (position.y <= 370) { speed.y = 5; }

    position.y += speed.y;

    if (rectHitCheck(VECTOR2(position.x - size.x, position.y - (size.y * 2)), size.x, size.y / 2, VECTOR2(garbage.position.x - garbage.size.x, garbage.position.y - (garbage.size.y * 2)), garbage.size.x, garbage.size.y) && garbage.exist)
    {
        garbage.exist = false;

        shakeFlag = true;
    }

    if (shakeFlag) //”j‰ó‚µ‚½‚Æ‚«‚Ì‹““®
    {
        speed.y = 12.8f;

        timer++;

        if (timer >= 5)
        {
            shakeFlag = false;
            timer = 0;
        }
    }
}

void PressMachine::draw()
{
    if (data) { data->draw(position); }
}
