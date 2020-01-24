#pragma once

#include "all.h"

class PressMachine : public OBJ2D
{
public:
    float atariSize = 0;

    float atari = 0;

    bool shakeFlag = false;

    void init();
    void update();
    void draw();
};

EXTERN PressMachine press_machine;