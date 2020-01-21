#include "all.h"
static int a = 0;

void over_init()
{

}
void over_update()
{
    a = 10;
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

