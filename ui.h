#pragma once
#include "all.h"

extern int combNum[2];
extern int combKeta[2];
extern int timerNum;
extern int timerKeta;

class UI : public MoveAlg //move関数を宣言していないので抽象クラス
{
public:        

    void timerMove(OBJ2D*);

    void combMove(OBJ2D*);

    void comb2Move(OBJ2D*);//プレイヤー2用

    void randoMark(OBJ2D*);

    void rankingMove(OBJ2D*);
};
