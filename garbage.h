#pragma once
#include <list>
#define GARBAGE_INIT     (0)   
#define GARBAGE_MOVE     (1)
class Garbage : public MoveAlg
{
public:   
    void move(OBJ2D* obj);

    //void init();
    //void update();
    //void draw(); 
    void lifted(OBJ2D* obj);//持ち上げるた時のゴミの動き
    void thrown(OBJ2D* obj);//投げた時のゴミの動き

};

EXTERN Garbage garbage;

class GarbageErase : public EraseAlg
{
public:
    void erase(OBJ2D* obj);
};

EXTERN GarbageErase garbageErase;

class GarbageManager : public OBJ2DManager
{



};

EXTERN GarbageManager GarbageManager_;

extern int count;