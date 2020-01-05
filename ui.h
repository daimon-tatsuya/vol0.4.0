#pragma once
#include "all.h"

extern int combNum;
extern int combKeta;
extern int timerNum;
extern int timerKeta;

class UI : public MoveAlg //moveŠÖ”‚ğéŒ¾‚µ‚Ä‚¢‚È‚¢‚Ì‚Å’ŠÛƒNƒ‰ƒX
{
public:    
    int timerKetaID = 0;

    void timerMove(OBJ2D*);

    void combMove(OBJ2D*);
};
