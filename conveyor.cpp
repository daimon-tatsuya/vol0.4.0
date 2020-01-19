#include "all.h"

using namespace GameLib;
using namespace system;

void Conveyor::init()
{
    animeData = animeConveyor[0];
    color = VECTOR4(1.0f, 1.0f, 1.0f, 1);
    position = VECTOR2(0, 0);
    scale = VECTOR2(1, 1);
}

void Conveyor::update()
{
    if (animeData)
    {
        animeUpdate(animeData);
    }
}

void Conveyor::draw()
{
    if (data)
    {
        data->draw(position, scale, angle, color);
    }
}