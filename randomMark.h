#pragma once

class RandomMark : public UI
{
public:
    void move(OBJ2D*);
};

EXTERN RandomMark randomMark;

class RandoMErase : public EraseAlg
{
public:
    void erase(OBJ2D*);
};

EXTERN RandoMErase randoMErase;

class RandoManager : public OBJ2DManager
{
public:
    enum RandoMark
    {
        TIMER_MAX1,
        TIMER_MAX2,
    };
};

EXTERN RandoManager RandoManager_;