#pragma once
#define GARBAGE_INIT     (0)   
#define GARBAGE_MOVE     (1)
class Garbage : public OBJ2D
{
public:
    bool caughtFlg;    //true‚Ì‚¿ã‚°‚ç‚ê‚Ä‚é
    VECTOR2 initVelocity;//‰‘¬“x

    void init();
    void update();
    void draw();
};

