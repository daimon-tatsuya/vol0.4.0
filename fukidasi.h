#pragma once

class Fukidasi : public MoveAlg
{
public:
    void move(OBJ2D* obj);    
};

//static int liftedCount = 0;//�����グ����
EXTERN Fukidasi fukidasi;

class FukidasiErase : public EraseAlg
{
public:
    void erase(OBJ2D* obj);
};

EXTERN FukidasiErase fukidasiErase;

class FukidasiManager : public OBJ2DManager
{
public:

    OBJ2D* add(MoveAlg* mvAlg, const VECTOR2& pos, int type); // objList�ɐV����OBJ2D��ǉ�����                                                              
};

EXTERN FukidasiManager FukidasiManager_;
