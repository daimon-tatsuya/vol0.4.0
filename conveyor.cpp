#include "all.h"

using namespace GameLib;
using namespace system;

void Conveyor::init()
{
    animeData = animeConveyor;

    position = VECTOR2(0, 0);
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
        data->draw(position);
    }
}