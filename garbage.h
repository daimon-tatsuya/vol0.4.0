#pragma once
#include <list>
#define GARBAGE_INIT     (0)   
#define GARBAGE_DROP     (1)
#define GARBAGE_MOVE     (2)
#define GARBAGE_DELETE   (3)
class Garbage : public MoveAlg
{
public:    
    void move(OBJ2D* obj);
    void lifted(OBJ2D* obj, int playerType);//持ち上げるた時のゴミの動き
    void thrown(OBJ2D* obj, int playerType);//投げた時のゴミの動き

};
static int groundPosYKeep_Garbage=0;
//static int liftedCount = 0;//持ち上げた数
EXTERN Garbage garbage;

class GarbageErase : public EraseAlg
{
public:
    void erase(OBJ2D* obj);
};

EXTERN GarbageErase garbageErase;

class GarbageManager : public OBJ2DManager
{
public:
    
    OBJ2D* add(MoveAlg* mvAlg, const VECTOR2& pos, int type); // objListに新たなOBJ2Dを追加する

};

EXTERN GarbageManager GarbageManager_;

