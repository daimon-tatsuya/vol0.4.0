#pragma once

class Tutorial : public OBJ2D
{
public:
    int mode = 0;   
    bool nextFlag = false;

    void init();
    void update();
    void draw();
};

EXTERN Tutorial tutorial;