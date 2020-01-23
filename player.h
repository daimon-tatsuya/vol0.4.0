#pragma once
//ラベル
#define PLAYER_INIT     (0)   
#define PLAYER_MOVE     (1)

enum PLAYER_STATUS
{
    CONVEYORUP,
    SPEEDUP,
    POWERUP,
    ITEMADD,
};

enum PLAYER
{
    LIFTED_MAX,
    CONVETIMER,
    SPEEDTIMER,
    POWERTIMER,
    ITEMADDTIMER,
};

constexpr float SpeedMax = 8.0f;
constexpr float jump = -10.f;


class Player : public OBJ2D
{
public:
    int liftedCount = 0;//持ち上げた数
    float itemSpeed = 0;
    bool liftFlg;//garbage.cppで使う
    //int type;//1p,2pの
    void init();
    void update();
    void draw();
};
extern Player player[2];