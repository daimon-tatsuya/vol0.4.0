#pragma once

class DustBox : public MoveAlg
{
public:
    void move(OBJ2D*);
};

EXTERN DustBox dustBox;

class DustBoxErase : public EraseAlg
{
public:
    void erase(OBJ2D*);
};

EXTERN DustBoxErase dustBoxErase;

class DustBoxManager : public OBJ2DManager
{

};

EXTERN DustBoxManager DustBoxManager_;