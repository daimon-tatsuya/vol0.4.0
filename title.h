#pragma once
#include <list>

    
#define TITLE_DROP     (0)
#define TITLE_MOVE     (1)
#define TITLE_DELETE   (2)
class Title : public OBJ2D
{
public:
    void init();
    void update();
    void draw();
   // int timer;
};
extern bool titleDropFlg;
extern bool titleScaleDownFlg;

static int groundPosYKeep_Title = 0;

EXTERN Title title;





