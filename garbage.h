#pragma once
#define GARBAGE_INIT     (0)   
#define GARBAGE_MOVE     (1)
class Garbage : public OBJ2D
{
public:
    bool caughtFlg;    //trueの時持ち上げられてる
    VECTOR2 initVelocity;//初速度

    void init();
    void update();
    void draw();
};

extern Garbage garbage;
