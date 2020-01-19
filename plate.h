#pragma once

class Plate : public MoveAlg
{
public:
    void move(OBJ2D* obj);
};

EXTERN Plate plate;

class PlateErase : public EraseAlg
{
public:
    void erase(OBJ2D* obj);
};

EXTERN PlateErase plateErase;

class PlateManager : public OBJ2DManager
{

};

EXTERN PlateManager PlateManager_;
