#pragma once
//ƒ‰ƒxƒ‹
#define PLAYER_INIT     (0)   
#define PLAYER_MOVE     (1)

enum PLAYER_STATUS
{
    SPEEDUP,
    SPEEDDOWN,
};

constexpr float SpeedMax = 8.0f;
constexpr float jump = -10.f;
constexpr float GROUND_POS_Y = 570.0f;

class Player : public OBJ2D
{
public:
    void init();
    void update();
    void draw();
};
extern Player player;