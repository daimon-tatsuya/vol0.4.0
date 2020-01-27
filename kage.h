#pragma once

class Kage : public MoveAlg
{
public:

    void move(OBJ2D*);
};

EXTERN Kage kage;

class KageErase : public EraseAlg
{
public:

    void erase(OBJ2D*);
};

EXTERN KageErase kageErase;

class KageManager : public OBJ2DManager
{

};

EXTERN KageManager KageManager_;