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

};

EXTERN RandoManager RandoManager_;