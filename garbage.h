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
    void lifted(OBJ2D* obj, int playerType);//�����グ�邽���̃S�~�̓���
    void thrown(OBJ2D* obj, int playerType);//���������̃S�~�̓���

};
static int groundPosYKeep_Garbage=0;
//static int liftedCount = 0;//�����グ����
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
    
    OBJ2D* add(MoveAlg* mvAlg, const VECTOR2& pos, int type); // objList�ɐV����OBJ2D��ǉ�����

};

EXTERN GarbageManager GarbageManager_;

