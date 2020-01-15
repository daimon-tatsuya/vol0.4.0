#pragma once
//ƒ‰ƒxƒ‹
#define PLAYER_INIT     (0)   
#define PLAYER_MOVE     (1)

enum PLAYER_STATUS
{
    SPEEDUP,
    SPEEDDOWN,
};

enum PLAYER
{
    LIFTED_MAX,
};

constexpr float SpeedMax = 8.0f;
constexpr float jump = -10.f;


class Player : public OBJ2D
{
public:
    int liftedCount = 0;//‚¿ã‚°‚½”

    void init();
    void update();
    void draw();
};
extern Player player;