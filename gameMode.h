#pragma once

class GameMode :public OBJ2D
{
public:
    void init();
    void update();
    void draw();
};
EXTERN GameMode gamemode[2];