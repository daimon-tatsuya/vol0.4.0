#include "all.h"

extern int nextScene;

static int over_timer = 0;//scene_over.cpp‚ÅŽg‚¤

void over_init()
{
    for (int i = 0; i < 2; i++)
    {
        over[i].init();
    }
    
}
void over_update()
{
    over_timer++;
    for (int i = 0; i < 2; i++)
    {
        over[i].update();
    }
  
    if ((TRG(0) & PAD_TRG2 ) || over_timer >= 1200)
    {
        if (twoPlayMode)
        {
            nextScene = SCENE_TITLE;
        }
        else
        {
            nextScene = SCENE_RANKING;
        }        

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



