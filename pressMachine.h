#pragma once

#include "all.h"

class PressMachine : public OBJ2D
{
public:

    void init();
    void update();
    void draw();
};

EXTERN PressMachine press_machine;