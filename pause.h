#pragma once
#pragma once

class Pause :public OBJ2D
{
public:
    void init();
    void update();
    void draw();
};
EXTERN Pause pause[6];
extern int pause_state;
extern int PauseCount ;