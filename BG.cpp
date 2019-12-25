#include "all.h"

using namespace GameLib;
using namespace system;

void Bg::init()
{
    data = &sprBG;
    position = VECTOR2(0, 0);
    scale = VECTOR2(1, 1);
    angle = 0.0f;
    color = VECTOR4(1, 1, 1, 0);
}

void Bg::update()
{

}

void Bg::draw()
{
    if (data)
    {
        data->draw(position);
    }
}