#include "all.h"

void DustBox::init()
{
    data = &sprDustBox;
    position = VECTOR2(400, 84);

    if (no >= 263)
    {
        position.x += no;
    }

    
}

void DustBox::update()
{

}

void DustBox::draw()
{
    if (data)
    {
        data->draw(position);
    }
}