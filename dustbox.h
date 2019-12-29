#pragma once
#include "all.h"

class DustBox : public OBJ2D
{
public:
    void init();
    void update();
    void draw();
};

EXTERN DustBox dustBox[3];