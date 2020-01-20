#pragma once

class Fukidasi : public MoveAlg
{
public:
    void move(OBJ2D* obj);    
};

//static int liftedCount = 0;//持ち上げた数
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

    OBJ2D* add(MoveAlg* mvAlg, const VECTOR2& pos, int type); // objListに新たなOBJ2Dを追加する                                                              
};

EXTERN FukidasiManager FukidasiManager_;
