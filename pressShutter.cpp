#include "all.h"
//#include "pressShutter.h"
//#include "sprite_data.h"

//using namespace GameLib;
using namespace system;

void Shutter::init()
{
    data = &sprPressMachine;
    if (type == 0) { position = VECTOR2(0, 0); }
    else if (type == 1) { position = VECTOR2(0, SCREEN_HEIGHT); }
    //position = VECTOR2(0, -SCREEN_HEIGHT);
    scale = { 9.5f, 2 };
    angle = 0;
    color = VECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
}

//void Shutter::update()
//{
//    switch (type)
//    {
//    case 0:
//
//        if(scrollDown())
//        break;
//
//    case 1:
//
//        break;
//    }
//    
//}

bool Shutter::scrollUp()//スクロールしきったらtrueを返す。
{
    position.y -= 10;

    if (position.y < 0)
    {
        position.y = 0;
        type = 0;
        return true;
    }

    return false;
}

bool Shutter::scrollDown()//スクロールしきったらtrueを返す。
{
    position.y += 10;

    if (position.y > SCREEN_HEIGHT)
    {
        position.y = SCREEN_HEIGHT;
        type = 1;
        return true;
    }
    return false;
}

void Shutter::draw()
{
    data->draw(position, scale);
}