#include "all.h"

using namespace GameLib;
using namespace system;

void PressMachine::init()
{
    data = &sprPressMachine;

    position = VECTOR2(108, 610);
}

void PressMachine::update()
{
    if (position.y >= 610) { speed.y -= 5; }

    else if (position.y <= 370) { speed.y += 5; }

    position.y += speed.y;
}

void PressMachine::draw()
{
    if (data) { data->draw(position); }
}
