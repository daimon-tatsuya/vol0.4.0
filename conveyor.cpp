#include "all.h"

using namespace GameLib;
using namespace system;

void Conveyor::init()
{
    animeData = animeConveyor;
    color = VECTOR4(0.8f, 0.3f, 0, 1);
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