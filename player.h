#pragma once
//ƒ‰ƒxƒ‹
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
    int liftedCount = 0;//‚¿ã‚°‚½”
    float itemSpeed = 0;
    bool liftFlg;//garbage.cpp‚Åg‚¤
    //bool moveUpFlg;//ã‚É•à‚¢‚Ä‚¢‚é‚Æ‚«true
    //int type;//1p,2p‚Ì
    void init();
    void update();
    void draw();
};
extern Player player[2];