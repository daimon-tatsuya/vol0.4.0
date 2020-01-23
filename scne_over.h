#pragma once

extern void over_init();
extern void over_update();
extern void over_draw();
extern void over_end();
class  OVER :public OBJ2D
{
public:
    void init();
    void update();
    void draw();
};
EXTERN OVER over[6];




