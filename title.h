#pragma once
#include <list>
#define TITLE_INIT     (0)   
#define TITLE_DROP     (1)
#define TITLE_MOVE     (2)
#define TITLE_DELETE   (3)
class Title : public MoveAlg
{
public:
    void move(OBJ2D* obj);
};
static int groundPosYKeep_Title = 0;

EXTERN Title title;

class TitleErase : public EraseAlg
{
public:
    void erase(OBJ2D* obj);
};

EXTERN TitleErase titleErase;

class TitleManager : public OBJ2DManager
{
public:

    OBJ2D* add(MoveAlg* mvAlg, const VECTOR2& pos, int type); // objListÇ…êVÇΩÇ»OBJ2DÇí«â¡Ç∑ÇÈ

};

EXTERN TitleManager titleManager_;