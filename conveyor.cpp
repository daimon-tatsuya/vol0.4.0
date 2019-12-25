#include "all.h"

using namespace GameLib;
using namespace system;

void Conveyor::init()
{
    data = &sprConveyor;

    position = VECTOR2(0, 0);
}

void Conveyor::update()
{

}

void Conveyor::draw()
{
    if (data)
    {
        data->draw(position);
    }
}