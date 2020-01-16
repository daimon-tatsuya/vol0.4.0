#pragma once
//ÉâÉxÉã
#define PLAYER_INIT     (0)   
#define PLAYER_MOVE     (1)

enum PLAYER_STATUS
{
    CONVEYORUP,
    SPEEDUP,
    POWERUP,
};

enum PLAYER
{
    LIFTED_MAX,
    CONVETIMER,
    SPEEDTIMER,
    POWERTIMER,
};

constexpr float SpeedMax = 8.0f;
constexpr float jump = -10.f;


class Player : public OBJ2D
{
public:
    int liftedCount = 0;//éùÇøè„Ç∞ÇΩêî
    float itemSpeed = 0;

    void init();
    void update();
    void draw();
};
extern Player player;