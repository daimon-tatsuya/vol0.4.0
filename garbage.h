#pragma once
#define GARBAGE_INIT     (0)   
#define GARBAGE_MOVE     (1)
class Garbage : public OBJ2D
{
public:
    bool caughtFlg  = false;    //trueの時持ち上げられてる
   
    bool throwFlg = false;

    VECTOR2 initVelocity;//初速度

    int state_throw = 0;

    void init();
    void update();
    void draw(); 
    void lifted();//持ち上げるた時のゴミの動き
    void thrown();//投げた時のゴミの動き
  
};

extern Garbage garbage;
