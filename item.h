#pragma once

void itemMove1(OBJ2D* obj);
void itemMove2(OBJ2D* obj);
void itemMove3(OBJ2D* obj);
void itemMove4(OBJ2D* obj);

#define ITEM_INIT     (0)   
#define ITEM_DROP     (1)
#define ITEM_MOVE     (2)
#define ITEM_DELETE   (3)

class Item : public MoveAlg
{
public:
    
    void move(OBJ2D*);
};

static int groundPosYKeep_Item;

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
    OBJ2D* add(MoveAlg* mvAlg, const VECTOR2& pos, int type); // objListÇ…êVÇΩÇ»OBJ2DÇí«â¡Ç∑ÇÈ
};

EXTERN ItemManager ItemManager_;