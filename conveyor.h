#pragma once
#include "all.h"

class Conveyor : public OBJ2D
{
public:
    void init();
    void update();
    void draw();
};

EXTERN Conveyor conveyor;