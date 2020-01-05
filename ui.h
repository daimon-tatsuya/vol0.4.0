#pragma once
#include "all.h"

extern int combNum;
extern int combKeta;
extern int timerNum;
extern int timerKeta;

class UI : public MoveAlg //move関数を宣言していないので抽象クラス
{
public:    
    int timerKetaID = 0;

    void timerMove(OBJ2D*);

    void combMove(OBJ2D*);
};
