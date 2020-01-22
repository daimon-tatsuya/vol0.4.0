#include "all.h"

extern int nextScene;

static int a = 0;

void over_init()
{

}
void over_update()
{
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
    }

}
void over_draw()
{
    a += 1;
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

