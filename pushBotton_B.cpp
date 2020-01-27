#include "all.h"

using namespace GameLib;
using namespace system;

void PushBotton_B::init()
{
    data = &sprPush_B;
    position = VECTOR2(SCREEN_WIDTH/2,SCREEN_HEIGHT/2);
    scale = VECTOR2(1, 1);
    angle = 0.0f;
    color = VECTOR4(1, 1, 1, 0);
}

void PushBotton_B::update()
{

}

void PushBotton_B::draw()
{
    if (data)
    {
        data->draw(position);
    }
}