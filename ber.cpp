#include "all.h"

void Ber::init()
{
    data = &sprBer;

    position = VECTOR2(0, 0);
}

void Ber::update()
{

}

void Ber::draw()
{
    if (data)
    {
        data->draw(position);
    }
}