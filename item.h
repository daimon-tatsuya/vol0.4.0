#pragma once

void itemMove1(OBJ2D* obj);
void itemMove2(OBJ2D* obj);
void itemMove3(OBJ2D* obj);
void itemMove4(OBJ2D* obj);

class Item : public MoveAlg
{
public:
    void move(OBJ2D*);
};

EXTERN Item item;

class ItemErase : public EraseAlg
{
public:
    void erase(OBJ2D* obj);
};

EXTERN ItemErase itemErase;

class ItemManager : public OBJ2DManager
{
public:
    OBJ2D* add(MoveAlg* mvAlg, const VECTOR2& pos, int type); // objList�ɐV����OBJ2D��ǉ�����
};

EXTERN ItemManager ItemManager_;