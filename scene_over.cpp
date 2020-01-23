#include "all.h"
static int a = 0;

void over_init()
{
    for (int i = 0; i < 2; i++)
    {
        over[i].init();
    }
    
}
void over_update()
{
    for (int i = 0; i < 2; i++)
    {
        over[i].update();
    }

}
void over_draw()
{
    for (int i = 0; i < 2; i++)
    {
        over[i].draw();
    }

}
void over_end()
{
    for (int i = 0; i < 2; i++)
    {
        player[i].mvAlg = nullptr;
    }

    int i;
    for (i = 0; i < MUSIC_FILE_MAX; i++)
    {
        music::stop(i);
    }
}
//win,lose
void OVER::init()
{
    position = { 0, 0};
    scale    = { 1.0f,1.0f };
    data = nullptr;
}
void OVER::update()
{

}

void OVER::draw()
{

}



