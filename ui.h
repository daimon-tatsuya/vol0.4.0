#pragma once
#include "all.h"

extern int combNum;
extern int combKeta;
extern int timerNum;
extern int timerKeta;

class UI : public MoveAlg //move�֐���錾���Ă��Ȃ��̂Œ��ۃN���X
{
public:    
    int timerKetaID = 0;

    void timerMove(OBJ2D*);

    void combMove(OBJ2D*);
};
