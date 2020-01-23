#include "all.h"

extern int nextScene;

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
<<<<<<< HEAD
    for (int i = 0; i < 2; i++)
    {
        over[i].update();
=======
    a = 10;

    if (TRG(0) & PAD_TRG2) 
    {
        if (twoPlayMode)
        {
            nextScene = SCENE_TITLE;
        }
        else
        {
            nextScene = SCENE_RANKING;
        }        
>>>>>>> 8866147c1d8a8bcefd66c4e5b08f0f55f62e53de
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



