#pragma once

#define OVER_MAX (7)

extern void over_init();
extern void over_update();
extern void over_draw();
extern void over_end();

enum OVER_STATE
{
    OVER_SCORE,
    OVER_NUMBER1,
    OVER_NUMBER2,
    OVER_WIN,
    OVER_LOSE,
    OVER_PLAYER1,
    OVER_PLAYER2,
};

class  OVER :public OBJ2D
{
public:
    VECTOR2 posComp[7] = { {0, 0} };
    VECTOR2 scoreSCale = VECTOR2(0, 0);
    bool mode = false;
    bool player1Win = false;

    void init();
    void update();
    void draw();
};
EXTERN OVER over;




