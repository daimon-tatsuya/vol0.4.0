#pragma once
#include <list>
#define GARBAGE_INIT     (0)   
#define GARBAGE_DROP     (1)
#define GARBAGE_MOVE     (2)
class Garbage : public MoveAlg
{
public:   
    void move(OBJ2D* obj);

    //void init();
    //void update();
    //void draw(); 
    void lifted(OBJ2D* obj);//‚¿ã‚°‚é‚½‚ÌƒSƒ~‚Ì“®‚«
    void thrown(OBJ2D* obj);//“Š‚°‚½‚ÌƒSƒ~‚Ì“®‚«

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
public:
    OBJ2D* add(MoveAlg* mvAlg, const VECTOR2& pos, int type); // objList‚ÉV‚½‚ÈOBJ2D‚ğ’Ç‰Á‚·‚é
};

EXTERN GarbageManager GarbageManager_;

extern int count;