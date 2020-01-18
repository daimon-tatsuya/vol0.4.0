#pragma once

class Effect : public MoveAlg
{
public:
    void move(OBJ2D* obj);
};

EXTERN Effect effect;

class EffectErase : public EraseAlg
{
public:
    void erase(OBJ2D* obj);
};

EXTERN EffectErase effectErase;

class EffectManager : public OBJ2DManager
{
public:

    OBJ2D* add(MoveAlg* mvAlg, const VECTOR2& pos, int type, int no); // objListに新たなOBJ2Dを追加する                                                              
};

EXTERN EffectManager EffectManager_;
