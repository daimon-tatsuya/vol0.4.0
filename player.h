#pragma once
//ƒmƒxƒ‹
#define PLAYER_INIT     (0)   
#define PLAYER_MOVE     (1)


class Player : public OBJ2D
{
public:
    void init();
    void update();
    void draw();
};
extern Player player;