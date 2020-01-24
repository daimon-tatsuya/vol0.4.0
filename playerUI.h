#pragma once

class PlayerUI : public UI
{
public:   
    void move(OBJ2D*);
};

EXTERN PlayerUI playerUI;

class PlayerUIErase : public EraseAlg
{
public:
    void  erase(OBJ2D*);
};

EXTERN PlayerUIErase playerUIErase;

class PlayerUIManager : public OBJ2DManager
{
public:
    OBJ2D* add(MoveAlg* mvAlg, const VECTOR2& pos, int type); // objList�ɐV����OBJ2D��ǉ�����
};

EXTERN PlayerUIManager PlayerUIManager_;