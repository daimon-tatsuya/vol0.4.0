#pragma once
#define GARBAGE_INIT     (0)   
#define GARBAGE_MOVE     (1)
class Garbage : public OBJ2D
{
public:
    bool caughtFlg = false;    //true‚Ì‚¿ã‚°‚ç‚ê‚Ä‚é

    bool throwFlg = false;

    VECTOR2 initVelocity;//‰‘¬“x


    void init();
    void update();
    void draw(); 
    void lifted();//‚¿ã‚°‚é‚½‚ÌƒSƒ~‚Ì“®‚«
    void thrown();//“Š‚°‚½‚ÌƒSƒ~‚Ì“®‚«
  
};

extern Garbage garbage;
